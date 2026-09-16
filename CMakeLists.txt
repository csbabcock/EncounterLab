cmake_minimum_required(VERSION 4.3)
project(EncounterLab)

set(CMAKE_CXX_STANDARD 20)

add_executable(EncounterLab main.cpp)

target_link_options(EncounterLab PRIVATE -static-libgcc -static-libstdc++)