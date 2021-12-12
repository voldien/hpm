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
#include "org_jhpm_Vector2.h"
#include <hpm.h>

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector2_negate(JNIEnv *env, jobject o) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector2_get(JNIEnv *env, jobject o, jint i) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector2_length(JNIEnv *env, jobject o) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector2_squaredLength(JNIEnv *env, jobject o) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT void JNICALL Java_org_jhpm_Vector2_makeUnitVector(JNIEnv *env, jobject o) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT void JNICALL Java_org_jhpm_Vector2_setX(JNIEnv *env, jobject o, jfloat f) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT void JNICALL Java_org_jhpm_Vector2_setY(JNIEnv *env, jobject o, jfloat f) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector2_x(JNIEnv *env, jobject o) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector2_y(JNIEnv *env, jobject o) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector2_minComponent(JNIEnv *env, jobject o) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector2_maxComponent(JNIEnv *env, jobject o) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector2_maxAbsComponent(JNIEnv *env, jobject o) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector2_minAbsComponent(JNIEnv *env, jobject o) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jint JNICALL Java_org_jhpm_Vector2_indexOfMinComponent(JNIEnv *env, jobject o) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jint JNICALL Java_org_jhpm_Vector2_indexOfMaxComponent(JNIEnv *env, jobject o) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jint JNICALL Java_org_jhpm_Vector2_indexOfMinAbsComponent(JNIEnv *env, jobject o) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jint JNICALL Java_org_jhpm_Vector2_indexOfMaxAbsComponent(JNIEnv *env, jobject o) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector2_normalize(JNIEnv *env, jobject o) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jboolean JNICALL Java_org_jhpm_Vector2_equals(JNIEnv *env, jobject o1, jobject o2) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector2_add(JNIEnv *env, jobject o1, jobject o2) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector2_sub(JNIEnv *env, jobject o1, jobject o2) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector2_div__Lorg_jhpm_Vector2_2(JNIEnv *env, jobject o1, jobject o2) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector2_div__F(JNIEnv *env, jobject o, jfloat f) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector2_mul__Lorg_jhpm_Vector2_2(JNIEnv *env, jobject o1, jobject o2) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector2_mul__F(JNIEnv *env, jobject o, jfloat f) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector2_clone(JNIEnv *env, jobject o) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector2_unitVector3(JNIEnv *env, jclass c, jobject o) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector2_minVec(JNIEnv *env, jclass c, jobject o1, jobject o2) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector2_maxVec(JNIEnv *env, jclass c, jobject o1, jobject o2) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector2_reflection(JNIEnv *env, jclass c, jobject o1, jobject o2) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Vector2_dot(JNIEnv *env, jclass c, jobject o1, jobject o2) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Vector2_zero(JNIEnv *env, jclass c) {
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}
