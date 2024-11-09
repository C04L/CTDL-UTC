cmake_minimum_required(VERSION 3.29)
project(baitaplon2vector)

set(CMAKE_CXX_STANDARD 20)

add_executable(baitaplon2vector main.cpp
        MyVector.cpp
        SoLon.cpp)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc --static")