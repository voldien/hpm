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
#include<stdio.h>
#include<GL/gl.h>

/**
 *	Global constants.
 */
extern const char* vertexpolygone;      /*	Vertex */
extern const char* fragmentpolygone;    /*	Fragment.	*/

/**
 *	Global variable.
 */
extern uint32_t g_hpmflag;      /*	*/
extern FILE* g_outputfd;        /*	*/
extern int g_fullscreen;        /*	*/

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
 *	Create shader.
 *	@Return
 */
extern GLint createShader(const char* __restrict__ vsource,
        const char* __restrict__ fsource);

/**
 *	Create bunny.
 *	@Return
 */
extern GLuint createBunny(unsigned int* __restrict__ numvertices,
        unsigned int* __restrict__ numindices);

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
