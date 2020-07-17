import ctypes as ct
from os.path import realpath, dirname
from .library_helpers import _find_ctypes_lib


def def_c_function(ctypes_lib, return_type, c_symbol_name, *arg_types):
    """provides a ctypes handle for a C-API function (symbol)"""
    c_api_func = getattr(ctypes_lib, c_symbol_name)

    # declare the result (i.e. return) type of the C-API function
    c_api_func.restype = return_type

    # declare the arguments
    c_api_func.argtypes = list(arg_types) if len(arg_types) > 0 else None
    return c_api_func


def string_to_encoded_ctypes_str(s, encoding="utf-8"):
    result = None
    if s is not None:
        _temp_str = s.encode(encoding)
        result = ct.c_char_p(_temp_str)
    return result


def ctypes_str_to_decoded_string(bstr, encoding="utf-8"):
    if bstr is not None:
        if isinstance(bstr, ct.Array):
            _bstr_bytes = bytes(bstr.value)
        elif isinstance(bstr, bytes):
            _bstr_bytes = bstr
        else:
            _bstr_bytes = None
            raise Exception(
                f"""
                Illegal type for parameter bstr {type(bstr)}, required
                ctypes.Array or bytes
                """
            )
    if _bstr_bytes is not None:
        if b"\0" in _bstr_bytes:
            _bstr_bytes = _bstr_bytes.split(b"\0", 1)[0]
        return _bstr_bytes.decode(encoding)
    else:
        return b"".decode(encoding)


ldprofilelib_path = _find_ctypes_lib("ldprofile", realpath(dirname(__file__)))
ldprofilelib = ct.CDLL(ldprofilelib_path)

# ------------------------------------------------------------------------------
# define types

ptr_double_ct = ct.POINTER(ct.c_double)
ld_method_type_ct = ct.c_uint64

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# a) qgauss.h:

Math_q_gauss_ct = def_c_function(
    ldprofilelib, ct.c_double, "Math_q_gauss", ct.c_double, ct.c_double, ct.c_double
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# b) base_profile.h:

ptr_LDProfile_ct = ct.c_void_p  # LDProfile is not a POD / C-Style class -> void*
LDProfile_NULL = ct.cast(0, ptr_LDProfile_ct)

LDProfile_delete_ct = def_c_function(
    ldprofilelib, None, "LDProfile_delete", ptr_LDProfile_ct,
)

LDProfile_method_ct = def_c_function(
    ldprofilelib, ld_method_type_ct, "LDProfile_method", ptr_LDProfile_ct,
)

LDProfile_evaluate_ct = def_c_function(
    ldprofilelib, ct.c_double, "LDProfile_evaluate", ptr_LDProfile_ct, ct.c_double
)

LDProfile_evaluate_num_values_ct = def_c_function(
    ldprofilelib,
    None,
    "LDProfile_evaluate_num_values",
    ptr_LDProfile_ct,
    ptr_double_ct,
    ptr_double_ct,
    ct.c_size_t,
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# b) ld_coasting.h:

LDProfile_create_coasting_ct = def_c_function(
    ldprofilelib, ptr_LDProfile_ct, "LDProfileCoasting_create", ct.c_double,
)

LDProfile_is_coasting_ct = def_c_function(
    ldprofilelib, ct.c_bool, "LDProfile_is_coasting", ptr_LDProfile_ct,
)

LDProfileCoasting_create_ct = LDProfile_create_coasting_ct

LDProfileCoasting_value_ct = def_c_function(
    ldprofilelib, ct.c_double, "LDProfileCoasting_value", ptr_LDProfile_ct,
)

LDProfileCoasting_update_ct = def_c_function(
    ldprofilelib, None, "LDProfileCoasting_update", ptr_LDProfile_ct, ct.c_double
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# b) ld_qgauss.h:

LDProfileQGaussian_create_ct = def_c_function(
    ldprofilelib,
    ptr_LDProfile_ct,
    "LDProfileQGaussian_create",
    ct.c_double,
    ct.c_double,
)

LDProfileQGaussian_create_gaussian_ct = def_c_function(
    ldprofilelib, ptr_LDProfile_ct, "LDProfileQGaussian_create_gaussian", ct.c_double,
)

LDProfile_is_qgaussian_ct = def_c_function(
    ldprofilelib, ct.c_bool, "LDProfile_is_qgaussian", ptr_LDProfile_ct,
)

LDProfileQGaussian_q_ct = def_c_function(
    ldprofilelib, ct.c_double, "LDProfileQGaussian_q", ptr_LDProfile_ct,
)

LDProfileQGaussian_min_support_ct = def_c_function(
    ldprofilelib, ct.c_double, "LDProfileQGaussian_min_support", ptr_LDProfile_ct,
)

LDProfileQGaussian_max_support_ct = def_c_function(
    ldprofilelib, ct.c_double, "LDProfileQGaussian_max_support", ptr_LDProfile_ct,
)

LDProfileQGaussian_sqrt_beta_ct = def_c_function(
    ldprofilelib, ct.c_double, "LDProfileQGaussian_sqrt_beta", ptr_LDProfile_ct,
)

LDProfileQGaussian_cq_ct = def_c_function(
    ldprofilelib, ct.c_double, "LDProfileQGaussian_cq", ptr_LDProfile_ct,
)

LDProfileQGaussian_update_as_gaussian_ct = def_c_function(
    ldprofilelib,
    None,
    "LDProfileQGaussian_update_as_gaussian",
    ptr_LDProfile_ct,
    ct.c_double,
)

LDProfileQGaussian_update_ct = def_c_function(
    ldprofilelib, None, "LDProfileQGaussian_update", ct.c_double, ct.c_double
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# c) ld_lin_interpol.h:

LDProfileLinInterpol_create_ct = def_c_function(
    ldprofilelib,
    ptr_LDProfile_ct,
    "LDProfileLinInterpol_create",
    ct.c_double,
    ct.c_double,
    ct.c_size_t,
)

LDProfileLinInterpol_create_detailed_ct = def_c_function(
    ldprofilelib,
    ptr_LDProfile_ct,
    "LDProfileLinInterpol_create_detailed",
    ct.c_double,
    ct.c_double,
    ct.c_size_t,
    ptr_double_ct,
)

LDProfile_is_lin_interpol_ct = def_c_function(
    ldprofilelib, ct.c_bool, "LDProfile_is_lin_interpol", ptr_LDProfile_ct,
)

LDProfileLinInterpol_z0_ct = def_c_function(
    ldprofilelib, ct.c_double, "LDProfileLinInterpol_z0", ptr_LDProfile_ct,
)

LDProfileLinInterpol_dz_ct = def_c_function(
    ldprofilelib, ct.c_double, "LDProfileLinInterpol_dz", ptr_LDProfile_ct,
)

LDProfileLinInterpol_values_begin_ct = def_c_function(
    ldprofilelib, ptr_double_ct, "LDProfileLinInterpol_values_begin", ptr_LDProfile_ct,
)

LDProfileLinInterpol_values_end_ct = def_c_function(
    ldprofilelib, ptr_double_ct, "LDProfileLinInterpol_values_end", ptr_LDProfile_ct,
)

LDProfileLinInterpol_value_ct = def_c_function(
    ldprofilelib,
    ct.c_double,
    "LDProfileLinInterpol_value",
    ptr_LDProfile_ct,
    ct.c_size_t,
)

LDProfileLinInterpol_set_value_ct = def_c_function(
    ldprofilelib,
    None,
    "LDProfileLinInterpol_set_value",
    ptr_LDProfile_ct,
    ct.c_size_t,
    ct.c_double,
)

LDProfileLinInterpol_num_values_ct = def_c_function(
    ldprofilelib, ct.c_size_t, "LDProfileLinInterpol_num_values", ptr_LDProfile_ct
)
