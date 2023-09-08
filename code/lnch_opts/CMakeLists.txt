cmake_minimum_required(VERSION 3.8)
project(lnch_opts)

add_executable(${PROJECT_NAME} main.cpp  lnch_opts.cpp lnch_opts.hpp ${SRC_FILES})

target_include_directories(${PROJECT_NAME}
                           PRIVATE ${PROJECT_ROOT}/code/asd_core/inc)
