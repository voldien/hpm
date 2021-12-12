/**
	High performance matrix library wrapper, utilizing SIMD extensions.
	Copyright (C) 2017  Valdemar Lindberg

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
#include "org_jhpm_Hpm.h"
#include "org_jhpm_helper.h"
#include <hpm.h>

JNIEXPORT jint JNICALL Java_org_jhpm_Hpm_init(JNIEnv *env, jclass c, jobject o) {

	unsigned int simd;
	jint status = 0;

	/*	Get enum value.	*/
	jclass enc = (*env)->GetObjectClass(env, o);
	jfieldID fid = (*env)->GetFieldID(env, enc, "simd", "J");
	simd = (*env)->GetIntField(env, o, fid);

	/*  Check if value is power of 2.   */
	if ((simd && ((simd - 1) & simd))) {
		hpmjni_throw_out_of_bound(env, "Invalid SIMD argument");
		return -1;
	}

	/*	Initialize.	*/
	if (!hpm_isinit())
		status = hpm_init(simd);

	/*	Return initialization status.	*/
	return status;
}
