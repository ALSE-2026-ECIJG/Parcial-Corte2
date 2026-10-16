cmake_minimum_required(VERSION 3.12)
project(ParcialCorte2)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)


add_executable(ParcialCorte2
    src/main.cpp
    src/PanelSolar.cpp
    include/PanelSolar.h
)
