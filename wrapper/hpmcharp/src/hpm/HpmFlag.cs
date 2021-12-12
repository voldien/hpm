namespace HpmSharp
{
			public enum SIMD : uint {
			HPM_NONE = (0 << 0),		/*	No HPM SIMD exention flag.	*/
			HPM_NOSIMD = (1 << 0),		/*	No SIMD hardware feature, using the FPU and ALU.	*/
			HPM_MMX = (1 << 1),		/*	MMX. = (Yet not supported),	*/
			HPM_SSE = (1 << 2),		/*	SSE = (Streaming SIMD Extensions),.	*/
			HPM_SSE2 = (1 << 3),		/*	SSE2 = (Streaming SIMD Extensions),.	*/
			HPM_SSE3 = (1 << 4),		/*	SSE3 = (Streaming SIMD Extensions),.	*/
			HPM_SSSE3 = (1 << 5),		/*	SSSE3 = (Streaming SIMD Extensions),.	*/
			HPM_SSE4_1 = (1 << 6),		/*	SSE4.1 = (Streaming SIMD Extensions),.	*/
			HPM_SSE4_2 = (1 << 7),		/*	SSE4.2 = (Streaming SIMD Extensions),.	*/
			HPM_AVX = (1 << 8),		/*	AVX Version 1 = (Advanced Vector Extension),.	*/
			HPM_AVX2 = (1 << 9),		/*	AVX Version 2 = (Advanced Vector Extension),.	= (Not tested),*/
			HPM_AVX512 = (1u << 10),		/*	AVX512 = (Advanced Vector Extension),. = (Yet not supported),	*/
			HPM_NEON = (1u << 11),		/*	ARM	FPU = (floating-point unit), feature.	*/
			HPM_SVML = (1u << 29),		/*	Not supported.	*/
			HPM_ACML = (1u << 30),		/*	Not supported.	*/
			HPM_DEFAULT = (1u << 31)		/*	Default, makes attempt to take the best SIMD extension on the system.	*/
		}
}
