if( NOT pybind11_FOUND )
    message( FATAL_ERROR "We positively need pybind11 for the bindings to work!" )
endif()

set( LDPROFILE_PYBIND11_HEADERS ldprofile_wrap.hpp )
set( LDPROFILE_PYBIND11_SOURCES ldprofile_wrap.cpp )

pybind11_add_module( ldprofile_pybind11 MODULE
    ${LDPROFILE_PYBIND11_HEADERS} ${LDPROFILE_PYBIND11_SOURCES} )

# include paths, definitions, etc. should be passed on transitiently from
# ldprofilecore:

target_link_libraries( ldprofile_pybind11 PRIVATE ldprofilecore )

file( COPY "${CMAKE_CURRENT_SOURCE_DIR}/__init__.py"
      DESTINATION ${CMAKE_CURRENT_BINARY_DIR} )

install( TARGETS ldprofile_pybind11 DESTINATION "ldprofile_pybind11" )
install( FILES __init__.py DESTINATION "ldprofile_pybind11" )
