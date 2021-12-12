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
#ifndef _ORG_JHPM_HELPER_H_
#define _ORG_JHPM_HELPER_H_ 1
#include <assert.h>
#include <hpm.h>
#include <jni.h>

/**
 *  Forward function declaration.
 */
extern jfloatArray hpmjni_get_float_array_reference(JNIEnv *__restrict__ env, jobject __restrict__ objref);

extern jfloat *hpmjni_get_float_array_pointer_reference(JNIEnv *__restrict__ env, jobject __restrict__ objref,
														jfloatArray *__restrict__ array);

extern void hpmjni_get_float_array_pointer_reference_a_b(JNIEnv *__restrict__ env, jobject *__restrict__ objref,
														 jfloatArray *__restrict__ parray,
														 jfloat **__restrict__ pfloat);

extern void hpmjni_get_float_array_pointer_reference_a_b_c(JNIEnv *__restrict__ env, jobject *__restrict__ objref,
														   jfloatArray *__restrict__ parray,
														   jfloat **__restrict__ pfloat);

extern void hpmjni_release_float_array_pointer_reference(JNIEnv *__restrict__ env, const jfloatArray __restrict__ array,
														 jfloat *__restrict__ fp);

extern void hpmjni_release_float_array_pointer_reference_a_b(JNIEnv *__restrict__ env, jfloatArray *__restrict__ parray,
															 jfloat **__restrict__ pfloat);

extern void hpmjni_release_float_array_pointer_reference_a_b_c(JNIEnv *__restrict__ env,
															   jfloatArray *__restrict__ parray,
															   jfloat **__restrict__ pfloat);

extern jobject hpmjni_create_object_instance(JNIEnv *__restrict__ env, jclass __restrict__ c);

extern jobject hpmjni_create_clone(JNIEnv *__restrict__ env, jobject __restrict__ o);

/**
 *  Exceptions forward function declaration.
 */
extern void hpmjni_throw_out_of_bound(JNIEnv *__restrict__ env, const char *__restrict__ msg);
extern void hpmjni_throw_illegal_argument(JNIEnv *__restrict__ env, const char *__restrict__ msg);
extern void hpmjni_throw_null_reference(JNIEnv *__restrict__ env, const char *__restrict__ msg);
extern void hpmjni_throw_unsupported_operation(JNIEnv *__restrict__ env, const char *__restrict__ msg);
#endif
