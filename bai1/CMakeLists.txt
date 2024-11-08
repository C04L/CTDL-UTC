cmake_minimum_required(VERSION 3.29)
project(baitaplon)

set(CMAKE_CXX_STANDARD 20)

add_executable(baitaplon appConfig.cpp
        sinhvien.cpp
        main.cpp)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc --static")