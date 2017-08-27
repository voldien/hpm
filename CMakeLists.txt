CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(hpm)


# Build shared/dynamic library option
OPTION(BUILD_SHARED_LIBS "Build package with shared libraries." ON)
IF(NOT BUILD_SHARED_LIBS)
	SET(CMAKE_EXE_LINKER_FLAGS "-static")
	SET(LINK_SEARCH_START_STATIC TRUE)
ENDIF()

# hpm version setup.
SET(HPM_VERSION_MAJOR 0)
SET(HPM_VERSION_MINOR 6)
SET(HPM_VERSION_REVISION 0)
SET(HPM_VERSION_STATE a)
SET(HPM_VERSION ${HPM_VERSION_MAJOR}.${HPM_VERSION_MINOR}${HPM_VERSION_STATE}${HPM_VERSION_REVISION} )

# Set version preprocessor macros.
MESSAGE(STATUS "Version ${HPM_VERSION}")
ADD_DEFINITIONS(-DHPM_MAJOR_VERSION=${HPM_VERSION_MAJOR})
ADD_DEFINITIONS(-DHPM_MINOR_VERSION=${HPM_VERSION_MINOR})
ADD_DEFINITIONS(-DHPM_REVISION_VERSION=${HPM_VERSION_REVISION})
ADD_DEFINITIONS(-DHPM_STATE_VERSION=${HPM_VERSION_STATE})
ADD_DEFINITIONS(-DHPM_STR_VERSION="${HPM_VERSION}")

# gcc compiler options.
IF((CMAKE_COMPILER_IS_GNUCC) AND NOT CMAKE_COMPILER_IS_MINGOW)
	IF(BUILD_SHARED_LIBS AND CMAKE_SIZEOF_VOID_P EQUAL 8)
		ADD_DEFINITIONS(-fPIC)
		SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
	ENDIF()

	# Compiling language standard.
	ADD_DEFINITIONS(-std=c11)
	# 
	ADD_DEFINITIONS(-w)

	# Check build target.
	IF (CMAKE_BUILD_TYPE STREQUAL "Release")
		MESSAGE(STATUS "Compile for release.")
		ADD_DEFINITIONS(-DNDEBUG -O2)
		SET(CMAKE_RELEASE TRUE)
		SET(SIMD_FLAGS "-ftree-vectorize -ftree-slp-vectorize -ftree-vectorizer-verbose=10 -fopt-info-vec-optimized")
	ELSEIF( CMAKE_BUILD_TYPE STREQUAL "Debug")
		MESSAGE(STATUS "Compile for debug.")
		ADD_DEFINITIONS(-D_DEBUG)
		ADD_DEFINITIONS(-g3)
		SET(CMAKE_DEBUG TRUE)
		SET(SIMD_FLAGS "-ftree-vectorize -ftree-slp-vectorize -ftree-vectorizer-verbose=10 -fopt-info-vec-optimized")
	ENDIF()

ELSEIF(MSVC)

		# Enable multi-core complication with MSVC
		ADD_DEFINITIONS(/MP)
ENDIF()

# Source files.
FILE (GLOB headers ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
FILE (GLOB basecore ${CMAKE_CURRENT_SOURCE_DIR}/src/base/*
		    ${CMAKE_CURRENT_SOURCE_DIR}/src/utility.c )
FILE (GLOB nosimdsource ${CMAKE_CURRENT_SOURCE_DIR}/src/nosimd/* )
FILE (GLOB all_sse_source ${CMAKE_CURRENT_SOURCE_DIR}/src/sse/*)
FILE (GLOB avx_source ${CMAKE_CURRENT_SOURCE_DIR}/src/avx/*)
#FILE (GLOB avx512_source src/avx/*)
INCLUDE_DIRECTORIES(include)

# Main library target for initializing the library.
ADD_LIBRARY(hpm src/hpm.c)
SET_TARGET_PROPERTIES(hpm PROPERTIES COMPILE_FLAGS "-DHPM_INTERNAL=1" )
TARGET_LINK_LIBRARIES(hpm -lm -ldl)

# Target with no simd extensions requirements.
ADD_LIBRARY(hpmnosimd ${basecore} ${nosimdsource})
SET_TARGET_PROPERTIES(hpmnosimd PROPERTIES COMPILE_FLAGS "-mno-abm -DHPM_INTERNAL_IMP=1" )
TARGET_LINK_LIBRARIES(hpmnosimd -lm)

# X86 and amd64 CPU architecture.
IF (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)|(amd64)|(AMD64)")
	# Will added later when AVX512 is more accessible.
	#ADD_LIBRARY(${avx512_source} ${basecore} )
	#SET_TARGET_PROPERTIES(hpmavx512 PROPERTIES COMPILE_FLAGS "-mavx512" )
	#TARGET_LINK_LIBRARIES(hpmavx512 -lm)

	# Target for AVX2
	ADD_LIBRARY(hpmavx2 ${avx_source} ${basecore})
	SET_TARGET_PROPERTIES(hpmavx2 PROPERTIES COMPILE_FLAGS "-mavx2 -DHPM_INTERNAL_IMP=1 ${SIMD_FLAGS} " )
	TARGET_LINK_LIBRARIES(hpmavx2 -lm)

	# Target for AVX
	ADD_LIBRARY(hpmavx ${avx_source} ${basecore})
	SET_TARGET_PROPERTIES(hpmavx PROPERTIES COMPILE_FLAGS "-mavx -DHPM_INTERNAL_IMP=1 ${SIMD_FLAGS} " )
	TARGET_LINK_LIBRARIES(hpmavx -lm)

	# Target for SSE
	ADD_LIBRARY(hpmsse ${basecore} ${all_sse_source})
	SET_TARGET_PROPERTIES(hpmsse PROPERTIES COMPILE_FLAGS "-msse -DHPM_INTERNAL_IMP=1 ${SIMD_FLAGS} " )
	TARGET_LINK_LIBRARIES(hpmsse -lm)

	# Target for SSE2
	ADD_LIBRARY(hpmsse2 ${basecore} ${all_sse_source})
	SET_TARGET_PROPERTIES(hpmsse2 PROPERTIES COMPILE_FLAGS "-msse2 -DHPM_INTERNAL_IMP=1 ${SIMD_FLAGS} " )
	TARGET_LINK_LIBRARIES(hpmsse2 -lm)

	# Target for SSE3
	ADD_LIBRARY(hpmsse3 ${basecore} ${all_sse_source})
	SET_TARGET_PROPERTIES(hpmsse3 PROPERTIES COMPILE_FLAGS "-msse3 -DHPM_INTERNAL_IMP=1 ${SIMD_FLAGS} " )
	TARGET_LINK_LIBRARIES(hpmsse3 -lm)

	# Target for SSE4.1
	ADD_LIBRARY(hpmsse41 ${basecore} ${all_sse_source})
	SET_TARGET_PROPERTIES(hpmsse41 PROPERTIES COMPILE_FLAGS "-msse4.1 -DHPM_INTERNAL_IMP=1 ${SIMD_FLAGS} " )
	TARGET_LINK_LIBRARIES(hpmsse41 -lm)

	# Target for SSE4.2
	ADD_LIBRARY(hpmsse42 ${basecore} ${all_sse_source})
	SET_TARGET_PROPERTIES(hpmsse42 PROPERTIES COMPILE_FLAGS "-msse4.2 -DHPM_INTERNAL_IMP=1 ${SIMD_FLAGS} ")
	TARGET_LINK_LIBRARIES(hpmsse42 -lm)
ELSE()
	# Target for Neon 
	ADD_LIBRARY(hpmneon ${basecore}) #	Will resolve the neon specific implementation later. 
	SET_TARGET_PROPERTIES(hpmneon PROPERTIES COMPILE_FLAGS " -DHPM_INTERNAL_IMP=1  -mfpu=neon" )	#-funsafe-math-optimizations 
ENDIF()

# Non specific SIMD targets.
INSTALL (FILES ${headers} DESTINATION include/hpm)

# Add the install targets
INSTALL (TARGETS hpm DESTINATION lib)
INSTALL (TARGETS hpmnosimd DESTINATION lib)
IF (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)|(amd64)|(AMD64)")
	#INSTALL (TARGETS hpmavx512 DESTINATION lib)
	INSTALL (TARGETS hpmavx2 DESTINATION lib)
	INSTALL (TARGETS hpmavx DESTINATION lib)
	INSTALL (TARGETS hpmsse DESTINATION lib)
	INSTALL (TARGETS hpmsse2 DESTINATION lib)
	INSTALL (TARGETS hpmsse3 DESTINATION lib)
	INSTALL (TARGETS hpmsse41 DESTINATION lib)
	INSTALL (TARGETS hpmsse42 DESTINATION lib)
ENDIF()
IF(__arm__)
	INSTALL (TARGETS hpmneon DESTINATION lib)
ENDIF()

#
ADD_SUBDIRECTORY(test)

IF( UNIX )
	SET( TARGETDIR "${PROJECT_NAME}-${HPM_VERSION}")
	ADD_CUSTOM_TARGET(	distribution
				COMMAND mkdir -p ${TARGETDIR}
				COMMAND cp -r src include test CMakeLists.txt LICENSE README.md ${TARGETDIR}
				COMMAND tar cf - ${TARGETDIR} | gzip -c > ${TARGETDIR}.tar.gz
				COMMAND rm -r ${TARGETDIR} )
ENDIF()

