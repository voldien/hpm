# Root cmake for all the test sub programs for the
# hpm library.
OPTION(BUILD_ASSERT "Build Assert/Benchmark program." ON)
OPTION(BUILD_GLBUNNY "Build OpenGL Bunny program." ON)


# Add hpmglbunny test.
IF(BUILD_GLBUNNY)
	ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/glbunny)
ENDIF()
# Add hpm assert for testing each function and assert them.
IF(BUILD_ASSERT)
	ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/hpmassert)
ENDIF()
