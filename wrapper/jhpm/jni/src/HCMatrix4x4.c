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
#include "org_jhpm_Matrix4x4.h"
#include "org_jhpm_helper.h"
#include <assert.h>
#include <hpm.h>
#include <hpmmath.h>

JNIEXPORT jboolean JNICALL Java_org_jhpm_Matrix4x4_isIdentity(JNIEnv *env, jobject o) {
	const hpmvec4x4f_t id;

	/*	Get memory pointer of c object.	*/
	jfloatArray arr;
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Create identity for comparing.	*/
	hpm_mat4x4_identityfv((hpmvec4f *)id);

	/*	Performance compare.	*/
	jboolean status = hpm_mat4_eqfv((const hpmvec4f *)e, (const hpmvec4f *)id);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return status;
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Matrix4x4_determinant(JNIEnv *env, jobject o) {

	/*	Get memory pointer of c object.	*/
	jfloatArray arr;
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Compute the determine of the matrix.	*/
	jfloat det = hpm_mat4x4_determinantfv((const hpmvec4f *)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return det;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_inverse(JNIEnv *env, jobject o) {

	jobject objs[2] = {o};
	jfloatArray arr[2];
	jfloat *p[2];

	/*	Create clone object.	*/
	/*	Get memory pointer of c object.	*/
	objs[1] = hpmjni_create_clone(env, o);
	hpmjni_get_float_array_pointer_reference_a_b(env, objs, arr, p);

	hpm_mat4x4_inversefv((const hpmvec4f *)p[0], (hpmvec4f *)p[1]);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference_a_b(env, arr, p);
	return objs[1];
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_transpose(JNIEnv *env, jobject o) {

	/*	Create clone object.	*/
	jfloatArray arr;
	jobject c = hpmjni_create_clone(env, o);
	/*	Get memory pointer of c object.	*/
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	hpm_mat4x4_transposefv((hpmvec4f *)e);

	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return c;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_get__I(JNIEnv *env, jobject o, jint i) {

	jobject co = hpmjni_create_object_instance(env, NULL);

	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Matrix4x4_get__II(JNIEnv *env, jobject o, jint i, jint j) {

	/*	Get memory pointer of c object.	*/
	jfloatArray arr;
	jfloat *f = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	*/
	jfloat val = f[i * 4 + j];

	hpmjni_release_float_array_pointer_reference(env, arr, f);
	return val;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_add(JNIEnv *env, jobject o1, jobject o2) {

	jobject objs[3] = {o1, o2};
	jfloatArray arry[3];
	jfloat *eo[3];

	/*	Create copy instance.	*/
	objs[2] = hpmjni_create_clone(env, o1);
	hpmjni_get_float_array_pointer_reference_a_b_c(env, objs, arry, eo);

	/*	*/
	hpm_mat4x4_additition_mat4x4fv((const hpmvec4f *)eo[0], (const hpmvec4f *)eo[1], (hpmvec4f *)eo[2]);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference_a_b_c(env, arry, eo);
	return objs[2];
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_sub(JNIEnv *env, jobject o1, jobject o2) {
	jobject objs[3] = {o1, o2};
	jfloatArray arry[3];
	jfloat *eo[3];

	/*	Create copy instance.	*/
	objs[2] = Java_org_jhpm_Matrix4x4_clone(env, o1);
	hpmjni_get_float_array_pointer_reference_a_b_c(env, objs, arry, eo);

	/*	*/
	hpm_mat4x4_subraction_mat4x4fv((hpmvec4f *)eo[0], (hpmvec4f *)eo[1], (hpmvec4f *)eo[2]);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference_a_b_c(env, arry, eo);
	return objs[2];
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_mul__Lorg_jhpm_Matrix4x4_2(JNIEnv *env, jobject o1, jobject o2) {
	jobject objs[3] = {o1, o2};
	jfloatArray arry[3];
	jfloat *eo[3];

	/*	Create copy instance.	*/
	objs[2] = Java_org_jhpm_Matrix4x4_clone(env, o1);
	hpmjni_get_float_array_pointer_reference_a_b_c(env, objs, arry, eo);

	/*	*/
	hpm_mat4x4_multiply_mat4x4fv((hpmvec4f *)eo[0], (hpmvec4f *)eo[1], (hpmvec4f *)eo[2]);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference_a_b_c(env, arry, eo);
	return objs[2];
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_mul__F(JNIEnv *env, jobject o1, jfloat f) {
	jobject objs[2] = {o1};
	jfloatArray arry[2];
	jfloat *eo[2];

	/*	Create copy instance.	*/
	objs[1] = Java_org_jhpm_Matrix4x4_clone(env, o1);
	hpmjni_get_float_array_pointer_reference_a_b(env, objs, arry, eo);

	/*	*/
	hpm_mat4x4_multiply_scalarf((hpmvec4f *)eo[0], f, (hpmvec4f *)eo[1]);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference_a_b_c(env, arry, eo);
	return objs[1];
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_mul__Lorg_jhpm_Vector4_2(JNIEnv *env, jobject o1, jobject o2) {

	jobject objs[3] = {o1, o2};
	jfloatArray arry[3];
	jfloat *eo[3];

	/*	Create copy instance.	*/
	objs[2] = Java_org_jhpm_Matrix4x4_clone(env, o1);
	hpmjni_get_float_array_pointer_reference_a_b_c(env, objs, arry, eo);

	/*	*/
	hpm_mat4x4_multiply_mat1x4fv((hpmvec4f *)eo[0], (hpmvec4f *)eo[1], (hpmvec4f *)eo[2]);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference_a_b_c(env, arry, eo);
	return objs[2];
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_clone(JNIEnv *env, jobject o1) {

	jobject o[2] = {o1};
	jfloatArray fa[2];
	jfloat *p[2];

	/*	Create clone object.	*/
	/*	Get memory pointer of c object.	*/
	o[1] = hpmjni_create_clone(env, o1);
	hpmjni_get_float_array_pointer_reference_a_b(env, o, fa, p);

	hpm_mat4x4_copyfv((hpmvec4f *)p[1], (const hpmvec4f *)p[0]);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference_a_b(env, fa, p);
	return o[1];
}

JNIEXPORT jboolean JNICALL Java_org_jhpm_Matrix4x4_equals(JNIEnv *env, jobject o1, jobject o2) {

	jobject o[2] = {o1, o2};
	jfloatArray fa[2];
	jfloat *p[2];

	hpmjni_get_float_array_pointer_reference_a_b(env, o, fa, p);

	hpmboolean status = hpm_mat4_eqfv((hpmvec4f *)p[0], (hpmvec4f *)p[1]);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference_a_b(env, fa, p);
	return status;
}

JNIEXPORT jstring JNICALL Java_org_jhpm_Matrix4x4_toString(JNIEnv *env, jobject o) {
	jfloatArray arr;
	jchar text[256];
	jsize slen;

	/*  Get memory.	*/
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);
	hpmvec4f *m = (hpmvec4f *)e;

	/*	Create string representation.	*/
	slen = sprintf((char *)text,
				   "{ %.1f, %.1f, %.1f, %.1f }\n"
				   "{ %.1f, %.1f, %.1f, %.1f }\n"
				   "{ %.1f, %.1f, %.1f, %.1f }\n"
				   "{ %.1f, %.1f, %.1f, %.1f }\n",
				   m[0][0], m[1][0], m[2][0], m[3][0], m[0][1], m[1][1], m[2][1], m[3][1], m[0][2], m[1][2], m[2][2],
				   m[3][2], m[0][3], m[1][3], m[2][3], m[3][3]);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return (*env)->NewString(env, text, slen);
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_translate__FFF(JNIEnv *env, jclass c, jfloat x, jfloat y, jfloat z) {

	/*	Create default instance of the object.	*/
	jobject o = hpmjni_create_object_instance(env, c);

	/*	Get memory pointer of c object.	*/
	jfloatArray arr;
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	hpm_mat4x4_translationf((hpmvec4f *)e, x, y, z);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return o;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_translate__Lhpmjni_Vector3_2(JNIEnv *env, jclass c, jobject o1) {

	jobject o[2] = {o1};
	jfloatArray fa[2];
	jfloat *p[2];

	/*	Create default instance of the object.	*/
	o[1] = hpmjni_create_object_instance(env, c);
	hpmjni_get_float_array_pointer_reference_a_b(env, o, fa, p);

	hpm_mat4x4_translationfv((hpmvec4f *)p[1], (const hpmvec3f *)p[0]);

	hpmjni_release_float_array_pointer_reference_a_b(env, fa, p);
	return o[1];
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_rotate__FLhpmjni_Vector3_2(JNIEnv *env, jclass c, jfloat r,
																			 jobject o1) {

	jobject o[2] = {o1};
	jfloatArray fa[2];
	jfloat *p[2];

	/*	Create default instance of the object.	*/
	o[1] = hpmjni_create_object_instance(env, c);
	hpmjni_get_float_array_pointer_reference_a_b(env, o, fa, p);

	hpm_mat4x4_rotationfv((hpmvec4f *)p[1], r, (const hpmvec3f *)p[0]);

	hpmjni_release_float_array_pointer_reference_a_b(env, fa, p);
	return o[1];
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_rotate__Lhpmjni_Quaternion_2(JNIEnv *env, jclass c, jobject q) {

	jobject o[2] = {q};
	jfloatArray fa[2];
	jfloat *p[2];

	/*	Create default instance of the object.	*/
	o[1] = hpmjni_create_object_instance(env, c);
	hpmjni_get_float_array_pointer_reference_a_b(env, o, fa, p);

	hpm_mat4x4_rotationQfv((hpmvec4f *)p[1], (const hpmvec3f *)p[0]);

	hpmjni_release_float_array_pointer_reference_a_b(env, fa, p);
	return o[1];
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_scale__FFF(JNIEnv *env, jclass c, jfloat x, jfloat y, jfloat z) {

	/*	*/
	jfloatArray arr;
	/*	Create default instance of the object.	*/
	jobject o = hpmjni_create_object_instance(env, c);
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	hpm_mat4x4_scalef((hpmvec4f *)e, x, y, z);

	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return o;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_scale__Lhpmjni_Vector3_2(JNIEnv *env, jclass c, jobject o1) {

	jobject o[2] = {o1};
	jfloatArray fa[2];
	jfloat *p[2];

	/*	Create default instance of the object.	*/
	o[1] = hpmjni_create_object_instance(env, c);
	hpmjni_get_float_array_pointer_reference_a_b(env, o, fa, p);

	hpm_mat4x4_scalefv((hpmvec4f *)p[1], (const hpmvec3f *)p[0]);

	hpmjni_release_float_array_pointer_reference_a_b(env, fa, p);
	return o[1];
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_perspective(JNIEnv *env, jclass c, jfloat angle, jfloat ratio,
															  jfloat near, jfloat far) {

	/*	Create default instance of the object.	*/
	/*	*/
	jfloatArray arr;
	jobject o = hpmjni_create_object_instance(env, c);
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	hpm_mat4x4_projfv((hpmvec4f *)e, angle, ratio, near, far);

	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return o;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_lookAt(JNIEnv *env, jclass c, jobject o1, jobject o2, jobject o3) {

	jobject objs[3] = {o1, o2};
	jfloatArray arry[3];
	jfloat *eo[3];

	/*	Create default instance of the object.	*/
	objs[2] = hpmjni_create_object_instance(env, c);
	hpmjni_get_float_array_pointer_reference_a_b_c(env, objs, arry, eo);

	// hpm_util_lookatfv( )

	hpmjni_release_float_array_pointer_reference_a_b_c(env, arry, eo);
	return objs[2];
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_orth(JNIEnv *env, jclass c, jfloat l, jfloat r, jfloat t, jfloat b,
													   jfloat front, jfloat back) {

	/*	*/
	jfloatArray arr;
	jobject o = hpmjni_create_object_instance(env, c);
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	hpm_mat4x4_orthfv((hpmvec4f *)e, l, r, t, b, front, back);

	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return o;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_biasMatrix(JNIEnv *env, jclass c) {

	jfloatArray arr;
	jobject o = hpmjni_create_object_instance(env, c);
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	const hpmvec4f row0 = {0};
	const hpmvec4f row1 = {0};
	const hpmvec4f row2 = {0};
	const hpmvec4f row3 = {0};

	const hpmvec4x4f_t bias = {
		{0.5f, 0.0f, 0.0f, 0.0f},
		{0.0f, 0.5f, 0.0f, 0.0f},
		{0.0f, 0.0f, 0.5f, 0.0f},
		{0.5f, 0.5f, 0.5f, 1.0f},
	};

	hpm_mat4x4_copyfv((hpmvec4x4fp_t *)e, bias);

	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return o;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_identity(JNIEnv *env, jclass c) {

	/*	*/
	jfloatArray arr;
	jobject o = hpmjni_create_object_instance(env, c);
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*  */
	hpm_mat4x4_identityfv((hpmvec4f *)e);

	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return o;
}
