cmake_minimum_required(VERSION 3.11)

project(Ponca-ci-submodule-helper)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set( PONCA_CONFIGURE_EXAMPLES CACHE BOOL OFF)
set( PONCA_CONFIGURE_TESTS    CACHE BOOL OFF)
set( PONCA_CONFIGURE_DOC      CACHE BOOL OFF)
add_subdirectory(ponca)

add_executable(test main.cpp)
target_link_libraries(test Ponca::Fitting)

# Running with local eigen: EIGEN3_INCLUDE_DIRS is computed by Ponca
if(NOT Eigen3_FOUND)
    target_include_directories(test PRIVATE ${EIGEN3_INCLUDE_DIRS})
endif()
