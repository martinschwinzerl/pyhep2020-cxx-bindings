#include "qgauss.h"

#include <limits.h>
#include <math.h>

double MATH_QGAUSS_Q_EPS( void ) QGAUSS_NOEXCEPT
{
    return ( double )1e-6L;
}

double MATH_QGAUSS_SQRT_PI( void ) QGAUSS_NOEXCEPT
{
    return ( double
        )1.77245385090551602729816748334114518279754945612238712821381L;
}

double MATH_QGAUSS_INV_SQRT2( void ) QGAUSS_NOEXCEPT
{
    return ( double )1.0L / sqrt( ( double )2.0L );
}

double qgauss_min_support(
    double const q, double const sqrt_beta ) QGAUSS_NOEXCEPT
{
    QGAUSS_ASSERT( q < ( double )3.0L );
    if( q >= ( double )1.0L )
    {
        return -( double )__DBL_MAX__;
    }
    else
    {
        QGAUSS_ASSERT( sqrt_beta * sqrt_beta > ( double )0.0L );
        return ( double )-1.0L / sqrt(
            sqrt_beta * sqrt_beta * ( ( double )1.0L - q ) );
    }
}

double qgauss_max_support( double const q, double const sqrt_beta ) QGAUSS_NOEXCEPT
{
    QGAUSS_ASSERT( q < ( double )3.0L );
    if( q >= ( double )1.0L )
    {
        return ( double )__DBL_MAX__;
    }
    else
    {
        QGAUSS_ASSERT( sqrt_beta * sqrt_beta > ( double )0.0L );
        return ( double )1.0L / sqrt(
            sqrt_beta * sqrt_beta * ( ( double )1.0L - q ) );
    }
}

double qgauss_sqrt_beta_from_gauss_sigma( double const gauss_sigma ) QGAUSS_NOEXCEPT
{
    QGAUSS_ASSERT( gauss_sigma > ( double )0.0L );
    return ( double )1.0L / ( sqrt( ( double )2.0L ) * gauss_sigma );
}

double qgauss_cq( double const q ) QGAUSS_NOEXCEPT
{
    double cq = MATH_QGAUSS_SQRT_PI();
    static const double ONE = ( double )1.0L;

    QGAUSS_ASSERT( q < ( double )3.0L );
    if( q >= ( ONE + MATH_QGAUSS_Q_EPS() ) )
    {
        double const q_minus_1 = q - ONE;
        cq *= tgamma( ( ( double )3.0L - q ) / ( ( double )2.0L * q_minus_1 ) );
        cq /= sqrt( q_minus_1 ) * tgamma( ONE / q_minus_1 );
    }
    else if( q <= ( ONE - MATH_QGAUSS_Q_EPS() ) )
    {
        double const one_minus_q = ONE - q;
        double const three_minus_q = ( double )3.0L - q;
        cq *= ( double )2.0L * tgamma( ONE / one_minus_q );
        cq /= three_minus_q * sqrt( one_minus_q ) *
              tgamma( three_minus_q / ( ( double )2.0L * one_minus_q ) );
    }

    return cq;
}

double qgauss_exp_q( double const x, double const q ) QGAUSS_NOEXCEPT
{
    static const double ONE = ( double )1.0L;

    double const one_minus_q = ONE - q;
    double const abs_one_minus_q = ( one_minus_q >= ( double )0.0L )
        ? one_minus_q : -one_minus_q;

    QGAUSS_ASSERT( q < ( double )3.0L );

    if( abs_one_minus_q >= MATH_QGAUSS_Q_EPS() )
    {
        double const u_plus = ONE + one_minus_q * x;
        return ( u_plus >= ( double )0.0L )
            ? pow( u_plus, ONE / one_minus_q ) : ( double )0.0L;
    }
    else
    {
        return exp( x );
    }
}

double qgauss_detailed( double const x, double const q,
               double const sqrt_beta, double const cq ) QGAUSS_NOEXCEPT
{
    QGAUSS_ASSERT( q < ( double )3.0L );
    QGAUSS_ASSERT( cq > ( double )0.0L );
    QGAUSS_ASSERT( sqrt_beta > ( double )0.0L );

    double const sqrt_beta_x = sqrt_beta * x;
    return ( sqrt_beta / cq ) * qgauss_exp_q( -sqrt_beta_x * sqrt_beta_x, q );
}


double qgauss( double const x, double const q,
               double const sqrt_beta ) QGAUSS_NOEXCEPT
{
    return qgauss_detailed( x, q, sqrt_beta, qgauss_cq( q ) );
}


double qgauss_gauss( double const x, double const sigma,
                     double const mu ) QGAUSS_NOEXCEPT
{
    double const q = ( double )1.0L;
    double const cq = qgauss_cq( q );
    double const sqrt_beta = qgauss_sqrt_beta_from_gauss_sigma( sigma );

    return qgauss_detailed( x - mu, q, sqrt_beta, cq );
}
