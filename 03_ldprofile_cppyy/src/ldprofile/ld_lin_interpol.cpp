#include "ldprofile/ld_lin_interpol.h"

::LinInterpolLDProfile* LDProfileLinInterpol_create(
    double const z0, double const dz, size_t const num_values )
{
    return new ldprofile::LinInterpolLDProfile( z0, dz, num_values );
}

::LinInterpolLDProfile* LDProfileLinInterpol_create_detailed(
    double const z0, double const dz, size_t const num_values,
    double const* values_begin )
{
    return new ldprofile::LinInterpolLDProfile(
        z0, dz, num_values, values_begin );
}

bool LDProfile_is_lin_interpol(
    const ::LDProfile *const profile ) LDPROFILE_NOEXCEPT
{
    return ( ( profile != nullptr ) && ( profile->method() ==
                 ldprofile::LDPROFILE_METHOD_LINEAR_INTERPOL1D ) );
}

double LDProfileLinInterpol_z0(
    const ::LDProfile *const base_profile ) LDPROFILE_NOEXCEPT
{
    ldprofile::LinInterpolLDProfile const* profile = ldprofile::as_derived<
        ldprofile::LinInterpolLDProfile >( base_profile );

    return ( profile != nullptr ) ? profile->z0() : double{ 0 };
}

double LDProfileLinInterpol_dz(
    const ::LDProfile *const base_profile ) LDPROFILE_NOEXCEPT
{
    ldprofile::LinInterpolLDProfile const* profile = ldprofile::as_derived<
        ldprofile::LinInterpolLDProfile >( base_profile );

    return ( profile != nullptr ) ? profile->dz() : double{ 0 };
}

double const* LDProfileLinInterpol_const_values_begin(
    const ::LDProfile *const base_profile ) LDPROFILE_NOEXCEPT
{
    ldprofile::LinInterpolLDProfile const* profile = ldprofile::as_derived<
        ldprofile::LinInterpolLDProfile >( base_profile );

    return ( profile != nullptr ) ? profile->values_begin() : nullptr;
}

double const* LDProfileLinInterpol_const_values_end(
    const ::LDProfile *const base_profile ) LDPROFILE_NOEXCEPT
{
    ldprofile::LinInterpolLDProfile const* profile = ldprofile::as_derived<
        ldprofile::LinInterpolLDProfile >( base_profile );

    return ( profile != nullptr ) ? profile->values_end() : nullptr;
}

double* LDProfileLinInterpol_values_begin(
    ::LDProfile* base_profile ) LDPROFILE_NOEXCEPT
{
    ldprofile::LinInterpolLDProfile* profile = ldprofile::as_derived<
        ldprofile::LinInterpolLDProfile >( base_profile );

    return ( profile != nullptr ) ? profile->values_begin() : nullptr;
}

double* LDProfileLinInterpol_values_end(
    ::LDProfile* base_profile ) LDPROFILE_NOEXCEPT
{
    ldprofile::LinInterpolLDProfile* profile = ldprofile::as_derived<
        ldprofile::LinInterpolLDProfile >( base_profile );

    return ( profile != nullptr ) ? profile->values_end() : nullptr;
}

double LDProfileLinInterpol_value(
    const ::LDProfile *const base_profile, ::size_t const idx )
{
    ldprofile::LinInterpolLDProfile const* profile = ldprofile::as_derived<
        ldprofile::LinInterpolLDProfile >( base_profile );

    return ( profile != nullptr ) ? profile->value( idx ) : double{ 0 };
}

void LDProfileLinInterpol_set_value(
    ::LDProfile* base_profile, ::size_t const idx, double const value )
{
    ldprofile::LinInterpolLDProfile* profile = ldprofile::as_derived<
        ldprofile::LinInterpolLDProfile >( base_profile );

    if( profile != nullptr ) profile->value( idx ) = value;
}

::size_t LDProfileLinInterpol_num_values(
    const ::LDProfile *const base_profile ) LDPROFILE_NOEXCEPT
{
    ldprofile::LinInterpolLDProfile const* profile = ldprofile::as_derived<
        ldprofile::LinInterpolLDProfile >( base_profile );

    return ( profile != nullptr ) ? profile->num_values() : ::size_t{ 0 };
}
