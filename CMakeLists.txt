cmake_minimum_required(VERSION 3.6)

option(BUILD_SHARED_LIBS "Build Shared Libraries" OFF)
set(LIB_TYPE STATIC)
if(BUILD_SHARED_LIBS)
  set(LIB_TYPE SHARED)
endif(BUILD_SHARED_LIBS)

set(CMAKE_CXX_STANDARD 11)

set(YAML_CPP_INCLUDE_DIR "" CACHE STRING "Include directory for yaml-cpp")
set(YAML_CPP_LIB_DIR "" CACHE STRING "Library directory for yaml-cpp")

project(yaml_parser)

include_directories(include/)
include_directories(${YAML_CPP_INCLUDE_DIR})

file(GLOB SRC src/*.cpp)
add_library(yaml_parser ${LIB_TYPE} ${SRC})

# Test
enable_testing()
add_executable(test1 test/test1.cpp)
find_library(YAML_CPP_LIB yaml-cpp ${YAML_CPP_LIB_DIR})
target_link_libraries(test1 yaml_parser ${YAML_CPP_LIB})
add_test(NAME test1 COMMAND test1)
