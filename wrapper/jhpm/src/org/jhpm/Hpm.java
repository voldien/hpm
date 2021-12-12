/**
 * High performance matrix library wrapper, utilizing SIMD extensions.
 * Copyright (C) 2017  Valdemar Lindberg
 * <p>
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * <p>
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * <p>
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package org.jhpm;

/**
 * Class responsible for initializing the
 * hpm library.
 *
 * @apiNote Library is a Java wrapper
 * around the hpm library.
 *
 * @author Valdemar Lindberg
 */
public class Hpm {

    /**
     * All possible SIMD mode
     * support.
     */
    public enum SIMD {
        HPM_NONE(0 << 0),		/*	No HPM SIMD exention flag.	*/
        HPM_NOSIMD(1 << 0),		/*	No SIMD hardware feature, using the FPU and ALU.	*/
        HPM_MMX(1 << 1),		/*	MMX. = (Yet not supported),	*/
        HPM_SSE(1 << 2),		/*	SSE = (Streaming SIMD Extensions),.	*/
        HPM_SSE2(1 << 3),		/*	SSE2 = (Streaming SIMD Extensions),.	*/
        HPM_SSE3(1 << 4),		/*	SSE3 = (Streaming SIMD Extensions),.	*/
        HPM_SSSE3(1 << 5),		/*	SSSE3 = (Streaming SIMD Extensions),.	*/
        HPM_SSE4_1(1 << 6),		/*	SSE4.1 = (Streaming SIMD Extensions),.	*/
        HPM_SSE4_2(1 << 7),		/*	SSE4.2 = (Streaming SIMD Extensions),.	*/
        HPM_AVX(1 << 8),		/*	AVX Version 1 = (Advanced Vector Extension),.	*/
        HPM_AVX2(1 << 9),		/*	AVX Version 2 = (Advanced Vector Extension),.	= (Not tested),*/
        HPM_AVX512(1 << 10),		/*	AVX512 = (Advanced Vector Extension),. = (Yet not supported),	*/
        HPM_NEON(1 << 11),		/*	ARM	FPU = (floating-point unit), feature.	*/
        HPM_SVML(1 << 29),		/*	Not supported.	*/
        HPM_ACML(1 << 30),		/*	Not supported.	*/
        HPM_DEFAULT(1 << 31);		/*	Default, makes attempt to take the best SIMD extension on the system.	*/

        private long simd;

        SIMD(int numVal) {
            this.simd = numVal;
        }
    }

    /**
     * Initialize hpm library.
     *
     * @param simd SIMD extension for which will be loaded into memory.
     * @return status of initialization.
     * @throws IllegalArgumentException
     */
    public static native int init(SIMD simd);

    /**
     * Load hpmjni library. This is required in order
     * for the wrapper library to work.
     */
    static {
        /* Load native library at runtime	*/
        /* hello.dll (Windows) or libhello.so (Unixes)	*/
        System.loadLibrary("hpmjni");
    }
}
