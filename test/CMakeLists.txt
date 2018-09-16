# Root cmake for all the test sub programs for the
# hpm library.

# Add hpmglbunny test.
ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/glbunny)
# Add hpm assert for testing each function and assert them.
ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/hpmassert)
