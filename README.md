# HPM
[![Hpm Linux](https://github.com/voldien/hpm/actions/workflows/Linux.yml/badge.svg)](https://github.com/voldien/hpm/actions/workflows/Linux.yml)
[![License: LGPL v3](https://img.shields.io/badge/License-LGPLv3-blue.svg)](https://www.gnu.org/licenses/lgpl-3.0)
[![GitHub release](https://img.shields.io/github/release/voldien/hpm.svg)](https://github.com/voldien/hpm/releases)

*HPM* is a matrix library that supports multiple SIMD implementations that can be loaded in run-time. Furthermore, the program can load the most appropriated implementation on its own and, it can as well explicitly load a specific SIMD extension with the available SIMD enumerators.

The number of features is relatively low as a result of the same function as to be implemented multiple times for multiple SIMD extensions.
## Features ##
* Matrix4x4, Matrix3x3 - Common matrix operation for a 4x4 and 3x3 is supported.
* Vector4, Vector3 - Common vector operation for vector3 and vector4 is supported.
* Quaternion - About all common quaternion operation is supported.
* Compare - Compare matrices, vectors, and quaternion by the object or by component-wise.
* Math - Simple maths function as max, min, sqrt, and random are supported.
* Utility - Support functions that utilities the other features for creating specific types of matrices.
* Print - Easy function for printing vector primitive type values.

#### Remark
The matrix2x2 and the vector2 are not supported as a result of not being able to take advantages of the SIMD features at all.

## Motivation
The main motivation of this project is to create a single library header interface for performing matrix operations, commonly used in 3D programming. Where the appropriated implementation, based on the available CPU extensions, will load the most efficient implementation. 
Where it can be done either automatically or manually.

## Installation
The software can be easily installed with invoking the following commands.
```bash
mkdir build && cd build
cmake ..
cmake --build .
make install
```

## Examples
1. The following code initializes the *hpm* library to use the *SSE2* SIMD extension and, create an identity matrix. The release function will close the loaded library which in succession will make each function pointer undefined, which means all the matrices functions will be undefined.
```c
#include<hpm/hpm.h>

int main(int argc, const char** argv){
	hpm_init(HPM_SSE2);
	hpmvec4x4f_t mat4;
	hpm_mat4x4_identitiy(mat4);
	hpm_mat4x4_print(mat4);
	hpm_release();
}
```
The following line demonstrates how to compile it and link the program in a Unix environment:
```
gcc *.c -o hpmexample -lhpm
```

## Assert/Performance Tools
In order to evaluate if the library has any performance differences on the system. The following test program for *hpm* can be used.
### Performance 
It will perform a performance test for all SIMD feature if supported by the machine when no SIMD extension argument has been set.
```bash
hpmassert --performance
```
The performance gain can be rather subtle for high-end computer specification, whereas low ends are more distinguishable. What should remark about the *hpmassert* program is that everything is executed in consecutive order. This does not represent what the performance differences would be when each function is called in random order.

The following table is an example of a subset of the result that is presented with the benchmark program. To see some tested CPU performance, Check the [benchmarks](test/hpmassert/README.md).


|         Function             | NOSIMD |   SSE  |  SSE2  |  SSE3  | SSSE3  | SSE41  | SSE42  |   AVX  |
| :---                         |     :---:  |      ---: |      ---: |      ---: |      ---: |      ---: |      ---: |      ---: |
| hpm_mat4x4_copyfv            |      1.000 |     1.375 |     1.375 |     1.375 |     1.375 |     1.375 |     1.376 |     1.032 |
| hpm_mat4x4_multiply_mat4x4fv |      1.000 |     2.949 |     2.936 |     2.925 |     2.949 |     2.899 |     2.939 |     3.476 |
| hpm_mat4x4_multiply_mat1x4fv |      1.000 |     2.352 |     2.352 |     2.352 |     2.352 |     2.353 |     2.354 |     2.537 |
| hpm_mat4x4_identityfv        |      1.143 |     1.143 |     1.143 |     1.143 |     1.143 |     1.143 |     1.143 |     1.000 |
| hpm_mat4x4_transposefv       |      1.111 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.213 |
| hpm_mat4x4_determinantfv     |      1.111 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.212 |
....
### Assertion - Integrity
The following command will perform a set of unit tests that will check and determine that all of the implementations for each of the SIMD extensions work.
```bash
hpmassert --assert
```

## hpmglbunny 
The *hpmglbunny* program is a simple test program to determine if the matrices and quaternion function implementation work, which is commonly used in rendering 3D models. This program will render multiple rotating bunnies.
See the following for an example of how to execute the test tool:
```bash
hpmglbunny --simd=avx
```
The *hpmglbunny* will by default use the *HPM_SIMD_DEFAULT* enumerator as the flag parameter for loading function pointers through the *hpm_init* function. This will attempt to load the latest *SIMD* extension supported on the system. However, the *simd=* argument can override it to a specific *SIMD* extension.

The primary purpose of this small program is to check if the *hpm* implementations work as accordingly in a 3D environment.

# Important 
Because the library is still in development. That means that the symbol table has yet not been finalized. Thus it can be expected that it might change in till the first stable release.

## Dependencies 
The *hpm* project does not have any additional dependency other than the libraries provided with the standard *c* libraries.
However, it is recommended that the following Debian packages have to be installed prior, see the following. If a higher version is already installed this is not required.
```bash
apt-get install gcc-6
```
The following command will display current version of gcc.
```bash
gcc --version
```

## License
This project is licensed under the LGPL+3 License - see the [LICENSE](LICENSE) file for details

