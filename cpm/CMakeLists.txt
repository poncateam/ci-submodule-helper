cmake_minimum_required(VERSION 3.11)

project(Ponca-ci-submodule-helper-cpm)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CPM/cmake/CPM.cmake)
set(PONCA_REPOSITORY "poncateam/ponca#master" CACHE STRING "Ponca repository")
CPMAddPackage("gh:${PONCA_REPOSITORY}")

add_library(testlib STATIC ../testlib.cpp ../testlib.h)
target_link_libraries(testlib PUBLIC Ponca::Fitting)

add_executable(test ../main.cpp)
target_link_libraries(test PRIVATE testlib)
