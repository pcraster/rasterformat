cmake_minimum_required(VERSION 2.8.9)

if(POLICY CMP0069)
  cmake_policy(SET CMP0069 NEW)
endif()

project(RasterFormat)

add_subdirectory(sources)
