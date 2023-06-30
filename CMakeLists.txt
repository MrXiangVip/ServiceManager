cmake_minimum_required(VERSION 3.15)
project(servicemanager)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++11 -pthread")

set(ManagerSources ServiceManager.cpp main.cpp ProcessState.cpp Static.cpp RefBase.cpp Looper.cpp)
add_executable(servicemanager ${ManagerSources})



set(InstalldSources installd/installd.cpp installd/InstalldNativeService.cpp  IServiceManager.cpp ServiceManager.cpp)
add_executable(installd ${InstalldSources})



set(HelloSources Hello/HelloServer.cpp Hello/BnHelloService.cpp Hello/BpHelloService.cpp ProcessState.cpp IPCThreadState.cpp IServiceManager.cpp Static.cpp RefBase.cpp ServiceManager.cpp)
add_executable( helloServer ${HelloSources})
