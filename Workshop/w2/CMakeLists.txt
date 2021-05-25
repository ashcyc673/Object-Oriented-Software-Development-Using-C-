cmake_minimum_required(VERSION 3.15)
project(w2)

set(CMAKE_CXX_STANDARD 17)

add_executable(w2 main.cpp RecordSet.cpp TimedEvents.cpp RecordSet.h TimedEvents.h)