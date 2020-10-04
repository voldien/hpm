# CMake file for setting up the hpm assert test
# program.

GET_TARGET_PROPERTY(LIBHPM_INCLUDES hpm INCLUDE_DIRECTORIES)

# Source files for the hpmassert program.
FILE(GLOB assertsrc	${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
			${CMAKE_CURRENT_SOURCE_DIR}/src/assert/*.c)

# Executable hpm assert program.
ADD_EXECUTABLE(hpmassert ${assertsrc})
TARGET_LINK_LIBRARIES(hpmassert m check pthread rt subunit hpm)
TARGET_INCLUDE_DIRECTORIES(hpmassert PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${LIBHPM_INCLUDES} )
ADD_DEPENDENCIES(hpmassert hpm)

# Install target.
IF(BUILD_WITH_INSTALL)
	INSTALL (TARGETS hpmassert DESTINATION bin)
ENDIF()

ADD_TEST(
		NAME assert
		COMMAND hpmassert --assert
		WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
SET_TESTS_PROPERTIES(assert PROPERTIES DEPENDS hpmassert)
