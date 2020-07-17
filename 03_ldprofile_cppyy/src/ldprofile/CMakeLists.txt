set( LDPROFILE_HEADERS
     ldprofile.h definitions.h base_profile.h ld_coasting.h ld_qgauss.h
     ld_lin_interpol.h qgauss.h )

set( LDPROFILE_SOURCES
     base_profile.cpp ld_coasting.cpp ld_qgauss.cpp ld_lin_interpol.cpp
     qgauss.cpp )

add_library( ldprofilecore SHARED ${LDPROFILE_HEADERS} ${LDPROFILE_SOURCES} )

target_include_directories(
    ldprofilecore
    PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>
    PUBLIC $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLULDEDIR}> )

set_target_properties( ldprofilecore PROPERTIES
    LINKER_LANGUAGE CXX POSITION_INDEPENDENT_CODE ON CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    LINK_WHAT_YOU_USE TRUE )

