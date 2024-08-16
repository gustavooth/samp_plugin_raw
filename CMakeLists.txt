cmake_minimum_required(VERSION 3.29)

project(myplugin C)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_STANDARD 23)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_C_COMPILER clang)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")

file(GLOB_RECURSE SOURCE "src/*.c")

include_directories(
    ${CMAKE_SOURCE_DIR}/src/
    ${CMAKE_SOURCE_DIR}/inc/
    /usr/include
)

add_definitions(
    -DLINUX
)

add_library(myplugin SHARED ${SOURCE})

add_subdirectory(inc/amx)
add_subdirectory(inc/invoke)

target_link_Libraries(myplugin amx invoke)
