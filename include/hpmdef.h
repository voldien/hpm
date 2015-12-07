/**
    Copyright (C) 2015  Valdemar Lindberg

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
#ifndef _HPM_DEF_H_
#define _HPM_DEF_H_ 1
#include<stdio.h>


/*
    Compiler
*/
#ifdef _MSC_VER 	/*	Visual Studio C++ Compiler.	*/
	#define HPM_VC
	#define HPM_COMPILER 1
	#if _MSC_VER >= 1900
		#define HPM_V13 _MSC_VER
	#elif _MSC_VER >= 1800
		#define HPM_V12 _MSC_VER
	#elif _MSC_VER >= 1700
		#define HPM_VC11 _MSC_VER
	#elif _MSC_VER >= 1600
		#define HPM_VC10 _MSC_VER
	#elif _MSC_VER >= 1500
		#define HPM_VC9 _MSC_VER
	#elif _MSC_VER >= 1400
		#define HPM_VC8 _MSC_VER
	#elif _MSC_VER >= 1300
		#define HPM_VC7 _MSC_VER
	#else
		#define HPM_VC6 _MSC_VER
	#endif
    	#pragma warning(disable : 4201)
	#define HPM_COMPILER_NAME "Visual Studio C++/C"

#elif defined(__clang__)  || defined(__llvm__)           /*  LLVM, clang   */
    #define HPM_LLVM 1
	#define HPM_CLANG 1
	#define HPM_COMPILER 5
	#define HPM_COMPILER_NAME "LLVM/CLANG"
	#define HPM_COMPILER_MAJOR_VERSION __clang_major__
	#define HPM_COMPILER_MINOR_VERSION __clang_minor__

#elif defined(__GNUC__) || defined(__SNC__) || defined( __GNUC_MINOR__)	/*  GNU C Compiler*/
	#define HPM_GNUC 1
	#define HPM_COMPILER 2
	#define HPM_COMPILER_NAME "GNU C"
	#define HPM_COMPILER_MAJOR_VERSION __clang_major__
	#define HPM_COMPILER_MINOR_VERSION __clang_minor__

#elif defined(__GNUG__) /*  GNU C++ Compiler*/
	#define HPM_GNUC 2

#elif defined(__ghs__)		/* GHS	*/
	#define HPM_GHS 1
	#define HPM_COMPILER 3

#elif defined(__HP_cc) || defined(__HP_aCC)			/*	*/

#elif defined(__PGI)			/*	*/

#elif defined(__ICC) || defined(__INTEL_COMPILER) /*  Intel Compiler  */
	#define HPM_INTEL
	#define HPM_COMPILER 4
	#define HPM_COMPILER_NAME "Intel C++"

#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)

#else
	#error Unsupported Compiler.
#endif



/*
	Platform define
	Architecture!
*/
#ifdef HPM_VC
	#if defined(_M_IX86) || defined(_WIN32)
		#define HPM_X86                          /**/
		#define HPM_X32                          /**/
		#define HPM_WIN32                        /**/
		#define HPM_WINDOWS                      /**/
	#elif defined(_M_X64) || defined(_WIN64)
		#define HPM_X64                          /**/
		#define HPM_WIN64                        /**/
		#define HPM_WINDOWS                      /**/
	#elif defined(_M_PPC)
		#define HPM_PPC                          /**/
		#define HPM_X360                         /**/
		#define HPM_VMX                          /**/
	#elif defined(_M_ARM)
		#define HPM_ARM                          /**/
		#define HPM_ARM_NEON                     /**/
	#endif
#elif defined(HPM_GNUC) || defined(HPM_CLANG)
	#ifdef __CELLOS_LV2__   /**/
        #define HPM_PS3                          /*	playstation 3*/
	#elif defined(__arm__)	/**/
		#define HPM_ARM
        #define HPM_PSP2                         /*	playstation portable 2*/
        #define HPM_RAS_PI                       /*	rasberry pi	*/
	#endif
	#if defined(_WIN32) /**  Window*/
		#define HPM_X86
		#define HPM_WINDOWS                      /**/
	#endif
	#if ( defined(__linux__) || defined(__linux) || defined(linux) ) && (!(__ANDROID__) || !(ANDROID))/* Linux */
		#define HPM_LINUX 1                       /**/
		#if defined(__amd64) || defined(__x86_64__) || defined(__i386__)
            #define HPM_X86 1
		#endif
		#if defined(__arm__)
              #define EX_ARM 1
        #endif

	#elif defined (ANDROID) || defined(__ANDROID__) || __ANDROID_API__ > 9  /** Android */
        #include<jni.h>
		#define HPM_ANDROID 1
		/*  android Architecture*/
        #if defined(__arm__)
			#define HPM_ARM 1
		  #if defined(__ARM_ARCH_7A__)
			#if defined(__ARM_NEON__)
			  #if defined(__ARM_PCS_VFP)
				#define ABI "armeabi-v7a/NEON (hard-float)"
			  #else
				#define ABI "armeabi-v7a/NEON"
			  #endif
			#else
			  #if defined(__ARM_PCS_VFP)
				#define ABI "armeabi-v7a (hard-float)"
			  #else
				#define ABI "armeabi-v7a"
			  #endif
			#endif
		  #else
		   #define ABI "armeabi"
		  #endif
		#elif defined(__i386__)
		   #define ABI "x86"
		#elif defined(__x86_64__)
		   #define ABI "x86_64"
		#elif defined(__mips64)  /* mips64el-* toolchain defines __mips__ too */
		   #define ABI "mips64"
		#elif defined(__mips__)
		   #define ABI "mips"
		#elif defined(__aarch64__)
		   #define ABI "arm64-v8a"
		#else
		   #define ABI "unknown"
		#endif

	#elif defined (__APPLE__)   /*  Apple product   */
		#define HPM_APPLE 1
		#if defined(__arm__)
			#define HPM_APPLE_IOS    /*  Apple iphone/ipad OS    */
		#elif defined(MACOSX) || defined(macintosh) || defined(Macintosh)
			#define EX_MAC 1
		#endif
	#elif defined(__CYGWIN) 	/**/
		#define HPM_CYGWIN 1
		#define HPM_LINUX 1
	#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)   /*  BSD*/
		#define HPM_BSD
    	#elif defined(__llvm__) || defined(__clang__)   	/*  llvm    */
        	#define HPM_LLVM 1
	#endif

#elif defined(__ICC) || defined(__INTEL_COMPILER)


#else
	#error  Unsupported architecture!   /*  No architecture support implicitly. remove this line to compile anyway*/
#endif

#if defined(__native_client__)	/*	nacl google	*/
	#define HPM_NACL 1
#endif
#if defined(__pnacl__)          /* portable nacl google */
	#define HPM_PNACL 1
#endif
#if defined(__unix__) || defined(__unix) || defined(unix)	/*  Unix    */
	#   define HPM_UNIX 1
#endif


#ifdef HPM_WINDOWS	        /** Windows Calling Convention.*/
	#define HPMAPIENTRY     __cdecl
	#define HPMAPIFASTENTRY __fastcall
	#define HPMAPITHISENTRY __thiscall
	#define HPMAPISTDENTRY  __stdcall
#elif defined(HPM_ANDROID)   /** Android Calling Convention*/
    #define HPMAPIENTRY JNICALL
    #define HPMAPIFASTENTRY JNICALL
    #define HPMAPITHISENTRY JNICALL
    #define HPMAPISTDENTRY JNICALL
#else
#   ifndef __cdecl
        #define __cdecl  __attribute__ ((__cdecl__))
        #define __stdcall  __attribute__ ((stdcall))
		#define __fastcall __attribute__((fastcall))
#   endif
	#define HPMAPIENTRY     __cdecl
	#define HPMAPISTDENTRY  __stdcall
	#define HPMAPIFASTENTRY __fastcall
#endif




/*	alignment	*/
#ifdef HPM_GNUC
	#define HPM_ALIGN(alignment) __attribute__ ((aligned(alignment)))
#elif defined(HPM_VC)
	#define HPM_ALIGN(alignment) __attribute__ ((aligned(alignment)))
#endif




#ifdef HPM_GNUC
	#define HPMDECLSPEC
#elif defined(HPM_VC)
	#define HPMDECLSPEC __declspec(dllimport)
#endif

#endif
