cmake_minimum_required(VERSION 3.22)
project(mahjong-cpp, VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(mahjong-cpp
    src/hand.cpp
    src/tile.cpp
    src/wall.cpp
    src/player.cpp
    src/game.cpp
)
add_executable(a.out main.cpp)
target_link_libraries(a.out mahjong-cpp)
