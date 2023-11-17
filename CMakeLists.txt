# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

project(cpp-datalab)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_library(cpp-datalab src/matrix.cpp)

add_executable(example examples/main.cpp)
target_link_libraries(example cpp-datalab)
