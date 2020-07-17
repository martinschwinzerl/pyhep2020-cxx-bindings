#include "ldprofile/base_profile.h"

void LDProfile_delete( ::LDProfile* profile ) LDPROFILE_NOEXCEPT
{
    delete profile;
}

::ld_method_type LDProfile_method(
    const ::LDProfile *const profile ) LDPROFILE_NOEXCEPT
{
    return ( profile != nullptr )
        ? profile->method() : ldprofile::LDPROFILE_ILLEGAL_METHOD;
}

double LDProfile_evaluate( const ::LDProfile *const profile, double const z )
{
    return ( profile != nullptr ) ? profile->evaluate( z ) : double{ 0 };
}

void LDProfile_evaluate_num_values( const ::LDProfile *const profile,
    double* result_begin, double const* z_begin, size_t const num_values )
{
    if ( profile != nullptr )
    {
        profile->evaluate( result_begin, z_begin, num_values );
    }
}
