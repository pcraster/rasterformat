add_library(pcraster_raster_format STATIC
    _getcell
    _getrow
    _gsomece
    _putcell
    _rputrow
    angle
    attravai
    attrsize
    cellsize
    create2
    csfglob
    csfsup
    delattr
    dumconv
    endian
    file
    filename
    gattrblk
    gattridx
    gcellrep
    gdattype
    getattr
    getx0
    gety0
    ggisfid
    gmaxval
    gminval
    gnrcols
    gnrrows
    gproj
    gputproj
    gvalscal
    gvartype
    gversion
    ismv
    kernlcsf
    legend
    mclose
    mopen
    moreattr
    mperror
    pgisfid
    pmaxval
    pminval
    putallmv
    putattr
    putsomec
    putx0
    puty0
    pvalscal
    rattrblk
    rcomp
    rcoords
    rdup2
    reseterr
    rextend
    rmalloc
    rrowcol
    ruseas
    setangle
    setmv
    setvtmv
    strconst
    strpad
    swapio
    trackmm
    vs2
    vsdef
    vsis
    vsvers
    wattrblk
)

add_library(pcraster::raster_format ALIAS pcraster_raster_format)

target_include_directories(pcraster_raster_format
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

install(
    TARGETS
        pcraster_raster_format
    EXPORT
        pcraster_raster_format_targets
    ARCHIVE
        DESTINATION
            lib
)

install(
    DIRECTORY 
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)

set_target_properties(pcraster_raster_format PROPERTIES
    DEBUG_POSTFIX d
)

# For this target only, increase the warning level to match GDAL's
target_compile_options(pcraster_raster_format
    PRIVATE
        $<$<C_COMPILER_ID:GNU>:-Wdeclaration-after-statement -ansi>
)
