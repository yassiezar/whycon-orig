cmake_minimum_required(VERSION 3.10)
project(whycon)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(${PROJECT_SOURCE_DIR}/include/)

add_library(gsl SHARED IMPORTED )
set_target_properties(gsl PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/libs/libgsl.so )

add_library(gslcblas SHARED IMPORTED )
set_target_properties(gslcblas PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/libs/libgslcblas.so)

#set( Boost_INCLUDE_DIR ${BOOST_ROOT}/include )
#set(Boost_DEBUG 1)
set(BOOST_ROOT /usr/local)
set( Boost_INCLUDE_DIR ${BOOST_ROOT}/include )
set( Boost_LIBRARY_DIR ${BOOST_ROOT}/lib )
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# Build subdirs
add_subdirectory(src/common)
add_subdirectory(src/imageproc)

#add_library(whycon SHARED imageproc)
add_library(whycon SHARED $<TARGET_OBJECTS:common> $<TARGET_OBJECTS:imageproc>)

#target_link_libraries(whycon ${GSL_LIBRARIES})
target_link_libraries(whycon gsl gslcblas)

target_compile_options(whycon PRIVATE -Werror -Wall -Wextra -ggdb)