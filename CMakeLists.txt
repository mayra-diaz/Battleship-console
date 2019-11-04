cmake_minimum_required(VERSION 3.15)
project(POO_I)

set(CMAKE_CXX_STANDARD 17)

add_executable(POO_I main.cpp CNavy.h CNavy.cpp CBoard.h Types-Random.h
        CWeapon.h IOfunctions.h IOfunctions.cpp CSquare.h CBoard.cpp CGame.cpp CGame.h CPlayer.h CPlayer.cpp)

