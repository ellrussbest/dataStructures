add_library(libstack STATIC stack.cpp)
target_include_directories(libstack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
set_target_properties(libstack PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)