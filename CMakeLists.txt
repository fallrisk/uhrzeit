cmake_minimum_required(VERSION 3.10)
project(uhrzeit)

set(CMAKE_CXX_STANDARD 11)

add_executable(uhrzeit main.cpp)

install(TARGETS uhrzeit RUNTIME DESTINATION bin)
