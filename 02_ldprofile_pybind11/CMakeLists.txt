cmake_minimum_required( VERSION 3.8 )
project( libldprofile-pybind11 VERSION 1.0.0 )

include( GNUInstallDirs )
set( CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH} )

add_subdirectory( src )

