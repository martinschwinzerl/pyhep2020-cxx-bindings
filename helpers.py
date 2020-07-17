import sys
import os
from os.path import realpath, dirname, join

def list_dir_tree(from_path, level_spacing=4, exclude=[], allow=None):
    for root, dirs, files in os.walk(from_path, topdown=True):
        if allow is not None and len( allow ) > 0:
            dirs[:] = [ d for d in dirs if d in allow ]
        dirs[:] = [ d for d in dirs if d not in exclude ]
        level = root.replace(from_path, '').count(os.sep)
        indent = ' ' * level_spacing * (level)
        print(f'{indent}{os.path.basename(root)}/')
        subindent = ' ' * level_spacing * (level + 1)
        for f in files:
            print(f'{subindent}{f}')

def get_dynamic_library_ext():
    if sys.platform.startswith('win32'):
        ext = '.dll'
    elif sys.platform.startswith('darwin'):
        ext = '.dylib'
    elif sys.platform.startswith('linux'):
        ext = '.so'
    else:
        ext = None
        raise Exception( f'Unknown operating system: {sys.platform}' )
    return ext

def find_dynamic_library( lname, root_dir, _debug=False ):
    extension = get_dynamic_library_ext()
    import glob
    # windows doesnt always start names with lib
    if _debug:
        print(f'Attempting to find library in root_dir = {root_dir}')
        print(f'libname = {lname}')
    candidates = []
    if sys.platform.startswith('win32'):
        candidates += list(glob.glob( join(
            root_dir, lname + '*' + extension)))
    else:
        candidates += list(glob.glob(join(
            root_dir, 'lib' + lname + '*' + extension)))

    if len(candidates) == 0:
        raise Exception( f'Unable to find library {lname} in {root_dir}')
    if len(candidates) > 1:
        raise Exception(f'Too many matching libs: {candidates}')

    found_lib = candidates[ 0 ]
    if _debug:
        print(f'Selected library {found_lib} from {root_dir}')
    return found_lib
