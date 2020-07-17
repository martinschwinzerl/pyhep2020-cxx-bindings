#ifndef LDPROFILE_PYBIND11_LDPROFILE_WRAP_CXX_HPP__
#define LDPROFILE_PYBIND11_LDPROFILE_WRAP_CXX_HPP__

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include <stdexcept>
#include <vector>
#include <iostream>

// NOTE: correct include path from target_link_libary with ldprofilecore
#include "ldprofile/ldprofile.h"

namespace ldprofile
{
namespace python
{
    template< class T >
    LDPROFILE_STATIC LDPROFILE_INLINE void Create_bindings_base_profile(
        pybind11::module& m,
        pybind11::class_< ldprofile::TLineDensityProfileBase< T > >& cls )
    {
        namespace py = pybind11;
        namespace ld = ldprofile;

        using base_profile_t = ld::TLineDensityProfileBase< T >;
        using value_t = typename base_profile_t::value_type;

        // getter methods can be directly translated into @property getters
        cls.def_property_readonly( "method", &base_profile_t::method );

        // Overloading the evaluate member to allow both scalar and
        // vector valued arguments:

        // Scalar method:
        cls.def( "evaluate",
                 []( base_profile_t& instance, value_t const& z ) -> value_t
                 {
                     return instance.evaluate( z );
                 },
                 "evaluate longitudinal density profile at position z",
                 py::arg( "z_value" ) );

        // Generic buffer implementation
        cls.def( "evaluate",
                 []( base_profile_t& instance, py::buffer const& z ) ->
                     py::array_t< value_t >
                 {
                     // get the buffer_info of the input buffer
                     py::buffer_info z_info = z.request();

                     // ensure that the input array is a vector
                     if( z_info.ndim != 1 )
                         throw std::runtime_error( "ndim != 1" );

                     // create a result buffer info
                     py::array_t< value_t > result( py::buffer_info(
                         nullptr, // nullptr -> allocate
                         sizeof( value_t ), // itemsize
                         py::format_descriptor< value_t >::format(), //fmt str
                         z_info.ndim, // ndim
                         z_info.shape, //
                         z_info.strides ) );

                     py::buffer_info result_info = result.request();

                     instance.evaluate(
                         static_cast< value_t* >( result_info.ptr ),
                         static_cast< value_t const* >( z_info.ptr ),
                         result.size() );

                    return py::array_t< value_t >( result_info );
                 },
                 "evaluate longitudinal density profile at multiple positions z",
                 py::arg( "z_values" ) );

    }

    template< class T >
    LDPROFILE_STATIC LDPROFILE_INLINE void Create_bindings_coasting_profile(
        pybind11::module& m,
        pybind11::class_< ldprofile::TCoastingLDProfile< T > >& cls )
    {
        namespace py = pybind11;
        namespace ld = ldprofile;

        using coasting_profile_t = ld::TCoastingLDProfile< T >;
        using value_t = typename coasting_profile_t::value_type;

        // Constructor -> we can define our own default arguments which
        // can differ from the defaults in C++!

        cls.def( py::init(
            []( value_t const& ld_value )
            {
                // use make_unique if available!
                return std::unique_ptr< coasting_profile_t >(
                    new coasting_profile_t( ld_value ) );
            } ),
            py::arg( "value" ) = value_t{ 42 } );

        // similar to above, we can define different constructors, evan allowing
        // to add ones not present in C++ !! */

        // getter for ld profile value -> @property
        cls.def_property_readonly( "value", &coasting_profile_t::value );

        // update method
        cls.def( "update", &coasting_profile_t::update,
             "update the longitudinal density profile value",
             py::arg( "new_value" ) );

        // expose static member function as a @staticmethod
        cls.def_static( "METHOD", &coasting_profile_t::Method );
    }

    template< class T >
    LDPROFILE_STATIC LDPROFILE_INLINE void Create_bindings_qgauss_profile(
        pybind11::module& m,
        pybind11::class_< ldprofile::TQGaussianLDProfile< T > >& cls )
    {
        namespace py = pybind11;
        namespace ld = ldprofile;

        using qgauss_profile_t = ld::TQGaussianLDProfile< T >;
        using value_t = typename qgauss_profile_t::value_type;

        // Constructor -> we can define our own default arguments which
        // can differ from the defaults in C++!

        cls.def( py::init(
            []( value_t const& gauss_sigma )
            {
                // use make_unique if available!
                return std::unique_ptr< qgauss_profile_t >(
                    new qgauss_profile_t( gauss_sigma ) );
            } ),
            py::arg( "gauss_sigma" ) = value_t{ 1 } );

        cls.def( py::init(
            []( value_t const& q, value_t const& sqrt_beta )
            {
                // use make_unique if available!
                return std::unique_ptr< qgauss_profile_t >(
                    new qgauss_profile_t( q, sqrt_beta ) );
            } ),
            py::arg( "q" ), py::arg( "sqrt_beta" ) );

        // similar to above, we can define different constructors, evan allowing
        // to add ones not present in C++ !! */

        // getters -> @property based getters
        cls.def_property_readonly(
            "min_support", &qgauss_profile_t::min_support );

        cls.def_property_readonly(
            "max_support", &qgauss_profile_t::max_support );

        cls.def_property_readonly( "q", &qgauss_profile_t::q );
        cls.def_property_readonly( "sqrt_beta", &qgauss_profile_t::sqrt_beta );
        cls.def_property_readonly( "cq", &qgauss_profile_t::cq );

        // We can even easily define methods, @properties, etc. that are not
        // present in the C++ API
        cls.def_property_readonly( "beta",
            []( qgauss_profile_t const& inst ) -> value_t
            { return inst.sqrt_beta() * inst.sqrt_beta(); },
            "returns the q-gaussian beta parameter" );

        // Instead of providing lambdas to handle overloading, we can
        // cast the member function

        cls.def( "update", ( void ( qgauss_profile_t::* )( value_t const& )
                     )&qgauss_profile_t::update,
                 "update profile with a gaussian distribution",
                 py::arg( "sigma" ) = 1.0 );

        cls.def( "update", ( void ( qgauss_profile_t::* )(
                     value_t const&, value_t const& ) )&qgauss_profile_t::update,
                 "update profile with a q-gaussian distribution",
                 py::arg( "q" ), py::arg( "sqrt_beta" ) );

        // expose static member function as a @staticmethod
        cls.def_static( "METHOD", &qgauss_profile_t::Method );
    }

    template< class T >
    LDPROFILE_STATIC LDPROFILE_INLINE void Create_bindings_lin_interpol_profile(
        pybind11::module& m,
        pybind11::class_< ldprofile::TLinInterpolLDProfile< T > >& cls )
    {
        namespace py = pybind11;
        namespace ld = ldprofile;

        using lin_profile_t = ld::TLinInterpolLDProfile< T >;
        using value_t = typename lin_profile_t::value_type;
        using size_t = typename lin_profile_t::size_type;

        // Constructor -> we can define our own default arguments which
        // can differ from the defaults in C++!

        cls.def( py::init(
            []( value_t const& z0, value_t const& dz, py::array_t< value_t > values )
            {
                py::buffer_info values_info = values.request();

                if( values_info.ndim != 1 )
                    throw std::runtime_error( "values.ndim != 1" );

                if( values_info.format.compare(
                    py::format_descriptor< value_t >::format() ) != 0 )
                {
                    throw std::runtime_error( "type format mismatch" );
                }

                // use make_unique if available!
                return std::unique_ptr< lin_profile_t >(
                    new lin_profile_t( z0, dz, values.size(),
                        static_cast< value_t const* >( values_info.ptr ) ) );
            } ),
            py::arg( "z0" ), py::arg( "dz" ), py::arg( "values" ) );

        cls.def( py::init(
            []( value_t const& z0, value_t const& dz, size_t const num_values )
            {
                // use make_unique if available!
                return std::unique_ptr< lin_profile_t >(
                    new lin_profile_t( z0, dz, num_values ) );
            } ),
            py::arg( "z0" ),
            py::arg( "dz" ),
            py::arg( "num_values" ) );

        // expose the getter methods as @property accessors:
        cls.def_property_readonly( "z0", &lin_profile_t::z0 );
        cls.def_property_readonly( "dz", &lin_profile_t::dz );
        cls.def_property_readonly( "num_values", &lin_profile_t::num_values );

        // provide __getitem__ and __setitem__ accessors:

        cls.def( "__getitem__",
        []( lin_profile_t const& instance, size_t const idx ) -> value_t const&
        {
            return instance.value( idx );
        }, py::arg( "value_idx" ) );

        cls.def( "__setitem__",
        []( lin_profile_t& instance, size_t const idx,
            value_t const& new_value ) -> value_t&
        {
            instance.value( idx ) = new_value;
        }, py::arg( "value_idx" ), py::arg( "value" ) );

        // provide __len__ operator:
        cls.def( "__len__", &lin_profile_t::num_values );

        // update methods:
        cls.def( "update",
            []( lin_profile_t& instance, value_t const& z0,
                value_t const& dz, size_t const num_values )
            {
                instance.update( z0, dz, num_values );
            },
            "updates the instance, changes the size to num_values and sets all values to 0",
            py::arg("z0"), py::arg( "dz" ), py::arg( "num_values" ) );

        cls.def( "update",
            []( lin_profile_t& instance, value_t const& z0,
                value_t const& dz, py::buffer values )
            {
                py::buffer_info values_info = values.request();

                if( values_info.ndim != 1 )
                    throw std::runtime_error( "values.ndim != 1" );

                instance.update( z0, dz,
                    values_info.shape[ 0 ] * values_info.shape[ 1 ],
                         static_cast< value_t const* >( values_info.ptr ) );
            },
            "updates the instance, with new values; resizes as required",
            py::arg("z0") = value_t{ 0 },
            py::arg( "dz" ) = value_t{ 1 },
            py::arg( "values" ) = py::array_t< value_t >{} );

        // expose static member function as a @staticmethod
        cls.def_static( "METHOD", &lin_profile_t::Method );
    }

} // ns: python
} // ns: ldprofile

#endif /* LDPROFILE_PYBIND11_LDPROFILE_WRAP_CXX_HPP__ */
