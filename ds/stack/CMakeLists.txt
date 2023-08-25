cmake_minimum_required(VERSION 3.6.0)
project(stack_lib CXX)

file (GLOB_RECURSE SRC_FILES "*.cpp")
file (GLOB_RECURSE HDR_FILES "*.hpp")

add_library(stack STATIC ${SRC_FILES} ${HDR_FILES})
target_include_directories(stack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(stack PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)