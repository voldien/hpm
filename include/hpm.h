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



/*
 *	function pointer type define
 */
typedef void (HPMAPIENTRY *p_hpm_vec4_addition_scalef)(hpmvec4f larg, hpmvecf rarg);




/**
 *
 */
#define HPM_MMX			0x1			/*	*/
#define HPM_SSE			0x2			/*	*/
#define HPM_SSE2		0x4			/*	*/
#define HPM_SSE3		0x8			/*	*/
#define HPM_SSSE3		0x10		/*	*/
#define HPM_SSE4_1		0x20		/*	*/
#define HPM_SSE4_2		0x40		/*	*/
#define HPM_AVX			0x80		/*	*/
#define HPM_AVX2		0x100		/*	*/
#define HPM_AVX512		0x200		/*	*/


/**
 *
 *	@Return
 */
extern HPMDECLSPEC int HPMAPIENTRY hpm_init(unsigned int simd);

/**
 *	\cfunctionName
 *	@Return func pointer
 */
extern HPMDECLSPEC void* HPMAPIENTRY hpm_get_address(const char* cfunctionName);

/**
 *	@Return
 */
extern HPMDECLSPEC int HPMAPIENTRY hpm_version(void);


#endif
