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
#include "org_jhpm_Vector3.h"
#include "org_jhpm_helper.h"
#include <hpm.h>

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector3_negate(JNIEnv *env, jobject o) {

	jfloatArray arr;
	jfloat *e;

	/*	Create clone object and fetch memory pointer.	*/
	jobject c = hpmjni_create_clone(env, o);
	e = hpmjni_get_float_array_pointer_reference(env, c, &arr);

	/*	Compute the length.	*/
	hpm_vec4_negatefv((hpmvec4f *)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return c;
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector3_length(JNIEnv *env, jobject o) {

	jfloatArray arr;
	jfloat *e;

	/*	Create clone object and fetch memory pointer.	*/
	e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Compute the length.	*/
	jfloat length = hpm_vec3_lengthfv((const hpmvec3f *)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return length;
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector3_squaredLength(JNIEnv *env, jobject o) {

	jfloatArray arr;
	jfloat *e;

	/*	Create clone object and fetch memory pointer.	*/
	e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Compute the length.	*/
	jfloat length = hpm_vec3_lengthsquarefv((const hpmvec3f *)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return length;
}

JNIEXPORT void JNICALL Java_org_jhpm_Vector3_makeUnitVector(JNIEnv *env, jobject o) {

	jfloatArray arr;
	jfloat *e;

	/*	Create clone object and fetch memory pointer.	*/
	e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Compute the length.	*/
	hpm_vec3_normalizefv((hpmvec3f *)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector3_minComponent(JNIEnv *env, jobject o) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector3_maxComponent(JNIEnv *env, jobject o) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector3_maxAbsComponent(JNIEnv *env, jobject o) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector3_minAbsComponent(JNIEnv *env, jobject o) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jint JNICALL Java_org_jhpm_Vector3_indexOfMinComponent(JNIEnv *env, jobject o) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jint JNICALL Java_org_jhpm_Vector3_indexOfMaxComponent(JNIEnv *env, jobject o) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jint JNICALL Java_org_jhpm_Vector3_indexOfMinAbsComponent(JNIEnv *env, jobject o) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jint JNICALL Java_org_jhpm_Vector3_indexOfMaxAbsComponent(JNIEnv *env, jobject o) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector3_normalize(JNIEnv *env, jobject o) {
	jfloatArray arr;
	jobject co = Java_org_jhpm_Vector3_clone(env, o);
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, co, &arr);

	/*  */
	hpm_vec4_normalizefv((hpmvec4f *)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return co;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector3_lerp(JNIEnv *env, jclass c, jobject o1, jobject o2, jfloat f) {

	jobject objs[3] = {o1, o2};
	jfloatArray arry[3];
	jfloat *p[3];

	/*	Create default instance of the object.	*/
	objs[2] = hpmjni_create_object_instance(env, c);
	hpmjni_get_float_array_pointer_reference_a_b_c(env, objs, arry, p);

	hpm_vec4_lerpfv((const hpmvec4f *)p[0], (const hpmvec4f *)p[1], f, (hpmvec4f *)p[2]);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference_a_b_c(env, arry, p);
	return objs[2];
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector3_slerp(JNIEnv *env, jclass c, jobject o1, jobject o2, jfloat f) {

	jobject objs[3] = {o1, o2};
	jfloatArray arry[3];
	jfloat *p[3];

	/*	Create default instance of the object.	*/
	objs[2] = hpmjni_create_object_instance(env, c);
	hpmjni_get_float_array_pointer_reference_a_b_c(env, objs, arry, p);

	hpm_vec4_slerpfv((const hpmvec4f *)p[0], (const hpmvec4f *)p[1], f, (hpmvec4f *)p[2]);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference_a_b_c(env, arry, p);
	return objs[2];
}

JNIEXPORT jboolean JNICALL Java_org_jhpm_Vector3_equals(JNIEnv *env, jobject o1, jobject o2) {

	jfloatArray farr[2];
	jobject objarr[2] = {o1, o2};
	jfloat *eoarr[2];
	jboolean eq;

	/*	Fetch a and b float pointer objects.	*/
	hpmjni_get_float_array_pointer_reference_a_b(env, objarr, farr, eoarr);

	/*	Check equality.	*/
	eq = hpm_vec4_eqfv((const hpmvec4f *)eoarr[0], (const hpmvec4f *)eoarr[1]);

	/*	Release pointer and float array object.	*/
	hpmjni_release_float_array_pointer_reference_a_b(env, farr, eoarr);
	return eq;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector3_clone(JNIEnv *env, jobject o1) {

	jobject o[2] = {o1};
	jfloatArray fa[2];
	jfloat *p[2];

	/*	Create clone object.	*/
	/*	Get memory pointer of c object.	*/
	o[1] = hpmjni_create_clone(env, o1);
	hpmjni_get_float_array_pointer_reference_a_b(env, o, fa, p);

	hpm_vec4_copyfv((hpmvec4f *)p[1], (const hpmvec4f *)p[0]);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference_a_b(env, fa, p);
	return o[1];
}

JNIEXPORT jstring JNICALL Java_org_jhpm_Vector3_toString(JNIEnv *env, jobject o) {
	jfloatArray arr;
	jstring string;

	int len;
	jchar tostring[64];

	/*	Get memory pointer of c object.	*/
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Comput the string.	*/
	len = sprintf((char *)tostring, "{ %.1f, %.1f, %.1f }", e[0], e[1], e[2]);
	string = (*env)->NewString(env, tostring, len);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return string;
}
