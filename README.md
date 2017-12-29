# hpm #
------
The *hpm* is a matrix library that supports multiple SIMD implementation that can be loaded in rune-time. Furthermore, the program can load the most appropriated implementation on its own and as well  explicit load a specific SIMD extension through the SIMD enumerator.

The number of features are relative low as a result of the same function as to be implemented multiple time for multiple SIMD extension.
## Features ##
* Matrix4x4, Matrix3x3 - Common matrix operation for a 4x4 and 3x3 is supported.
* Vector4, Vector3 - Common vector operation for 3 and 4 vector is supported.
* Quaternion - About all quaternion operation is supported.
* Compare - Compare matrices, vectors and quaternion by object or by elements.
* Math - Simple maths function as max, min, sqrt and random is supported.
* Utility - Support functions that utilities the other features for creating specific types of matrices.

The 2x2 matrix and the vector2 are not supported as a result of not being able to take advantages of the SIMD features at all.

# Motivation #
The main motivation of this project is to create a single library header interface for performing matrix operations, commonly used in 3D programming. Where the appropriated implementation, based on the available CPU extensions, will load the most efficient implementation. Where its done either automatically or manually.

# Examples #
1. The following code initialize hpm library to use *SSE2* and create an identity matrix. The release function will close the loaded library which in succession will make each function pointer undefined.
```c
#include<hpm/hpm.h>

int main(int argc, const char** argv){
	hpm_init(HPM_SSE2);
	hpmvec4x4 mat4x4;
	hpm_mat4x4_identitiy(mat4x4);
	hpm_release();
}

```

The following line demonstrate how to compile it and link the program:
```
gcc *.c -o hpmexample -lhpm
```

# Assert/Performance Tools #
In order to evaluate if the library has any performance differences on the system. The following test program for *hpm* can be used. It will perform test for all SIMD feature if supported by the machine, when no argument has been set.

```bash
hpmassert
```
The performance gain can be rather subtle for high end computer specification, whereas low end are more distinguishable.
What should remark about the *hpmtest* program, is that everything is execute in a consecutive order. So it does not represent what the performance differences would be when each function is called in a randomly order.

## hpmglbunny ##
The *hpmglbunny* is test program for determine if the matrices and quaternion function implementation, which is commonly used in rendering 3D models, works as accordingly. This program will render multiple rotating bunnies.
See following for example of how to execute the test tool:
```bash
hpmglbunny --simd=avx
```
The *hpmglbunny* will by default use the HPM_SIMD_DEFAULT enumerator as the flag parameter for loading function pointers through the *hpm_init* function. This will attempt to load the the latest *SIMD* extension supported on the system. However the *simd=* argument can override it to a specific *SIMD* extension.

This programs servers two purposes. First is to check if the functions works as accordingly. Secondly for making test if there are any performance gains between each of the SIMD versions.

## Important ##
---
Because the library is still in development. That means that the symbol table hasn't been finalised. Thus it can be expected that it might change in till first stable release version.

## Dependencies ##
----------------
The *hpm* project does not have any additional dependency other than the libraries provided with the standard *c* library.

## License ##
------
This project is licensed under the GPL+3 License - see the [LICENSE](LICENSE) file for details
