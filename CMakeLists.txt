cmake_minimum_required(VERSION 3.3)
project(Jakub_CS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic")

set(SOURCE_FILES main.cpp Grid.cpp header.h RobotData.cpp Maths.cpp)
add_executable(Jakub_CS ${SOURCE_FILES})