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
#ifndef _HPM_H_
#define _HPM_H_ 1
#include "hpmdef.h"
#include "hpmentries.h"
#include "hpmlogic.h"
#include "hpmmath.h"
#include "hpmmatrix.h"
#include "hpmprint.h"
#include "hpmquaternion.h"
#include "hpmutil.h"
#include "hpmvector.h"

/**
 * The main hpm library header file.
 * Hpm library has be initialize in order
 * utilize the library with hpm_init.
 */

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

/**
 * Function data types.
 */
typedef int(HPMAPIENTRY PHPMINIT)(unsigned int simd);
typedef int(HPMAPIENTRY PHPMRELEASE)(void);
typedef int(HPMAPIENTRY PHPMISINIT)(void);
typedef unsigned int(HPMAPIENTRY PHPMGETSIMD)(void);
typedef void *(HPMAPIENTRY PHPMGETADDRESS)(const char *cfunctionName, unsigned int simd);
typedef const char *(HPMAPIENTRY PHPMVERSION)(void);
typedef int(HPMAPIENTRY PHPMSUPPORTCPUFEAT)(unsigned int simd);
typedef const char *(HPMAPIENTRY PHPMGETSIMDSYMBOL)(unsigned int SIMD);

/**
 * SIMD (single instruction multiple data) extensions flags.
 */
#define HPM_NONE        (0 << 0)    /*  No HPM SIMD exention flag.	*/
#define HPM_NOSIMD      (1 << 0)    /*  No SIMD hardware feature, using the FPU and ALU.	*/
#define HPM_MMX         (1 << 1)    /*  MMX. (Yet not supported)	*/
#define HPM_SSE         (1 << 2)    /*  SSE (Streaming SIMD Extensions).	*/
#define HPM_SSE2        (1 << 3)    /*  SSE2 (Streaming SIMD Extensions).	*/
#define HPM_SSE3        (1 << 4)    /*  SSE3 (Streaming SIMD Extensions).	*/
#define HPM_SSSE3       (1 << 5)    /*  SSSE3 (Streaming SIMD Extensions).	*/
#define HPM_SSE4_1      (1 << 6)    /*  SSE4.1 (Streaming SIMD Extensions).	*/
#define HPM_SSE4_2      (1 << 7)    /*  SSE4.2 (Streaming SIMD Extensions).	*/
#define HPM_AVX         (1 << 8)    /*  AVX Version 1 (Advanced Vector Extension).	*/
#define HPM_AVX2        (1 << 9)    /*  AVX Version 2 (Advanced Vector Extension).	(Not tested)*/
#define HPM_AVX512      (1 << 10)   /*  AVX512 (Advanced Vector Extension). (Yet not supported)	*/
#define HPM_NEON        (1 << 11)   /*  ARM	FPU (floating-point unit) feature.	*/
#define HPM_FMA         (1 << 12)   /*  Not supported.	*/
#define HPM_SVML        (1 << 28)   /*  Not supported.	*/
#define HPM_ACML        (1 << 29)   /*  Not supported.	*/
#define HPM_DEFAULT     (1 << 30)   /*  Default, makes attempt to take the best SIMD extension on the system.	*/

/**
 * Initialize hpm library by assigning all function pointer in respect
 * to what SIMD (Single Instruction multiple data) extension chosen.
 *
 * @param SIMD what SIMD (Single Instruction multiple data) extension.
 *
 * @return 1 if successfully initialized. 0 if there was a failure.
 */
extern HPMDECLSPEC int HPMAPIENTRY hpm_init(unsigned int SIMD);

/**
 * Release library which all the function pointer associates with.
 * This means all the function pointer will become invalid.
 *
 * @return non-zero if successfully released.
 */
extern HPMDECLSPEC int HPMAPIENTRY hpm_release(void);

/**
 * 	Check if hpm has been initialized.
 *
 * @return none zero if initialized. Otherwise 0.
 */
extern HPMDECLSPEC int HPMAPIENTRY hpm_isinit(void);

/**
 * Get current initialized SIMD extension.
 *
 * @return none zero if initialized.
 */
extern HPMDECLSPEC unsigned int HPMAPIENTRY hpm_get_simd(void);

/**
 * Get function pointer address by its symbol name
 * from the hpm library currently loaded, that was
 * specified in hpm_init.
 *
 * @param cfunctionName function symbol name defined by HPM_FUNCSYMBOL.
 *
 * @param simd the SIMD associated with the function. used for extracting
 * correct symbol for when using hpm in single library mode.
 *
 * @return func pointer to the function. if NULL then the cfunction Name was
 * valid.
 */
extern HPMDECLSPEC void *HPMAPIENTRY hpm_get_address(const char *cfunctionName, unsigned int simd);

/**
 * Get hpm version.
 *
 * @return non NULL terminated string pointer.
 */
extern HPMDECLSPEC const char *HPMAPIENTRY hpm_version(void);

/**
 * Determine if SIMD extension is supported on the CPU.
 *
 * @param SIMD SIMD extension to check if supported on the CPU.
 *
 * @return 1 if supported. 0 if not supported.
 */
extern HPMDECLSPEC int HPMAPIENTRY hpm_support_cpu_feat(unsigned int SIMD);

/**
 * Get symbol name for specified SIMD enumerator.
 *
 * @param SIMD SIMD enumerator.
 *
 * @return non-null terminated string.
 */
extern HPMDECLSPEC const char *HPMAPIENTRY hpm_get_simd_symbol(unsigned int SIMD);

/**
 *
 *
 */
extern HPMDECLSPEC void hpm_get_method_callbacks(int *nr, HpmCallBackEntry *pEntries);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif
