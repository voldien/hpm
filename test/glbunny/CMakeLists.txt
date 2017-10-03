# CMake file for setting up the hpmglbunny test
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
		# Enable multi-core complication with MSVC.
		ADD_DEFINITIONS(/MP)
ENDIF()

# Include directory for hpm declaration.
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../../include)

# Source files for the gl bunny program.
FILE(GLOB bunnysrc ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

# Executable OpenGL hpm benchmark.
ADD_EXECUTABLE(hpmglbunny ${bunnysrc})
TARGET_LINK_LIBRARIES(hpmglbunny -lGL -lSDL2 hpm)
SET_TARGET_PROPERTIES(hpmglbunny PROPERTIES COMPILE_FLAGS "" )

# Install target.
INSTALL (TARGETS hpmglbunny DESTINATION bin)

