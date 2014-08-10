project(play-pixel)
cmake_minimum_required(VERSION 2.8)

aux_source_directory(. SRC_LIST)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O3 -Wall -fPIE")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -std=c++11")
set(CMAKE_CXX_DEBUG_FLAGS "${CMAKE_CXX_DEBUG_FLAGS} ${CMAKE_CXX_FLAGS} -O0 -ggdb")
set(CMAKE_CXX_RELEASE_FLAGS "${CMAKE_CXX_RELEASE_FLAGS} ${CMAKE_CXX_FLAGS} -O3 -flto -DNDEBUG")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

add_executable(${PROJECT_NAME} ${SRC_LIST})
