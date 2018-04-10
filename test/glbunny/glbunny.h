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
#include<hpm.h>
#include<stdio.h>
#include<GL/glew.h>
/**
 *	Global constants.
 */
extern const char* gc_vertexpolygone;      /*	Vertex */
extern const char* gc_fragmentpolygone;    /*	Fragment.	*/

/**
 *	Global variable.
 */
extern uint32_t g_hpmflag;      /*	*/
extern FILE* g_outputfd;        /*	*/
extern int g_fullscreen;        /*	*/
extern int g_debug;				/*	*/

/**
 *
 */
typedef struct geometry_t{
	GLint vao;
	GLint vbo;
	GLint ibo;
	GLint numVertices;
	GLint numIndices;
	hpmvec4f minBound;
	hpmvec4f maxBound;
	hpmvec4f centerBound;
}Geometry;

/**
 *	Get version of hpmglbunny program
 *	version.
 *	@Return non-null terminated string.
 */
extern const char* get_glbunny_version(void);

/**
 *	Get GLSL version of current opengl context.
 *	@Return 3 digited version in 10^3.
 */
extern unsigned int getGLSLVersion(void);

/**
 *	log2 with mutuality exclusive bit flag.
 *
 *	@Return exponent of base 2 for a.
 */
extern int Log2MutExlusive32(unsigned int a);

/**
 *
 */
extern void enableGLDebug(void);

/**
 *	Create shader object from shader source
 *	string.
 *
 *	@Return shader program unique id.
 */
extern GLint createShader(const char* HPM_RESTRICT vsource,
        const char* HPM_RESTRICT fsource);

/**
 *	Create bunny.
 *
 *	@Return non-negative if succesfully.
 */
extern GLuint createBunny(unsigned int* HPM_RESTRICT numvertices,
        unsigned int* HPM_RESTRICT numindices);

/**
 *	Create grid object.
 *
 *	@Return
 */
extern GLuint createGrid(unsigned int* HPM_RESTRICT numvertices,
        unsigned int* HPM_RESTRICT* numindices);
/**
 *	@Return
 */
extern GLuint createCube(unsigned int* HPM_RESTRICT nVertices,
        unsigned int* HPM_RESTRICT nIndices);

/**
 *	Print verbose information about the
 *	program.
 */
extern void print_dependency_versions(void);

/**
 *	Read user option argument.
 */
extern void readargument(int argc, const char** argv);

#endif
