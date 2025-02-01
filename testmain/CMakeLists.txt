cmake_minimum_required(VERSION 3.10)

set(PACKAGE_NAME atm_tester)

project(${PACKAGE_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ATM_INCLUDE_DIR ../ATMController/include)
MESSAGE("Linking atm headers in: " ${ATM_INCLUDE_DIR})
include_directories(
    ${ATM_INCLUDE_DIR}
)

MESSAGE("Generating executable.")
add_executable(${PACKAGE_NAME} ./main.cpp)

MESSAGE("Linking atm library")
target_link_libraries(${PACKAGE_NAME} 
${PROJECT_SOURCE_DIR}/lib/libatm_controller.so
)