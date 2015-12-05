
cmake_minimum_required(VERSION 2.8)
project(hpm)


#	build shared/dynamic library option
option(BUILD_SHARED_LIBS "Build package with shared libraries." ON)
if(NOT BUILD_SHARED_LIBS)
	set(CMAKE_EXE_LINKER_FLAGS "-static")
	set(LINK_SEARCH_START_STATIC TRUE)
endif()









if((CMAKE_COMPILER_IS_GNUCC) AND NOT CMAKE_COMPILER_IS_MINGOW)
	if(BUILD_SHARED_LIBS AND CMAKE_SIZEOF_VOID_P EQUAL 4)
		add_definitions(-fPIC)
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
	endif()

	add_definitions(-fvisibility=hidden -Wall)
	# hide all not exported symbols and ignore warnings
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fvisibility=hidden -Wall")

elseif(MSVC)
		# enable multi-core complication with MSVC
		add_definitions(/MP)
endif()






include_directories(include)



#
add_library(hpmavx2 src/avx2_matrix.c)
add_library(hpmavx src/avx_matrix.c)
add_library(hpmmmx src/mmx_matrix.c)
add_library(hpmsee src/sse_matrix.c)
add_library(hpm src/matrix.c)

# add the install targets
install (TARGETS hpmavx2 DESTINATION lib)
install (TARGETS hpmavx DESTINATION lib)
install (TARGETS hpmmmx DESTINATION lib)
install (TARGETS hpmsee DESTINATION lib)
install (TARGETS hpm DESTINATION lib)

file(GLOB includes include/*.h)
install (FILES ${includes} DESTINATION include/hpm)
