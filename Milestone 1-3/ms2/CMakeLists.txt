cmake_minimum_required(VERSION 3.15)
project(ms1)

set(CMAKE_CXX_STANDARD 17)

#enable_testing()
#add_executable(ms1 Tests/CustomerOrder_tests.cpp Station.cpp Station.h Utilities.cpp Utilities.h CustomerOrder.cpp CustomerOrder.h Tests/test_main.cpp)
#add_test(Project_Tests ms1)

add_executable(ms1 ms2.cpp Station.cpp Station.h Utilities.cpp Utilities.h CustomerOrder.cpp CustomerOrder.h)