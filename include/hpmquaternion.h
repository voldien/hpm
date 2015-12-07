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
#ifndef _HPM_QUATERNION_H_
#define _HPM_QUATERNION_H_ 1
#include"hpmvector.h"
#include"hpmmatrix.h"


HPM_ALIGN(16)
typedef hpmvecf hpmquatf[4];

HPM_ALIGN(32)
typedef hpmvecd hpmquatd[4];


#ifdef __cplusplus /*	C++ Environment	*/
extern "C"{
#endif

/*
 *
 */
extern void hpm_quat_multi_quatfv(const hpmquatf larg,const hpmquatf larg,const hpmquatf out);

/*
 *
 */
extern void hpm_quat_multi_quatdv(const hpmquatd larg,const hpmquatd larg,const hpmquatd out);



/*
	quaternion x rotation in radian
*/
extern float HPMAPIFASTENTRY hpm_quat_pitchfv(const hpmquatf lf_quad);
/*
	quaternion y rotation in radian
*/
extern float HPMAPIFASTENTRY hpm_quat_yawfv(const hpmquatf lf_quad);
/*
	quaternion z rotation in radian
*/
extern float HPMAPIFASTENTRY hpm_quat_rollfv(const hpmquatf lf_quad);



#ifdef __cplusplus /*	C++ Environment	*/
}
#endif


#endif
