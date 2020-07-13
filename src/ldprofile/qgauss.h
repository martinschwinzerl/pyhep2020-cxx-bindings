#ifndef LDPROFILE_QGAUSS_H__
#define LDPROFILE_QGAUSS_H__

#if !defined( LDPROFILE_NO_INCLUDES )
    #include "ldprofile/definitions.h"
#endif /* !defined( LDPROFILE_NO_INCLUDES ) */

#if !defined( LDPROFILE_MATH_QGAUSS_Q_EPS )
    #define LDPROFILE_MATH_QGAUSS_Q_EPS 1e-6L
#endif /* LDPROFILE_MATH_QGAUSS_Q_EPS */

#if defined( __cplusplus )
namespace ldprofile
{
    template< class T >
    LDPROFILE_STATIC LDPROFILE_FN T MATH_QGAUSS_Q_EPS(
        T const* ptr_dummy = nullptr ) LDPROFILE_NOEXCEPT;

    template< class T >
    LDPROFILE_STATIC LDPROFILE_FN T MATH_QGAUSS_SQRT_PI(
        T const* ptr_dummy = nullptr ) LDPROFILE_NOEXCEPT;

    template< class T >
    LDPROFILE_STATIC LDPROFILE_FN T MATH_QGAUSS_INV_SQRT2(
        T const* ptr_dummy = nullptr ) LDPROFILE_NOEXCEPT;

    template< class T >
    LDPROFILE_STATIC LDPROFILE_FN T Math_q_gauss_min_support(
        T const& q, T const& sqrt_beta ) LDPROFILE_NOEXCEPT;

    template< class T >
    LDPROFILE_STATIC LDPROFILE_FN T Math_q_gauss_max_support(
        T const& q, T const& sqrt_beta ) LDPROFILE_NOEXCEPT;

    template< class T >
    LDPROFILE_STATIC LDPROFILE_FN T Math_q_gauss_sqrt_beta_from_gauss_sigma(
        T const& gauss_sigma ) LDPROFILE_NOEXCEPT;

    template< class T >
    LDPROFILE_STATIC LDPROFILE_FN T Math_q_gauss_cq(
        T const& q ) LDPROFILE_NOEXCEPT;

    template< class T >
    LDPROFILE_STATIC LDPROFILE_FN T Math_q_gauss_exp_q( T const& x,
        T const& q ) LDPROFILE_NOEXCEPT;

    template< class T >
    LDPROFILE_STATIC LDPROFILE_FN T Math_q_gauss( T const& x, T const& q,
        T const& sqrt_beta ) LDPROFILE_NOEXCEPT;

    template< class T >
    LDPROFILE_STATIC LDPROFILE_FN T Math_q_gauss( T const& x, T const& q,
        T const& sqrt_beta, T const& cq ) LDPROFILE_NOEXCEPT;
}
#endif /* C++ */

#if defined( __cplusplus ) && !defined( _GPUCODE )
extern "C" {
#endif /* C++, Host */

LDPROFILE_EXTERN LDPROFILE_HOST_FN double
    MATH_QGAUSS_Q_EPS( void ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double
    MATH_QGAUSS_SQRT_PI( void ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double
    MATH_QGAUSS_INV_SQRT2( void ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double Math_q_gauss_min_support(
    double const q, double const sqrt_beta ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double Math_q_gauss_max_support(
    double const q, double const sqrt_beta ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double
Math_q_gauss_sqrt_beta_from_gauss_sigma(
    double const gauss_sigma ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double Math_q_gauss_cq(
    double const q ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double Math_q_gauss_exp_q(
    double const x, double const q ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double Math_q_gauss(
    double const x, double const q, double const sqrt_beta,
    double const cq ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double Math_q_gauss_detailed(
    double const x, double const q, double const sqrt_beta,
    double const cq ) LDPROFILE_NOEXCEPT;

#if defined( __cplusplus ) && !defined( _GPUCODE )
}
#endif /* C++, Host */

/* ************************************************************************* */
/* inline method implemention: */


#if !defined( LDPROFILE_NO_SYSTEM_INCLUDES ) && defined( __cplusplus )
    #include <limits>
#endif /* !defined( LDPROFILE_NO_SYSTEM_INCLUDES ) && defined( __cplusplus ) */

#if defined( __cplusplus )
namespace ldprofile
{
    template< class T > LDPROFILE_INLINE T MATH_QGAUSS_Q_EPS(
        T const* LDPROFILE_UNUSED( ptr_dummy ) ) LDPROFILE_NOEXCEPT
    {
        return static_cast< T >( 1e-6L );
    }

    template< class T > LDPROFILE_INLINE T MATH_QGAUSS_SQRT_PI(
        T const* LDPROFILE_UNUSED( ptr_dummy ) ) LDPROFILE_NOEXCEPT
    {
        return static_cast< T >(
            1.77245385090551602729816748334114518279754945612238712821381L );
    }

    template< class T > LDPROFILE_INLINE T MATH_QGAUSS_INV_SQRT2(
        T const* LDPROFILE_UNUSED( ptr_dummy ) ) LDPROFILE_NOEXCEPT
    {
        #if !defined( _GPUCODE )
        using std::sqrt;
        #endif /* Host */

        return T{ 1 } / sqrt( T{ 2 } );
    }

    template< class T > LDPROFILE_INLINE T Math_q_gauss_min_support(
        T const& q, T const& sqrt_beta ) LDPROFILE_NOEXCEPT
    {
        #if !defined( _GPUCODE )
        using std::sqrt;
        #endif /* Host */

        LDPROFILE_ASSERT( q < T{ 3 } );
        if( q >= T{ 1 } )
        {
            return std::numeric_limits< T >::min();
        }
        else
        {
            LDPROFILE_ASSERT( sqrt_beta * sqrt_beta > T{ 0 } );
            return T{ -1 } / sqrt( sqrt_beta * sqrt_beta * ( T{ 1 } - q ) );
        }
    }

    template< class T > LDPROFILE_INLINE T Math_q_gauss_max_support(
        T const& q, T const& sqrt_beta ) LDPROFILE_NOEXCEPT
    {
        #if !defined( _GPUCODE )
        using std::sqrt;
        #endif /* Host */

        LDPROFILE_ASSERT( q < T{ 3 } );
        if( q >= T{ 1 } )
        {
            return std::numeric_limits< T >::min();
        }
        else
        {
            LDPROFILE_ASSERT( sqrt_beta * sqrt_beta > T{ 0 } );
            return T{ 1 } / sqrt( sqrt_beta * sqrt_beta * ( T{ 1 } - q ) );
        }
    }

    template< class T >
    LDPROFILE_INLINE T Math_q_gauss_sqrt_beta_from_gauss_sigma(
        T const& gauss_sigma ) LDPROFILE_NOEXCEPT
    {
        #if !defined( _GPUCODE )
        using std::sqrt;
        #endif /* Host */

        LDPROFILE_ASSERT( gauss_sigma > T{ 0 } );
        return T{ 1 } / ( sqrt( T{ 2 } ) * gauss_sigma );
    }

    template< class T >
    LDPROFILE_INLINE T Math_q_gauss_cq( T const& q ) LDPROFILE_NOEXCEPT
    {
        #if !defined( _GPUCODE )
        using std::tgamma;
        using std::sqrt;
        #endif /* Host */

        T cq = ldprofile::MATH_QGAUSS_SQRT_PI< T >();
        static const T ONE = T{ 1 };

        LDPROFILE_ASSERT( q < T{ 3 } );
        if( q >= ( ONE + ldprofile::MATH_QGAUSS_Q_EPS< T >() ) )
        {
            T const q_minus_1 = q - ONE;
            cq *= tgamma( ( T{ 3 } - q ) / ( T{ 2 } * q_minus_1 ) );
            cq /= sqrt( q_minus_1 ) * tgamma( ONE / q_minus_1 );
        }
        else if( q <= ( ONE - ldprofile::MATH_QGAUSS_Q_EPS< T >() ) )
        {
            T const one_minus_q = ONE - q;
            T const three_minus_q = T{ 3 } - q;
            cq *= T{ 2 } * tgamma( ONE / one_minus_q );
            cq /= three_minus_q * sqrt( one_minus_q ) *
                  tgamma( three_minus_q / ( T{ 2 } * one_minus_q ) );
        }

        return cq;
    }

    template< class T > LDPROFILE_INLINE T Math_q_gauss_exp_q(
        T const& x, T const& q ) LDPROFILE_NOEXCEPT
    {
        #if !defined( _GPUCODE )
        using std::pow;
        using std::exp;
        #endif /* Host */

        static const T ONE = T{ 1 };
        LDPROFILE_ASSERT( q < T{ 3 } );

        T const one_minus_q = ONE - q;
        T const abs_one_minus_q = ( one_minus_q >= T{ 0 } )
            ? one_minus_q : -one_minus_q;

        if( abs_one_minus_q >= ldprofile::MATH_QGAUSS_Q_EPS< T >() )
        {
            T const u_plus = ONE + one_minus_q * x;
            return ( u_plus >= T{ 0 } )
                ? pow( u_plus, ONE / one_minus_q ) : T{ 0 };
        }
        else
        {
            return exp( x );
        }
    }

    template< class T >
    LDPROFILE_INLINE T Math_q_gauss( T const& x, T const& q,
        T const& sqrt_beta, T const& cq ) LDPROFILE_NOEXCEPT
    {
        LDPROFILE_ASSERT( q < T{ 3 } );
        LDPROFILE_ASSERT( cq > T{ 0 } );
        LDPROFILE_ASSERT( sqrt_beta > T{ 0 } );

        return ( sqrt_beta / cq ) * ldprofile::Math_q_gauss_exp_q(
            -( sqrt_beta * sqrt_beta * x * x ), q );
    }

    template< class T >
    LDPROFILE_INLINE T Math_q_gauss( T const& x, T const& q,
        T const& sqrt_beta ) LDPROFILE_NOEXCEPT
    {
        return ldprofile::Math_q_gauss< T >(
            x, q, sqrt_beta, ldprofile::Math_q_gauss_cq< T >( q ) );
    }
}
#endif /* C++ */
#endif /* LDPROFILE_QGAUSS_H__ */
