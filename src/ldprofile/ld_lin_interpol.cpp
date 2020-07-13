#include "ldprofile/ld_lin_interpol.h"
namespace { namespace ldp = ldprofile; }

::LinInterpolLDProfile* LDProfileLinInterpol_create(
    size_t const num_values, double const z0, double const dz )
{
    return new ldp::LinInterpolLDProfile( num_values, z0, dz );
}

::LinInterpolLDProfile* LDProfileLinInterpol_create_detailed(
    double const* values_begin, size_t const num_values,
    double const z0, double const dz )
{
    return new ldp::LinInterpolLDProfile( values_begin, num_values, z0, dz );
}

double LDProfileLinInterpol_z0(
    const ::LinInterpolLDProfile *const profile ) LDPROFILE_NOEXCEPT
{
    return ( profile != nullptr ) ? profile->z0() : double{ 0 };
}

double const* LineInterpol1DProfile_const_profile_values_begin(
    const ::LinInterpolLDProfile *const profile ) LDPROFILE_NOEXCEPT
{
    return ( profile != nullptr ) ? profile->profile_values_begin() : nullptr;
}

double const* LineInterpol1DProfile_const_profile_values_end(
    const ::LinInterpolLDProfile *const profile ) LDPROFILE_NOEXCEPT
{
    return ( profile != nullptr ) ? profile->profile_values_end() : nullptr;
}

double* LineInterpol1DProfile_profile_values_begin(
    ::LinInterpolLDProfile* profile ) LDPROFILE_NOEXCEPT
{
    return ( profile != nullptr ) ? profile->profile_values_begin() : nullptr;
}

double* LineInterpol1DProfile_profile_values_end(
    ::LinInterpolLDProfile* profile ) LDPROFILE_NOEXCEPT
{
    return ( profile != nullptr ) ? profile->profile_values_end() : nullptr;
}

double LineInterpol1DProfile_profile_value(
    const ::LinInterpolLDProfile *const profile,
    ::size_t const idx ) LDPROFILE_NOEXCEPT
{
    return ( profile != nullptr ) ? profile->profile_value( idx ) : double{ 0 };
}

void LineInterpol1DProfile_set_profile_value(
    ::LinInterpolLDProfile* profile, ::size_t const idx,
    double const value ) LDPROFILE_NOEXCEPT
{
    if( profile != nullptr ) profile->profile_value( idx ) = value;
}

::size_t LineInterpol1DProfile_num_values(
    const ::LinInterpolLDProfile *const profile ) LDPROFILE_NOEXCEPT
{
    return ( profile != nullptr ) ? profile->num_values() : ::size_t{ 0 };
}
