#ifndef QGAUSS_H__
#define QGAUSS_H__

#if !defined( QGAUSS_NO_INCLUDES )
    #include "definitions.h"
#endif /* !defined( QGAUSS_NO_INCLUDES ) */

#if !defined( QGAUSS_MATH_QGAUSS_Q_EPS )
    #define QGAUSS_MATH_QGAUSS_Q_EPS 1e-6L
#endif /* QGAUSS_MATH_QGAUSS_Q_EPS */

#if defined( __cplusplus ) && !defined( _GPUCODE )
extern "C" {
#endif /* C++, Host */

QGAUSS_EXTERN QGAUSS_HOST_FN double QGAUSS_Q_EPS( void ) QGAUSS_NOEXCEPT;

QGAUSS_EXTERN QGAUSS_HOST_FN double QGAUSS_SQRT_PI( void ) QGAUSS_NOEXCEPT;

QGAUSS_EXTERN QGAUSS_HOST_FN double QGAUSS_INV_SQRT2( void ) QGAUSS_NOEXCEPT;

QGAUSS_EXTERN QGAUSS_HOST_FN double qgauss_min_support(
    double const q, double const sqrt_beta ) QGAUSS_NOEXCEPT;

QGAUSS_EXTERN QGAUSS_HOST_FN double qgauss_max_support(
    double const q, double const sqrt_beta ) QGAUSS_NOEXCEPT;

QGAUSS_EXTERN QGAUSS_HOST_FN double qgauss_sqrt_beta_from_gauss_sigma(
    double const gauss_sigma ) QGAUSS_NOEXCEPT;

QGAUSS_EXTERN QGAUSS_HOST_FN double qgauss_cq( double const q ) QGAUSS_NOEXCEPT;

QGAUSS_EXTERN QGAUSS_HOST_FN double qgauss_exp_q(
    double const x, double const q ) QGAUSS_NOEXCEPT;

QGAUSS_EXTERN QGAUSS_HOST_FN double qgauss(
    double const x, double const q, double const sqrt_beta ) QGAUSS_NOEXCEPT;

QGAUSS_EXTERN QGAUSS_HOST_FN double qgauss_detailed(
    double const x, double const q, double const sqrt_beta,
    double const cq ) QGAUSS_NOEXCEPT;

QGAUSS_EXTERN QGAUSS_HOST_FN double qgauss_gauss(
    double const x, double const sigma, double const mu ) QGAUSS_NOEXCEPT;

#if defined( __cplusplus ) && !defined( _GPUCODE )
}
#endif /* C++, Host */
#endif /* QGAUSS_QGAUSS_H__ */
