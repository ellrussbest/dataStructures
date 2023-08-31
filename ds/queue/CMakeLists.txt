cmake_minimum_required(VERSION 3.6.0)
project(queue_lib CXX)

# file (GLOB_RECURSE SRC_FILES "*.cpp")
file (GLOB_RECURSE HDR_FILES "*.hpp")
message(${HDR_FILES})

add_library(queue INTERFACE ${HDR_FILES})
target_include_directories(queue INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(queue PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(queue PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)