cmake_minimum_required(VERSION 3.8)
project(asd_app CXX)

add_executable(${PROJECT_NAME} main.cpp ${SRC_FILES})

target_include_directories(${PROJECT_NAME}
                           PRIVATE ${PROJECT_ROOT}/code/asd_core/inc)

target_link_libraries(${PROJECT_NAME} asd_core)
