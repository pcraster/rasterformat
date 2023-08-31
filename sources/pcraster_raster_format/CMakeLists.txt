add_library(pcraster_raster_format STATIC
    _getcell.c
    _getrow.c
    _gsomece.c
    _putcell.c
    _rputrow.c
    angle.c
    file.c
    attravai.c
    attrsize.c
    cellsize.c
    create2.c
    csfglob.c
    csfsup.c
    delattr.c
    dumconv.c
    endian.c
    filename.c
    gattrblk.c
    gattridx.c
    gcellrep.c
    gdattype.c
    getattr.c
    getx0.c
    gety0.c
    ggisfid.c
    gmaxval.c
    gminval.c
    gnrcols.c
    gnrrows.c
    gproj.c
    gputproj.c
    gvalscal.c
    gvartype.c
    gversion.c
    ismv.c
    kernlcsf.c
    legend.c
    mclose.c
    mopen.c
    moreattr.c
    mperror.c
    pgisfid.c
    pmaxval.c
    pminval.c
    putallmv.c
    putattr.c
    putsomec.c
    putx0.c
    puty0.c
    pvalscal.c
    rattrblk.c
    rcomp.c
    rcoords.c
    rdup2.c
    reseterr.c
    rextend.c
    rmalloc.c
    rrowcol.c
    ruseas.c
    setangle.c
    setmv.c
    setvtmv.c
    strconst.c
    strpad.c
    swapio.c
    trackmm.c
    vs2.c
    vsdef.c
    vsis.c
    vsvers.c
    wattrblk.c
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
        "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wall;-Wextra>"
)
