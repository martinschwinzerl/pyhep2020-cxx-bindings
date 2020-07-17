import sys
from os.path import realpath
from os.path import dirname
from os.path import join

# Cf. https://github.com/Erotemic/scikit-build/tree/dev/ctypes_example
# and scikit-build PR #442 by github.com user @Erotemic


def _get_ctypes_lib_ext():
    if sys.platform.startswith("win32"):
        ext = ".dll"
    elif sys.platform.startswith("darwin"):
        ext = ".dylib"
    elif sys.platform.startswith("linux"):
        ext = ".so"
    else:
        ext = None
        raise Exception(f"Unknown operating system: {sys.platform}")
    return ext


def _find_ctypes_lib(lname, root_dir, _debug=False):
    extension = _get_ctypes_lib_ext()
    import glob

    # windows doesnt always start names with lib
    if _debug:
        print("Loading ctypes lib from root_dir = {!r}".format(root_dir))
        print("libname = {!r}".format(lname))
    candidates = []
    if sys.platform.startswith("win32"):
        candidates += list(glob.glob(join(root_dir, lname + "*" + extension)))
    else:
        candidates += list(glob.glob(join(root_dir, "lib" + lname + "*" + extension)))

    if len(candidates) == 0:
        raise Exception(f"Unable to find ctype lib {lname} in {root_dir}")
    if len(candidates) > 1:
        raise Exception(f"Too many matching libs: {candidates}")

    found_lib = candidates[0]
    if _debug:
        print(f"Selected ctypes lib {found_lib} from {root_dir}")
    return found_lib
