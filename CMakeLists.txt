project(Ponca-ci-submodule-helper)
CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(ponca)

add_executable(test main.cpp)
target_link_libraries(test Ponca::Fitting)