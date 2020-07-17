#include "ldprofile/ld_coasting.h"

::CoastingLDProfile* LDProfileCoasting_create( double const value )
{
    return new ::CoastingLDProfile( value );
}

bool LDProfile_is_coasting( const ::LDProfile *const profile ) LDPROFILE_NOEXCEPT
{
    return ( ( profile != nullptr ) &&
             ( profile->method() == ldprofile::LDPROFILE_METHOD_COASTING ) );
}

double LDProfileCoasting_value( const ::LDProfile *const
    base_profile ) LDPROFILE_NOEXCEPT
{
    ldprofile::CoastingLDProfile const* profile = ldprofile::as_derived<
        ldprofile::CoastingLDProfile >( base_profile );

    return ( profile != nullptr ) ? profile->value() : double{ 0 };
}

void LDProfileCoasting_update(
    ::LDProfile* base_profile, double const new_value ) LDPROFILE_NOEXCEPT
{
    ldprofile::CoastingLDProfile* profile = ldprofile::as_derived<
        ldprofile::CoastingLDProfile >( base_profile );

    if( profile != nullptr ) profile->update( new_value );
}
