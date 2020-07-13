#ifndef LDPRPOFILE_LD_LINEAR_INTERPOL1D_H__
#define LDPRPOFILE_LD_LINEAR_INTERPOL1D_H__

#if !defined( LDPROFILE_NO_INCLUDES )
    #include "ldprofile/base_profile.hpp"
    #include "ldprofile/qgauss.h"
#endif /* !defined( LDPROFILE_NO_INCLUDES ) */

#if !defined( LDPROFILE_NO_SYSTEM_INCLUDES )
    #include <algorithm>
    #include <vector>
#endif /* !defined( LDPROFILE_NO_SYSTEM_INCLUDES ) */

#if defined( __cplusplus )
namespace ldprofile
{
    static constexpr ld_method_type LDPROFILE_METHOD_LINEAR_INTERPOL1D =
        ld_method_type{ 0x03 };

    template< class T >
    class TLinInterpolLDProfile : public TLineDensityProfileBase< T >
    {
        public:

        using value_type = typename TLineDensityProfileBase< T >::value_type;
        using method_type = typename TLineDensityProfileBase< T >::method_type;
        using size_type = typename std::vector< value_type >::size_type;

        LDPROFILE_FN static method_type Method() LDPROFILE_NOEXCEPT
        {
            return LDPROFILE_METHOD_LINEAR_INTERPOL1D;
        }

        LDPROFILE_FN explicit TLinInterpolLDProfile(
            size_type const num_values,
            value_type const z0 = value_type{ 0 },
            value_type const dz = value_type{ 1 } ) :
            TLineDensityProfileBase< T >( Method() ),
            m_values( num_values, value_type{ 0 } ), m_z0( z0 ), m_dz( dz )
        {
            LDPROFILE_ASSERT( dz > value_type{ 0 } );
        }

        LDPROFILE_FN explicit TLinInterpolLDProfile(
            value_type const* values_begin, size_type const num_values,
            value_type const z0 = value_type{ 0 },
            value_type const dz = value_type{ 1 } ) :
            TLineDensityProfileBase< T >( Method() ),
            m_values( num_values, value_type{ 0 } ), m_z0( z0 ), m_dz( dz )
        {
            LDPROFILE_ASSERT( dz > value_type{ 0 } );

            if( values_begin != nullptr )
            {
                std::copy( values_begin, values_begin + num_values,
                           this->m_values.begin() );
            }
        }

        template< typename Iter >
        LDPROFILE_FN TLinInterpolLDProfile(
            Iter values_begin, Iter values_end, value_type const z0,
            value_type const dz ) :
            TLineDensityProfileBase< T >( Method() ),
            m_values( values_begin, values_end ), m_z0( z0 ), m_dz( dz )
        {

        }

        LDPROFILE_FN TLinInterpolLDProfile(
            TLinInterpolLDProfile< T > const& ) = default;

        LDPROFILE_FN TLinInterpolLDProfile(
            TLinInterpolLDProfile< T >&& ) = default;

        LDPROFILE_FN TLinInterpolLDProfile< T >& operator=(
            TLinInterpolLDProfile< T > const& ) = default;

        LDPROFILE_FN TLinInterpolLDProfile< T >& operator=(
            TLinInterpolLDProfile< T >&& ) = default;

        LDPROFILE_FN virtual ~TLinInterpolLDProfile() = default;

        LDPROFILE_FN T const* profile_values_begin() const LDPROFILE_NOEXCEPT
        {
            return this->m_values.data();
        }

        LDPROFILE_FN T* profile_values_begin() LDPROFILE_NOEXCEPT
        {
            return this->m_values.data();
        }

        LDPROFILE_FN T const* profile_values_end() const LDPROFILE_NOEXCEPT
        {
            auto ptr_end = this->profile_values_begin();
            if( ptr_end != nullptr ) ptr_end = ptr_end + this->m_values.size();
            return ptr_end;
        }

        LDPROFILE_FN T* profile_values_end() LDPROFILE_NOEXCEPT
        {
            return const_cast< T* >( static_cast< TLinInterpolLDProfile<
                T > const& >( *this ).profile_values_end() );
        }

        LDPROFILE_FN T const& profile_value(
            size_type const idx ) const LDPROFILE_NOEXCEPT
        {
            LDPROFILE_ASSERT( idx < this->m_values.size() );
            return this->m_values[ idx ];
        }

        LDPROFILE_FN T& profile_value( size_type const idx ) LDPROFILE_NOEXCEPT
        {
            return const_cast< T& >( static_cast< TLinInterpolLDProfile<
                T > const& >( *this ).profile_value( idx ) );
        }

        LDPROFILE_FN size_type num_values() const LDPROFILE_NOEXCEPT
        {
            return this->m_values.size();
        }

        LDPROFILE_FN T const& z0() const LDPROFILE_NOEXCEPT
        {
            return this->m_z0;
        }

        LDPROFILE_FN T const& dz() const LDPROFILE_NOEXCEPT
        {
            return this->m_dz;
        }

        protected:

        LDPROFILE_FN value_type do_calc_value( T const& z ) const override
        {
            LDPROFILE_ASSERT( z >= this->m_z0 );
            LDPROFILE_ASSERT( this->m_dz > T{ 0 } );
            LDPROFILE_ASSERT( !this->m_values.empty() );
            LDPROFILE_ASSERT( z <= (
                this->m_z0 + this->m_dz * this->m_values.size() ) );

            size_type const idx = ( z - this->m_z0 ) / this->m_dz;
            LDPROFILE_ASSERT( idx < this->m_values.size() );
            LDPROFILE_ASSERT( this->m_values[ idx ] <= z );
            LDPROFILE_ASSERT( this->m_values[ idx + 1 ] >= z );

            return this->m_values[ idx ] + ( z - this->m_z0 ) *
                ( this->m_values[ idx + 1 ] - this->m_values[ idx ] ) /
                    this->m_dz;
        }

        private:

        std::vector< value_type > m_values;
        value_type m_z0;
        value_type m_dz;
    };

    using LinInterpolLDProfile = TLinInterpolLDProfile< double >;
}

using LinInterpolLDProfile = ldprofile::LinInterpolLDProfile;

#else

struct LinInterpolLDProfile;

#endif /* C++ */

#if defined( __cplusplus ) && !defined( _GPUCODE )
extern "C" {
#endif /* C++, Host */

LDPROFILE_FN LinInterpolLDProfile* LDProfileLinInterpol_create(
    size_t const num_values, double const z0, double const dz );

LDPROFILE_FN LinInterpolLDProfile* LDProfileLinInterpol_create_detailed(
    double const* values_begin, size_t const num_values,
    double const z0, double const dz );

LDPROFILE_FN double LDProfileLinInterpol_z0(
    const LinInterpolLDProfile *const profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_FN double const* LineInterpol1DProfile_const_profile_values_begin(
    const LinInterpolLDProfile *const profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_FN double const* LineInterpol1DProfile_const_profile_values_end(
    const LinInterpolLDProfile *const profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_FN double* LineInterpol1DProfile_profile_values_begin(
    LinInterpolLDProfile* profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_FN double* LineInterpol1DProfile_profile_values_end(
    LinInterpolLDProfile* profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_FN double LineInterpol1DProfile_profile_value(
    const LinInterpolLDProfile *const profile,
    size_t const idx ) LDPROFILE_NOEXCEPT;

LDPROFILE_FN void LineInterpol1DProfile_set_profile_value(
    LinInterpolLDProfile* profile, size_t const idx,
    double const value ) LDPROFILE_NOEXCEPT;

LDPROFILE_FN size_t LineInterpol1DProfile_num_values(
    const LinInterpolLDProfile *const profile ) LDPROFILE_NOEXCEPT;

#if defined( __cplusplus ) && !defined( _GPUCODE )
}
#endif /* C++, Host */
#endif /* LDPRPOFILE_LD_LINEAR_INTERPOL1D_H__ */
