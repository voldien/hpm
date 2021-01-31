#ifndef _HPM_ENTRIES_H_
#define _HPM_ENTRIES_H_ 1

enum MethodEntry
{
	HPM_mat4x4_copyfv = 0,
	HPM_mat4x4_multiply_mat4x4fv=1,
	HPM_mat4x4_multiply_scalarf=2,
	HPM_mat4x4_multiply_mat1x4fv = 3,
	HPM_mat4x4_division_mat4x4f=4,
	HPM_mat4x4_additition_mat4x4fv=5,
	HPM_mat4x4_subraction_mat4x4fv=6,
	HPM_mat4x4_identityfv=7,
	HPM_mat4x4_transposefv=8,
	HPM_mat4x4_determinantfv=9,
	HPM_mat4x4_inversefv=10,
	HPM_mat4x4_decomposefv=11,
	HPM_mat4x4_translationf=12,
	HPM_mat4x4_translationfv=13,
	HPM_mat4x4_scalef=14,
	HPM_mat4x4_scalefv=15,
	HPM_mat4x4_rotationfv=16,
	HPM_mat4x4_rotationXf=17,
	HPM_mat4x4_rotationYf=18,
	HPM_mat4x4_rotationZf=19,
	HPM_mat4x4_rotationQfv=20,
	HPM_mat4x4_multi_translationfv=21,
	HPM_mat4x4_multi_scalefv=22,
	HPM_mat4x4_multi_rotationxf=23,
	HPM_mat4x4_multi_rotationyf=24,
	HPM_mat4x4_multi_rotationzf=25,
	HPM_mat4x4_multi_rotationQfv=26,

	/*	Projection matrix functions.    */
	HPM_mat4x4_projfv=27,
	HPM_mat4x4_orthfv=28,
	HPM_mat4x4_unprojf=29,

	/*	vector4	*/
	HPM_vec4_copyfv=30,
	HPM_vec4_setf=31,
	HPM_vec4_setsf=32,
	HPM_vec4_addition_scalefv=33,
	HPM_vec4_addition_scalef=34,
	HPM_vec4_subtractionf=35,
	HPM_vec4_multifv=36,
	HPM_vec4_multi_scalef=37,
	HPM_vec4_dotfv=38,
	HPM_vec4_lengthfv=39,
	HPM_vec4_lengthsqurefv=40,
	HPM_vec4_normalizefv=41,
	HPM_vec4_negatefv=42,

	HPM_vec4_max_compfv=43,
	HPM_vec4_min_compfv=44,

	HPM_vec4_lerpfv=45,
	HPM_vec4_slerpfv=46,

	/*	Vector3.	*/
	HPM_vec3_crossproductfv=47,
	HPM_vec3_tripleProductfv=48,
	HPM_vec3_dotfv=49,
	HPM_vec3_lengthfv=50,
	HPM_vec3_lengthsquarefv=51,
	HPM_vec3_normalizefv=52,
	HPM_vec3_reflectfv=53,
	HPM_vec3_refractfv=54,
	HPM_vec3_refract2fv=55,
	HPM_vec3_projfv=56,

	/*	Quaternion	*/
	HPM_quat_setf=57,
	HPM_quat_multi_quatfv=58,
	HPM_quat_multi_vec3fv=59,
	HPM_quat_directionfv=60,
	HPM_quat_get_vectorfv=61,
	HPM_quat_conjugatefv=62,
	HPM_quat_from_mat4x4fv=63,
	/*	*/
	HPM_quat_copyfv=64,
	HPM_quat_lengthfv=65,
	HPM_quat_lengthsqurefv=66,
	HPM_quat_normalizefv=67,
	HPM_quat_dotfv=68,
	HPM_quat_inversefv=69,
	HPM_quat_axis_anglefv=70,
	HPM_quat_axisf=71,
	HPM_quat_lookatfv=72,
	HPM_quat_powfv=73,
	HPM_quat_identityfv=74,
	HPM_quat_lerpfv=75,
	HPM_quat_slerpfv=76,
	HPM_quat_eularfv=77,
	HPM_quat_pitchfv=78,
	HPM_quat_yawfv=79,
	HPM_quat_rollfv=80,

	/*	Math	*/
	HPM_vec4_maxfv=81,
	HPM_vec8_maxfv=82,
	HPM_vec4_minfv=83,
	HPM_vec8_minfv=84,
	HPM_vec4_sqrtfv=85,
	HPM_vec8_sqrtfv=86,
	HPM_vec4_fast_sqrtfv=87,
	HPM_vec8_fast_sqrtfv=88,
	HPM_vec4_randomfv=89,
	HPM_vec8_randomfv=90,

	/*	Logic equality conditions.	*/
	HPM_vec_eqfv=91,
	HPM_vec_neqfv=92,
	HPM_vec4_com_eqfv=93,
	HPM_vec4_eqfv=94,
	HPM_vec4_com_neqfv=95,
	HPM_vec4_neqfv=96,
	HPM_vec4_com_gfv=97,
	HPM_vec4_com_lfv=98,

	/*	Utility.	*/
	HPM_mat4_eqfv=99,
	HPM_mat4_neqfv=100,

	/*	Utilities.	*/
	HPM_util_lookatfv=101,
};

typedef struct hpm_callback_entry_t
{
	enum MethodEntry id;
	void *callback;
} HpmCallBackEntry;

#endif
