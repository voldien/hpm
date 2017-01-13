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
#ifndef _HPM_TYPES_H_
#define _HPM_TYPES_H_ 1
#include"hpmdef.h"


/**
 *	Data types.
 */
typedef float hpmvecf;			/*	*/
typedef double hpmvecd;			/*	*/
typedef int hpmveci;			/*	*/
typedef long long hpmvec1di;	/*	*/
typedef char hpmvecqi;			/*	*/



/**
 *	Single component vector data type.
 */
typedef float hpmvecfv HPM_VECTORALIGN(4);		/**/
typedef double hpmvecdv HPM_VECTORALIGN(8);		/**/
typedef int hpmveciv HPM_VECTORALIGN(4);		/**/
typedef char hpmvecqiv HPM_VECTORALIGN(4);		/**/

/**
 *	Two component vector data type.
 */
typedef hpmveci hpmvec2i HPM_VECTORALIGN(8);	/**/
typedef hpmvecf hpmvec2f HPM_VECTORALIGN(8);	/**/
typedef hpmvecd hpmvec2d HPM_VECTORALIGN(16);	/**/

/**
 *
 */
typedef hpmveci hpmvec3i HPM_VECTORALIGN(16);	/*	*/
typedef hpmvecf hpmvec3f HPM_VECTORALIGN(16);	/*	*/
typedef hpmvecd hpmvec3d HPM_VECTORALIGN(32);	/*	*/


/**
 *	SEE 128 bits data types.
 */
typedef hpmveci hpmvec4i HPM_VECTORALIGN(16);	/*	*/
typedef hpmvecf hpmvec4f HPM_VECTORALIGN(16);	/*	*/
typedef struct hpm_vec4uf_t{
	union{
		hpmvec4f v;
		struct{hpmvecf x, y, z, w;};
	};
};
/**
 * 	Internal SSE 128 bit  data types
 *	for implementing the intrinsics.
 */
typedef hpmveci hpmv4si HPM_VECTORALIGNI(16);
typedef hpmvecf hpmv4sf HPM_VECTORALIGNI(16);



/**
 * 	AVX	256 bits data types.
 */
typedef hpmveci hpmvec8i HPM_VECTORALIGN(32);
typedef hpmvecf hpmvec8f HPM_VECTORALIGN(32);
typedef hpmvecd hpmvec4d HPM_VECTORALIGN(32);

/**
 *	Union data types
 */
HPM_ALIGN(16)
typedef struct hpmvec8fu_t{
	union{
		hpmvec4f d2[2];
		hpmvec8f d;
	};
}hpmvec8fu;
HPM_ALIGN(16)
typedef struct hpmvec4du_t{
	union{
		hpmvec2d d2[2];
		hpmvec4d d;
	};
}hpmvec4du;



/**
 *	AVX 512 bits data types.
 */
typedef hpmveci hpmvec16i HPM_VECTORALIGN(64);
typedef hpmvecf hpmvec16f HPM_VECTORALIGN(64);
typedef hpmvecd hpmvec8d HPM_VECTORALIGN(64);
HPM_ALIGN(16)
typedef struct hpmvec8du_t{
	union{
		hpmvec4d d2[2];
		hpmvec8d d;
	};
}hpmvec8du;








#endif
