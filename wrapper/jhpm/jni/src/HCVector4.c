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
#include "org_jhpm_Vector4.h"
#include "org_jhpm_helper.h"
#include <hpm.h>

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector4_length(JNIEnv *env, jobject o) {

	/*	Get memory pointer of c object.	*/
	jfloatArray arr;
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Compute the length.	*/
	jfloat length = hpm_vec4_lengthfv((const hpmvec4f *)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return length;
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector4_squaredLength(JNIEnv *env, jobject o) {

	/*	Get memory pointer of c object.	*/
	jfloatArray arr;
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Compute the length.	*/
	jfloat length = hpm_vec4_lengthsqurefv((const hpmvec4f *)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return length;
}

JNIEXPORT void JNICALL Java_org_jhpm_Vector4_makeUnitVector(JNIEnv *env, jobject o) {

	/*	Get memory pointer of c object.	*/
	jfloatArray arr;
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Compute the normalized vector.	*/
	hpm_vec4_normalizefv((hpmvec4f *)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector4_minComponent(JNIEnv *env, jobject o) {

	/*	Get memory pointer of c object.	*/
	jfloatArray arr;
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Compute the length.	*/
	jfloat min = hpm_vec4_min_compfv((const hpmvec4f *)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return min;
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector4_maxComponent(JNIEnv *env, jobject o) {

	/*	Get memory pointer of c object.	*/
	jfloatArray arr;
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Compute the length.	*/
	jfloat min = hpm_vec4_max_compfv((const hpmvec4f *)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return min;
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector4_maxAbsComponent(JNIEnv *env, jobject o) {
	jfloat max = Java_org_jhpm_Vector4_maxComponent(env, o);
	return max * max;
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector4_minAbsComponent(JNIEnv *env, jobject o) {
	jfloat max = Java_org_jhpm_Vector4_minComponent(env, o);
	return max * max;
}

JNIEXPORT jint JNICALL Java_org_jhpm_Vector4_indexOfMinComponent(JNIEnv *env, jobject o) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jint JNICALL Java_org_jhpm_Vector4_indexOfMaxComponent(JNIEnv *env, jobject o) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jint JNICALL Java_org_jhpm_Vector4_indexOfMinAbsComponent(JNIEnv *env, jobject o) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jint JNICALL Java_org_jhpm_Vector4_indexOfMaxAbsComponent(JNIEnv *env, jobject o) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector4_normalize(JNIEnv *env, jobject o) {

	jfloatArray arr;
	jobject co = Java_org_jhpm_Vector4_clone(env, o);
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, co, &arr);

	/*  */
	hpm_vec4_normalizefv((hpmvec4f *)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return co;
}

JNIEXPORT jboolean JNICALL Java_org_jhpm_Vector4_equals(JNIEnv *env, jobject o1, jobject o2) {

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

JNIEXPORT jstring JNICALL Java_org_jhpm_Vector4_toString(JNIEnv *env, jobject o) {

	jfloatArray arr;
	jchar text[128];
	jsize slen;

	/*  */
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	*/
	slen = sprintf((char *)text, "{ %.1f, %.1f, %.1f, %.1f }", e[0], e[1], e[2], e[3]);

	/*	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return (*env)->NewString(env, text, slen);
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector4_clone(JNIEnv *env, jobject o1) {

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

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector4_unitVector3(JNIEnv *env, jclass c, jobject o) {

	jobject co = Java_org_jhpm_Vector4_clone(env, o);

	jobjectArray arr;
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, co, &arr);

	hpm_vec4_normalizefv((hpmvec4f *)e);

	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return co;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector4_minVec(JNIEnv *env, jclass c, jobject o1, jobject o2) {

	jobject o[3] = {o1, o2};
	jfloatArray fa[3];
	jfloat *p[3];

	o[2] = hpmjni_create_object_instance(env, c);
	hpmjni_get_float_array_pointer_reference_a_b_c(env, o, fa, p);

	hpm_vec4_minfv((const hpmvec4f *)p[0], (const hpmvec4f *)p[1], (hpmvec4f *)p[2]);

	hpmjni_release_float_array_pointer_reference_a_b_c(env, fa, p);
	return o[2];
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector4_maxVec(JNIEnv *env, jclass c, jobject o1, jobject o2) {

	jobject o[3] = {o1, o2};
	jfloatArray fa[3];
	jfloat *p[3];

	o[2] = hpmjni_create_object_instance(env, c);
	hpmjni_get_float_array_pointer_reference_a_b_c(env, o, fa, p);

	hpm_vec4_maxfv((const hpmvec4f *)p[0], (const hpmvec4f *)p[1], (hpmvec4f *)p[2]);

	hpmjni_release_float_array_pointer_reference_a_b_c(env, fa, p);
	return o[2];
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector4_dot(JNIEnv *env, jclass c, jobject o1, jobject o2) {
	jfloat innerproduct;

	jobject o[2] = {o1, o2};
	jfloatArray fa[2];
	jfloat *p[2];

	hpmjni_get_float_array_pointer_reference_a_b(env, o, fa, p);

	/*	Compute dot product.	*/
	innerproduct = hpm_vec4_dotfv((const hpmvec4f *)p[0], (const hpmvec4f *)p[1]);

	hpmjni_release_float_array_pointer_reference_a_b(env, fa, p);
	return innerproduct;
}
