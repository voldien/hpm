# CMake file for setting up the hpm assert test
# program.

# gcc compiler options.
IF((CMAKE_COMPILER_IS_GNUCC) AND NOT CMAKE_COMPILER_IS_MINGOW)

	# Compiling language standard.
	ADD_DEFINITIONS(-std=c11)
	ADD_DEFINITIONS(-w)

	# Check build target.
	IF (CMAKE_BUILD_TYPE STREQUAL "Release")
		MESSAGE(STATUS "Compile for release.")
		ADD_DEFINITIONS(-DNDEBUG -O2)
		SET(CMAKE_RELEASE TRUE)
	ELSEIF( CMAKE_BUILD_TYPE STREQUAL "Debug")
		MESSAGE(STATUS "Compile for debug.")
		ADD_DEFINITIONS(-D_DEBUG)
		ADD_DEFINITIONS(-g3)
		SET(CMAKE_DEBUG TRUE)
	ENDIF()

ELSEIF(MSVC)
		# Enable multi-core complication with MSVC
		ADD_DEFINITIONS(/MP)
ENDIF()

# Include directory for hpm declaration.
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/../../include)
# Include header directory for this program.
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Source files for the hpmassert program.
FILE(GLOB assertsrc	${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
			${CMAKE_CURRENT_SOURCE_DIR}/src/assert/*.c)

# Executable hpm assert program.
ADD_EXECUTABLE(hpmassert ${assertsrc})
TARGET_LINK_LIBRARIES(hpmassert -lm -lcheck -lpthread -lrt -lsubunit hpm)

# Install target.
INSTALL (TARGETS hpmassert DESTINATION bin)


ADD_TEST(
		NAME assert
		COMMAND hpmassert --assert)
SET_TESTS_PROPERTIES(assert PROPERTIES DEPENDS hpmassert)


ADD_TEST(
		NAME performance
		COMMAND hpmassert --performance --quite --simd=all)
SET_TESTS_PROPERTIES(performance PROPERTIES DEPENDS hpmassert)
