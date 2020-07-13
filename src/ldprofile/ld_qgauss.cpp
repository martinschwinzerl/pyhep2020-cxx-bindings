#include "ldprofile/ld_qgauss.h"
#include "ldprofile/qgauss.h"

namespace
{
    namespace ldp = ldprofile;
}

::QGaussianLDProfile* LDProfileQGaussian_create(
    double const q, double const sqrt_beta )
{
    return new ldp::QGaussianLDProfile( q, sqrt_beta );
}

::QGaussianLDProfile* LDProfileQGaussian_create_gaussian(
    double const gaussian_sigma )
{
    return new ldp::QGaussianLDProfile( double{ 1 },
        ldp::Math_q_gauss_sqrt_beta_from_gauss_sigma( gaussian_sigma ) );
}

double LDProfileQGaussian_q(
    const ::QGaussianLDProfile *const profile ) LDPROFILE_NOEXCEPT
{
    return ( profile != nullptr ) ? profile->q() : double{ 1 };
}

double LDProfileQGaussian_min_support(
    const ::QGaussianLDProfile *const profile ) LDPROFILE_NOEXCEPT
{
    return ( profile != nullptr )
        ? ldp::Math_q_gauss_min_support( profile->q(), profile->sqrt_beta() )
        : double{ 0 };
}

double LDProfileQGaussian_max_support(
    const ::QGaussianLDProfile *const profile ) LDPROFILE_NOEXCEPT
{
    return ( profile != nullptr )
        ? ldp::Math_q_gauss_max_support( profile->q(), profile->sqrt_beta() )
        : double{ 0 };
}

double LDProfileQGaussian_sqrt_beta(
    const ::QGaussianLDProfile *const profile ) LDPROFILE_NOEXCEPT
{
    return ( profile != nullptr ) ? profile->sqrt_beta() : double{ 0 };
}

double LDProfileQGaussian_cq(
    const ::QGaussianLDProfile *const profile ) LDPROFILE_NOEXCEPT
{
    return ( profile != nullptr )
        ? profile->cq() : ldp::Math_q_gauss_cq( double{ 1 } );
}

void LDProfileQGaussian_update_as_gaussian( ::QGaussianLDProfile* profile,
    double const gaussian_sigma ) LDPROFILE_NOEXCEPT
{
    if( profile != nullptr ) profile->update( gaussian_sigma );
}

void LDProfileQGaussian_update( ::QGaussianLDProfile* profile,
    double const q, double const sqrt_beta ) LDPROFILE_NOEXCEPT
{
    if( profile != nullptr ) profile->update( q, sqrt_beta );
}
