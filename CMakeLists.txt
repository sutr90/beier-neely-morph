cmake_minimum_required(VERSION 3.3)
project(morph)

include_directories(D:\\dev\\dlib-18.17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp GetTimeMs.h morph_image.cpp morph_image.h morph_dlib.cpp morph_dlib.h)
add_executable(morph ${SOURCE_FILES})
target_link_libraries(morph D:/dev/dlib-18.17/dlib/libdlib.a)