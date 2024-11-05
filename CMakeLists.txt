cmake_minimum_required(VERSION 3.10)
project(GameboyEmulator VERSION 0.1.0 LANGUAGES C CXX)

add_executable(GameboyEmulator src/main.cpp src/cpu.cpp)
target_include_directories(GameboyEmulator PRIVATE include)
