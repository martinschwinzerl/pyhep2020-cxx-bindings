from skbuild import setup
import sys

def _get_library_name(fname='*', prefix=None):
    lname = fname if prefix is None else prefix + fname
    cmp_str = sys.platform
    if cmp_str.startswith( 'win32' ):
        lname += '.dll'
    elif cmp_str.startswith( 'darwin' ):
        lname += '.dylib'
    elif cmp_str.startswith( 'linux' ):
        lname += '.so'
    else:
        lname = None
        raise Exception( f'unknown sys.platform: {cmp_str}' )

    return lname


setup(
    name="ldprofile_pybind11",
    version="1.0.0",
    description="python bindings for ldprofile, using scikit-build and pybind11",
    author="Martin Schwinzerl",
    license="MIT",
    packages=['ldprofile_pybind11'],
    package_data={'ldprofile_pybind11': [
        _get_library_name("*"),
        _get_library_name("*", prefix="bin/" ) ] },
    install_requires=['numpy'],
    cmake_args=['-DCMAKE_BUILD_TYPE=Debug',]
)
