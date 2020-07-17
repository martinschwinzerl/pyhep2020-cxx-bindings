#ifndef LDPRPOFILE_LD_QGAUSSIAN_H__
#define LDPRPOFILE_LD_QGAUSSIAN_H__

#if !defined( LDPROFILE_NO_INCLUDES )
    #include "ldprofile/base_profile.h"
    #include "ldprofile/qgauss.h"
#endif /* !defined( LDPROFILE_NO_INCLUDES ) */

#if !defined( LDPROFILE_NO_SYSTEM_INCLUDES )
    #include <algorithm>
#endif /* !defined( LDPROFILE_NO_SYSTEM_INCLUDES ) */

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
        using size_type = typename TLineDensityProfileBase< T >::size_type;

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

        LDPROFILE_FN void do_calc_value(
            T* result_begin, T const* z_begin, size_type const num_z ) const
        {
            LDPROFILE_ASSERT( result_begin != nullptr );
            LDPROFILE_ASSERT( z_begin != nullptr );

            #if !defined( _GPUCODE )
            T const* z_end = z_begin;
            std::advance( z_end, num_z );
            std::transform( z_begin, z_end, result_begin,
                [this]( T const& z ) -> T
            {
                return ldprofile::Math_q_gauss< T >(
                    z, this->m_q, this->m_sqrt_beta, this->m_cq );
            } );

            #else
            for( size_type ii = size_type{ 0 } ; ii < num_z ; ++ii )
            {
                result_begin[ ii ] = ldprofile::Math_q_gauss< T >(
                    z_begin[ ii ], this->m_q, this->m_sqrt_beta, this->m_cq );
            }

            #endif /* _GPUCODE */
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

LDPROFILE_EXTERN LDPROFILE_HOST_FN QGaussianLDProfile*
LDProfileQGaussian_create( double const q, double const sqrt_beta );

LDPROFILE_EXTERN LDPROFILE_HOST_FN QGaussianLDProfile*
LDProfileQGaussian_create_gaussian( double const gaussian_sigma );

LDPROFILE_EXTERN LDPROFILE_HOST_FN bool LDProfile_is_qgaussian(
    const LDProfile *const base_profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double LDProfileQGaussian_q(
    const LDProfile *const base_profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double LDProfileQGaussian_min_support(
    const LDProfile *const base_profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double LDProfileQGaussian_max_support(
    const LDProfile *const base_profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double LDProfileQGaussian_sqrt_beta(
    const LDProfile *const base_profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double LDProfileQGaussian_cq(
    const LDProfile *const base_profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN void
LDProfileQGaussian_update_as_gaussian( LDProfile* base_profile,
    double const gaussian_sigma ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN void LDProfileQGaussian_update(
    LDProfile* base_profile,
    double const q, double const sqrt_beta ) LDPROFILE_NOEXCEPT;

#if defined( __cplusplus ) && !defined( _GPUCODE )
}
#endif /* C++, Host */

#endif /* LDPRPOFILE_LD_QGAUSSIAN_H__ */
