CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(hpm)


#	build shared/dynamic library option
OPTION(BUILD_SHARED_LIBS "Build package with shared libraries." ON)
IF(NOT BUILD_SHARED_LIBS)
	set(CMAKE_EXE_LINKER_FLAGS "-static")
	set(LINK_SEARCH_START_STATIC TRUE)
ENDIF()



#	Extract tag version from git if its a git directory.
IF(EXISTS .git)
	EXECUTE_PROCESS(COMMAND git describe
			COMMAND sed -e "s/[^0-9]*//g"
			COMMAND cut -c1-1
			OUTPUT_VARIABLE _hpm_major OUTPUT_STRIP_TRAILING_WHITESPACE
			RESULT_VARIABLE _major_version_failed)

	EXECUTE_PROCESS(COMMAND git describe
			COMMAND sed -e "s/[^0-9].[^0-9]*//g"
			COMMAND cut -c1-1
			OUTPUT_VARIABLE _hpm_minor OUTPUT_STRIP_TRAILING_WHITESPACE
			RESULT_VARIABLE _minor_version_failed)

	EXECUTE_PROCESS(COMMAND git describe
			COMMAND sed -e "s/[^0-9].[^0-9].[^0-9]*//g"
			COMMAND cut -c1-2
			OUTPUT_VARIABLE _hpm_revision OUTPUT_STRIP_TRAILING_WHITESPACE
			RESULT_VARIABLE _revision_version_failed)
ENDIF()

#	hpm version setup.
SET(HPM_VERSION_MAJOR ${_hpm_major})
SET(HPM_VERSION_MINOR ${_hpm_minor})
SET(HPM_VERSION_REVISION ${_hpm_revision})
SET(HPM_VERSION ${HPM_VERSION_MAJOR}.${HPM_VERSION_MINOR}.${HPM_VERSION_REVISION} )


MESSAGE(STATUS "Version ${HPM_VERSION}")
#ADD_DEFINITIONS(-DHPM_MAJOR_VERSION=${HPM_VERSION_MAJOR})
#ADD_DEFINITIONS(-DHPM_MINOR_VERSION=${HPM_VERSION_MINOR})
#ADD_DEFINITIONS(-DHPM_REVISION_VERSION=${HPM_VERSION_REVISION})
if((CMAKE_COMPILER_IS_GNUCC) AND NOT CMAKE_COMPILER_IS_MINGOW)
	IF(BUILD_SHARED_LIBS AND CMAKE_SIZEOF_VOID_P EQUAL 8)
		ADD_DEFINITIONS(-fPIC)
		SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
	ENDIF()

	ADD_DEFINITIONS(-std=c11)
	ADD_DEFINITIONS(-w)
	IF (CMAKE_BUILD_TYPE STREQUAL "Release")
		MESSAGE(STATUS "Compile for release.")
		ADD_DEFINITIONS(-DNDEBUG)
		SET(CMAKE_RELEASE TRUE)
		SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s -O2")
		SET(SIMD_FLAGS "-ftree-vectorize -ftree-slp-vectorize -ftree-vectorizer-verbose=10 -fopt-info-vec-optimized") # -march=native
	ELSE()
		MESSAGE(STATUS "Compile for debug.")
		ADD_DEFINITIONS(-D_DEBUG)
		ADD_DEFINITIONS(-g3 -O0)
		SET(CMAKE_DEBUG TRUE)
		SET(SIMD_FLAGS "-ftree-vectorize -ftree-slp-vectorize -ftree-vectorizer-verbose=10 -fopt-info-vec-optimized") # -march=native
	ENDIF()


elseif(MSVC)
		# enable multi-core complication with MSVC
		ADD_DEFINITIONS(/MP)
endif()


#	File source paths
FILE (GLOB headers "include/*.h")
FILE (GLOB basecore src/base_* )
FILE (GLOB nosimdsource src/nosimd_* )
FILE (GLOB allsimdsource src/allsimd_* )
FILE (GLOB all_sse_source src/all_sse_*)
FILE (GLOB sse_source src/sse_*)
FILE (GLOB sse2_source src/sse2_*)
FILE (GLOB sse3_source src/sse3_*)
FILE (GLOB sse41_source src/sse41_*)
FILE (GLOB sse42_source src/sse42_*)
FILE (GLOB avx_source src/avx_*)
FILE (GLOB avx2_source src/avx2_*)
INCLUDE_DIRECTORIES(include)


#
IF(USE_SINGLE_LIBRARY)

	ADD_LIBRARY(hpm src/hpm.c)

ELSE()

	ADD_LIBRARY(hpm src/hpm.c)
	SET_TARGET_PROPERTIES(hpm PROPERTIES COMPILE_FLAGS "-DHPM_INTERNAL=1" )
	TARGET_LINK_LIBRARIES(hpm -lm -ldl)

	#	Target for cpu with no supported simd extensions.
	ADD_LIBRARY(hpmnosimd ${basecore} ${nosimdsource})
	SET_TARGET_PROPERTIES(hpmnosimd PROPERTIES COMPILE_FLAGS "-mno-abm -DHPM_INTERNAL_IMP=1" )
	TARGET_LINK_LIBRARIES(hpmnosimd -lm)


	IF (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)|(amd64)|(AMD64)")
		#ADD_LIBRARY(${avx512_source} ${basecore} )
		#SET_TARGET_PROPERTIES(hpmavx512 PROPERTIES COMPILE_FLAGS "-mavx512" )
		#TARGET_LINK_LIBRARIES(hpmavx512 -lm)

		# Target for AVX2
		ADD_LIBRARY(hpmavx2 ${avx2_source}  ${basecore} ${allsimdsource})
		SET_TARGET_PROPERTIES(hpmavx2 PROPERTIES COMPILE_FLAGS "-mavx2 -DHPM_INTERNAL_IMP=1 ${SIMD_FLAGS} " )
		TARGET_LINK_LIBRARIES(hpmavx2 -lm)

		# Target for AVX
		ADD_LIBRARY(hpmavx ${avx_source} ${basecore} ${allsimdsource})
		SET_TARGET_PROPERTIES(hpmavx PROPERTIES COMPILE_FLAGS "-mavx -DHPM_INTERNAL_IMP=1 ${SIMD_FLAGS} " )
		TARGET_LINK_LIBRARIES(hpmavx -lm)

		# Target for MMX. But is not active because its old and most x86 supports SEE/SSE2 where MMX is subset.
		#ADD_LIBRARY(hpmmmx src/mmx_matrix.c ${basecore} )
		#SET_TARGET_PROPERTIES(hpmmmx PROPERTIES COMPILE_FLAGS "-mmmx -DHPM_INTERNAL_IMP=1 ${SIMD_FLAGS} " )
		#TARGET_LINK_LIBRARIES(hpmmmx -lm)

		# Target for SSE1
		ADD_LIBRARY(hpmsse ${basecore} ${allsimdsource} ${all_sse_source})
		SET_TARGET_PROPERTIES(hpmsse PROPERTIES COMPILE_FLAGS "-msse -DHPM_INTERNAL_IMP=1 ${SIMD_FLAGS} " )
		TARGET_LINK_LIBRARIES(hpmsse -lm)

		# Target for SSE2
		ADD_LIBRARY(hpmsse2 ${basecore} ${allsimdsource} ${all_sse_source})
		SET_TARGET_PROPERTIES(hpmsse2 PROPERTIES COMPILE_FLAGS "-msse2 -DHPM_INTERNAL_IMP=1 ${SIMD_FLAGS} " )
		TARGET_LINK_LIBRARIES(hpmsse2 -lm)

		# Target for SSE3 
		ADD_LIBRARY(hpmsse3 ${basecore} ${allsimdsource} ${all_sse_source})
		SET_TARGET_PROPERTIES(hpmsse3 PROPERTIES COMPILE_FLAGS "-msse3 -DHPM_INTERNAL_IMP=1 ${SIMD_FLAGS} " )
		TARGET_LINK_LIBRARIES(hpmsse3 -lm)
	
		# Target for SSSE3. Not active because there isn't so far any benificts of it.
		#ADD_LIBRARY(hpmssse3 ${basecore} ${allsimdsource} ${all_sse_source})
		#SET_TARGET_PROPERTIES(hpmssse3 PROPERTIES COMPILE_FLAGS "-mssse3 -DHPM_INTERNAL_IMP=1 ${SIMD_FLAGS} ")
		#TARGET_LINK_LIBRARIES(hpmssse3 -lm)

		# Target for SSE41.
		ADD_LIBRARY(hpmsse41 ${basecore} ${allsimdsource} ${all_sse_source})
		SET_TARGET_PROPERTIES(hpmsse41 PROPERTIES COMPILE_FLAGS "-msse4.1 -DHPM_INTERNAL_IMP=1 ${SIMD_FLAGS} " )
		TARGET_LINK_LIBRARIES(hpmsse41 -lm)

		# Target for SSE42
		ADD_LIBRARY(hpmsse42 ${basecore} ${allsimdsource} ${all_sse_source})
		SET_TARGET_PROPERTIES(hpmsse42 PROPERTIES COMPILE_FLAGS "-msse4.2 -DHPM_INTERNAL_IMP=1 ${SIMD_FLAGS} ")
		TARGET_LINK_LIBRARIES(hpmsse42 -lm)

	ELSEIF(CMAKE_SYSTEM_PROCESSOR MATCHES "(arm)")
		# Target for NEON.
		ADD_LIBRARY(hpmneon ${basecore}) #	Will resolve the neon specific implementation later. 
		SET_TARGET_PROPERTIES(hpmneon PROPERTIES COMPILE_FLAGS " -DHPM_INTERNAL_IMP=1  -mfpu=neon" )	#-funsafe-math-optimizations 
	ENDIF()

ENDIF()


# Executable hpm benchmark. 
ADD_EXECUTABLE(hpmtest test/main.c)
TARGET_LINK_LIBRARIES(hpmtest -lm hpm)
SET_TARGET_PROPERTIES(hpmtest PROPERTIES COMPILE_FLAGS "-Iinclude" )


#ADD_EXECUTABLE(hpmtest2 test/main2.c)
#TARGET_LINK_LIBRARIES(hpmtest -lm hpm)
#SET_TARGET_PROPERTIES(hpmtest PROPERTIES COMPILE_FLAGS "-Iinclude" )

# Add the install targets
INSTALL (TARGETS hpm DESTINATION lib)
INSTALL (TARGETS hpmnosimd DESTINATION lib)
IF (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)|(amd64)|(AMD64)")
	#INSTALL (TARGETS hpmavx512 DESTINATION lib)
	INSTALL (TARGETS hpmavx2 DESTINATION lib)
	INSTALL (TARGETS hpmavx DESTINATION lib)
	#INSTALL (TARGETS hpmmmx DESTINATION lib)
	INSTALL (TARGETS hpmsse DESTINATION lib)
	INSTALL (TARGETS hpmsse2 DESTINATION lib)
	INSTALL (TARGETS hpmsse3 DESTINATION lib)
	INSTALL (TARGETS hpmsse41 DESTINATION lib)
	INSTALL (TARGETS hpmsse42 DESTINATION lib)
ENDIF()
IF(__arm__)
	INSTALL (TARGETS hpmneon DESTINATION lib)
ENDIF()

# Include header for development.
INSTALL (FILES ${headers} DESTINATION include/hpm)

# Test binary.
INSTALL (TARGETS hpmtest DESTINATION bin)


