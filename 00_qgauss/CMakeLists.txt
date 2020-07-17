cmake_minimum_required( VERSION 3.8 )

project( qgauss-c99 VERSION "1.0.0" LANGUAGES C
    DESCRIPTION "minimal c99 library for calculating q-gaussian distributions" )

set( QGAUSS_HEADERS src/definitions.h src/qgauss.h )
set( QGAUSS_SOURCES src/qgauss.c )

add_library( qgauss SHARED ${QGAUSS_HEADERS} ${QGAUSS_SOURCES} )

target_include_directories(
    qgauss PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src> )

set_target_properties( qgauss PROPERTIES
    LINKER_LANGUAGE C
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 99
    C_STANDARD_REQUIRED ON )
