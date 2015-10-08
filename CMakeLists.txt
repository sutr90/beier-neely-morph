cmake_minimum_required(VERSION 3.3)
project(morph)

include_directories(~/dev/dlib-18.17/)

if (UNIX)
    include_directories(~/dev/dlib-18.17/)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DDLIB_PNG_SUPPORT")
endif (UNIX)

if (WIN32)
    include_directories(D:\\dev\\dlib-18.17)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif(WIN32)

set(SOURCE_FILES main.cpp GetTimeMs.h morph_dlib.cpp morph_dlib.h)
add_executable(morph ${SOURCE_FILES})
target_link_libraries(morph ${PROJECT_SOURCE_DIR}/libdlib.a png)