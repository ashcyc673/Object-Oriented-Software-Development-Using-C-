cmake_minimum_required(VERSION 3.15)
project(w4)

set(CMAKE_CXX_STANDARD 17)

add_executable(w4 w4_p2.cpp Reservation.cpp Reservation.h Restaurant.cpp Restaurant.h ConfirmationSender.cpp ConfirmationSender.h)