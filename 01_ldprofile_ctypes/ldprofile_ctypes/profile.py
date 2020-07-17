from .ct_api import *
from typing import List, overload, Union
import numpy as np


class LDProfileBase(object):
    def __init__(self, ptr_base=LDProfile_NULL, owns_ptr=True):
        assert ptr_base != LDProfile_NULL
        self._ptr_base = ptr_base
        self._owns_ptr = owns_ptr

    def __del__(self):
        if self._ptr_base != LDProfile_NULL and self._owns_ptr:
            LDProfile_delete_ct(self._ptr_base)

    @property
    def owns_ptr(self):
        return self._owns_ptr

    @property
    def pointer(self):
        return self._ptr_base

    @property
    def method(self):
        return LDProfile_method_ct(self._ptr_base)

    @overload
    def evaluate(self, z: float) -> float:
        ...

    @overload
    def evaluate(self, z_vec: List[float]) -> np.array:
        ...

    def evaluate(self, z):
        if isinstance(z, float):
            return LDProfile_evaluate_ct(self._ptr_base, ct.c_double(z))
        else:
            return np.array(
                [LDProfile_evaluate_ct(self._ptr_base, ct.c_double(zz)) for zz in z],
                dtype=np.float64,
            )


class CoastingLDProfile(LDProfileBase):
    def __init__(self, value: float = 0.0):
        ptr_base = LDProfileCoasting_create_ct(ct.c_double(value))
        super().__init__(ptr_base=ptr_base, owns_ptr=True)

    @property
    def value(self):
        return LDProfileCoasting_value_ct(self.pointer)

    def update(self, new_value: float):
        LDProfileCoasting_update_ct(self.pointer, ct.c_double(new_value))


class QGaussianLDProfile(LDProfileBase):
    def __init__(self, arg: float, sqrt_beta: float = 0.0):
        assert (arg > 0.0 and sqrt_beta <= 0.0) or (arg < 3.0 and sqrt_beta > 0.0)
        if sqrt_beta > 0.0:
            ptr_base = LDProfileQGaussian_create_ct(
                ct.c_double(arg), ct.c_double(sqrt_beta)
            )
        else:
            ptr_base = LDProfileQGaussian_create_gaussian_ct(ct.c_double(arg))
        super().__init__(ptr_base=ptr_base, owns_ptr=True)

    @property
    def min_support(self) -> float:
        return LDProfileQGaussian_min_support_ct(self.pointer)

    @property
    def max_support(self) -> float:
        return LDProfileQGaussian_max_support_ct(self.pointer)

    @property
    def cq(self) -> float:
        return LDProfileQGaussian_cq_ct(self.pointer)

    @property
    def q(self) -> float:
        return LDProfileQGaussian_q_ct(self.pointer)

    @property
    def sqrt_beta(self) -> float:
        return LDProfileQGaussian_sqrt_beta_ct(self.pointer)

    def update(self, arg: float, sqrt_beta: float = 0.0):
        assert (arg > 0.0 and sqrt_beta <= 0.0) or (arg < 3.0 and sqrt_beta > 0.0)
        if sqrt_beta > 0.0:
            LDProfileQGaussian_update_ct(
                self.pointer, ct.c_double(arg), ct.c_double(sqrt_beta)
            )
        else:
            LDProfileQGaussian_update_as_gaussian_ct(self.pointer, ct.c_double(arg))


class LinInterpolLDProfile(LDProfileBase):
    def __init__(
        self, z0: float, dz: float, values: List[float] = [], num_values: int = 0
    ):
        assert dz > 0.0
        assert len(values) >= 2 or num_values >= 2
        if len(values) >= 2:
            _tmp_values = np.array(values)
            num_values = len(values)
            ptr_base = LDProfileLinInterpol_create_detailed_ct(
                ct.c_double(z0),
                ct.c_double(dz),
                ct.c_size_t(num_values),
                _tmp_values.ctypes.data_as(ptr_double_ct),
            )
        else:
            ptr_base = LDProfileLinInterpol_create_ct(
                ct.c_double(z0), ct.c_double(dz), ct.c_size_t(num_values)
            )
        super().__init__(ptr_base=ptr_base, owns_ptr=True)

    @property
    def z0(self):
        return LDProfileLinInterpol_z0_ct(self.pointer)

    @property
    def dz(self):
        return LDProfileLinInterpol_dz_ct(self.pointer)

    def __len__(self):
        return LDProfileLinInterpol_num_values_ct(self.pointer)

    def __getitem__(self, key: int):
        if key >= 0 and key < LDProfileLinInterpol_num_values_ct(self.pointer):
            return LDProfileLinInterpol_value_ct(self.pointer, ct.c_size_t(key))
        raise KeyError(f"{key} out of bounds")

    def __setitem__(self, key: int, value: float):
        if key >= 0 and key < LDProfileLinInterpol_num_values_ct(self.pointer):
            return LDProfileLinInterpol_set_value_ct(
                self.pointer, ct.c_size_t(key), ct.c_double(value)
            )
        raise KeyError(f"{key} out of bounds")
