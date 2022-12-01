#include "glbunny.h"
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <assert.h>
#include <getopt.h>
#include <hpm.h>
#include <unistd.h>

#define BUNNY_IMPLEMENTATION
#include "Bunny.h"
uint32_t g_hpmflag = HPM_SSE2;
FILE *g_outputfd = NULL;
int g_fullscreen = 0;
int g_debug = 0;

/**
 *  Vertex shader.
 */
const char* gc_vertexpolygone = ""
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
 * Fragment shader.
 */
const char* gc_fragmentpolygone = ""
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

const char *get_glbunny_version(void) { return hpm_version(); }

unsigned int getGLSLVersion(void) {

	unsigned int version;
	char glstring[128] = {0};
	char *wspac;

	/*	Extract version number.	*/
	strcpy(glstring, (const char *)glGetString(GL_SHADING_LANGUAGE_VERSION));
	wspac = strstr(glstring, " ");
	if (wspac) {
		*wspac = '\0';
	}

	/*  Compute ascii to number.    */
	version = strtof(glstring, NULL) * 100;

	return version;
}

GLint createShader(const char *HPM_RESTRICT vsource, const char *HPM_RESTRICT fsource) {

	GLuint prog;
	GLuint vs, fs;
	GLuint vstatus, lstatus;

	char version[128]; /*	*/
	char *vsources[2]; /*	*/
	char *fsources[2]; /*	*/
	int sourcecount = sizeof(vsources) / sizeof(vsources[0]);

	/*  Get version string. */
	sprintf(version, "#version %d %s \n", getGLSLVersion(), "");
	vsources[0] = version;
	fsources[0] = version;
	/*  Assgin shader string.   */
	vsources[1] = (char *)vsource;
	fsources[1] = (char *)fsource;

	/*	Create shader.	*/
	prog = glCreateProgram();

	/*  Create vertex shader object.    */
	vs = glCreateShader(GL_VERTEX_SHADER_ARB);
	glShaderSourceARB(vs, sourcecount, vsources, NULL);
	glCompileShaderARB(vs);
	glAttachShader(prog, vs);

	/*  Create fragment shader object.  */
	fs = glCreateShader(GL_FRAGMENT_SHADER_ARB);
	glShaderSourceARB(fs, sourcecount, fsources, NULL);
	glCompileShaderARB(fs);
	glAttachShader(prog, fs);

	/*  Link and validate shader program.   */
	glLinkProgramARB(prog);
	glValidateProgramARB(prog);
	glGetProgramiv(prog, GL_LINK_STATUS, &lstatus);
	glGetProgramiv(prog, GL_VALIDATE_STATUS, &vstatus);

	/*  */
	if (lstatus == GL_FALSE) {
		char errorlog[2048];
		glGetProgramInfoLog(prog, sizeof(errorlog), NULL, &errorlog[0]);
		fprintf(stderr, errorlog);
		return -1;
	}

	/*	Release shader data.	*/
	/*	detach shader object and release their resources.	*/
	if (glIsShader(vs)) {
		glDetachShader(prog, vs);
		glDeleteShader(vs);
	}
	if (glIsShader(fs)) {
		glDetachShader(prog, fs);
		glDeleteShader(fs);
	}
	return prog;
}

GLuint createBunny(Geometry *geometry) {

	/*	Create bunny geometry.	*/
	glGenVertexArrays(1, &geometry->vao);
	glBindVertexArray(geometry->vao);

	glGenBuffersARB(1, &geometry->vbo);
	glGenBuffersARB(1, &geometry->nbo);
	glGenBuffersARB(1, &geometry->ibo);

	geometry->numIndices = BUNNY_NUM_INDICES;
	geometry->numVertices = BUNNY_NUM_VERTS;

	/*	*/
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, geometry->vbo);
	glBufferDataARB(GL_ARRAY_BUFFER_ARB, BUNNY_NUM_VERTS * sizeof(float) * 3, bunny_vertices, GL_STATIC_DRAW_ARB);

	/*	*/
	glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, geometry->ibo);
	glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, BUNNY_NUM_INDICES * sizeof(unsigned short), bunny_indices,
					GL_STATIC_DRAW_ARB);

	glEnableVertexAttribArrayARB(0);
	glVertexAttribPointerARB(0, 3, GL_FLOAT, GL_FALSE, 12, NULL);

	glBindBufferARB(GL_ARRAY_BUFFER_ARB, geometry->nbo);
	glBufferDataARB(GL_ARRAY_BUFFER_ARB, BUNNY_NUM_VERTS * sizeof(float) * 3, bunny_normals, GL_STATIC_DRAW_ARB);

	glEnableVertexAttribArrayARB(1);
	glVertexAttribPointerARB(1, 3, GL_FLOAT, GL_FALSE, 12, NULL);

	glBindVertexArray(0);

	return geometry->vao;
}

GLuint createGrid(unsigned int *numvertices, unsigned int *HPM_RESTRICT *numindices) { return 0; }

void print_dependency_versions(void) {
	SDL_version sdl_version;
	printf("------- Version ------\n");
	printf("hpm version %s.\n", hpm_version());
	SDL_GetVersion(&sdl_version);
	printf("SDL version %d.%d.%d.\n", sdl_version.major, sdl_version.minor, sdl_version.patch);
	printf("------------------\n\n");
}

void readargument(int argc, const char **argv) {

	/*	Possible long options.	*/
	static struct option longoption[] = {
		{"version", no_argument, NULL, 'v'},	  /*	Print version of the glbunny and hpm library.	*/
		{"debug", no_argument, NULL, 'd'},		  /*	Change default SIMD. */
		{"output", required_argument, NULL, 'o'}, /*	Override the time output.	*/
		{"simd", required_argument, NULL, 's'},	  /*	Change default SIMD. */
		{NULL, 0, NULL, 0},
	};

	int c;
	int indexopt;
	const char *shortopt = "vVdo:s:";

	/*  Iterate through all argument.	*/
	while ((c = getopt_long(argc, (char *const *)argv, shortopt, longoption, &indexopt)) != EOF) {
		switch (c) {
		case 'v':
			printf("version %s.\n", get_glbunny_version());
			exit(EXIT_SUCCESS);
		case 's':
			if (optarg) {
				int i = 1;

				do {
					if (strcmp(hpm_get_simd_symbol(i), optarg) == 0) {
						break;
					}
					i <<= 1;
					if (hpm_get_simd_symbol(i) == NULL) {
						fprintf(stderr, "Invalid SIMD option, %s.\n", optarg);
						exit(EXIT_FAILURE);
					}
				} while (hpm_get_simd_symbol(i));
				g_hpmflag = i;

				/*	Check if supported.	*/
				if (!hpm_support_cpu_feat(g_hpmflag)) {
					fprintf(stderr, "SIMD extension not supported.\n");
					exit(EXIT_FAILURE);
				}
			}
			break;
		case 'o':
			if (optarg)
				g_outputfd = fopen(optarg, "wb");
			break;
		case 'd':
			g_debug = 1;
			break;
		default:
			break;
		}
	}

	/*	Default output.	*/
	if (g_outputfd == NULL)
		g_outputfd = stdout;

	/*	Reset getopt.	*/
	optind = 0;
	opterr = 0;
	optarg = NULL;
}
