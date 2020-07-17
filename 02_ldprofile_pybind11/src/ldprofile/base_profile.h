#ifndef LDPROFILE_BASE_PROFILE_CXX_HPP__
#define LDPROFILE_BASE_PROFILE_CXX_HPP__

#if !defined( LDPROFILE_NO_INCLUDES )
    #include "ldprofile/definitions.h"
#endif /* !defined( LDPROFILE_NO_INCLUDES ) */

#if !defined( LDPROFILE_NO_SYSTEM_INCLUDES )
    #include <algorithm>
    #include <cstdint>
    #include <type_traits>
#endif /* !defined( LDPROFILE_NO_SYSTEM_INCLUDES ) */

typedef uint64_t ld_method_type;

#if defined( __cplusplus )
namespace ldprofile
{
    using ld_method_type = ::ld_method_type;

    static constexpr ld_method_type LDPROFILE_ILLEGAL_METHOD =
        ld_method_type{ 0xff };

    template< class T >
    class TLineDensityProfileBase
    {
        public:

        using value_type = T;
        using method_type = ::ld_method_type;
        using size_type = std::size_t;

        static constexpr method_type ILLEGAL_METHOD = LDPROFILE_ILLEGAL_METHOD;

        LDPROFILE_FN method_type method() const LDPROFILE_NOEXCEPT
        {
            return this->m_method;
        }

        LDPROFILE_FN value_type evaluate( T const& z ) const
        {
            /* NOTE: Not optimal if value() is called in the "
             *       hot-path / tight loops! */

            value_type result;
            this->do_calc_value( &result, &z, size_type{ 1 } );
            return result;
        }

        LDPROFILE_FN void evaluate( T* result_begin,
            T const* z_begin, size_type const num_z ) const
        {
            this->do_calc_value( result_begin, z_begin, num_z );
        }

        LDPROFILE_FN virtual ~TLineDensityProfileBase() = default;

        protected:

        LDPROFILE_FN explicit TLineDensityProfileBase( method_type const method ) :
            m_method( method ) {}

        LDPROFILE_FN TLineDensityProfileBase(
            TLineDensityProfileBase< T > const& orig ) = default;

        LDPROFILE_FN TLineDensityProfileBase(
            TLineDensityProfileBase< T >&& orig ) = default;

        LDPROFILE_FN TLineDensityProfileBase< T >& operator=(
            TLineDensityProfileBase< T > const& orig ) = default;

        LDPROFILE_FN TLineDensityProfileBase< T >& operator=(
            TLineDensityProfileBase< T >&& orig ) = default;

        LDPROFILE_FN void do_set_method(
            method_type const method ) LDPROFILE_NOEXCEPT
        {
            this->m_method = method;
        }

        LDPROFILE_FN virtual void do_calc_value( T* result_begin,
            T const* LDPROFILE_UNUSED( z_begin ), size_type const num_z ) const
        {
            LDPROFILE_ASSERT( result_begin != nullptr );

            #if !defined( _GPUCODE )
            T* result_end = result_begin;
            std::advance( result_end, num_z );
            std::fill( result_begin, result_end, T{ 0 } );

            #else
            for( size_type ii = size_type{ 0 } ; ii < num_z ; ++ii )
            {
                result_begin[ ii ] = T{ 0 };
            }

            #endif /* _GPUCODE */
        }

        private:

        method_type m_method;
    };

    template< class T >
    constexpr typename TLineDensityProfileBase< T >::method_type
        TLineDensityProfileBase< T >::ILLEGAL_METHOD;

    /* --------------------------------------------------------------------- */

    template< class Derived, typename _SFINAE_Enabled = void >
    struct TLineDensityProfileBaseTraits
    {
        static ld_method_type Method() LDPROFILE_NOEXCEPT
        {
            return ldprofile::LDPROFILE_ILLEGAL_METHOD;
        }
    };

    template< class Derived >
    struct TLineDensityProfileBaseTraits< Derived, typename std::enable_if<
        Derived::Method() != ldprofile::LDPROFILE_ILLEGAL_METHOD, void >::type >
    {
        static ld_method_type Method() LDPROFILE_NOEXCEPT
        {
            return Derived::Method();
        }
    };

    /* --------------------------------------------------------------------- */

    template< class Derived, class T = typename Derived::value_type >
    LDPROFILE_STATIC LDPROFILE_INLINE typename std::enable_if<
        std::is_base_of< TLineDensityProfileBase< T >, Derived >::value,
        Derived const* >::type
    as_derived( const TLineDensityProfileBase< T > *const
        ptr_base ) LDPROFILE_NOEXCEPT
    {
        using base_t = TLineDensityProfileBase< T >;
        using traits_t = TLineDensityProfileBaseTraits< Derived >;
        Derived const* ptr_derived = nullptr;

        if( ( ptr_base != nullptr ) &&
            ( ptr_base->method() != base_t::ILLEGAL_METHOD ) &&
            ( ptr_base->method() == traits_t::Method() ) )
        {
            ptr_derived = static_cast< Derived const* >( ptr_base );
        }

        return ptr_derived;
    }

    template< class Derived, class T = typename Derived::value_type >
    LDPROFILE_STATIC LDPROFILE_INLINE typename std::enable_if<
        !std::is_base_of< TLineDensityProfileBase< T >, Derived >::value,
        Derived const* >::type
    as_derived( const TLineDensityProfileBase<
        typename Derived::value_type > *const LDPROFILE_UNUSED(
            ptr_base ) ) LDPROFILE_NOEXCEPT
    {
        return nullptr;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< class Derived, class T = typename Derived::value_type >
    LDPROFILE_STATIC LDPROFILE_INLINE Derived* as_derived(
        TLineDensityProfileBase< T >* ptr_base ) LDPROFILE_NOEXCEPT
    {
        return const_cast< Derived* >( ldprofile::as_derived< Derived, T >(
            static_cast< TLineDensityProfileBase< T > const* >( ptr_base ) ) );
    }
}

using LDProfile = ldprofile::TLineDensityProfileBase< double >;

#else

struct LDProfile;

#endif /* C++ */

#if defined( __cplusplus ) && !defined( _GPUCODE )
extern "C" {
#endif /* C++, Host */

LDPROFILE_FN void LDProfile_delete( LDProfile* profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_FN ld_method_type LDProfile_method(
    const LDProfile *const profile ) LDPROFILE_NOEXCEPT;

LDPROFILE_FN double LDProfile_evaluate(
    const LDProfile *const profile, double const z );

LDPROFILE_FN void LDProfile_evaluate_num_values(
    const LDProfile *const profile, double* result_begin,
    double const* z_begin, size_t const num_values );

#if defined( __cplusplus ) && !defined( _GPUCODE )
}
#endif /* C++, Host */
#endif /* LDPROFILE_BASE_PROFILE_CXX_HPP__ */
