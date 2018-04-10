/**
    High performance matrix library utilizing SIMD extensions.
    Copyright (C) 2016  Valdemar Lindberg

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
#ifndef _HPM_TEST_H_
#define _HPM_TEST_H_ 1
#include<hpm.h>
#include<hpmmath.h>
#include<assert.h>

/**
 *	Global variable decleration.
 */
extern int g_SIMD;
extern int g_type;
extern int g_precision;
extern const unsigned int g_it;

/**
 *	Macro function declaration.
 */
#define HPM_BENCHMARK_FUNC_DECL(func)	\
extern void func##sp_test(void);
#define HPM_BENCHMARK_FUNC_IMP(func)	\
void func##sp_test(void)

/**
 * Vector benchmark function declaration
 */
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_copyfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_multifv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_dotfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_lengthfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_lengthsqurefv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_normalizefv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_negatefv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_lerpfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_slerpfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_max_compfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_min_compfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec3_crossproductfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec3_tripleProductfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec3_dotfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec3_lengthfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec3_lengthsquarefv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec3_normalizefv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec3_reflectfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec3_refractfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec3_projfv);

/**
 *	Quaternion benchmark function declaration.
 */
HPM_BENCHMARK_FUNC_DECL(hpm_quat_copyfv);
HPM_BENCHMARK_FUNC_DECL(hpm_quat_multi_quatfv);
HPM_BENCHMARK_FUNC_DECL(hpm_quat_multi_vec3fv);
HPM_BENCHMARK_FUNC_DECL(hpm_quat_directionfv);
HPM_BENCHMARK_FUNC_DECL(hpm_quat_get_vectorfv);
HPM_BENCHMARK_FUNC_DECL(hpm_quat_conjugatefv);
HPM_BENCHMARK_FUNC_DECL(hpm_quat_inversefv);
HPM_BENCHMARK_FUNC_DECL(hpm_quat_dotfv);
HPM_BENCHMARK_FUNC_DECL(hpm_quat_identityfv);
HPM_BENCHMARK_FUNC_DECL(hpm_quat_axis_anglefv);
HPM_BENCHMARK_FUNC_DECL(hpm_quat_from_mat4x4fv);
HPM_BENCHMARK_FUNC_DECL(hpm_quat_axisf);
HPM_BENCHMARK_FUNC_DECL(hpm_quat_lerpfv);
HPM_BENCHMARK_FUNC_DECL(hpm_quat_slerpfv);
HPM_BENCHMARK_FUNC_DECL(hpm_quat_pitchfv);
HPM_BENCHMARK_FUNC_DECL(hpm_quat_yawfv);
HPM_BENCHMARK_FUNC_DECL(hpm_quat_rollfv);

/**
 *	Matrices.
 */
HPM_BENCHMARK_FUNC_DECL(hpm_mat4x4_copyfv);
HPM_BENCHMARK_FUNC_DECL(hpm_mat4x4_multiply_mat4x4fv);
HPM_BENCHMARK_FUNC_DECL(hpm_mat4x4_multiply_mat1x4fv);
HPM_BENCHMARK_FUNC_DECL(hpm_mat4x4_identityfv);
HPM_BENCHMARK_FUNC_DECL(hpm_mat4x4_transposefv);
HPM_BENCHMARK_FUNC_DECL(hpm_mat4x4_determinantfv);
HPM_BENCHMARK_FUNC_DECL(hpm_mat4x4_inversefv);
HPM_BENCHMARK_FUNC_DECL(hpm_mat4x4_decomposefv);
HPM_BENCHMARK_FUNC_DECL(hpm_mat4x4_translationfv);
HPM_BENCHMARK_FUNC_DECL(hpm_mat4x4_scalefv);
HPM_BENCHMARK_FUNC_DECL(hpm_mat4x4_rotationfv);
HPM_BENCHMARK_FUNC_DECL(hpm_mat4x4_rotationXf);
HPM_BENCHMARK_FUNC_DECL(hpm_mat4x4_rotationYf);
HPM_BENCHMARK_FUNC_DECL(hpm_mat4x4_rotationZf);
HPM_BENCHMARK_FUNC_DECL(hpm_mat4x4_rotationQf);
HPM_BENCHMARK_FUNC_DECL(hpm_mat4x4_projfv);
HPM_BENCHMARK_FUNC_DECL(hpm_mat4x4_orthfv);
HPM_BENCHMARK_FUNC_DECL(hpm_mat4x4_unprojf);

/**
 * Math benchmark function declaration.
 */
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_maxfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec8_maxfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_minfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec8_minfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_sqrtfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec8_sqrtfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_fast_sqrtfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec8_fast_sqrtfv);

/**
 *	Compare logic benchmark function declaration.
 */
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_com_eqfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_eqfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_com_neqfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_neqfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_com_gfv);
HPM_BENCHMARK_FUNC_DECL(hpm_vec4_com_lfv);
HPM_BENCHMARK_FUNC_DECL(hpm_mat4_eqfv);
HPM_BENCHMARK_FUNC_DECL(hpm_mat4_neqfv);

/**
 *	Perforamance type.
 */
enum PerformanceTestType{
	eMatrix 		= 0x1,						/*	Matrices.	*/
	eTransfering 	= 0x2,						/*	Data transfer.	*/
	eComparing 		= 0x4,						/*	*/
	eIntegrity 		= 0x8,						/*	*/
	eQuaternion 	= 0x10,						/*	*/
	eMath 			= 0x20,						/*	*/
	eVector 		= 0x40,						/*	*/
	eAll 			= (unsigned int)(-1)		/*	*/
};

/**
 *	Precision type.
 */
enum PrecisionType{
	eFloat			= 1,					/**/
	eDouble 		= 2,					/**/
	eAllPrecision	= (eFloat | eDouble)
};


/**
 *	Read user argument option.
 */
extern void readArgument(int argc, char** argv);

extern void htpReadArgument(int argc, char** argv);	/*	Read user argument option.	*/
extern long int hptGetTime(void);					/*	Get current time in nano seconds.	*/
extern long int hptGetTimeResolution(void);			/*	Get time resolution used.	*/
extern int hptLog2MutExlusive32(unsigned int a);	/*	*/
extern void htpSimdExecute(unsigned int simd);		/*	*/
extern void htpBenchmarkPerformanceTest(void);		/*	*/
extern void htpIntegritySpCheckf(void);				/*	Check each function is working as accordinly.	*/
extern void htpFormatResult(unsigned int numResults, const Result* results);

#endif
