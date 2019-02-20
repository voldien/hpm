#include<hpm.h>
#include"glbunny.h"
#include<assert.h>
#include<getopt.h>
#include<SDL2/SDL.h>
#include<GL/glew.h>
#include"Bunny.h"


int createScene(Scene* scene) {

	int status = 1;

	/*	*/
	int result = 0;                         /*	*/
	int glflag;                             /*	*/
	SDL_DisplayMode dismode = {0};		    /*	*/
	const float fov = 40.0f;				/*	*/

	/*	Initialize SDL.	*/
	result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	if( result != 0){
		fprintf(stderr, "Failed to initialize, %s.\n", SDL_GetError());
		status = EXIT_FAILURE;
		goto error;
	}

	/*	Get display window size.	*/
	if(SDL_GetCurrentDisplayMode(0, &dismode) != 0){
		fprintf(stderr, "SDL_GetCurrentDisplayMode failed, %s.\n", SDL_GetError());
		status = EXIT_FAILURE;
		goto error;
	}

	/*	Create window.	*/
	char title[128];
	sprintf(title, "hpm-benchmark-GL - %s", hpm_get_simd_symbol(g_hpmflag));
	scene->window = SDL_CreateWindow(title,
	                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	                          dismode.w  / 2, dismode.h / 2,
	                          SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE );
	if(scene->window == NULL){
		fprintf(stderr, "Failed to create window, %s.\n", SDL_GetError());
		status = EXIT_FAILURE;
		goto error;
	}

	/*	Create OpenGL display.	*/
	SDL_GL_GetAttribute(SDL_GL_CONTEXT_FLAGS, &glflag);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, glflag | SDL_GL_CONTEXT_DEBUG_FLAG);
	scene->glc = SDL_GL_CreateContext(scene->window);
	if( scene->glc == NULL ) {
		fprintf(stderr, "Failed to create OpenGL context, %s.\n", SDL_GetError());
		status = EXIT_FAILURE;
		goto error;
	}

	/*	Make GL Context current with the window.	*/
	if( SDL_GL_MakeCurrent(scene->window, scene->glc) > 0){
		fprintf(stderr, "Failed to make current, %s.\n", SDL_GetError());
		status = EXIT_FAILURE;
		goto error;
	}

	/*	Initialize glslview.	*/
	if(glewInit() != GLEW_OK){
		fprintf(stderr, "Failed init glew.\n");
		exit(EXIT_FAILURE);
	}

	/*  Check if OpenGL debug shall be enabled. */
	if(g_debug)
		enableGLDebug();

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
	hpm_mat4x4_projfv(scene->proj,
	                  HPM_DEG2RAD(fov),
	                  (float)dismode.w / (float)dismode.h,
	                  0.15f, 1000.0f);

	/*	Create bunny geometry.	*/
	createBunny(&scene->bunny);

	/*	Create shader.	*/
	scene->prog = createShader(gc_vertexpolygone, gc_fragmentpolygone);
	if(scene->prog < 0){
		fprintf(stderr, "Failed create shader.\n");
		status = 0;
		goto error;
	}

	error:

	return status;
}

int releaseScene(Scene *scene) {

	/*	Release matrices memory chunk.	*/
	free(scene->mvp);
	free(scene->model);
	free(scene->modelview);
	free(scene->quat);

	/*	Release OpenGL Resources.	*/
	if(scene->window && scene->glc){
		glDeleteVertexArrays(1, &scene->bunny.vao);
		glDeleteBuffersARB(1, &scene->bunny.vbo);
		glDeleteBuffersARB(1, &scene->bunny.ibo);
		glDeleteProgram(scene->prog);

		/*	Release context and window.*/
		SDL_GL_MakeCurrent(scene->window, NULL);
		SDL_GL_DeleteContext(scene->glc);
		SDL_DestroyWindow(scene->window);
	}
	return 0;
}

void sceneRenderer(Scene* scene) {
	
	/*	*/
	int isAlive = 1;            /*	*/
	int i,j,z;                  /*	*/
	SDL_Event event = {0};      /*	*/
	Uint64 freq;                /*	*/
	Uint64 pretime;             /*	*/

	/*	*/
	const unsigned int rows = 4;			/*	*/
	const unsigned int colu = 4;			/*	*/
	const unsigned int layers = 1;			/*	*/
	const unsigned int numInstances = rows * colu * layers;

	float rot = 0.0f;						/*	*/
	float fov = 40.0f;						/*	*/

	GLint mvploc = 0;
	GLint modeloc = 0;

	/*	Allocate matrix buffers.	*/
	scene->mvp = malloc(sizeof(hpmvec4x4f_t) * numInstances);
	scene->model = malloc(sizeof(hpmvec4x4f_t) * numInstances);
	scene->modelview = malloc(sizeof(hpmvec4x4f_t) * numInstances);
	scene->quat = malloc(sizeof(hpmquatf) * numInstances);
	assert(scene->mvp);
	assert(scene->model);
	assert(scene->modelview);
	assert(scene->quat);

	/*	Initilize default values for each matrix and quaternion.	*/
	for( i = 0; i < numInstances; i++){
		hpm_mat4x4_identityfv(scene->mvp[i]);
		hpm_mat4x4_identityfv(scene->model[i]);
		hpm_mat4x4_identityfv(scene->modelview[i]);
		hpm_quat_identityfv(&scene->quat[i]);
	}
	hpm_mat4x4_identityfv(scene->view);
	hpm_mat4x4_identityfv(scene->proj);
	hpm_quat_identityfv(&scene->camor);

	/*	Enable shader program. */
	glUseProgram(scene->prog);
	mvploc = glGetUniformLocation(scene->prog, "mvp");
	modeloc = glGetUniformLocation(scene->prog, "model");

	/*  Init timer value.   */
	pretime = SDL_GetPerformanceCounter();
	/*	Get timer frequency resolution.	*/
	freq = SDL_GetPerformanceFrequency();

	/*	Main loop.	*/
	while( isAlive ){

		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT:
					isAlive = 0;
					break;
				case SDL_MOUSEWHEEL:
					/*	Move forward and back based on
					 *	the forward direction
					 *	vector.*/
					hpm_quat_directionfv(&scene->camor, &scene->dir);

					scene->position += scene->dir * (float)event.wheel.y;

					hpm_mat4x4_translationfv(scene->view, &scene->position);
					hpm_mat4x4_multi_rotationQfv(scene->view, &scene->camor);
					break;
				case SDL_MOUSEMOTION:{

					hpmvec3f right;
					hpmvec3f up = { 0, 1, 0 , 0 };

					hpm_quat_normalizefv(&scene->camor);
					hpm_quat_directionfv(&scene->camor, &scene->dir);
					hpm_vec3_crossproductfv(&up, &scene->dir, &right );
					hpm_vec3_crossproductfv( &scene->dir, &right, &up );

					if(event.motion.state & SDL_BUTTON_LMASK){
						/*	Rotate around point.	*/
						hpmquatf tmpquat;
						hpmquatf tmpquat2;
						hpmquatf tmpcamrot;

						tmpcamrot = scene->camor;

						hpm_quat_axis_anglefv(&tmpquat, &up, event.motion.xrel / 50.0f);
						hpm_quat_axis_anglefv(&tmpquat2, &right, event.motion.yrel / 50.0f);
						hpm_quat_multi_quatfv(&tmpcamrot, &tmpquat2, &scene->camor);
						hpm_quat_normalizefv(&scene->camor);
						tmpcamrot = scene->camor;
						hpm_quat_multi_quatfv(&tmpcamrot, &tmpquat, &scene->camor);
						hpm_quat_normalizefv(&scene->camor);
					}

					if(event.motion.state & SDL_BUTTON_MMASK){
						/*	Pan on the plane with camera direction as normal	.*/
						hpmvec4f tmpdiff = { 0.0f };
						tmpdiff += (float)event.motion.yrel  * ( 1.0f / 30.0f ) * up;
						tmpdiff += (float)event.motion.xrel  * ( 1.0f / 30.0f ) * right;
						scene->position += tmpdiff  * -1.0f;
					}

					if(event.motion.state & SDL_BUTTON_RMASK){
						/*	Zoom forward/backward.	*/
						scene->position += scene->dir * (float)event.motion.xrel * ( 1.0f / 30.0f );
					}

					/*	Update view matrix.	*/
					hpm_mat4x4_translationfv(scene->view, &scene->position);
					hpm_mat4x4_multi_rotationQfv(scene->view, &scene->camor);
				}break;
				case SDL_KEYDOWN:
					/*	Set fullscreen.	*/
					if( ( event.key.keysym.sym == SDLK_RETURN ) && (event.key.keysym.mod & SDLK_LCTRL ) ){
						g_fullscreen = ~g_fullscreen & 0x1;
						SDL_SetWindowFullscreen(scene->window, g_fullscreen ?  SDL_WINDOW_FULLSCREEN_DESKTOP : 0 );
					}

					if(event.key.keysym.sym == SDLK_f){

						/*	Reset view.	*/
						hpm_vec4_setf(&scene->position,
						              -( bunny_model_centroid[0] + bunny_model_maxbounds[0] ),
						              -( bunny_model_centroid[1] + bunny_model_maxbounds[1] ),
						              -( bunny_model_centroid[2] + bunny_model_maxbounds[2] ), 0.0f);
						hpm_quat_axisf(&scene->camor, (hpmvecf)HPM_DEG2RAD( 30.0f ), 0, 0);

						/*	Update view matrix.	*/
						hpm_mat4x4_translationfv(scene->view, &scene->position);
						hpm_mat4x4_multi_rotationQfv(scene->view, &scene->camor);
					}

					/*	*/
					const hpmvec3f cdir[] = {
							{1, 0, 0, 0},
							{-1,0, 0, 0},
							{0, 0,-1, 0},
							{0, 0, 1, 0}};

					if(event.key.keysym.sym == SDLK_UP
					   || event.key.keysym.sym == SDLK_LEFT
					   || event.key.keysym.sym == SDLK_RIGHT
					   || event.key.keysym.sym == SDLK_DOWN){


						/*  Get direction vector from quaternion rotation. */
						const hpmvec3f* direction = &cdir[SDLK_RIGHT - event.key.keysym.sym];
						hpm_quat_get_vectorfv(&scene->camor, direction , &scene->dir);

						/*  Update position.    */
						scene->position += scene->dir  * -1.0f * 1000.0f;
					}

					break;
				case SDL_WINDOWEVENT:
					switch(event.window.event){
						case SDL_WINDOWEVENT_RESIZED:
						case SDL_WINDOWEVENT_SIZE_CHANGED:
							glViewport(0,0, event.window.data1, event.window.data2);
							hpm_mat4x4_projfv(scene->proj,
							                  (hpmvecf)HPM_DEG2RAD(fov),
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
							goto error;
						default:
							break;
					}
					break;
				default:
					break;
			}
		}

		/*	Update time uniform.	*/
		float time = (SDL_GetPerformanceCounter() - pretime ) / (float)freq;
		pretime = SDL_GetPerformanceCounter();
		fprintf(g_outputfd, "%f seconds - average ,%d fps\n", time, (unsigned int)(1.0f / time));

		rot += time;

		/*	Create matrices for each geometry object.	*/
		for(i = 0; i < rows; i++){
			for( j = 0; j < colu; j++){
				int index = i * rows + j;
				hpmvec4f pos = { i , 0, j , 0};
				pos *= 3;

				/*	Create model matrix.	*/
				hpm_quat_axisf(&scene->quat[index], 0, rot + i , 0);
				hpm_mat4x4_translationfv(scene->model[index], &pos);
				hpm_mat4x4_multi_rotationQfv(scene->model[index], &scene->quat[index]);

				/*	Create mode view matrix.	*/
				hpm_mat4x4_multiply_mat4x4fv( scene->view, scene->model[index], scene->modelview[index]);
				hpm_mat4x4_multiply_mat4x4fv( scene->proj, scene->modelview[index], scene->mvp[index]);
			}
		}

		/*	Display image.	*/
		SDL_GL_SwapWindow(scene->window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		/*	Set each matrix uniforms.	*/
		glUniformMatrix4fv(mvploc, numInstances, GL_FALSE, (const GLfloat*)scene->mvp);
		glUniformMatrix4fv(modeloc, numInstances, GL_FALSE, (const GLfloat*)scene->model);

		/*  Draw all geometries.   */
		glBindVertexArray(scene->bunny.vao);
		glDrawElementsInstancedARB(GL_TRIANGLES, scene->bunny.numIndices, GL_UNSIGNED_SHORT, NULL, numInstances);
		glBindVertexArray(0);


		/*  Draw background and floor.  */
	}

	error:	/*	Cleanup.	*/
	
	return;
}
