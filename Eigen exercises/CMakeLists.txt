cmake_minimum_required(VERSION 3.5)

project(Eigen_exercises LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Eigen_exercises main.cpp bmi_lib.h bmi_project.cpp)
