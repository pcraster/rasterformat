CMAKE_MINIMUM_REQUIRED(VERSION 2.8.9)
PROJECT(RasterFormat)

IF(DEFINED ENV{PCRTEAM_EXTERN})
    # Assume PCRaster devevelopment environment is configured.
    SET(CMAKE_MODULE_PATH "$ENV{CMAKE_MODULE_PATH}")
    INCLUDE(Site)
    PCR_SET_PROJECT_VERSIONS("1" "4" "0")
ELSE()
    # Assume we are used by external projects.
    IF(WIN32)
        SET(CMAKE_DEBUG_POSTFIX "d")
    ENDIF()
ENDIF()

ADD_CUSTOM_TARGET(tests ALL)
ADD_SUBDIRECTORY(documentation)
ADD_SUBDIRECTORY(sources)
