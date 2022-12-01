/**
	High performance matrix library utilizing SIMD extensions.
	Copyright (C) 2016  Valdemar Lindberg

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#ifndef _HPM_GL_BUNNY_H_
#define _HPM_GL_BUNNY_H_ 1
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <hpm.h>
#include <stdio.h>

/**
 * Global constants.
 */
extern const char *gc_vertexpolygone;	/*	Vertex */
extern const char *gc_fragmentpolygone; /*	Fragment.	*/

/**
 * Global variable.
 */
extern uint32_t g_hpmflag; /*	*/
extern FILE *g_outputfd;   /*	*/
extern int g_fullscreen;   /*	*/
extern int g_debug;		   /*	*/

/**
 *
 */
typedef struct geometry_t {
	GLuint vao;
	GLuint vbo;
	GLuint nbo;
	GLuint ibo;
	GLint numVertices;
	GLint numIndices;
	hpmvec4f minBound;
	hpmvec4f maxBound;
	hpmvec4f centerBound;
} Geometry;

typedef struct scene_t {
	int glflag;			/*	*/
	SDL_Window *window; /*	*/
	SDL_GLContext *glc; /*	*/
	Uint64 freq;		/*	*/
	Uint64 pretime;		/*	*/

	hpmvec4x4f_t *mvp;		 /*	*/
	hpmvec4x4f_t *model;	 /*	*/
	hpmvec4x4f_t *modelview; /*	*/
	hpmvec4x4f_t view;		 /*	*/
	hpmvec4x4f_t proj;		 /*	*/
	hpmvec4f position;		 /*	*/
	hpmquatf camor;			 /*	*/
	hpmvec4f dir;			 /*	*/
	hpmquatf *quat;			 /*	*/

	Geometry bunny;
	Geometry plan;
	GLuint prog;
	GLint mvploc;
	GLint modeloc;
} Scene;

/**
 * Get version of hpmglbunny program
 *	version.
 * @return non-null terminated string.
 */
extern const char *get_glbunny_version(void);

/**
 * Get GLSL version of current OpenGL context.
 * @return 3 digit version in 10^3.
 */
extern unsigned int getGLSLVersion(void);

/**
 * Enable OpenGL debug callback and logging.
 */
extern void enableGLDebug(void);

/**
 * Create shader object from shader source
 *	string.
 *
 * @return shader program unique id.
 */
extern GLint createShader(const char *HPM_RESTRICT vsource, const char *HPM_RESTRICT fsource);

/**
 * Create bunny.
 *
 * @return non-negative if succesfully.
 */
extern GLuint createBunny(Geometry *HPM_RESTRICT geometry);

/**
 * Create grid object.
 * @param numvertices
 * @param numindices
 * @return
 */
extern GLuint createGrid(unsigned int *HPM_RESTRICT numvertices, unsigned int *HPM_RESTRICT *numindices);

/**
 *
 * @param nVertices
 * @param nIndices
 * @return
 */
extern GLuint createCube(unsigned int *HPM_RESTRICT nVertices, unsigned int *HPM_RESTRICT nIndices);

/**
 * Print verbose information about the
 *	program.
 */
extern void print_dependency_versions(void);

/**
 * Read user option argument.
 * @param argc
 * @param argv
 */
extern void readargument(int argc, const char **argv);

/**
 *
 * @param scene
 * @return
 */
extern int createScene(Scene *scene);

/**
 *
 * @param scene
 * @return
 */
extern int releaseScene(Scene *scene);

/**
 *
 */
extern void sceneRenderer(Scene *scene);

#endif
