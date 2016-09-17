cmake_minimum_required(VERSION 3.5)
project(Chess)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Piece.cpp Piece.h Board.cpp Board.h)
add_executable(Chess ${SOURCE_FILES})