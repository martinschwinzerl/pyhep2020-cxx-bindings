#include "ldprofile/ld_coasting.h"

::CoastingLDProfile* LDProfileCoasting_create( double const value )
{
    return new ::CoastingLDProfile( value );
}

void LDProfileCoasting_set_value(
    ::CoastingLDProfile* profile, double const new_value ) LDPROFILE_NOEXCEPT
{
    if( profile != nullptr ) profile->set_value( new_value );
}
