project(Ponca-ci-submodule-helper)
CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Eigen3 QUIET)

add_subdirectory(ponca)

add_executable(test main.cpp)
target_link_libraries(test Ponca::Fitting)

# Running with local eigen: EIGEN3_INCLUDE_DIRS is computed by Ponca
if(NOT Eigen3_FOUND)
    target_include_directories(test PRIVATE ${EIGEN3_INCLUDE_DIRS})
endif()
