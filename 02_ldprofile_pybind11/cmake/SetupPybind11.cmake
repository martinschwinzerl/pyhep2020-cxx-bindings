if( NOT LDPROFILE_CMAKE_SETUP_PYBIND11_FINISHED )
   set( LDPROFILE_CMAKE_SETUP_PYBIND11_FINISHED 1 )

    find_package( pybind11 QUIET )

    if( NOT pybind11_FOUND )
        set( EXT_PYBIND11_IN_DIR "${CMAKE_SOURCE_DIR}/cmake/" )
        set( EXT_PYBIND11_TMPL "" )

        set( EXT_PYBIND11_IN_FILE
             "${CMAKE_SOURCE_DIR}/cmake/SetupPybind11CMakeLists.txt.in" )

        set( EXT_PYBIND11_OUT_DIR "${CMAKE_BINARY_DIR}/ext_pybind11" )
        set( EXT_PYBIND11_INSTALL_DIR "${EXT_PYBIND11_OUT_DIR}/install/" )
        set( EXT_PYBIND11_OUT "${EXT_PYBIND11_OUT_DIR}/CMakeLists.txt"  )

        configure_file( ${EXT_PYBIND11_IN_FILE} ${EXT_PYBIND11_OUT} @ONLY )
        message( STATUS "Attempting to download and build pybind11 ... " )

        execute_process(
            COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
            RESULT_VARIABLE result
            WORKING_DIRECTORY ${EXT_PYBIND11_OUT_DIR} )

        if( NOT result )
            message( STATUS "Successfully run cmake for external pybind11" )
        else()
            message( FATAL_ERROR "cmake for ext. pybind11 failed: ${result}" )
        endif()

        execute_process(
            COMMAND ${CMAKE_COMMAND} --build .
            RESULT_VARIABLE result
            WORKING_DIRECTORY ${EXT_PYBIND11_OUT_DIR} )

        if( NOT result )
            message( STATUS
                "Successfully completed building external pybind11" )
        else()
            message( FATAL_ERROR
                "Building for ext. pybind11 failed: ${result}" )
        endif()

        set( pybind11_DIR ${EXT_PYBIND11_INSTALL_DIR}/share/cmake/pybind11 )
        find_package( pybind11 REQUIRED CONFIG )
    else()
        message( STATUS "Found existing pybind11 ${pybind11_VERSION}" )
    endif()
endif()
