cmake_minimum_required(VERSION 3.8)
project(asd_core)

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/inc)

file(GLOB_RECURSE SRC_FILES *.cpp *.hpp)
add_library(${PROJECT_NAME} STATIC ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})
