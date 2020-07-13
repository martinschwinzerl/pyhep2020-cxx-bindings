#ifndef LDPRPOFILE_LD_QGAUSSIAN_H__
#define LDPRPOFILE_LD_QGAUSSIAN_H__

#if !defined( LDPROFILE_NO_INCLUDES )
    #include "ldprofile/base_profile.hpp"
    #include "ldprofile/qgauss.h"
#endif /* !defined( LDPROFILE_NO_INCLUDES ) */

#if defined( __cplusplus )
namespace ldprofile
{
    static constexpr ld_method_type LDPROFILE_METHOD_QGAUSSIAN =
        ld_method_type{ 0x02 };

    template< class T >
    struct TQGaussianSupport
    {
        T min_support;
        T max_support;
    };

    template< class T >
    class TQGaussianLDProfile : public TLineDensityProfileBase< T >
    {
        public:

        using value_type = typename TLineDensityProfileBase< T >::value_type;
        using method_type = typename TLineDensityProfileBase< T >::method_type;

        LDPROFILE_FN static method_type Method() LDPROFILE_NOEXCEPT
        {
            return LDPROFILE_METHOD_QGAUSSIAN;
        }

        LDPROFILE_FN explicit TQGaussianLDProfile(
            value_type const q = value_type{ 0 } ) :
            TLineDensityProfileBase< T >( Method() ),
            m_q( q ), m_sqrt_beta( ldprofile::MATH_QGAUSS_INV_SQRT2< T >() ),
            m_cq( ldprofile::Math_q_gauss_cq< T >( q ) )
        {}

        LDPROFILE_FN explicit TQGaussianLDProfile(
            value_type const q, value_type const sqrt_beta ) :
            TLineDensityProfileBase< T >( Method() ),
            m_q( q ), m_sqrt_beta( sqrt_beta ),
            m_cq( ldprofile::Math_q_gauss_cq< T >( q ) )
        {
            LDPROFILE_ASSERT( sqrt_beta > T{ 0 } );
        }

        LDPROFILE_FN TQGaussianLDProfile(
            TQGaussianLDProfile< T > const& ) = default;

        LDPROFILE_FN TQGaussianLDProfile( TQGaussianLDProfile< T >&& ) = default;

        LDPROFILE_FN TQGaussianLDProfile< T >& operator=(
            TQGaussianLDProfile< T > const& ) = default;

        LDPROFILE_FN TQGaussianLDProfile< T >& operator=(
            TQGaussianLDProfile< T >&& ) = default;

        LDPROFILE_FN virtual ~TQGaussianLDProfile() = default;

        LDPROFILE_FN void update( T const& q, T const& sqrt_beta )
        {
            LDPROFILE_ASSERT( q < T{ 3 } );
            LDPROFILE_ASSERT( sqrt_beta > T{ 0 } );

            this->m_q = q;
            this->m_sqrt_beta = sqrt_beta;
            this->m_cq = ldprofile::Math_q_gauss_cq( q );
        }

        LDPROFILE_FN void update( T const& gauss_sigma )
        {
            LDPROFILE_ASSERT( gauss_sigma > T{ 0 } );
            this->update( T{ 1 },
                ldprofile::Math_q_gauss_sqrt_beta_from_gauss_sigma(
                    gauss_sigma ) );
        }

        LDPROFILE_FN value_type min_support() const LDPROFILE_NOEXCEPT
        {
            return ldprofile::Math_q_gauss_min_support(
                this->m_q, this->m_sqrt_beta );
        }

        LDPROFILE_FN value_type max_support() const LDPROFILE_NOEXCEPT
        {
            return ldprofile::Math_q_gauss_max_support(
                this->m_q, this->m_sqrt_beta );
        }

        LDPROFILE_FN value_type q() const LDPROFILE_NOEXCEPT
        {
            return this->m_q;
        }

        LDPROFILE_FN value_type cq() const LDPROFILE_NOEXCEPT
        {
            return this->m_cq;
        }

        LDPROFILE_FN value_type sqrt_beta() const LDPROFILE_NOEXCEPT
        {
            return this->m_sqrt_beta;
        }

        protected:

        LDPROFILE_FN value_type do_calc_value( T const& z ) const override
        {
            return ldprofile::Math_q_gauss(
                z, this->m_q, this->m_sqrt_beta, this->m_cq );
        }

        private:

        value_type m_q;
        value_type m_sqrt_beta;
        value_type m_cq;
    };

    using QGaussianLDProfile = TQGaussianLDProfile< double >;
}

using QGaussianLDProfile = ldprofile::QGaussianLDProfile;

#else

struct QGaussianLDProfile;

#endif /* C++ */

#if defined( __cplusplus ) && !defined( _GPUCODE )
extern "C" {
#endif /* C++, Host */

LDPROFILE_HOST_FN QGaussianLDProfile* LDProfileQGaussian_create(
    double const q, double const sqrt_beta );

LDPROFILE_HOST_FN QGaussianLDProfile* LDProfileQGaussian_create_gaussian(
    double const gaussian_sigma );

LDPROFILE_HOST_FN double LDProfileQGaussian_q(
    const QGaussianLDProfile *const profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_HOST_FN double LDProfileQGaussian_min_support(
    const QGaussianLDProfile *const profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_HOST_FN double LDProfileQGaussian_max_support(
    const QGaussianLDProfile *const profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_HOST_FN double LDProfileQGaussian_sqrt_beta(
    const QGaussianLDProfile *const profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_HOST_FN double LDProfileQGaussian_cq(
    const QGaussianLDProfile *const profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_HOST_FN void LDProfileQGaussian_update_as_gaussian(
    QGaussianLDProfile* profile,
    double const gaussian_sigma ) LDPROFILE_NOEXCEPT;

LDPROFILE_HOST_FN void LDProfileQGaussian_update( QGaussianLDProfile* profile,
    double const q, double const sqrt_beta ) LDPROFILE_NOEXCEPT;

#if defined( __cplusplus ) && !defined( _GPUCODE )
}
#endif /* C++, Host */

#endif /* LDPRPOFILE_LD_QGAUSSIAN_H__ */
