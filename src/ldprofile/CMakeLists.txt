set( LDPROFILE_HEADERS
     definitions.h
     base_profile.hpp
     ld_coasting.h
     ld_qgauss.h
     ld_lin_interpol.h
     qgauss.h
)

set( LDPROFILE_SOURCES
     base_profile.cpp
     ld_coasting.cpp
     ld_qgauss.cpp
     ld_lin_interpol.cpp
     qgauss.cpp
)

add_library( ldprofile SHARED
    ${LDPROFILE_HEADERS} ${LDPROFILE_SOURCES} )

target_include_directories( ldprofile
    PUBLIC $<INSTALL_INTERFACE:include>
    PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}> )

set_target_properties( ldprofile PROPERTIES
    LINKER_LANGUAGE C POSITION_INDEPENDENT_CODE ON CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON )
