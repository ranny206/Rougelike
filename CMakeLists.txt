cmake_minimum_required(VERSION 3.15)
project(Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Game main.cpp Me.cpp Me.h GameObject.cpp GameObject.h Character.cpp Character.h Map.cpp Map.h Enemy.cpp Enemy.h Holiday.cpp Holiday.h Wall.cpp Wall.h Screen.cpp Screen.h Medicine.cpp Medicine.h Enum.h Direction.h)