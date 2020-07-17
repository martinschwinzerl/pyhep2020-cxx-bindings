# Build core C/C++ library
add_subdirectory( ldprofile )

# ------------------------------------------------------------------------------
# Python Bindings

if( SKBUILD )
    find_package( PythonInterp 3.6 REQUIRED )
    find_package( PythonLibs 3.6 REQUIRED )
    find_package( PythonExtensions REQUIRED )

    # ------------------------------------------------------------------------------
    # Find or download and setup pybind11

    include( SetupPybind11 )
    add_subdirectory( wrap )

endif()

