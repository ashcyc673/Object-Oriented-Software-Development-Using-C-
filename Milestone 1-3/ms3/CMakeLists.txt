cmake_minimum_required(VERSION 3.15)
project(ms1)

set(CMAKE_CXX_STANDARD 17)

#enable_testing()
#add_executable(ms1 Station.cpp Station.h Utilities.cpp Utilities.h CustomerOrder.cpp CustomerOrder.h Workstation.h Workstation.cpp LineManager.h LineManager.cpp Tests/test_main.cpp Tests/Line_Manager_tests.cpp)
#add_test(Project_Tests ms1)

add_executable(ms1 ms3.cpp Station.cpp Station.h Utilities.cpp Utilities.h CustomerOrder.cpp CustomerOrder.h Workstation.cpp Workstation.h LineManager.cpp LineManager.h)