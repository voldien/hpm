
cmake_minimum_required(VERSION 2.8)
project(hpm)


#	build shared/dynamic library option
option(BUILD_SHARED_LIBS "Build package with shared libraries." ON)
if(NOT BUILD_SHARED_LIBS)
	set(CMAKE_EXE_LINKER_FLAGS "-static")
	set(LINK_SEARCH_START_STATIC TRUE)
endif()









if((CMAKE_COMPILER_IS_GNUCC) AND NOT CMAKE_COMPILER_IS_MINGOW)
	if(BUILD_SHARED_LIBS AND CMAKE_SIZEOF_VOID_P EQUAL 8)
		add_definitions(-fPIC)
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
	endif()

	#add_definitions(-fvisibility=hidden -Wall)
	# hide all not exported symbols and ignore warnings
	#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fvisibility=hidden -Wall")
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")

elseif(MSVC)
		# enable multi-core complication with MSVC
		add_definitions(/MP)
endif()


#
#set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -g")
#set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall -O2")



include_directories(include)
#6356969216
#6413750016
#6363976192
#2897997056
#42068848896
#39848390912
#

ADD_LIBRARY(hpm src/matrix.c)
SET_TARGET_PROPERTIES(hpm PROPERTIES COMPILE_FLAGS "" )

ADD_LIBRARY(hpmavx2 src/avx2_matrix.c)
SET_TARGET_PROPERTIES(hpmavx2 PROPERTIES COMPILE_FLAGS "-mavx2" )

ADD_LIBRARY(hpmavx src/avx_matrix.c src/avx_vector.c)
SET_TARGET_PROPERTIES(hpmavx PROPERTIES COMPILE_FLAGS "-mavx" )

ADD_LIBRARY(hpmmmx src/mmx_matrix.c)
SET_TARGET_PROPERTIES(hpmmmx PROPERTIES COMPILE_FLAGS "-mmmx" )

ADD_LIBRARY(hpmsse src/sse_matrix.c src/sse_vector.c src/sse_quaternion.c)
SET_TARGET_PROPERTIES(hpmsse PROPERTIES COMPILE_FLAGS "-msse" )

ADD_LIBRARY(hpmsse2 src/sse_matrix.c)
SET_TARGET_PROPERTIES(hpmsse2 PROPERTIES COMPILE_FLAGS "-msse2" )

ADD_LIBRARY(hpmsse3 src/sse_matrix.c src/sse3_vector.c)
SET_TARGET_PROPERTIES(hpmsse3 PROPERTIES COMPILE_FLAGS "-msse3" )

ADD_LIBRARY(hpmsse41 src/sse_matrix.c)
SET_TARGET_PROPERTIES(hpmsse41 PROPERTIES COMPILE_FLAGS "-msse4" )

ADD_LIBRARY(hpmsse42 src/sse_matrix.c)
SET_TARGET_PROPERTIES(hpmsse42 PROPERTIES COMPILE_FLAGS "-msse4" )


if(__arm__)
	add_library(hpmneon src/neon_matrix.c)
	SET_TARGET_PROPERTIES(hpmneon PROPERTIES COMPILE_FLAGS "-mneon" )
endif()



# add the install targets
INSTALL (TARGETS hpm DESTINATION lib)
INSTALL (TARGETS hpmavx2 DESTINATION lib)
INSTALL (TARGETS hpmavx DESTINATION lib)
INSTALL (TARGETS hpmmmx DESTINATION lib)
INSTALL (TARGETS hpmsse DESTINATION lib)
INSTALL (TARGETS hpmsse2 DESTINATION lib)
INSTALL (TARGETS hpmsse3 DESTINATION lib)
INSTALL (TARGETS hpmsse41 DESTINATION lib)
INSTALL (TARGETS hpmsse42 DESTINATION lib)
if(__arm__)
INSTALL (TARGETS hpmneon DESTINATION lib)
endif()


file(GLOB includes include/*.h)
install (FILES ${includes} DESTINATION include/hpm)
