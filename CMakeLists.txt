cmake_minimum_required(VERSION 3.7)

if(POLICY CMP0069)
  cmake_policy(SET CMP0069 NEW)
endif()

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

project(RasterFormat)

add_subdirectory(sources)
