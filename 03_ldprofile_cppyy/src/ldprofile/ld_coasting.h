#ifndef LDPRPOFILE_LD_COASTING_H__
#define LDPRPOFILE_LD_COASTING_H__

#if !defined( LDPROFILE_NO_INCLUDES )
    #include "ldprofile/base_profile.h"
#endif /* !defined( LDPROFILE_NO_INCLUDES ) */

#if defined( __cplusplus )
namespace ldprofile
{
    static constexpr ld_method_type LDPROFILE_METHOD_COASTING =
        ld_method_type{ 0x01 };

    template< class T >
    class TCoastingLDProfile : public TLineDensityProfileBase< T >
    {
        public:

        using value_type = typename TLineDensityProfileBase< T >::value_type;
        using method_type = typename TLineDensityProfileBase< T >::method_type;
        using size_type = typename TLineDensityProfileBase< T >::size_type;

        LDPROFILE_FN static method_type Method() LDPROFILE_NOEXCEPT
        {
            return LDPROFILE_METHOD_COASTING;
        }

        LDPROFILE_FN TCoastingLDProfile(
            value_type const& value = value_type{ 0 } ) :
            TLineDensityProfileBase< T >( Method() ), m_value( value ) {}

        LDPROFILE_FN TCoastingLDProfile(
            TCoastingLDProfile< T > const& ) = default;

        LDPROFILE_FN TCoastingLDProfile( TCoastingLDProfile< T >&& ) = default;

        LDPROFILE_FN TCoastingLDProfile< T >& operator=(
            TCoastingLDProfile< T > const& ) = default;

        LDPROFILE_FN TCoastingLDProfile< T >& operator=(
            TCoastingLDProfile< T >&& ) = default;

        LDPROFILE_FN virtual ~TCoastingLDProfile() = default;

        LDPROFILE_FN T const& value() const LDPROFILE_NOEXCEPT
        {
            return this->m_value;
        }

        LDPROFILE_FN void update( T const& value )
        {
            this->m_value = value;
        }

        protected:

        LDPROFILE_FN void do_calc_value( T* result_begin,
            T const* LDPROFILE_UNUSED( z_begin ), size_type const num_z ) const
        {
            LDPROFILE_ASSERT( result_begin != nullptr );

            #if !defined( _GPUCODE )
            T* result_end = result_begin;
            std::advance( result_end, num_z );
            std::fill( result_begin, result_end, this->m_value );

            #else
            for( size_type ii = size_type{ 0 } ; ii < num_z ; ++ii )
            {
                result_begin[ ii ] = this->m_value;
            }

            #endif /* _GPUCODE */
        }

        private:

        value_type m_value;
    };

    using CoastingLDProfile = TCoastingLDProfile< double >;
}

using CoastingLDProfile = ldprofile::CoastingLDProfile;

#else

struct CoastingLDProfile;

#endif /* C++ */

#if defined( __cplusplus ) && !defined( _GPUCODE )
extern "C" {
#endif /* C++, Host */

LDPROFILE_HOST_FN CoastingLDProfile* LDProfileCoasting_create(
    double const value );

LDPROFILE_HOST_FN bool LDProfile_is_coasting(
    const LDProfile *const profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_HOST_FN double LDProfileCoasting_value(
    const LDProfile *const profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_HOST_FN void LDProfileCoasting_update(
    LDProfile* profile, double const new_value ) LDPROFILE_NOEXCEPT;

#if defined( __cplusplus ) && !defined( _GPUCODE )
}
#endif /* C++, Host */
#endif /* LDPRPOFILE_LD_COASTING_H__ */
