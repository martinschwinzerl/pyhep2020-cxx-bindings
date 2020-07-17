import setuptools
from skbuild import setup
import sys

setup(
    name="ldprofile_pybind11",
    version="1.0.0",
    description="python bindings for ldprofile, using scikit-build and pybind11",
    author="Martin Schwinzerl",
    license="MIT",
    packages=['ldprofile_pybind11'],
    install_requires=['numpy', 'matplotlib'],
    #cmake_args=['-DCMAKE_BUILD_TYPE=Debug',]
)
