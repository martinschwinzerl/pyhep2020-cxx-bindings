cmake_minimum_required( VERSION 3.8 )
project( libldprofile-ctypes
         VERSION 1.0.0
         LANGUAGES CXX C
         DESCRIPTION "python bindings for ldprofile demo library using ctypes" )

# ------------------------------------------------------------------------------
# define headers and sources

set( LDPROFILE_HEADERS src/ldprofile/ldprofile.h src/ldprofile/definitions.h
     src/ldprofile/base_profile.h src/ldprofile/ld_coasting.h
     src/ldprofile/ld_qgauss.h src/ldprofile/ld_lin_interpol.h
     src/ldprofile/qgauss.h )

set( LDPROFILE_SOURCES src/ldprofile/base_profile.cpp
     src/ldprofile/ld_coasting.cpp src/ldprofile/ld_qgauss.cpp
     src/ldprofile/ld_lin_interpol.cpp src/ldprofile/qgauss.cpp )

# ------------------------------------------------------------------------------
# build library

if( SKBUILD )
    find_package( PythonInterp 3.6 REQUIRED )
    find_package( PythonLibs 3.6 REQUIRED )
    find_package( PythonExtensions REQUIRED )

    add_library( ldprofile MODULE
        ${LDPROFILE_HEADERS} ${LDPROFILE_SOURCES} )
else()
    add_library( ldprofile SHARED
        ${LDPROFILE_HEADERS} ${LDPROFILE_SOURCES} )
endif()

target_include_directories( ldprofile
    PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src> )

set_target_properties( ldprofile PROPERTIES
    LINKER_LANGUAGE C POSITION_INDEPENDENT_CODE ON CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON )

if( NOT SKBUILD )
    target_include_directories( ldprofile
        PUBLIC $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}> )
endif()

# ------------------------------------------------------------------------------
# handle installation

install( TARGETS ldprofile LIBRARY DESTINATION "ldprofile_ctypes" )
