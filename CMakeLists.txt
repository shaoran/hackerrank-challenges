
project(hackerrank-solutions C)

cmake_minimum_required(VERSION 2.6)

#set(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BUILD_DIR})

# https://blog.kitware.com/cmake-and-the-default-build-type/
set(default_build_type "Release")
if(EXISTS "${CMAKE_SOURCE_DIR}/.git")
  set(default_build_type "Debug")
endif()

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()


if(NOT THIS_IS_THE_FIRST_TIME)
	set(CMAKE_C_FLAGS "-Wall -Wwrite-strings ${CMAKE_C_FLAGS}" CACHE STRING "" FORCE)

	set(THIS_IS_THE_FIRST_TIME TRUE CACHE INTERNAL "" FORCE)
endif(NOT THIS_IS_THE_FIRST_TIME)

file(GLOB SUBDIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)


macro(createbin LIBS)
	file(GLOB C_SOURCES *.c)
	file(GLOB C_HEADERS *.h)

	get_filename_component(binfile ${CMAKE_CURRENT_SOURCE_DIR} NAME)

	add_executable(${binfile} ${C_SOURCES} ${C_HEADERS})
	set_target_properties(${binfile} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
	target_link_libraries(${binfile} ${LIBS})
endmacro()


foreach(subdir ${SUBDIRS})
	if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/CMakeLists.txt)
		message(STATUS adding ${subdir})
		add_subdirectory(${subdir})
	endif()
endforeach()
