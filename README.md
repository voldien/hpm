# hpm #
------
hpm is a matrix library that supports loading various SIMD version depending if the machine support it, in runetime. It will load the dynamic library that is associated with the chosen SIMD version. Where in the hpm initialization function, it will load all function pointer and assigned them to function pointer variable.


## Examples ##
1. The following code initialize hpm library to use SSE2 and create an identity matrix. The release function will close the loaded library which in succession will make each function pointer undefined.
```c
#include<hpm/hpm.h>

int main(int argc, const char** argv){
hpm_init(HPM_SSE2);
hpmvec4x4 mat4x4;
hpm_mat4x4_identitiy(mat4x4);
hpm_release();
}

```
The following line demonstrate how to compile it.
```
gcc *.c -o hpmexample -lhpm
```

## Tests ##
In order to evaluate if the library has any performance differences on the system. The following test program for *hpm* can be used. It will perform test for all SIMD feature if supported by the machine, when no argument has been set.

```bash
hpmtest
```
The performance gain can be rather subtle for high end computer rig whereas low end more distinguishable.
What should remark about the *hpmtest* program, is that everything is execute in a consecutive order. So it does not represent what the performance differences would be when each function is called in a randomly order.

## Important ##
---
Because the library is still in development. That means that the symbol table hasn't been finalised. Thus it can be expected that it might change in till the init version.