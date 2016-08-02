/**
    Copyright (C) 2014  Valdemar Lindberg

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
#ifndef _HPM_H_
#define _HPM_H_ 1
#include"hpmdef.h"
#include"hpmmatrix.h"
#include"hpmvector.h"
#include"hpmquaternion.h"

/**
 *	hpm follows opengl structure for how row and coloum is defiend for the
 *	matrix.
 */

/**
 *
 */
#define HPM_NOSIMD		(0 << 0)	/*	No SIMD hardware feature.	*/
#define HPM_MMX			(1 << 0)	/*	MMX. (Yet not supported)	*/
#define HPM_SSE			(1 << 1)	/*	SSE.	*/
#define HPM_SSE2		(1 << 2)	/*	SSE2.	*/
#define HPM_SSE3		(1 << 3)	/*	SSE3.	*/
#define HPM_SSSE3		(1 << 4)	/*	SSSE3.	*/
#define HPM_SSE4_1		(1 << 5)	/*	SSE4.1.	*/
#define HPM_SSE4_2		(1 << 6)	/*	SSE4.2.	*/
#define HPM_AVX			(1 << 7)	/*	AVX Version 1 (Advanced Vector Extension).	*/
#define HPM_AVX2		(1 << 8)	/*	AVX Version 2 (Advanced Vector Extension).	*/
#define HPM_AVX512		(1 << 9)	/*	AVX512 (Advanced Vector Extension). (Yet not supported)	*/
#define HPM_NEON		(1 << 10)	/*	ARM	fpu(floating-point unit) feature.	*/


/**
 *	initialize hpm.
 *	@Return
 */
extern HPMDECLSPEC int HPMAPIENTRY hpm_init(unsigned int simd);

/**
 *	Release library.
 *	@Return
 */
extern HPMDECLSPEC int HPMAPIENTRY hpm_release(void);

/**
 *	Get function pointer address.
 *	\cfunctionName
 *	@Return func pointer
 */
extern HPMDECLSPEC void* HPMAPIENTRY hpm_get_address(const char* cfunctionName);

/**
 *	Get hpm version.
 *	@Return
 */
extern HPMDECLSPEC int HPMAPIENTRY hpm_version(void);

/**
 *	@Return
 */
extern HPMDECLSPEC int HPMAPIENTRY hpm_supportcpufeat(unsigned int simd_extension);


#endif
