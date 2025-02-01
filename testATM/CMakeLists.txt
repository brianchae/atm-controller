cmake_minimum_required(VERSION 3.10)

set(PACKAGE_NAME atm_control_tester)

project(${PACKAGE_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PACKAGE_NAME} ./testmain/main.cpp)