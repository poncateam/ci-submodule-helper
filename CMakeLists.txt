cmake_minimum_required(VERSION 3.11)

project(Ponca-ci-submodule-helper)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set( PONCA_CONFIGURE_EXAMPLES CACHE BOOL OFF)
set( PONCA_CONFIGURE_TESTS    CACHE BOOL OFF)
set( PONCA_CONFIGURE_DOC      CACHE BOOL OFF)
add_subdirectory(ponca)

add_library(testlib SHARED testlib.cpp testlib.h)
target_link_libraries(testlib PUBLIC Ponca::Fitting)

include(GNUInstallDirs)

install(TARGETS testlib
        EXPORT testlibTarget
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

export(EXPORT testlibTarget
       FILE ${CMAKE_CURRENT_BINARY_DIR}/testlib.cmake)

add_executable(test main.cpp)
target_link_libraries(test testlib)

# Running with local eigen: EIGEN3_INCLUDE_DIRS is computed by Ponca
if(NOT Eigen3_FOUND)
    target_include_directories(testlib PUBLIC ${EIGEN3_INCLUDE_DIRS})
endif()
