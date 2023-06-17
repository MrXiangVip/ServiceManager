cmake_minimum_required(VERSION 3.15)
project(servicemanager)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCES ServiceManager.cpp main.cpp ProcessState.cpp Static.cpp RefBase.cpp Looper.cpp)
add_executable(servicemanager ${SOURCES})