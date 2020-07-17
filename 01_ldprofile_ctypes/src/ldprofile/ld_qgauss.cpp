#include "ldprofile/ld_qgauss.h"
#include "ldprofile/qgauss.h"

::QGaussianLDProfile* LDProfileQGaussian_create(
    double const q, double const sqrt_beta )
{
    return new ldprofile::QGaussianLDProfile( q, sqrt_beta );
}

bool LDProfile_is_qgaussian(
    const ::LDProfile *const base_profile ) LDPROFILE_NOEXCEPT
{
    return ( ( base_profile != nullptr ) &&
             ( base_profile->method() ==
               ldprofile::LDPROFILE_METHOD_QGAUSSIAN ) );
}

::QGaussianLDProfile* LDProfileQGaussian_create_gaussian(
    double const gaussian_sigma )
{
    return new ldprofile::QGaussianLDProfile( double{ 1 },
        ldprofile::Math_q_gauss_sqrt_beta_from_gauss_sigma( gaussian_sigma ) );
}

double LDProfileQGaussian_q(
    const ::LDProfile *const base_profile ) LDPROFILE_NOEXCEPT
{
    ldprofile::QGaussianLDProfile const* profile = ldprofile::as_derived<
        ldprofile::QGaussianLDProfile >( base_profile );

    return ( profile != nullptr ) ? profile->q() : double{ 1 };
}

double LDProfileQGaussian_min_support(
    const ::LDProfile *const base_profile ) LDPROFILE_NOEXCEPT
{
    ldprofile::QGaussianLDProfile const* profile = ldprofile::as_derived<
        ldprofile::QGaussianLDProfile >( base_profile );

    return ( profile != nullptr )
        ? ldprofile::Math_q_gauss_min_support(
            profile->q(), profile->sqrt_beta() )
        : double{ 0 };
}

double LDProfileQGaussian_max_support(
    const ::LDProfile *const base_profile ) LDPROFILE_NOEXCEPT
{
    ldprofile::QGaussianLDProfile const* profile = ldprofile::as_derived<
        ldprofile::QGaussianLDProfile >( base_profile );

    return ( profile != nullptr )
        ? ldprofile::Math_q_gauss_max_support(
            profile->q(), profile->sqrt_beta() )
        : double{ 0 };
}

double LDProfileQGaussian_sqrt_beta(
    const ::LDProfile *const base_profile ) LDPROFILE_NOEXCEPT
{
    ldprofile::QGaussianLDProfile const* profile = ldprofile::as_derived<
        ldprofile::QGaussianLDProfile >( base_profile );

    return ( profile != nullptr ) ? profile->sqrt_beta() : double{ 0 };
}

double LDProfileQGaussian_cq(
    const ::LDProfile *const base_profile ) LDPROFILE_NOEXCEPT
{
    ldprofile::QGaussianLDProfile const* profile = ldprofile::as_derived<
        ldprofile::QGaussianLDProfile >( base_profile );

    return ( profile != nullptr )
        ? profile->cq() : ldprofile::Math_q_gauss_cq( double{ 1 } );
}

void LDProfileQGaussian_update_as_gaussian( ::LDProfile* base_profile,
    double const gaussian_sigma ) LDPROFILE_NOEXCEPT
{
    ldprofile::QGaussianLDProfile* profile = ldprofile::as_derived<
        ldprofile::QGaussianLDProfile >( base_profile );

    if( profile != nullptr ) profile->update( gaussian_sigma );
}

void LDProfileQGaussian_update( ::LDProfile* base_profile,
    double const q, double const sqrt_beta ) LDPROFILE_NOEXCEPT
{
    ldprofile::QGaussianLDProfile* profile = ldprofile::as_derived<
        ldprofile::QGaussianLDProfile >( base_profile );

    if( profile != nullptr ) profile->update( q, sqrt_beta );
}
