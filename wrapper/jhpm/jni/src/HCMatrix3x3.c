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
#include "org_jhpm_Matrix3x3.h"
#include "org_jhpm_helper.h"
#include <hpm.h>

JNIEXPORT jfloat JNICALL Java_org_jhpm_Matrix3x3_determinant(JNIEnv *env, jobject o) {

	jfloatArray arr;
	/*	Get memory pointer of c object.	*/
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Compute the determine of the matrix.	*/
	jfloat det = hpm_mat4x4_determinantfv((const hpmvec4f *)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return det;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix3x3_inverse(JNIEnv *env, jobject o) {

	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jboolean JNICALL Java_org_jhpm_Matrix3x3_isIdentity(JNIEnv *env, jobject o) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT void JNICALL Java_org_jhpm_Matrix3x3_identity(JNIEnv *env, jobject o) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix3x3_transpose(JNIEnv *env, jobject o) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jboolean JNICALL Java_org_jhpm_Matrix3x3_equals(JNIEnv *env, jobject o1, jobject o2) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix3x3_clone(JNIEnv *env, jobject o) {

	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jstring JNICALL Java_org_jhpm_Matrix3x3_toString(JNIEnv *env, jobject o) {
	jfloatArray arr;
	jchar text[128];
	jsize slen;

	/*  Get memory.	*/
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);
	hpmvec4f *mat = (hpmvec4f *)e;

	/*	Create string representation.	*/
	slen = sprintf((char *)text,
				   "{ %.1f, %.1f, %.1f }\n"
				   "{ %.1f, %.1f, %.1f }\n"
				   "{ %.1f, %.1f, %.1f }\n",
				   mat[0][0], mat[1][0], mat[2][0], mat[0][1], mat[1][1], mat[2][1], mat[0][2], mat[1][2], mat[2][2]);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return (*env)->NewString(env, text, slen);
}
