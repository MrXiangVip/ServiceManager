cmake_minimum_required(VERSION 3.15)
project(servicemanager)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++11 -pthread")

set(ServiceSources ServiceManager/ServiceManager.cpp ServiceManager/main.cpp binder/ProcessState.cpp binder/Static.cpp binder/RefBase.cpp ServiceManager/Looper.cpp)
add_executable(servicemanager ${ServiceSources})


set(InstalldSources installd/installd.cpp installd/InstalldNativeService.cpp binder/IServiceManager.cpp ServiceManager/ServiceManager.cpp)
add_executable(installd ${InstalldSources})



set(HelloSources Hello/HelloServer.cpp Hello/BnHelloService.cpp Hello/BpHelloService.cpp binder/ProcessState.cpp binder/IPCThreadState.cpp binder/IServiceManager.cpp binder/Static.cpp binder/RefBase.cpp ServiceManager/ServiceManager.cpp)
add_executable( helloServer ${HelloSources})
