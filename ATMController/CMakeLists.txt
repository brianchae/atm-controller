cmake_minimum_required(VERSION 3.10)

set(PACKAGE_NAME atm_controller)

project(${PACKAGE_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

MESSAGE("Including Directories in: " ${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)

set(LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
MESSAGE("Setting lib output to: " ${LIB_DIR})

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
MESSAGE("Including source codes in: " ${PROJECT_SOURCE_DIR})
add_library(${PROJECT_NAME} SHARED
${SRC_DIR}/ATMController.cpp
${SRC_DIR}/AccountFinder/AccountFinder.cpp
${SRC_DIR}/CardReader/CardReader.cpp
${SRC_DIR}/PINIdentificator/PINIdentificator.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LIB_DIR})