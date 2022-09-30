cmake_minimum_required (VERSION 3.16)
project(CPPFTL VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(CPPFTL_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(CPPFTL_HEADER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/headers")
set(CPPFTL_EXPORT_HEADER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/export_headers")

# add header files from headers directory

file(GLOB_RECURSE  CPPFTL_SOURCE_FILES
     "${CPPFTL_SOURCE_DIR}/*.cpp"
     "${CPPFTL_HEADER_DIR}/*.h"
      "${CPPFTL_EXPORT_HEADER_DIR}/*.h"
     "${CPPFTL_SOURCE_DIR}/*.c"
     )

add_subdirectory(CPPFTL_Library)
list(APPEND EXTRA_LIBS CPPFTL_Library)


add_executable(CPPFTL ${CPPFTL_SOURCE_FILES})
target_include_directories(CPPFTL PUBLIC ${CPPFTL_HEADER_DIR})
target_include_directories(CPPFTL PUBLIC ${CPPFTL_EXPORT_HEADER_DIR})
target_link_libraries(CPPFTL PUBLIC ${EXTRA_LIBS})
target_include_directories(CPPFTL PUBLIC ${PROJECT_BINARY_DIR}/headers)
target_include_directories(CPPFTL PUBLIC ${PROJECT_BINARY_DIR}/export_header)
