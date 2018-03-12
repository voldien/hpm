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
#ifndef _HPM_PRINT_H_
#define _HPM_PRINT_H_ 1
#include"hpmdef.h"
#include"hpmmatrix.h"
#include"hpmquaternion.h"
#include"hpmvector.h"

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

/**
 *
 */
extern HPMDECLSPEC void hpm_vec4_print(const hpmvec4f* vec);

/**
 *
 */
extern HPMDECLSPEC void hpm_vec4_sprint(char* text, const hpmvec4f* vec);

/**
 *
 */
extern HPMDECLSPEC void hpm_vec3_print(const hpmvec3f* vec);

/**
 *
 */
extern HPMDECLSPEC void hpm_vec3_sprint(char* text, const hpmvec3f* vec);

/**
 *
 */
extern HPMDECLSPEC void hpm_quat_print(const hpmquatf* quat);

/**
 *
 */
extern HPMDECLSPEC void hpm_quat_sprint(char* text, const hpmquatf* vec);

/**
 *
 */
extern HPMDECLSPEC void hpm_mat4x4_print(const hpmvec4x4f_t mat);

/**
 *
 */
extern HPMDECLSPEC void hpm_mat4x4_sprint(char* text, const hpmvec4x4f_t mat);


#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif
