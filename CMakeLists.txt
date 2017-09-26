cmake_minimum_required(VERSION 3.6)

option(BUILD_SHARED_LIBS "Build Shared Libraries" OFF)
set(LIB_TYPE STATIC)
if(BUILD_SHARED_LIBS)
  set(LIB_TYPE SHARED)
endif(BUILD_SHARED_LIBS)

set(CMAKE_CXX_STANDARD 11)

project(yaml_parser)

file(GLOB HEADER "include/*.hpp")
file(GLOB SRC src/*.cpp)

include_directories(include/)
find_path(YAML_CPP_INCLUDE yaml-cpp/yaml.h)
include_directories(${YAML_CPP_INCLUDE})

add_library(yaml_parser ${LIB_TYPE} ${SRC})

# Test
enable_testing()
add_executable(test1 test/test1.cpp)
find_library(YAML_CPP_LIB yaml-cpp)
target_link_libraries(test1 yaml_parser ${YAML_CPP_LIB})
add_test(NAME test1 COMMAND test1)

# Install
set_target_properties(
	yaml_parser
	PROPERTIES
	PUBLIC_HEADER "${HEADER}"
)
install(
	TARGETS yaml_parser
	LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
	ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include
)

