#include"glbunny.h"
#include<hpm/hpm.h>
#include<assert.h>
#include<getopt.h>
#include<unistd.h>
#include<SDL2/SDL.h>
#ifdef HPM_WINDOWS	/*	This is done because Windows supports only OpenGL1.1 natively so yeah....*/
	#include<GL/glew.h>
#else
	#include<GL/gl.h>
	#include<GL/glext.h>
#endif

#define BUNNY_IMPLEMENTATION
#include"Bunny.h"
uint32_t hpmflag = HPM_SSE2;
FILE* outputfd = NULL;

const char* gc_simd_symbols[] = {
		"",
		"nosimd",
		"MMX",
		"SSE",
		"SSE2",
		"SSE3",
		"SSE41",
		"SSE42",
		"AVX",
		"AVX2",
		"AVX512",
		"NEON",
		NULL,
};


/**
 *  Vertex shader.
 */
const char* vertexpolygone = ""
"\n"
"#if __VERSION__ >= 330\n"
"layout(location = 0) in vec3 vertex;\n"
"layout(location = 1) in vec3 normal;\n"
"#else\n"
"attribute vec3 vertex;\n"
"attribute vec3 normal;\n"
"#endif\n"
"uniform mat4 mvp[128];\n"
"uniform mat4 model[128];\n"
"#if __VERSION__ > 120\n"
"out vec3 Normal;\n"
"#else\n"
"uniform int gl_instanceID;\n"
"varying vec3 Normal;\n"
"#endif\n"
"void main(void){\n"
"	#if __VERSION__ >= 140\n"
"	gl_Position = mvp[gl_InstanceID] * vec4(vertex, 1.0);\n"
"	Normal = ( model[gl_InstanceID] * vec4(normal, 0.0)).xyz;\n"
"	#else\n"
"	gl_Position = mvp[0] * vec4(vertex, 1.0);\n"
"	Normal = ( model[0] * vec4(normal, 0.0)).xyz;\n"
"	#endif\n"
"}\n";

/**
 *  Fragment shader.
 */
const char* fragmentpolygone = ""
"\n"
"#if __VERSION__ >= 330\n"
"layout(location = 0) out vec4 fragColor;\n"
"#endif\n"
"uniform mat4 proj;\n"
"uniform float time;\n"
"#if __VERSION__ > 120\n"
"in vec3 Normal;\n"
"#else\n"
"varying vec3 Normal;\n"
"#endif\n"
"void main(void){\n"
"#if __VERSION__ >= 330\n"
"	fragColor = vec4(vec3(dot(Normal, vec3(0,-1,0) ) ), 1.0);\n"
"	#else\n"
"	gl_FragColor = vec4(vec3(dot(Normal, vec3(0,-1,0) ) ), 1.0);\n"
"	#endif\n"
"}\n";



unsigned int getGLSLVersion(void){

	unsigned int version;
	char glstring[128] = {0};
	char* wspac;

	/*	Extract version number.	*/
	strcpy(glstring, (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION));
	wspac = strstr(glstring, " ");
	if(wspac){
		*wspac = '\0';
	}

	/*  Compute ascii to number.    */
	version = strtof(glstring, NULL) * 100;

	return version;
}

int Log2MutExlusive32(unsigned int a){

	int i = 0;
	int po = 0;
	const int bitlen = 32;

	if(a == 0)
		return 0;

	for(; i < bitlen; i++){
		if((a >> i) & 0x1)
			return (i + 1);
	}

	assert(0);
}

GLint createShader(const char* __restrict__ vsource,
        const char* __restrict__ fsource) {

	GLuint prog;
	GLuint vs, fs;
	GLuint vstatus, lstatus;

	char version[128];					/*	*/
	char* vsources[2];					/*	*/
	char* fsources[2];					/*	*/
	int sourcecount = sizeof(vsources) / sizeof(vsources[0]);

	/*  Get version string. */
	sprintf(version, "#version %d\n", getGLSLVersion() );
	vsources[0] = version;
	fsources[0] = version;
	/*  Assgin shader string.   */
	vsources[1] = (char*)vsource;
	fsources[1] = (char*)fsource;

	/*	Create shader.	*/
	prog = glCreateProgram();

	/*  Create vertex shader object.    */
	vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, sourcecount, vsources, NULL);
	glCompileShader(vs);
	glAttachShader(prog, vs);

	/*  Create fragment shader object.  */
	fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, sourcecount, fsources, NULL);
	glCompileShader(fs);
	glAttachShader(prog, fs);

	/*  Link and validate shader program.   */
	glLinkProgram(prog);
	glValidateProgram(prog);
	glGetProgramiv(prog, GL_LINK_STATUS, &lstatus);
	glGetProgramiv(prog, GL_VALIDATE_STATUS, &vstatus);

	/*  */
	if(lstatus == GL_FALSE){
		char errorlog[2048];
		glGetProgramInfoLog(prog, sizeof(errorlog), NULL, &errorlog[0]);
		fprintf(stderr, errorlog);
		return -1;
	}

	/*	Release shader data.	*/
	/*	detach shader object and release their resources.	*/
	glDetachShader(prog, vs);
	glDetachShader(prog);
	glDeleteShader(vs);
	glDeleteShader(fs);
	return prog;
}

GLuint createBunny(unsigned int* __restrict__ numvertices,
        unsigned int* __restrict__ numindices){

	GLuint vao;
	GLuint vbo;
	GLuint ibo;
	GLuint nbo;

	/*	Create bunny geometry.	*/
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glGenBuffers(1, &nbo);
	glGenBuffers(1, &ibo);

	*numindices = BUNNY_NUM_INDICES;
	*numvertices = BUNNY_NUM_VERTS;

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, BUNNY_NUM_VERTS * sizeof(float) * 3, bunny_vertices, GL_STATIC_DRAW);

	/*	*/
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, BUNNY_NUM_INDICES * sizeof(unsigned short), bunny_indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12, NULL);

	glBindBuffer(GL_ARRAY_BUFFER, nbo);
	glBufferData(GL_ARRAY_BUFFER, BUNNY_NUM_VERTS * sizeof(float) * 3, bunny_normals, GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 12, NULL);

	return vao;
}

void print_dependency_versions(void){
	SDL_version sdl_version;
	printf("------- Version ------\n");
	printf("hpm version %s.\n", hpm_version());
	SDL_GetVersion(&sdl_version);
	printf("SDL version %d.%d.%d.\n", sdl_version.major, sdl_version.minor, sdl_version.patch);
	printf("------------------\n\n");
}

void readargument(int argc, const char** argv){

    /*	*/
	static struct option longoption[] = {
			{"version",	no_argument,	NULL, 'v'},
			{"output",	required_argument,	NULL, 'o'},
			{"simd",	required_argument,	NULL, 's'},
			{NULL,	0,	NULL, 0},
	};

	int c;
	int indexopt;
	const char* shortopt = "vVo:s:";

	/*  Iterate through all argument.	*/
	while ( ( c = getopt_long(argc, ( char *const *)argv, shortopt, longoption, &indexopt)) != EOF){
		switch(c){
		case 'v':
			printf("version.\n");
			exit(EXIT_SUCCESS);
			break;
		case 's':
			if(optarg){
			    hpmflag = 0;
			}
			break;
		case 'o':
			if(optarg)
				outputfd = fopen(optarg, "wb");
			break;
		default:
			break;
		}
	}

	/*	Default output.	*/
	if(outputfd == NULL)
		outputfd = stdout;

	/*	Reset getopt.	*/
	optind = 0;
	opterr = 0;
	optarg = NULL;
}