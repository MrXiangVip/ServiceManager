cmake_minimum_required(VERSION 3.15)
project(servicemanager)

set(CMAKE_CXX_STANDARD 14)
set(SOURCES ServiceManager.cpp main.cpp)
add_executable(servicemanager ${SOURCES})