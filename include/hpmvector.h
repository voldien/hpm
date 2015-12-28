/**
    Copyright (C) 2015  Valdemar Lindberg

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
#ifndef _HPM_VECTOR_H_
#define _HPM_VECTOR_H_ 1
#include"hpmdef.h"


typedef float hpmvecf;

typedef double hpmvecd;


//HPM_VECTORALIGN(8)
typedef hpmvecf hpmvec2f[2];

//HPM_VECTORALIGN(16)
typedef hpmvecd hpmvec2d[2];



//HPM_VECTORALIGN(16)
typedef hpmvecf hpmvec3f[3];

//HPM_VECTORALIGN(32)
typedef hpmvecd hpmvec3d[3];




typedef hpmvecf hpmvec4f[4] HPM_VECTORALIGN(16);

//HPM_VECTORALIGN(32)
typedef hpmvecd hpmvec4d[4];

#ifdef __cplusplus /*	C++ Environment	*/
extern "C"{
#endif



extern void hpm_vec4_addition_float(hpmvec3f larg, hpmvecf rarg);


#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif
