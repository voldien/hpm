using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
using NativeLibraryLoader;


namespace HpmSharp.HpmBinding
{
	public static unsafe partial class HpmNative
	{

		private enum MethodEntry
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


		[StructLayout(LayoutKind.Sequential, Pack=0)]
		struct HpmCallBackEntry
		{
			public uint id;
			public IntPtr func;
		}



		// [DllImport(CallingConvention = CallingConvention.Cdecl)]
        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
		private delegate int hpm_init_t(uint simd);
		private static hpm_init_t s_hpm_init;
		public static int hpm_init(uint simd) => s_hpm_init(simd);

		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
		private delegate void hpm_release_t();
		private static hpm_release_t s_hpm_release;
		public static void hpm_release() => s_hpm_release();

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
		private delegate string hpm_version_t();
		private static hpm_version_t s_hpm_version;
		public static string hpm_version() => s_hpm_version();

       [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
		private delegate int hpm_support_cpu_feat_t(int simd);
		private static hpm_support_cpu_feat_t s_hpm_support_cpu_feat;

       [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
		private delegate void hpm_get_method_callbacks_t(int* nr, HpmCallBackEntry* entries);
		private static hpm_get_method_callbacks_t s_hpm_get_method_callbacks;

       [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
		private delegate int hpm_vec4_print_t(float* vec);
		private static hpm_vec4_print_t s_hpm_vec4_print;

       [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
		private delegate int hpm_vec4_sprint_t([In()] [MarshalAs(UnmanagedType.LPStr)]string text, float* vec);
		private static hpm_vec4_sprint_t s_hpm_vec4_sprint;
		public static int hpm_vec4_sprint([In()] [MarshalAs(UnmanagedType.LPStr)] string text, float* vec) => s_hpm_vec4_sprint(text, vec);


       [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
		private delegate int hpm_quat_sprint_t([In()] [MarshalAs(UnmanagedType.LPStr)]string text, float* quat);
		private static hpm_quat_sprint_t s_hpm_quat_sprint;
		public static int hpm_quat_sprint([In()] [MarshalAs(UnmanagedType.LPStr)] string text, float* quat) => s_hpm_quat_sprint(text, quat);


       [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
		private delegate int hpm_mat4x4_sprint_t(string text, float* vec);
		private static hpm_mat4x4_sprint_t s_hpm_mat4x4_sprint;
		public static int hpm_mat4x4_sprint(string text, float* vec) => s_hpm_mat4x4_sprint(text, vec);


		// public static extern int hpm_init(uint simd);

		// [DllImport(CallingConvention = CallingConvention.Cdecl)]
		// public static extern int hpm_release();
		// [DllImport(CallingConvention = CallingConvention.Cdecl)]
		// public static extern int hpm_version();
		// [DllImport(CallingConvention = CallingConvention.Cdecl)]
		// public static extern int hpm_support_cpu_feat(uint flag);



		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate void hpm_vec4_copyfv_t(float* destination, float* source);
        private static hpm_vec4_copyfv_t s_hpm_vec4_copyfv;
		public static void hpm_vec4_copyfv(float* destination, float* source) => s_hpm_vec4_copyfv(destination, source);

		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate void hpm_vec4_normalizefv_t(float* v);
        private static hpm_vec4_normalizefv_t s_hpm_vec4_normalizefv;
		public static void hpm_vec4_normalizefv(float* v) => s_hpm_vec4_normalizefv(v);



		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate bool hpm_vec4_eqfv_t(float* v1, float* v2);
        private static hpm_vec4_eqfv_t s_hpm_vec4_eqfv;
		public static bool hpm_vec4_eqfv(float* v1, float* v2) => hpm_vec4_eqfv(v1, v2);

		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate bool hpm_vec4_neqfv_t(float* v1, float* v2);
        private static hpm_vec4_neqfv_t s_hpm_vec4_neqfv;
		public static bool hpm_vec4_neqfv(float* v1, float* v2) => hpm_vec4_neqfv(v1, v2);

		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate float hpm_vec4_lengthfv_t(float* vec);
        private static hpm_vec4_lengthfv_t s_hpm_vec4_lengthfv;
		public static float hpm_vec4_lengthfv(float* vec) => s_hpm_vec4_lengthfv(vec);

		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate float hpm_vec4_lengthsqurefv_t(float* vec);
        private static hpm_vec4_lengthsqurefv_t s_hpm_vec4_lengthsqurefv;
		public static float hpm_vec4_lengthsqurefv(float* vec) => s_hpm_vec4_lengthsqurefv(vec);

		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate float hpm_vec4_dotfv_t(float* v1, float* v2);
        private static hpm_vec4_dotfv_t s_hpm_vec4_dotfv;
		public static float hpm_vec4_dotfv(float* v1, float* v2) => s_hpm_vec4_dotfv(v1, v2);






		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate void hpm_mat4x4_copyfv_t(float* destination, float* source);
        private static hpm_mat4x4_copyfv_t s_hpm_mat4x4_copyfv;
		public static void hpm_mat4x4_copyfv(float* destination, float* source) => s_hpm_mat4x4_copyfv(destination, source);

		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate void hpm_mat4x4_identityfv_t(float* a);
        private static hpm_mat4x4_identityfv_t s_hpm_mat4x4_identityfv;
		public static void hpm_mat4x4_identityfv(float* a) => s_hpm_mat4x4_identityfv(a);

		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate void hpm_mat4x4_transposefv_t(float* a, float* o);
        private static hpm_mat4x4_transposefv_t s_hpm_mat4x4_transposefv;
		public static void hpm_mat4x4_transposefv(float* a, float* o) => s_hpm_mat4x4_transposefv(a,o);

		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate void hpm_mat4x4_translationf_t(float* a, float x, float y, float z);
        private static hpm_mat4x4_translationf_t s_hpm_mat4x4_translationf;
		public static void hpm_mat4x4_translationf(float* a, float x, float y, float z) => s_hpm_mat4x4_translationf(a, x, y ,z );

		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate void hpm_mat4x4_translationfv_t(float* a, float* v);
        private static hpm_mat4x4_translationfv_t s_hpm_mat4x4_translationfv;
		public static void hpm_mat4x4_translationfv(float* a, float* v) => s_hpm_mat4x4_translationfv(a, v );


		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate void hpm_mat4x4_scalef_t(float* a, float x, float y, float z);
        private static hpm_mat4x4_scalef_t s_hpm_mat4x4_scalef;
		public static void hpm_mat4x4_scalef(float* a, float x, float y, float z) => s_hpm_mat4x4_scalef(a, x, y ,z );

		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate void hpm_mat4x4_scalefv_t(float* a, float* vec);
        private static hpm_mat4x4_scalefv_t s_hpm_mat4x4_scalefv;
		public static void hpm_mat4x4_scalefv(float* a, float* vec) => s_hpm_mat4x4_scalefv(a, vec );



        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate void hpm_mat4x4_multiply_mat4x4fv_t(float* larg, float* rag, float* output);
        private static hpm_mat4x4_multiply_mat4x4fv_t s_hpm_mat4x4_multiply_mat4x4fv;
		public static void hpm_mat4x4_multiply_mat4x4fv(float* larg, float* rag, float* output) => s_hpm_mat4x4_multiply_mat4x4fv(larg, rag, output);


        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate void hpm_mat4x4_multiply_mat1x4fv_t(float* larg, float* rag, float* output);
        private static hpm_mat4x4_multiply_mat1x4fv_t s_hpm_mat4x4_multiply_mat1x4fv;
		public static void hpm_mat4x4_multiply_mat1x4fv(float* larg, float* rag, float* output) => s_hpm_mat4x4_multiply_mat1x4fv(larg, rag, output);


        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate void hpm_mat4x4_multiply_scalarf_t(float* larg, float rarg, float* output);
        private static hpm_mat4x4_multiply_scalarf_t s_hpm_mat4x4_multiply_scalarf;
        public static void hpm_mat4x4_multiply_scalarf(float* larg, float rarg, float* output) => s_hpm_mat4x4_multiply_scalarf(larg, rarg, output);


        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate float hpm_mat4x4_determinantfv_t(float* m);
        private static hpm_mat4x4_determinantfv_t s_hpm_mat4x4_determinantfv;
        public static float hpm_mat4x4_determinantfv(float* m) => s_hpm_mat4x4_determinantfv(m);


        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate float hpm_mat4x4_inversefv_t(float* m, float* o);
        private static hpm_mat4x4_inversefv_t s_hpm_mat4x4_inversefv;
        public static float hpm_mat4x4_inversefv(float* m, float* o) => s_hpm_mat4x4_inversefv(m,o);


        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate void hpm_mat4x4_orthfv_t(float* a, float left, float right, float bottom, float top,
											float near, float far);
        private static hpm_mat4x4_orthfv_t s_hpm_mat4x4_orthfv;
        public static void hpm_mat4x4_orthfv(float* a, float left, float right, float bottom, float top,
											float near, float far) => s_hpm_mat4x4_orthfv(a, left, right, bottom, top, near, far);

		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate bool hpm_mat4x4_projfv_t(float* a, float fov, float aspect, float near,
												float far);
        private static hpm_mat4x4_projfv_t s_hpm_mat4x4_projfv;
        public static bool hpm_mat4x4_projfv(float* a, float fov, float aspect, float near,
												float far) => s_hpm_mat4x4_projfv(a, fov,aspect, near, far);


        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate bool hpm_mat4_eqfv_t(float* a, float*b);
        private static hpm_mat4_eqfv_t s_hpm_mat4_eqfv;
        public static bool hpm_mat4_eqfv(float* a, float*b) => s_hpm_mat4_eqfv(a, b);


        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate bool hpm_mat4_neqfv_t(float* a, float*b);
        private static hpm_mat4_neqfv_t s_hpm_mat4_neqfv;
        public static bool hpm_mat4_neqfv(float* a, float*b) => s_hpm_mat4_neqfv(a, b);



        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate bool hpm_vec4_maxfv_t(float* a, float*b, float* c);
        private static hpm_vec4_maxfv_t s_hpm_vec4_maxfv;
        public static bool hpm_vec4_maxfv(float* a, float*b, float* c) => s_hpm_vec4_maxfv(a, b, c);


        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate bool hpm_vec4_minfv_t(float* a, float*b, float* c);
        private static hpm_vec4_minfv_t s_hpm_vec4_minfv;
        public static bool hpm_vec4_minfv(float* a, float*b, float* c) => s_hpm_vec4_minfv(a, b, c);
			//[MarshalAs()
		private unsafe static void LoadOpenHpm()
		{
			/*	*/
			s_hpm_init = LoadFunction<hpm_init_t>("hpm_init");
			s_hpm_release = LoadFunction<hpm_release_t>("hpm_release");
			s_hpm_version = LoadFunction<hpm_version_t>("hpm_version");
			s_hpm_support_cpu_feat = LoadFunction<hpm_support_cpu_feat_t>("hpm_support_cpu_feat");
			s_hpm_get_method_callbacks = LoadFunction<hpm_get_method_callbacks_t>("hpm_get_method_callbacks");

			s_hpm_vec4_sprint = LoadFunction<hpm_vec4_sprint_t>("hpm_vec4_sprint");
			s_hpm_quat_sprint = LoadFunction<hpm_quat_sprint_t>("hpm_quat_sprint");
			s_hpm_mat4x4_sprint = LoadFunction<hpm_mat4x4_sprint_t>("hpm_mat4x4_sprint");

		}

		public static void loadHpmInternalFunctions(){


			s_hpm_mat4x4_copyfv = LoadFunction<hpm_mat4x4_copyfv_t>("hpm_mat4x4_copyfv");
			s_hpm_mat4x4_multiply_mat4x4fv = LoadFunction<hpm_mat4x4_multiply_mat4x4fv_t>("hpm_mat4x4_multiply_mat4x4fv");
			s_hpm_mat4x4_multiply_mat1x4fv = LoadFunction<hpm_mat4x4_multiply_mat1x4fv_t>("hpm_mat4x4_multiply_mat1x4fv");


			s_hpm_mat4x4_identityfv = LoadFunction<hpm_mat4x4_identityfv_t>("hpm_mat4x4_identityfv");
			s_hpm_mat4x4_determinantfv = LoadFunction<hpm_mat4x4_determinantfv_t>("hpm_mat4x4_determinantfv");
			s_hpm_mat4x4_orthfv = LoadFunction<hpm_mat4x4_orthfv_t>("hpm_mat4x4_orthfv");
			s_hpm_mat4x4_projfv = LoadFunction<hpm_mat4x4_projfv_t>("hpm_mat4x4_projfv");


			s_hpm_mat4_eqfv = LoadFunction<hpm_mat4_eqfv_t>("hpm_mat4_neqfv");
			s_hpm_mat4_neqfv = LoadFunction<hpm_mat4_neqfv_t>("hpm_mat4_neqfv");



			s_hpm_vec4_lengthfv = LoadFunction<hpm_vec4_lengthfv_t>("hpm_vec4_lengthfv");

			int nr;
			s_hpm_get_method_callbacks(&nr, null);
			HpmCallBackEntry[] entries = new HpmCallBackEntry[nr];
			fixed(HpmCallBackEntry* pEntries = &entries[0]){
				s_hpm_get_method_callbacks(&nr, pEntries);
			}


			//hpm_mat4x4_copyfv(x, y);
			/*	*/
			//s_hpm_mat4x4_copyfv = LoadHpmFunction<hpm_mat4x4_copyfv_t>(entries, MethodEntry.HPM_mat4x4_copyfv);

			//s_hpm_mat4x4_copyfv = LoadHpmFunction<hpm_mat4x4_copyfv_t>(entries, MethodEntry.HPM_mat4x4_copyfv);
			//s_hpm_mat4x4_multiply_mat4x4fv = LoadHpmFunction<hpm_mat4x4_multiply_mat4x4fv_t>(entries, MethodEntry.HPM_mat4x4_multiply_mat4x4fv);
			//s_hpm_mat4x4_determinantfv = LoadHpmFunction<hpm_mat4x4_determinantfv_t>(entries, MethodEntry.HPM_mat4x4_determinantfv);
			//s_hpm_mat4x4_identityfv = LoadHpmFunction<hpm_mat4x4_identityfv_t>(entries, MethodEntry.HPM_mat4x4_identityfv);
			//s_hpm_vec4_lengthfv = LoadHpmFunction<hpm_vec4_lengthfv_t>(entries, MethodEntry.HPM_quat_lengthfv);
			// float[] a = new float[4];
			// float[] b = new float[4];
			// fixed(float* x = &a[0], y = &b[0]){
			// 	float _p = s_hpm_vec4_lengthfv(x);
			// 	_p +=s_hpm_vec4_lengthfv(x);
			// }

			// s_hpm_mat4x4_multiply_scalarf = LoadHpmFunction<hpm_mat4x4_multiply_scalarf_t>(entries, MethodEntry.HPM_mat4x4_multi_scalefv);
			// s_hpm_mat4x4_multiply_scalarf = LoadHpmFunction<hpm_mat4x4_multiply_scalarf_t>(entries, MethodEntry.HPM_mat4x4_multi_scalefv);
			// s_hpm_mat4x4_multiply_scalarf = LoadHpmFunction<hpm_mat4x4_multiply_scalarf_t>(entries, MethodEntry.HPM_mat4x4_multi_scalefv);
			// s_hpm_mat4x4_multiply_scalarf = LoadHpmFunction<hpm_mat4x4_multiply_scalarf_t>(entries, MethodEntry.HPM_mat4x4_multi_scalefv);
			// s_hpm_mat4x4_multiply_scalarf = LoadHpmFunction<hpm_mat4x4_multiply_scalarf_t>(entries, MethodEntry.HPM_mat4x4_multi_scalefv);
			// s_hpm_mat4x4_multiply_scalarf = LoadHpmFunction<hpm_mat4x4_multiply_scalarf_t>(entries, MethodEntry.HPM_mat4x4_multi_scalefv);
			// s_hpm_mat4x4_multiply_scalarf = LoadHpmFunction<hpm_mat4x4_multiply_scalarf_t>(entries, MethodEntry.HPM_mat4x4_multi_scalefv);
			// s_hpm_mat4x4_multiply_scalarf = LoadHpmFunction<hpm_mat4x4_multiply_scalarf_t>(entries, MethodEntry.HPM_mat4x4_multi_scalefv);
			// s_hpm_mat4x4_multiply_scalarf = LoadHpmFunction<hpm_mat4x4_multiply_scalarf_t>(entries, MethodEntry.HPM_mat4x4_multi_scalefv);
			// s_hpm_mat4x4_multiply_scalarf = LoadHpmFunction<hpm_mat4x4_multiply_scalarf_t>(entries, MethodEntry.HPM_mat4x4_multi_scalefv);
		}

        private static T LoadHpmFunction<T>(HpmCallBackEntry[] entries, MethodEntry entry)
        {
            return Marshal.GetDelegateForFunctionPointer<T>(entries[(int)entry].func);
        }

	}
}
