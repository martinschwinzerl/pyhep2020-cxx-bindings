#ifndef LDPRPOFILE_LD_LINEAR_INTERPOL1D_H__
#define LDPRPOFILE_LD_LINEAR_INTERPOL1D_H__

#if !defined( LDPROFILE_NO_INCLUDES )
    #include "ldprofile/base_profile.h"
    #include "ldprofile/qgauss.h"
#endif /* !defined( LDPROFILE_NO_INCLUDES ) */

#if !defined( LDPROFILE_NO_SYSTEM_INCLUDES )
    #include <algorithm>
    #include <cmath>
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
        using size_type = typename TLineDensityProfileBase< T >::size_type;

        LDPROFILE_FN static method_type Method() LDPROFILE_NOEXCEPT
        {
            return LDPROFILE_METHOD_LINEAR_INTERPOL1D;
        }

        LDPROFILE_FN TLinInterpolLDProfile(
            value_type const z0, value_type const dz,
            size_type const num_values,
            value_type const* values_begin = nullptr ) :
            TLineDensityProfileBase< T >( Method() ),
            m_values( num_values, value_type{ 0 } ), m_z0(), m_dz()
        {
            this->update( z0, dz, num_values, values_begin );
        }

        template< typename Iter >
        LDPROFILE_FN TLinInterpolLDProfile(
            value_type const z0, value_type const dz,
            Iter values_begin, Iter values_end ) :
            TLineDensityProfileBase< T >( Method() ), m_values(), m_z0(), m_dz()
        {
            this->update( z0, dz, values_begin, values_end );
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

        LDPROFILE_FN T const* values_begin() const LDPROFILE_NOEXCEPT
        {
            return this->m_values.data();
        }

        LDPROFILE_FN T* values_begin() LDPROFILE_NOEXCEPT
        {
            return this->m_values.data();
        }

        LDPROFILE_FN T const* values_end() const LDPROFILE_NOEXCEPT
        {
            auto ptr_end = this->values_begin();
            if( ptr_end != nullptr ) ptr_end = ptr_end + this->m_values.size();
            return ptr_end;
        }

        LDPROFILE_FN T* values_end() LDPROFILE_NOEXCEPT
        {
            return const_cast< T* >( static_cast< TLinInterpolLDProfile<
                T > const& >( *this ).values_end() );
        }

        LDPROFILE_FN T const& value( size_type const idx ) const
        {
            return this->m_values.at( idx );
        }

        LDPROFILE_FN T& value( size_type const idx )
        {
            return const_cast< T& >( static_cast< TLinInterpolLDProfile<
                T > const& >( *this ).value( idx ) );
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

        LDPROFILE_FN void update( value_type const& z0, value_type const& dz,
            size_type const num_values,
            value_type const* values_begin = nullptr )
        {
            LDPROFILE_ASSERT( dz > value_type{ 0 } );
            size_type const sanitized_num_values =
                ( num_values >= size_type{ 2 } ) ? num_values : size_type{ 2 };

            this->m_z0 = z0;
            this->m_dz = dz;

            if( values_begin == nullptr )
            {
                this->m_values.clear();
                this->m_values.resize( sanitized_num_values, value_type{ 0 } );
            }
            else
            {
                this->m_values.assign(
                    values_begin, values_begin + sanitized_num_values );
            }
        }


        template< typename Iter >
        LDPROFILE_FN void update( value_type const& z0, value_type const& dz,
            Iter values_begin, Iter values_end )
        {
            LDPROFILE_ASSERT( dz > value_type{ 0 } );

            this->m_z0 = z0;
            this->m_dz = dz;

            if( std::distance( values_begin, values_end ) >= std::ptrdiff_t{ 2 } )
            {
                this->m_values.assign( values_begin, values_end );
            }
            else
            {
                this->m_values.clear();
                this->m_values.resize( 2, value_type{ 0 } );
            }
        }

        protected:

        LDPROFILE_FN void do_calc_value(
            T* result_begin, T const* z_begin, size_type const num_z ) const
        {
            LDPROFILE_ASSERT( result_begin != nullptr );
            LDPROFILE_ASSERT( z_begin != nullptr );

            #if !defined( _GPUCODE )
            using std::floor;
            #endif /* _GPUCODE */

            for( size_type ii = size_type{ 0 } ; ii < num_z ; ++ii )
            {
                T const z = z_begin[ ii ];

                LDPROFILE_ASSERT( z >= this->m_z0 );
                LDPROFILE_ASSERT( this->m_dz > T{ 0 } );
                LDPROFILE_ASSERT( !this->m_values.empty() );
                LDPROFILE_ASSERT( z <= (
                    this->m_z0 + this->m_dz * this->m_values.size() ) );

                size_type const idx = static_cast< size_type >(
                    floor( ( z - this->m_z0 ) / this->m_dz ) );

                LDPROFILE_ASSERT( idx < this->m_values.size() );
                value_type const zi = this->m_z0 + idx * this->m_dz;
                LDPROFILE_ASSERT( zi <= z );
                LDPROFILE_ASSERT( zi + this->m_dz >= z );

                result_begin[ ii ] = this->m_values[ idx ] + ( z - zi ) *
                    ( this->m_values[ idx + 1 ] - this->m_values[ idx ] ) /
                        this->m_dz;
            }
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

LDPROFILE_EXTERN LDPROFILE_HOST_FN LinInterpolLDProfile*
LDProfileLinInterpol_create(
    double const z0, double const dz, size_t const num_values );

LDPROFILE_EXTERN LDPROFILE_HOST_FN LinInterpolLDProfile*
LDProfileLinInterpol_create_detailed(
    double const z0, double const dz, size_t const num_values,
    double const* values_begin );

LDPROFILE_EXTERN LDPROFILE_HOST_FN bool LDProfile_is_lin_interpol(
    const LDProfile *const base_profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double LDProfileLinInterpol_z0(
    const LDProfile *const base_profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double LDProfileLinInterpol_dz(
    const LDProfile *const base_profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double const*
LDProfileLinInterpol_const_values_begin(
    const LDProfile *const base_profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double const*
LDProfileLinInterpol_const_values_end(
    const LDProfile *const base_profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double*
LDProfileLinInterpol_values_begin( LDProfile* base_profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double*
LDProfileLinInterpol_values_end( LDProfile* base_profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_EXTERN LDPROFILE_HOST_FN double LDProfileLinInterpol_value(
    const LDProfile *const base_profile, size_t const idx );

LDPROFILE_EXTERN LDPROFILE_HOST_FN void LDProfileLinInterpol_set_value(
    LDProfile* base_profile, size_t const idx, double const value );

LDPROFILE_EXTERN LDPROFILE_HOST_FN size_t
LDProfileLinInterpol_num_values(
    const LDProfile *const base_profile ) LDPROFILE_NOEXCEPT;

#if defined( __cplusplus ) && !defined( _GPUCODE )
}
#endif /* C++, Host */
#endif /* LDPRPOFILE_LD_LINEAR_INTERPOL1D_H__ */
