#ifndef LDPRPOFILE_LD_COASTING_H__
#define LDPRPOFILE_LD_COASTING_H__

#if !defined( LDPROFILE_NO_INCLUDES )
    #include "ldprofile/base_profile.hpp"
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

        LDPROFILE_FN static method_type Method() LDPROFILE_NOEXCEPT
        {
            return LDPROFILE_METHOD_COASTING;
        }

        LDPROFILE_FN TCoastingLDProfile(
            value_type const value = value_type{ 0 } ) :
            TLineDensityProfileBase< T >( Method() ), m_value( value ) {}

        LDPROFILE_FN TCoastingLDProfile(
            TCoastingLDProfile< T > const& ) = default;

        LDPROFILE_FN TCoastingLDProfile( TCoastingLDProfile< T >&& ) = default;

        LDPROFILE_FN TCoastingLDProfile< T >& operator=(
            TCoastingLDProfile< T > const& ) = default;

        LDPROFILE_FN TCoastingLDProfile< T >& operator=(
            TCoastingLDProfile< T >&& ) = default;

        LDPROFILE_FN virtual ~TCoastingLDProfile() = default;

        LDPROFILE_FN void set_value( T const& value )
        {
            this->m_value = value;
        }

        protected:

        LDPROFILE_FN value_type do_calc_value( T const&
            LDPROFILE_UNUSED( z ) ) const override
        {
            return this->m_value;
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

LDPROFILE_HOST_FN void LDProfileCoasting_set_value(
    CoastingLDProfile* profile, double const new_value ) LDPROFILE_NOEXCEPT;


#if defined( __cplusplus ) && !defined( _GPUCODE )
}
#endif /* C++, Host */

#endif /* LDPRPOFILE_LD_COASTING_H__ */
