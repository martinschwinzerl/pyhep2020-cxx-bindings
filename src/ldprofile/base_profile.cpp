#include "ldprofile/base_profile.hpp"

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

double LDProfile_value( const ::LDProfile *const profile, double const z )
{
    return ( profile != nullptr ) ? profile->value( z ) : double{ 0 };
}
