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

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

/**
 * Compare float equality.
 *
 * @param a valid float.
 * @param b valid float.
 * @return non-zero if a and b is equal.
 */
HPM_EXPORT(hpmboolean, HPMAPIFASTENTRY, hpm_vec_eqfv, hpmvecf a, hpmvecf b);

/**
 * Compare float inequality.
 *
 * @param a valid float.
 * @param b valid float.
 * @return non-zero if a and b is not equal.
 */
HPM_EXPORT(hpmboolean, HPMAPIFASTENTRY, hpm_vec_neqfv, hpmvecf a, hpmvecf b);

/**
 * Determine if a and b is equal.
 *
 * @param res return a non 0 value for each element of the vector.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_com_eqfv, const hpmvec4f *HPM_RESTRICT a,
           const hpmvec4f *HPM_RESTRICT b, hpmvec4f *HPM_RESTRICT res);

/**
 * Determine if a and b is equal.
 *
 * @return non-zero if equal, zero otherwise.
 */
HPM_EXPORT(hpmboolean, HPMAPIENTRY, hpm_vec4_eqfv, const hpmvec4f *HPM_RESTRICT a,
           const hpmvec4f *HPM_RESTRICT b);

/**
 * Determine if a and b is not equal.
 *
 * @param res return a non 0 value for each element of the vector.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_com_neqfv, const hpmvec4f *HPM_RESTRICT a,
           const hpmvec4f *HPM_RESTRICT b, hpmvec4f *HPM_RESTRICT res);

/**
 * Determine if a and b is not equal.
 *
 * @return non-zero if not equal, zero otherwise.
 */
HPM_EXPORT(hpmboolean, HPMAPIENTRY, hpm_vec4_neqfv, const hpmvec4f *HPM_RESTRICT a,
           const hpmvec4f *HPM_RESTRICT b);

/**
 * Determine if a is greater than b.
 *
 * @param res return a non 0 value for each element of the vector.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_com_gfv, const hpmvec4f *HPM_RESTRICT a,
           const hpmvec4f *HPM_RESTRICT b, hpmvec4f *HPM_RESTRICT res);

/**
 * Determine if a is less than b.
 *
 * @param a left side argument.
 *
 * @param b right side argument.
 *
 * @param res
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_com_lfv, const hpmvec4f *HPM_RESTRICT a,
           const hpmvec4f *HPM_RESTRICT b, hpmvec4f *HPM_RESTRICT res);

/**
 * Compute if matrix a and b is equal to each other.
 * The compare is based on the values of each of the matrices.
 *
 * @return none zero if statement is true.
 */
HPM_EXPORT(hpmboolean, HPMAPIENTRY, hpm_mat4_eqfv, const hpmvec4x4f_t a,
           const hpmvec4x4f_t b);

/**
 * Compute if matrix a and b is not equal to each other.
 * The compare is based on the values of each of the matrices.
 *
 * @return none zero if statement is true.
 */
HPM_EXPORT(hpmboolean, HPMAPIENTRY, hpm_mat4_neqfv, const hpmvec4x4f_t a,
           const hpmvec4x4f_t b);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif
