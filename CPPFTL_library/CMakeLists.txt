cmake_minimum_required (VERSION 3.16)
project(CPPFTL_library VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

include(FetchContent)

file(GLOB_RECURSE  CPPFTL_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/*.c
     )
    



add_library(CPPFTL_Library ${CPPFTL_SOURCE_FILES})
target_include_directories(CPPFTL_Library  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)
target_include_directories(CPPFTL_Library  PUBLIC ${EXTRA_HEADER_DIRS})
target_link_libraries(CPPFTL_Library ${EXTRA_LIBS})
