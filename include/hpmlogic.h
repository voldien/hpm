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
#ifndef _HPM_LOGIC_FUNC_H_
#define _HPM_LOGIC_FUNC_H_ 1
#include"hpmdef.h"
#include"hpmvector.h"
#include"hpmmatrix.h"

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
 *	Compute if matrix a and b is equal to each other.
 *	The compare is based on the values of each of the matrices.
 *
 *	@Return none zero if statemnt is true.
 */
HPM_EXPORT(hpmboolean, HPMAPIENTRY, hpm_mat4_eqfv, const hpmvec4x4f_t a,
		const hpmvec4x4f_t b);

/**
 *	Compute if matrix a and b is not equal to each other.
 *	The compare is based on the values of each of the matrices.
 *
 *	@Return none zero if statemnt is true.
 */
HPM_EXPORT(hpmboolean, HPMAPIENTRY, hpm_mat4_neqfv, const hpmvec4x4f_t a,
		const hpmvec4x4f_t b);

/**
 *	Determine if a and b is equal.
 *
 *	@Return return a non 0 value for each element of the vector.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec2_com_eqfv, const hpmvec2f* __restrict__ a,
		const hpmvec2f* __restrict__ b, hpmvec2f* __restrict__ res);
HPM_EXPORT(hpmboolean, HPMAPIENTRY, hpm_vec2_eqfv, const hpmvec2f* __restrict__ a,
		const hpmvec2f* __restrict__ b);

/**
 *	Determine if a and b is not equal.
 *
 *	@Return
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec2_com_neqfv,
		const hpmvec2f* __restrict__ a, const hpmvec2f* __restrict__ b,
		hpmvec2f* __restrict__ res);
HPM_EXPORT(hpmboolean, HPMAPIENTRY, hpm_vec2_neqfv, const hpmvec2f* __restrict__ a,
		const hpmvec2f* __restrict__ b);

/**
 *	Determine if a is greater than b.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec2_com_gfv, const hpmvec2f* __restrict__ a,
		const hpmvec2f* __restrict__ b, hpmvec2f* __restrict__ res);
/**
 *	Determine if a is less than b.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec2_com_lfv, const hpmvec2f* __restrict__ a,
		const hpmvec2f* __restrict__ b, hpmvec2f* __restrict__ res);


#endif
