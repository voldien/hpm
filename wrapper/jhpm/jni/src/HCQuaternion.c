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
#include "org_jhpm_Quaternion.h"
#include "org_jhpm_helper.h"
#include <hpm.h>

JNIEXPORT void JNICALL Java_org_jhpm_Quaternion_set(JNIEnv *env, jobject o, jfloat w, jfloat x, jfloat y, jfloat z) {

	jfloatArray arr;
	/*	Get memory pointer of c object.	*/
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	hpm_quat_setf((hpmquatf *)e, w, x, y, z);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Quaternion_magnitude(JNIEnv *env, jobject o) {
	jfloatArray arr;
	/*	Get memory pointer of c object.	*/
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	jfloat length = hpm_quat_lengthfv((const hpmquatf *)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return length;
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Quaternion_magnitudeSquared(JNIEnv *env, jobject o) {
	jfloatArray arr;
	/*	Get memory pointer of c object.	*/
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	jfloat length = hpm_quat_lengthsqurefv((const hpmquatf *)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return length;
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Quaternion_dot(JNIEnv *env, jobject o1, jobject q1, jobject q2) {
	jfloat innerproduct;

	jobject o[2] = {q1, q2};
	jfloatArray fa[2];
	jfloat *p[2];

	hpmjni_get_float_array_pointer_reference_a_b(env, o, fa, p);

	/*	Compute dot product.	*/
	innerproduct = hpm_quat_dotfv((const hpmvec4f *)p[0], (const hpmvec4f *)p[1]);

	hpmjni_release_float_array_pointer_reference_a_b(env, fa, p);
	return innerproduct;
}

JNIEXPORT void JNICALL Java_org_jhpm_Quaternion_makeUnitQuaternion(JNIEnv *env, jobject o) {
	jfloatArray arr;
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*  */
	hpm_vec4_normalizefv((hpmvec4f *)e);

	/*  */
	hpmjni_release_float_array_pointer_reference(env, arr, e);
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_normalize(JNIEnv *env, jobject o) {
	jobject objs;
	jfloatArray arry;

	/*	Create copy instance.	*/
	objs = Java_org_jhpm_Quaternion_clone(env, o);
	jfloat *p = hpmjni_get_float_array_pointer_reference(env, objs, &arry);

	/*	*/
	hpm_quat_normalizefv((hpmquatf *)p);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arry, p);
	return objs;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_conjugate(JNIEnv *env, jobject o) {
	jobject objs;
	jfloatArray arry;

	/*	Create copy instance.	*/
	objs = Java_org_jhpm_Quaternion_clone(env, o);
	jfloat *p = hpmjni_get_float_array_pointer_reference(env, objs, &arry);

	/*	*/
	hpm_quat_conjugatefv((hpmquatf *)p);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arry, p);
	return objs;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_inverse(JNIEnv *env, jobject o) {
	jobject objs;
	jfloatArray arry;

	/*	Create copy instance.	*/
	objs = Java_org_jhpm_Quaternion_clone(env, o);
	jfloat *p = hpmjni_get_float_array_pointer_reference(env, objs, &arry);

	/*	*/
	hpm_quat_inversefv((hpmquatf *)p);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arry, p);
	return objs;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_clone(JNIEnv *env, jobject o1) {}

JNIEXPORT jboolean JNICALL Java_org_jhpm_Quaternion_equals(JNIEnv *env, jobject o1, jobject o2) {

	jobject o[2] = {o1, o2};
	jfloatArray fa[2];
	jfloat *p[2];

	hpmjni_get_float_array_pointer_reference_a_b(env, o, fa, p);

	jboolean status = hpm_vec4_eqfv((const hpmvec4f *)p[0], (const hpmvec4f *)p[1]);

	hpmjni_release_float_array_pointer_reference_a_b(env, fa, p);
	return status;
}

JNIEXPORT jstring JNICALL Java_org_jhpm_Quaternion_toString(JNIEnv *env, jobject o) {
	jfloatArray arr;
	jchar text[128];
	jsize slen;

	/*  */
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);
	slen =
		sprintf((char *)text, "{ %.1f, %.1f, %.1f, %.1f }", e[HPM_QUAT_W], e[HPM_QUAT_X], e[HPM_QUAT_Y], e[HPM_QUAT_Z]);

	/*	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return (*env)->NewString(env, text, slen);
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Quaternion_getPitch(JNIEnv *env, jobject o) {
	jfloat pitch;

	jfloatArray arr;

	/*	Get memory pointer of c object.	*/
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Compute quaternion pitch angle in radius.	*/
	pitch = hpm_quat_pitchfv((const hpmquatf *)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return pitch;
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Quaternion_getYaw(JNIEnv *env, jobject o) {
	jfloat yaw;

	jfloatArray arr;

	/*	Get memory pointer of c object.	*/
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Compute quaternion yaw angle radius.	*/
	yaw = hpm_quat_yawfv((const hpmquatf *)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return yaw;
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Quaternion_getRoll(JNIEnv *env, jobject o) {
	jfloat roll;

	jfloatArray arr;

	/*	Get memory pointer of c object.	*/
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Compute quaternion roll angle in radiuscd co.	*/
	roll = hpm_quat_rollfv((const hpmquatf *)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return roll;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_lookRotation(JNIEnv *env, jclass c, jobject o1, jobject o2) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_lookAt(JNIEnv *env, jclass c, jobject o1, jobject o2) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_createQuaternionOfAxis__FFF(JNIEnv *env, jclass c, jfloat x,
																			   jfloat y, jfloat z) {

	jobject o;
	jfloatArray arr;
	/*	Get memory pointer of c object.	*/
	o = hpmjni_create_object_instance(env, c);
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	hpm_quat_axisf((hpmquatf *)e, x, y, z);

	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return o;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_createQuaternionOfAxis__Lorg_jhpm_Vector3_2(JNIEnv *env, jclass c,
																							   jobject o) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_createFromAxisAngle(JNIEnv *env, jclass c, jobject o1, jfloat f) {

	jobject o[2] = {o1};
	jfloatArray fa[2];
	jfloat *p[2];

	o[1] = hpmjni_create_object_instance(env, c);
	hpmjni_get_float_array_pointer_reference_a_b(env, o, fa, p);

	hpm_quat_axis_anglefv((hpmquatf *)p[1], (const hpmvec3f *)p[0], f);

	hpmjni_release_float_array_pointer_reference_a_b(env, fa, p);
	return o[1];
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_createQuaternionOfDirection(JNIEnv *env, jclass c, jobject o1) {
	hpmjni_throw_unsupported_operation(env, "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_lerp(JNIEnv *env, jclass c, jobject o1, jobject o2, jfloat t) {

	jobject o[3] = {o1, o2};
	jfloatArray arr[3];
	jfloat *p[3];

	/*	Get memory pointer of c object.	*/
	o[2] = hpmjni_create_object_instance(env, c);
	hpmjni_get_float_array_pointer_reference_a_b_c(env, o, arr, p);

	/*	Compute the lerp.	*/
	hpm_quat_lerpfv((const hpmquatf *)p[0], (const hpmquatf *)p[1], t, (hpmquatf *)p[2]);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference_a_b_c(env, arr, p);
	return o[2];
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_slerp(JNIEnv *env, jclass c, jobject o1, jobject o2, jfloat t) {
	jobject o[3] = {o1, o2};
	jfloatArray arr[3];
	jfloat *p[3];

	/*	Get memory pointer of c object.	*/
	o[2] = hpmjni_create_object_instance(env, c);
	hpmjni_get_float_array_pointer_reference_a_b_c(env, o, arr, p);

	/*	Compute the lerp.	*/
	hpm_quat_slerpfv((const hpmquatf *)p[0], (const hpmquatf *)p[1], t, (hpmquatf *)p[2]);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference_a_b_c(env, arr, p);
	return o[2];
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_identity(JNIEnv *env, jclass c) {
	jobject o;
	jfloatArray arr;

	/*	Get memory pointer of c object.	*/
	o = hpmjni_create_object_instance(env, c);

	/*	Get memory pointer of c object.	*/
	jfloat *e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Create identitiy.	*/
	hpm_quat_identityfv((hpmquatf *)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return o;
}
