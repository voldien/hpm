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
#ifndef _HPM_MATH_FUNC_H_
#define _HPM_MATH_FUNC_H_ 1
#include"hpmdef.h"
#include"hpmvector.h"
#include"hpmmatrix.h"


#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif


/**
 *	Compute max value of a and b.
 *	max = a > b ? a : b
 *
 *	@Return max value for each element of the vector data type.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_maxfv, const hpmvec4f* __restrict__ a,
		const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ c);
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec8_maxfv, const hpmvec8f* __restrict__ a,
		const hpmvec8f* __restrict__ b, hpmvec8f* __restrict__ c);


/**
 *	Compute min value of a and b.
 *	min = a < b ? a : b
 *
 *	@Return min value for each element of the vector data type.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_minfv, const hpmvec4f* __restrict__ a,
		const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ c);
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec8_minfv, const hpmvec8f* __restrict__ a,
		const hpmvec8f* __restrict__ b, hpmvec8f* __restrict__ c);


/**
 *	Determine if a and b is equal.
 *
 *	@Return return a non 0 value for each element of the vector.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_com_eqfv, const hpmvec4f* __restrict__ a,
		const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res);
HPM_EXPORT(hpmboolean, HPMAPIENTRY, hpm_vec4_eqfv, const hpmvec4f* __restrict__ a,
		const hpmvec4f* __restrict__ b);

/**
 *	Determine if a and b is not equal.
 *
 *	@Return
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_com_neqfv,
		const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b,
		hpmvec4f* __restrict__ res);
HPM_EXPORT(hpmboolean, HPMAPIENTRY, hpm_vec4_neqfv, const hpmvec4f* __restrict__ a,
		const hpmvec4f* __restrict__ b);

/**
 *	Determine if a is greater than b.
 *
 *	@Return
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_com_gfv, const hpmvec4f* __restrict__ a,
		const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res);
/**
 *	Determine if a is less than b.
 *
 *	@Return
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_com_lfv, const hpmvec4f* __restrict__ a,
		const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res);

/**
 *
 *	@Return
 */
HPM_EXPORT(hpmboolean, HPMAPIENTRY, hpm_mat4_eqfv, const hpmvec4x4f_t a,
		const hpmvec4x4f_t b);

/**
 *
 *	@Return
 */
HPM_EXPORT(hpmboolean, HPMAPIENTRY, hpm_mat4_neqfv, const hpmvec4x4f_t a,
		const hpmvec4x4f_t b);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif
