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
 * Compute max value of a and b.
 * max = a > b ? a : b
 *
 * @Return max value for each element of the vector data type.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_maxfv, const hpmvec4f* HPM_RESTRICT a,
		const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT c);
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec8_maxfv, const hpmvec8f* HPM_RESTRICT a,
		const hpmvec8f* HPM_RESTRICT b, hpmvec8f* HPM_RESTRICT c);

/**
 * Compute min value of a and b.
 * min = a < b ? a : b
 *
 * @return min value for each element of the vector data type.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_minfv, const hpmvec4f* HPM_RESTRICT a,
		const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT c);
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec8_minfv, const hpmvec8f* HPM_RESTRICT a,
		const hpmvec8f* HPM_RESTRICT b, hpmvec8f* HPM_RESTRICT c);

/**
 * Computer square root for each element.
 *
 * @param arg reference object.
 *
 * @param out square rooted vector.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_sqrtfv, const hpmvec4f* HPM_RESTRICT arg,
        hpmvec4f* HPM_RESTRICT out);
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec8_sqrtfv, const hpmvec8f* HPM_RESTRICT arg,
        hpmvec8f* HPM_RESTRICT out);

/**
 * Computer approximate square root for each element.
 *
 * @param arg reference object.
 *
 * @param out square rooted vector.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_fast_sqrtfv, const hpmvec4f* HPM_RESTRICT arg,
        hpmvec4f* HPM_RESTRICT out);
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec8_fast_sqrtfv, const hpmvec8f* HPM_RESTRICT arg,
        hpmvec8f* HPM_RESTRICT out);

/**
 * Create random vector, where each component
 * is within the following range [0,1].
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_randomfv, hpmvec4f* out);
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec8_randomfv, hpmvec8f* out);


#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif
