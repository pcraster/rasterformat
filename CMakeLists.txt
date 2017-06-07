cmake_minimum_required(VERSION 2.8.9)
project(RasterFormat)

if(WIN32)
    SET(CMAKE_DEBUG_POSTFIX "d")
endif()

add_subdirectory(sources)
