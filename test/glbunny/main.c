#include<hpm.h>
#include"glbunny.h"
#include<assert.h>
#include<getopt.h>
#include<SDL2/SDL.h>
#ifdef HPM_WINDOWS	/*	This is done because Windows supports only OpenGL1.1 natively so yeah....*/
	#include<GL/glew.h>
#else
	#include<GL/gl.h>
	#include<GL/glext.h>
#endif

#include"Bunny.h"

int main(int argc, const char** argv){

	int status = EXIT_SUCCESS;

	/*	*/
	int result = 0;                         /*	*/
	int isAlive = 1;                        /*	*/
	int i,j,z;                              /*	*/
	int glflag;                             /*	*/
	SDL_Event event = {0};                  /*	*/
	SDL_Window* window = NULL;              /*	*/
	SDL_GLContext* glc = NULL;			/*	*/
	SDL_DisplayMode dismode = {0};		/*	*/
	Uint64 freq;						/*	*/
	Uint64 pretime;						/*	*/

	/*	*/
	const unsigned int rows = 4;			/*	*/
	const unsigned int colu = 4;			/*	*/
	const unsigned int layers = 1;			/*	*/
	const unsigned int numInstances = rows * colu * layers;

	hpmvec4x4f_t* mvp = NULL;				/*	*/
	hpmvec4x4f_t* model = NULL;				/*	*/
	hpmvec4x4f_t* modelview = NULL;			/*	*/
	hpmvec4x4f_t view;						/*	*/
	hpmvec4x4f_t proj;						/*	*/
	hpmvec4f position = { 0, 0, -100, 0 };	/*	*/
	hpmquatf camor = { 0.0f };				/*	*/
	hpmvec4f dir = { 0.0f };				/*	*/

	hpmquatf* quat = NULL;					/*	*/
	float rot = 0.0f;						/*	*/
	float fov = 40.0f;						/*	*/

	/*	*/
	unsigned int numindices;				/*	*/
	unsigned int numvertices;				/*	*/

	GLuint vao = 0;
	GLuint vbo = 0;
	GLuint nbo = 0;
	GLuint ibo = 0;
	GLuint prog = 0;
	GLint mvploc = 0;
	GLint modeloc = 0;

	/*	Read user argument.	*/
	readargument(argc, argv);

	/*	Print dependency library versions.*/
	print_dependency_versions();

	/*	*/
	if( hpm_init(g_hpmflag) == 0 ){
		fprintf(stderr, "Failed to initialize HPM, %x.\n", g_hpmflag);
		return EXIT_FAILURE;
	}

	/*	Allocate matrix buffers.	*/
	mvp = malloc(sizeof(hpmvec4x4f_t) * numInstances);
	model = malloc(sizeof(hpmvec4x4f_t) * numInstances);
	modelview = malloc(sizeof(hpmvec4x4f_t) * numInstances);
	quat = malloc(sizeof(hpmquatf) * numInstances);
	assert(mvp);
	assert(model);
	assert(modelview);
	assert(quat);

	/*	Initilize default values for each matrix and quaternion.	*/
	for( i = 0; i < numInstances; i++){
		hpm_mat4x4_identityfv(mvp[i]);
		hpm_mat4x4_identityfv(model[i]);
		hpm_mat4x4_identityfv(modelview[i]);
		hpm_quat_identityfv(&quat[i]);
	}
	hpm_mat4x4_identityfv(view);
	hpm_mat4x4_identityfv(proj);
	hpm_quat_identityfv(&camor);

	/*	Initialize SDL.	*/
	result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	if( result != 0){
		fprintf(stderr, "Failed to initialize, %s.\n", SDL_GetError());
		status = EXIT_FAILURE;
		goto error;
	}

	/*	Get timer frequency resolution.	*/
	freq = SDL_GetPerformanceFrequency();

	/*	Get display window size.	*/
	if(SDL_GetCurrentDisplayMode(0, &dismode) != 0){
		fprintf(stderr, "SDL_GetCurrentDisplayMode failed, %s.\n", SDL_GetError());
		status = EXIT_FAILURE;
		goto error;
	}

	/*	Create window.	*/
	char title[128];
	sprintf(title, "hpm-benchmark-GL - %s", hpm_get_simd_symbol(g_hpmflag));
	window = SDL_CreateWindow(title,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			dismode.w  / 2, dismode.h / 2,
			SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE );
	if(window == NULL){
		fprintf(stderr, "Failed to create window, %s.\n", SDL_GetError());
		status = EXIT_FAILURE;
		goto error;
	}


	/*	Create OpenGL display.	*/
	SDL_GL_GetAttribute(SDL_GL_CONTEXT_FLAGS, &glflag);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, glflag | SDL_GL_CONTEXT_DEBUG_FLAG);
	glc = SDL_GL_CreateContext(window);
	if( glc == NULL ) {
		fprintf(stderr, "Failed to create OpenGL context, %s.\n", SDL_GetError());
		status = EXIT_FAILURE;
		goto error;
	}

	/*	Make GL Context current with the window.	*/
	if( SDL_GL_MakeCurrent(window, glc) > 0){
		fprintf(stderr, "Failed to make current, %s.\n", SDL_GetError());
		status = EXIT_FAILURE;
		goto error;
	}

	/*	Initialize glslview.	*/
#ifdef HPM_WINDOWS

#endif

	/*	Set OpenGL state.	*/
	SDL_GL_SetSwapInterval(0);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LESS);
	glEnable(GL_DITHER);
	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_STENCIL_TEST);
	glDisable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_FALSE);
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	hpm_mat4x4_projfv(proj,
			HPM_DEG2RAD(fov),
			(float)(dismode.w / 2) / (float)(dismode.h / 2),
			0.15f, 1000.0f);

	/*	Create bunny geometry.	*/
	vao = createBunny(&numvertices, &numindices);

	/*	Create shader.	*/
	prog = createShader(vertexpolygone, fragmentpolygone);
	if(prog < 0){
		fprintf(stderr, "Failed create shader.\n");
		status = EXIT_FAILURE;
		goto error;
	}

	/*	Enable program. */
	glUseProgram(prog);
	mvploc = glGetUniformLocation(prog, "mvp");
	modeloc = glGetUniformLocation(prog, "model");

	/*	Main loop.	*/
	pretime = SDL_GetPerformanceCounter();
	while( isAlive ){

		while(SDL_PollEvent(&event)){
			switch(event.type){
			case SDL_QUIT:
				isAlive = 0;
				break;
			case SDL_MOUSEWHEEL:
				hpm_quat_directionfv(&camor, &dir);

				position += dir * (float)event.wheel.y;

				hpm_mat4x4_translationfv(view, &position);
				hpm_mat4x4_multi_rotationQfv(view, &camor);
				break;
			case SDL_MOUSEMOTION:{

				hpmvec3f right;
				hpmvec3f up = { 0, 1, 0 , 0 };

				hpm_quat_directionfv(&camor, &dir);
				hpm_vec3_crossproductfv(&up, &dir, &right );
				hpm_vec3_crossproductfv( &dir, &right, &up );

				if(event.motion.state & SDL_BUTTON_LMASK){
					hpmquatf tmpquat;
					hpmquatf tmpquat2;
					hpmquatf tmpcamrot;

					tmpcamrot = camor;

					hpm_quat_axis_anglefv(&tmpquat, &up, event.motion.xrel / 50.0f);
					hpm_quat_axis_anglefv(&tmpquat2, &right, event.motion.yrel / 50.0f);
					hpm_quat_multi_quatfv(&tmpcamrot, &tmpquat2, &camor);
					hpm_quat_normalizefv(&camor);
					tmpcamrot = camor;
					hpm_quat_multi_quatfv(&tmpcamrot, &tmpquat, &camor);
					hpm_quat_normalizefv(&camor);
				}

				if(event.motion.state & SDL_BUTTON_MMASK){
					hpmvec4f tmpdiff = { 0.0f };
					tmpdiff += (float)event.motion.yrel  * ( 1.0f / 30.0f ) * up;
					tmpdiff += (float)event.motion.xrel  * ( 1.0f / 30.0f ) * right;
					position += tmpdiff  * -1.0f;
				}

				if(event.motion.state & SDL_BUTTON_RMASK){
					position += dir * (float)event.motion.xrel * ( 1.0f / 30.0f );
				}


				hpm_mat4x4_translationfv(view, &position);
				hpm_mat4x4_multi_rotationQfv(view, &camor);
			}break;
			case SDL_KEYDOWN:
				if( ( event.key.keysym.sym == SDLK_RETURN ) && (event.key.keysym.mod & SDLK_LCTRL ) ){
					SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP );
				}
				if(event.key.keysym.sym == SDLK_f){
					hpm_vec4_setf(&position,
							-( bunny_model_centroid[0] + bunny_model_maxbounds[0] ),
							-( bunny_model_centroid[1] + bunny_model_maxbounds[1] ),
							-( bunny_model_centroid[2] + bunny_model_maxbounds[2] ), 0.0f);
					hpm_quat_axisf(&camor, HPM_DEG2RAD( 30.0f ), 0, 0);

					hpm_mat4x4_translationfv(view, &position);
					hpm_mat4x4_multi_rotationQfv(view, &camor);
				}
				if(event.key.keysym.sym == SDLK_UP){

					hpmvec3f up = { 0, 1, 0 , 0 };
					hpmvec3f right;

					hpm_quat_directionfv(&camor, &dir);
					hpm_vec3_crossproductfv(&up, &dir, &right );
					hpm_vec3_crossproductfv( &dir, &right, &up );

					hpmvec4f tmpdiff = { 0.0f };
					tmpdiff += ( 1.0f / 30.0f ) * up;
					position += tmpdiff  * -1.0f;
				}
				if(event.key.keysym.sym == SDLK_DOWN){

				}
				if(event.key.keysym.sym == SDLK_LEFT){

				}
				if(event.key.keysym.sym == SDLK_RIGHT){

				}

				break;
			case SDL_WINDOWEVENT:
				switch(event.window.event){
				case SDL_WINDOWEVENT_RESIZED:
				case SDL_WINDOWEVENT_SIZE_CHANGED:
					glViewport(0,0, event.window.data1, event.window.data2);
					hpm_mat4x4_projfv(proj,
							HPM_DEG2RAD(fov),
							(float)event.window.data1 / (float)event.window.data2,
							0.15f, 1000.0f);
					break;
				case SDL_WINDOWEVENT_SHOWN:
					break;
				case SDL_WINDOWEVENT_MOVED:
					break;
				case SDL_WINDOWEVENT_HIDDEN:
					break;
				case SDL_WINDOWEVENT_CLOSE:
					break;
				default:
					break;
				}
				break;
				default:
					break;
			}
		}

		/*	*/
		float time = (SDL_GetPerformanceCounter() - pretime ) / (float)freq;
		pretime = SDL_GetPerformanceCounter();
		fprintf(g_outputfd, "%f\n", time);

		rot += time;

		/*	Create matrices for each geometry object.	*/
		for(i = 0; i < rows; i++){
			for( j = 0; j < colu; j++){
				int index = i * rows + j;
				hpmvec4f pos = { i , 0, j , 0};
				pos *= 3;

				/*	Create model matrix.	*/
				hpm_quat_axisf(&quat[index], 0, rot + i , 0);
				hpm_mat4x4_translationfv(model[index], &pos);
				hpm_mat4x4_multi_rotationQfv(model[index], &quat[index]);

				/*	Create mode view matrix.	*/
				hpm_mat4x4_multiply_mat4x4fv( view, model[index], modelview[index]);
				hpm_mat4x4_multiply_mat4x4fv( proj, modelview[index], mvp[index]);
			}
		}

		/*	*/
		SDL_GL_SwapWindow(window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		/*	Render.	*/
		glUniformMatrix4fv(mvploc, numInstances, GL_FALSE, mvp);
		glUniformMatrix4fv(modeloc, numInstances, GL_FALSE, model);
		glDrawElementsInstanced(GL_TRIANGLES, numindices, GL_UNSIGNED_SHORT, NULL, numInstances);

	}

	error:	/*	Cleanup.	*/

	/*	Release matrix memory chunk.	*/
	free(mvp);
	free(model);
	free(modelview);
	free(quat);

	/*	Release OpenGL Resources.	*/
	if(window && glc){
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &ibo);
		glDeleteProgram(prog);

		/*	*/
		SDL_GL_MakeCurrent(window, NULL);
		SDL_GL_DeleteContext(glc);
		SDL_DestroyWindow(window);
	}
	SDL_Quit();
	hpm_release();

	return status;
}
