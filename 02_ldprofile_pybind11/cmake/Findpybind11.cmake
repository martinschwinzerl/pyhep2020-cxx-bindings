# (C) 2020 - Martin Schwinzerl, CERN
# Released under the terms of the MIT license
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

#[=======================================================================[.rst:
Findpybind11
-------

Finds the pybind11 library.

Imported Targets
^^^^^^^^^^^^^^^^

This module provides the following imported targets, if found:

``pybind11::pybind11``
  The (header-only) pybind11 library

Result Variables
^^^^^^^^^^^^^^^^

This will define the following variables:

``pybind11_FOUND``
  True if the system has the Foo library.
``pybind11_VERSION``
  The version of the Foo library which was found.
``pybind11_INCLUDE_DIRS``
  Include directories needed to use Foo.

Cache Variables
^^^^^^^^^^^^^^^

The following cache variables may also be set:

``pybind11_INCLUDE_DIR``
  The directory containing ``pybind11/pybind11.h``.

#]=======================================================================]

include( FindPackageHandleStandardArgs )

if( NOT pybind11_DIR )
    set( pybind11_DIR "$ENV{pybind11_DIR}" )
endif()

find_path( pybind11_INCLUDE_DIR pybind11/pybind11.h HINTS ${pybind11_DIR} )
find_package_handle_standard_args( pybind11 DEFAULT_MSG pybind11_DIR )

if( pybind11_FOUND )
    mark_as_advanced( pybind11_INCLUDE_DIR )

    if( NOT TARGET pybind11 )
        add_library( pybind11 INTERFACE IMPORTED )
        set_target_properties( pybind11 PROPERTIES
            INTERFACE_INCLUDE_DIRECTORIES ${pybind11_INCLUDE_DIR} )
    endif()
endif()
