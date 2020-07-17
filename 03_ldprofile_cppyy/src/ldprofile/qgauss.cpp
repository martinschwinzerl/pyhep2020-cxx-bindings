#include "ldprofile/qgauss.h"

double MATH_QGAUSSIAN_Q_EPS( void ) LDPROFILE_NOEXCEPT
{
    return ldprofile::MATH_QGAUSS_Q_EPS< double >();
}

double MATH_QGAUSSIAN_SQRT_PI( void ) LDPROFILE_NOEXCEPT
{
    return ldprofile::MATH_QGAUSS_SQRT_PI< double >();
}

double MATH_QGAUSSIAN_INV_SQRT2( void ) LDPROFILE_NOEXCEPT
{
    return ldprofile::MATH_QGAUSS_INV_SQRT2< double >();
}

double Math_q_gauss_min_support(
    double const q, double const sqrt_beta ) LDPROFILE_NOEXCEPT
{
    return ldprofile::Math_q_gauss_min_support( q, sqrt_beta );
}

double Math_q_gauss_max_support(
    double const q, double const sqrt_beta ) LDPROFILE_NOEXCEPT
{
    return ldprofile::Math_q_gauss_max_support( q, sqrt_beta );
}

double Math_q_gauss_sqrt_beta_from_gauss_sigma(
    double const gauss_sigma ) LDPROFILE_NOEXCEPT
{
    return ldprofile::Math_q_gauss_sqrt_beta_from_gauss_sigma( gauss_sigma );
}

double Math_q_gauss_cq( double const q ) LDPROFILE_NOEXCEPT
{
    return ldprofile::Math_q_gauss_cq( q );
}

double Math_q_gauss_exp_q( double const x, double const q ) LDPROFILE_NOEXCEPT
{
    return ldprofile::Math_q_gauss_exp_q( x, q );
}

double Math_q_gauss( double const x, double const q,
                     double const sqrt_beta ) LDPROFILE_NOEXCEPT
{
    return ldprofile::Math_q_gauss( x, q, sqrt_beta );
}

double Math_q_gauss_detailed( double const x, double const q,
    double const sqrt_beta, double const cq ) LDPROFILE_NOEXCEPT
{
    return ldprofile::Math_q_gauss( x, q, sqrt_beta, cq );
}
