cmake_minimum_required(VERSION 3.6)
project(con64)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Board.cpp Board.h Player.cpp Player.h HumanPlayer.cpp HumanPlayer.h)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
add_executable(con64 ${SOURCE_FILES})