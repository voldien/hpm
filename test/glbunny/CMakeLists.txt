# CMake file for setting up the hpmglbunny test
# program.

SET(OpenGL_GL_PREFERENCE "GLVND")
INCLUDE(FindOpenGL)
FIND_PACKAGE(OpenGL)
FIND_PACKAGE(GLEW)

IF(GLEW_FOUND)
    MESSAGE(STATUS "Glew found: ${GLEW_LIBRARIES}.")
ENDIF()

IF(OPENGL_FOUND)
    MESSAGE(STATUS "OpenGL found: ${OPENGL_LIBRARIES}.")
ENDIF()

# Source files for the gl bunny program.
FILE(GLOB bunnysrc ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

# Get the include directories for the target.
GET_TARGET_PROPERTY(LIBHPM_INCLUDES hpm INCLUDE_DIRECTORIES)

# Executable OpenGL hpm benchmark.
ADD_EXECUTABLE(hpmglbunny ${bunnysrc})
TARGET_LINK_LIBRARIES(hpmglbunny ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} SDL2 hpm )
SET_TARGET_PROPERTIES(hpmglbunny PROPERTIES COMPILE_FLAGS "" )
TARGET_INCLUDE_DIRECTORIES(hpmglbunny PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${LIBHPM_INCLUDES} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS})
ADD_DEPENDENCIES(hpmglbunny hpm)

# Install target.
IF(BUILD_WITH_INSTALL)
	INSTALL (TARGETS hpmglbunny DESTINATION bin)
ENDIF()
