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
#ifndef _HPM_UTIL_H_
#define _HPM_UTIL_H_ 1
#include"hpmmatrix.h"
#include"hpmquaternion.h"

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

/**
 * Create look at matrix.
 *
 * @param eye the look at target.
 *
 * @param position position in world space.
 *
 * @param up direction in respect to the viewer.
 *
 * @param mat look at matrix.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_util_lookatfv, const hpmvec4f* HPM_RESTRICT eye,
        const hpmvec4f* HPM_RESTRICT position, const hpmvec4f* HPM_RESTRICT up,
        hpmvec4x4f_t mat);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif
