#include "org_jhpm_helper.h"
/**
 *	Get object float array.
 *	@Return get float array data type.
 */
jfloatArray hpmjni_get_float_array_reference(JNIEnv *__restrict__ env, jobject __restrict__ objref) {

	/*	Check if object reference is valid. */
	assert(objref);

	/*	Get class type from object.	*/
	jclass cs = (*env)->GetObjectClass(env, objref);
	jfieldID field = (*env)->GetFieldID(env, cs, "e", "[F");

	/*	Get float array reference object.	*/
	jfloatArray arr = (*env)->GetObjectField(env, objref, field);

	/*	return float array object.  */
	return arr;
}

/**
 *	Get object float pointer.
 *	@Return get float array pointer data.
 */
jfloat *hpmjni_get_float_array_pointer_reference(JNIEnv *__restrict__ env, jobject __restrict__ objref,
												 jfloatArray *__restrict__ array) {

	/*	Requires non null object and array pointer.	*/
	assert(objref && array);

	/*	Fetch float array object.	*/
	*array = hpmjni_get_float_array_reference(env, objref);

	/*	Get class type from object.	*/
	return (*env)->GetFloatArrayElements(env, *array, NULL);
}

/**
 *	Release
 */
void hpmjni_release_float_array_pointer_reference(JNIEnv *__restrict__ env, const jfloatArray __restrict__ array,
												  jfloat *__restrict__ fp) {

	assert(array && fp);

	(*env)->ReleaseFloatArrayElements(env, array, fp, 0);
}

/**
 *	Get object float pointer.
 *	@Return get float array pointer data.
 */
void hpmjni_get_float_array_pointer_reference_a_b(JNIEnv *__restrict__ env, jobject *__restrict__ objref,
												  jfloatArray *__restrict__ parray, jfloat **__restrict__ pfloat) {

	const int n = 2;
	int i;

	/*	Requires non null object and array pointer.	*/
	assert(objref && parray && pfloat);

	/*	Get float pointer for each float array objects. */
	for (i = 0; i < n; i++) {
		pfloat[i] = hpmjni_get_float_array_pointer_reference(env, objref[i], &parray[i]);
	}
}

/**
 *	Get object float pointer.
 *	@Return get float array pointer data.
 */
void hpmjni_get_float_array_pointer_reference_a_b_c(JNIEnv *__restrict__ env, jobject *__restrict__ objref,
													jfloatArray *__restrict__ parray, jfloat **__restrict__ pfloat) {

	const int n = 3;
	int i;

	/*	Requires non null object and array pointer.	*/
	assert(objref && parray && pfloat);

	/*	Get float pointer for each float array objects. */
	for (i = 0; i < n; i++) {
		pfloat[i] = hpmjni_get_float_array_pointer_reference(env, objref[i], &parray[i]);
	}
}

/**
 *	Get object float pointer.
 *	@Return get float array pointer data.
 */
void hpmjni_release_float_array_pointer_reference_a_b(JNIEnv *__restrict__ env, jfloatArray *__restrict__ parray,
													  jfloat **__restrict__ pfloat) {

	const int n = 2;
	int i;

	/*	Requires non null object and array pointer.	*/
	assert(parray && pfloat);

	/*	Release all float array objects.    */
	for (i = 0; i < n; i++) {
		(*env)->ReleaseFloatArrayElements(env, parray[i], pfloat[i], 0);
	}
}

/**
 *	Release float pointer array.
 */
void hpmjni_release_float_array_pointer_reference_a_b_c(JNIEnv *__restrict__ env, jfloatArray *__restrict__ parray,
														jfloat **__restrict__ pfloat) {

	const int n = 3;
	int i;

	/*	Requires non null object and array pointer.	*/
	assert(parray && pfloat);

	/*	Release each float array objects.    */
	for (i = 0; i < n; i++) {
		(*env)->ReleaseFloatArrayElements(env, parray[i], pfloat[i], 0);
	}
}

/**
 *	Create instance object of
 *	specified class type.
 *
 *	@Return
 */
jobject hpmjni_create_object_instance(JNIEnv *__restrict__ env, jclass __restrict__ c) {

	/*	Get constructor method ID.	*/
	jmethodID constructor = (*env)->GetMethodID(env, c, "<init>", "()V");

	/*	Create new object.	*/
	jobject o = (*env)->NewObject(env, c, constructor);

	/*	*/
	return o;
}

/**
 *	Create clone.
 *
 *	@Return clone object.
 */
jobject hpmjni_create_clone(JNIEnv *__restrict__ env, jobject __restrict__ o) {
	jclass c = (*env)->GetObjectClass(env, o);

	jmethodID mid = (*env)->GetMethodID(env, c, "<init>", "()V");

	return (*env)->NewObject(env, c, mid, o);
}

void hpmjni_throw_out_of_bound(JNIEnv *__restrict__ env, const char *__restrict__ msg) {
	const char *className = "java/lang/IllegalArgumentException";
	const jclass illex = (*env)->FindClass(env, className);
	(*env)->ThrowNew(env, illex, msg);
}

void hpmjni_throw_illegal_argument(JNIEnv *__restrict__ env, const char *__restrict__ msg) {
	const char *className = "java/lang/IndexOutOfBoundsException";
	const jclass illex = (*env)->FindClass(env, className);
	(*env)->ThrowNew(env, illex, msg);
}

void hpmjni_throw_null_reference(JNIEnv *__restrict__ env, const char *__restrict__ msg) {
	const char *className = "java/lang/NullPointerException";
	const jclass illex = (*env)->FindClass(env, className);
	(*env)->ThrowNew(env, illex, msg);
}

void hpmjni_throw_unsupported_operation(JNIEnv *__restrict__ env, const char *__restrict__ msg) {
	const jclass illex = (*env)->FindClass(env, "java/lang/UnsupportedOperationException");
	(*env)->ThrowNew(env, illex, msg);
}
