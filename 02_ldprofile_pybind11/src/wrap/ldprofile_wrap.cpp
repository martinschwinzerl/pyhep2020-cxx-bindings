#include "ldprofile_wrap.hpp"

namespace
{
    namespace py = pybind11;
    namespace ld = ldprofile;
    namespace ldpy = ldprofile::python;
}

PYBIND11_MODULE( ldprofile_pybind11, m )
{
    m.doc() = "ldprofile python bindings generated using pybind11";

    /* For double precision */
    using base_profile_t = ld::TLineDensityProfileBase< double >;
    using c_profile_t = ld::TCoastingLDProfile< double >;
    using q_profile_t = ld::TQGaussianLDProfile< double >;
    using l_profile_t = ld::TLinInterpolLDProfile< double >;

    /* Model the class hierarchy */
    py::class_< base_profile_t > base_profile_obj( m, "LDProfileBase" );

    py::class_< c_profile_t > c_profile_obj( m, "CoastingLDProfile", base_profile_obj );
    py::class_< q_profile_t > q_profile_obj( m, "QGaussianLDProfile", base_profile_obj );
    py::class_< l_profile_t > l_profile_obj( m, "LinInterpolLDProfile", base_profile_obj );

    /* call the binding generation functions for the specific types */
    ldpy::Create_bindings_base_profile< double >( m, base_profile_obj );
    ldpy::Create_bindings_coasting_profile< double >( m, c_profile_obj );
    ldpy::Create_bindings_qgauss_profile< double >( m, q_profile_obj );
    ldpy::Create_bindings_lin_interpol_profile< double >( m, l_profile_obj );
}
