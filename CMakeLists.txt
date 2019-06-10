cmake_minimum_required(VERSION 3.10)
project(whycon)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#set(CMAKE_VERBOSE_MAKEFILE ON)

# Build subdirs
add_subdirectory(src/common)
add_subdirectory(src/imageproc)

#add_library(whycon SHARED imageproc)
add_library(whycon SHARED $<TARGET_OBJECTS:common> $<TARGET_OBJECTS:imageproc>)

target_compile_options(whycon PRIVATE -Werror -Wall -Wextra -ggdb)