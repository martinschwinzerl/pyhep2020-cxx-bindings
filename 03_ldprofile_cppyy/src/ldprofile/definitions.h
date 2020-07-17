#ifndef LDPROFILE_DEFINITIONS_H__
#define LDPROFILE_DEFINITIONS_H__

#if !defined(LDPROFILE_EXTERN)
    #if !defined( __cplusplus ) && !defined(_GPUCODE)
        #define LDPROFILE_EXTERN extern
    #else
        #define LDPROFILE_EXTERN
    #endif
#endif

#if !defined( _GPUCODE ) || defined( __CUDACC__ )
    #if defined( __cplusplus )
        #include <cassert>
        #include <cmath>
        #include <cstddef>
        #include <cstdlib>
        #include <cstring>
    #else
        #include <assert.h>
        #include <stddef.h>
        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>
    #endif /* __cplusplus */
    #include <stdint.h>
#endif /* !defined( _GPUCODE ) || defined(__CUDACC__ ) */

#if !defined( LDPROFILE_ARGPTR_DEC )
    #define LDPROFILE_ARGPTR_DEC_UNDEF
    #define LDPROFILE_ARGPTR_DEC
#endif /* defined( LDPROFILE_ARGPTR_DEC ) */

#if !defined( LDPROFILE_DATAPTR_DEC )
    #define LDPROFILE_DATAPTR_DEC_UNDEF
    #define LDPROFILE_DATAPTR_DEC
#endif /* defined( LDPROFILE_DATAPTR_DEC ) */

#if !defined( LDPROFILE_TRACK_RETURN )
    #define LDPROFILE_TRACK_RETURN int
#endif /* !defined( LDPROFILE_TRACK_RETURN ) */

#if defined( _GPUCODE )
    #if defined( __OPENCL_C_VERSION__ )
        #if __OPENCL_VERSION__ <= CL_VERSION_1_1
            #pragma OPENCL EXTENSION cl_khr_fp64 : enable
        #endif

        #if !defined( LDPROFILE_NO_SYSTEM_INCLUDES )
            #define  LDPROFILE_NO_SYSTEM_INCLUDES  1
        #endif /* !defined( LDPROFILE_NO_SYSTEM_INCLUDES */

        #define LDPROFILE_ALIGN_NUM 8u

        /* ---------------------------------------------------------------- */
        /* assert: */

        #if !defined( LDPROFILE_ASSERT )
            #define LDPROFILE_ASSERT( expr )
        #endif /* !defined( LDPROFILE_ASSERT ) */

        /* ---------------------------------------------------------------- */
        /* Type decorators -> these go in front of the LDPROFILE_*_T type   */

        #if !defined( LDPROFILE_PRIVATE_DEC )
            #define LDPROFILE_PRIVATE_DEC
        #endif /* !defined( LDPROFILE_PRIVATE_DEC ) */

        #if !defined( LDPROFILE_LOCAL_DEC )
            #define LDPROFILE_SHARED_DEC __local
        #endif /* !defined( LDPROFILE_LOCAL_DEC ) */

        #if !defined( LDPROFILE_GLOBAL_DEC )
            #define LDPROFILE_GLOBAL_DEC __global
        #endif /* !defined( LDPROFILE_GLOBAL_DEC ) */

        #if !defined( LDPROFILE_CONSTANT_DEC )
            #define LDPROFILE_CONSTANT_DEC __constant
        #endif /* !defined( LDPROFILE_CONSTANT_DEC ) */

        /* ---------------------------------------------------------------- */
        /* kernel and restrict key word for kernel parameters: */

        #if !defined( LDPROFILE_GPUKERNEL )
            #define LDPROFILE_GPUKERNEL __kernel
        #endif /* !defined( LDPROFILE_GPU_KERNEL ) */

        #if !defined( LDPROFILE_GPUKERNEL_RESTRICT )
            #define   LDPROFILE_GPUKERNEL_RESTRICT restrict
        #endif /* !defined( LDPROFILE_KERNELPARAM_RESTRICT ) */

        #if !defined( LDPROFILE_GPUKERNEL_RESTRICT_REF )
            #define   LDPROFILE_GPUKERNEL_RESTRICT_REF
        #endif /* !defined( LDPROFILE_KERNELPARAM_RESTRICT_REF ) */

        /* ---------------------------------------------------------------- */
        /* static, inline and restrict keywords:                            */

        #if !defined( LDPROFILE_RESTRICT )
            #define LDPROFILE_RESTRICT LDPROFILE_GPUKERNEL_RESTRICT
        #endif /* !defined( LDPROFILE_RESTRICT ) */

        #if !defined( LDPROFILE_RESTRICT_REF )
            #define LDPROFILE_RESTRICT_REF
        #endif /* !defined( LDPROFILE_RESTRICT_REF ) */

        #if !defined( LDPROFILE_STATIC )
            #define LDPROFILE_STATIC
        #endif /* !defined( LDPROFILE_STATIC ) */

        #if !defined( LDPROFILE_STATIC_VAR )
            #define LDPROFILE_STATIC_VAR
        #endif /* !defined( LDPROFILE_STATIC_VAR ) */

        #if !defined( LDPROFILE_INLINE )
            #define LDPROFILE_INLINE inline
        #endif /* !defined( LDPROFILE_INLINE ) */

        /* ---------------------------------------------------------------- */
        /* Function header decorators:                                      */

        #if !defined( LDPROFILE_HOST_FN )
            #define   LDPROFILE_HOST_FN
        #endif /* LDPROFILE_HOST_FN */

        #if !defined( LDPROFILE_DEVICE_FN )
            #define   LDPROFILE_DEVICE_FN
        #endif /* LDPROFILE_DEVICE_FN */

        #if !defined( LDPROFILE_FN )
            #define   LDPROFILE_FN
        #endif /* LDPROFILE_FN */

    #elif defined( __CUDACC__ )
        /* ---------------------------------------------------------------- */
        /* assert: */

        #if !defined( LDPROFILE_ASSERT )
            #define LDPROFILE_ASSERT( expr )
        #endif /* !defined( LDPROFILE_ASSERT ) */

        /* ---------------------------------------------------------------- */
        /* Type decorators -> these go in front of the LDPROFILE_*_T type   */

        #if !defined( LDPROFILE_PRIVATE_DEC )
            #define LDPROFILE_PRIVATE_DEC __local__
        #endif /* !defined( LDPROFILE_PRIVATE_DEC ) */

        #if !defined( LDPROFILE_LOCAL_DEC )
            #define LDPROFILE_LOCAL_DEC __shared__
        #endif /* !defined( LDPROFILE_LOCAL_DEC ) */

        #if !defined( LDPROFILE_GLOBAL_DEC )
            #define LDPROFILE_GLOBAL_DEC
        #endif /* !defined( LDPROFILE_GLOBAL_DEC ) */

        #if !defined( LDPROFILE_CONSTANT_DEC )
            #define LDPROFILE_CONSTANT_DEC __constant__
        #endif /* !defined( LDPROFILE_CONSTANT_DEC ) */

        /* ---------------------------------------------------------------- */
        /* kernel and restrict key word for kernel parameters: */

        #if !defined( LDPROFILE_GPUKERNEL )
            #define LDPROFILE_GPUKERNEL __global__
        #endif /* !defined( LDPROFILE_GPU_KERNEL ) */

        #if !defined( LDPROFILE_GPUKERNEL_RESTRICT )
            #define   LDPROFILE_GPUKERNEL_RESTRICT __restrict__
        #endif /* !defined( LDPROFILE_KERNELPARAM_RESTRICT ) */

        #if !defined( LDPROFILE_GPUKERNEL_RESTRICT_REF )
            #define   LDPROFILE_GPUKERNEL_RESTRICT_REF
        #endif /* !defined( LDPROFILE_KERNELPARAM_RESTRICT_REF ) */

        /* ---------------------------------------------------------------- */
        /* static, inline and restrict keywords:                            */

        #if !defined( LDPROFILE_RESTRICT )
            #define LDPROFILE_RESTRICT LDPROFILE_GPUKERNEL_RESTRICT
        #endif /* !defined( LDPROFILE_RESTRICT ) */

        #if !defined( LDPROFILE_RESTRICT_REF )
            #define LDPROFILE_RESTRICT_REF
        #endif /* !defined( LDPROFILE_RESTRICT_REF ) */

        #if !defined( LDPROFILE_STATIC )
            #define LDPROFILE_STATIC static
        #endif /* !defined( LDPROFILE_STATIC ) */

        #if !defined( LDPROFILE_STATIC_VAR )
            #define LDPROFILE_STATIC_VAR
        #endif /* !defined( LDPROFILE_STATIC_VAR ) */

        #if !defined( LDPROFILE_INLINE )
            #define LDPROFILE_INLINE inline
        #endif /* !defined( LDPROFILE_INLINE ) */

        /* ---------------------------------------------------------------- */
        /* Function header decorators:                                      */

        #if !defined( LDPROFILE_HOST_FN )
            #define   LDPROFILE_HOST_FN __host__
        #endif /* LDPROFILE_HOST_FN */

        #if !defined( LDPROFILE_DEVICE_FN )
            #define   LDPROFILE_DEVICE_FN __device__
        #endif /* LDPROFILE_DEVICE_FN */

        #if !defined( LDPROFILE_FN )
            #define   LDPROFILE_FN __host__ __device__
        #endif /* LDPROFILE_FN */

    #endif /* defined( __OPENCL_C_VERSION__ ) || defined( __CUDACC__ ) */

#else /* !defined( _GPUCODE ) */

    #define LDPROFILE_ALIGN_NUM 8u

    /* ----------------------------------------------------------------- */
    /* assert */

    #if !defined( LDPROFILE_ASSERT )
        #define LDPROFILE_ASSERT( expr ) assert( ( expr ) )
    #endif /* !defined( LDPROFILE_ASSERT ) */

    /* --------------------------------------------------------------------- */
    /* Type decorators -> these go in front of the LDPROFILE_*_T type        */

    #if !defined( LDPROFILE_PRIVATE_DEC )
        #define LDPROFILE_PRIVATE_DEC
    #endif /* !defined( LDPROFILE_PRIVATE_DEC ) */

    #if !defined( LDPROFILE_LOCAL_DEC )
        #define LDPROFILE_LOCAL_DEC
    #endif /* !defined( LDPROFILE_LOCAL_DEC ) */

    #if !defined( LDPROFILE_GLOBAL_DEC )
        #define LDPROFILE_GLOBAL_DEC
    #endif /* !defined( LDPROFILE_GLOBAL_DEC ) */

    #if !defined( LDPROFILE_CONSTANT_DEC )
        #define LDPROFILE_CONSTANT_DEC
    #endif /* !defined( LDPROFILE_CONSTANT_DEC ) */

    /* ---------------------------------------------------------------- */
    /* static, inline and restrict keywords: */

    #if !defined( __CUDACC__ )
        #if !defined( LDPROFILE_STATIC )
            #define LDPROFILE_STATIC static
        #endif /* !defined( LDPROFILE_STATIC ) */

        #if !defined( LDPROFILE_STATIC_VAR )
                #define LDPROFILE_STATIC_VAR static
        #endif /* !defined( LDPROFILE_STATIC_VAR ) */

    #else /* !defined( __CUDACC__ ) */

        #if !defined( LDPROFILE_STATIC )
            #define LDPROFILE_STATIC static
        #endif /* !defined( LDPROFILE_STATIC ) */

        #if !defined( LDPROFILE_STATIC_VAR )
                #define LDPROFILE_STATIC_VAR
        #endif /* !defined( LDPROFILE_STATIC_VAR ) */

    #endif /* */

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    #if !defined( LDPROFILE_INLINE )
        #define LDPROFILE_INLINE inline
    #endif /* !defined( LDPROFILE_INLINE ) */

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    #if defined( LDPROFILE_RESTRICT )
        #undef  LDPROFILE_RESTRICT
    #endif /* LDPROFILE_RESTRICT */

    #if defined( LDPROFILE_RESTRICT_REF )
        #undef  LDPROFILE_RESTRICT_REF
    #endif /* LDPROFILE_RESTRICT_REF */

    #ifdef __cplusplus
        #if ( ( defined( __clang__ ) ) || \
            ( ( ( defined( __GNUC__ ) ) && ( __GNUC__ >= 3 ) ) ) )
            #define LDPROFILE_RESTRICT     __restrict__
            #define LDPROFILE_RESTRICT_REF __restrict__
        #elif ( defined( _MSC_VER ) && _MSC_VER >= 1600 )
            #define LDPROFILE_RESTRICT __restrict
        #endif /* ( defined( _MSC_VER ) && _MSC_VER >= 1600 ) */
    #else /* __cplusplus */
        #if ( ( defined( __clang__ ) ) || \
            ( ( ( defined( __GNUC__ ) ) && ( __GNUC__ >= 3 ) ) ) )
            #if ( __STDC_VERSION__ >= 199901L )
                #define LDPROFILE_RESTRICT restrict
            #else
                #define LDPROFILE_RESTRICT __restrict__
            #endif /* C99 support */

        #endif /* gcc/mingw or clang */
    #endif /*defined( __cplusplus ) */

    #ifndef LDPROFILE_RESTRICT
        #define LDPROFILE_RESTRICT
    #endif /* LDPROFILE_RESTRICT */

    #ifndef LDPROFILE_RESTRICT_REF
        #define LDPROFILE_RESTRICT_REF
    #endif /* LDPROFILE_RESTRICT_REF */

    /* --------------------------------------------------------------------- */
    /* kernel and restrict key word for kernel parameters: */

    #if !defined( LDPROFILE_GPUKERNEL )
        #define LDPROFILE_GPUKERNEL
    #endif /* !defined( LDPROFILE_GPU_KERNEL ) */

    #if !defined( LDPROFILE_GPUKERNEL_RESTRICT )
        #define   LDPROFILE_GPUKERNEL_RESTRICT LDPROFILE_RESTRICT
    #endif /* !defined( LDPROFILE_KERNELPARAM_RESTRICT ) */

    #if !defined( LDPROFILE_GPUKERNEL_RESTRICT_REF )
        #define   LDPROFILE_GPUKERNEL_RESTRICT_REF LDPROFILE_RESTRICT_REF
    #endif /* !defined( LDPROFILE_KERNELPARAM_RESTRICT_REF ) */

    /* --------------------------------------------------------------------- */
    /* Function header decorators:                                           */

    #if !defined( __CUDACC__ )

        #if !defined( LDPROFILE_HOST_FN )
            #define   LDPROFILE_HOST_FN
        #endif /* LDPROFILE_HOST_FN */

        #if !defined( LDPROFILE_DEVICE_FN )
            #define   LDPROFILE_DEVICE_FN
        #endif /* LDPROFILE_DEVICE_FN */

        #if !defined( LDPROFILE_FN )
            #define   LDPROFILE_FN
        #endif /* LDPROFILE_FN */

    #else /* defined( __CUDACC__ ) */

        #if !defined( LDPROFILE_HOST_FN)
            #define   LDPROFILE_HOST_FN __host__
        #endif /* LDPROFILE_HOST_FN */

        #if !defined( LDPROFILE_DEVICE_FN )
            #define   LDPROFILE_DEVICE_FN __device__
        #endif /* LDPROFILE_DEVICE_FN */

        #if !defined( LDPROFILE_FN )
            #define   LDPROFILE_FN __host__ __device__
        #endif /* LDPROFILE_FN */

    #endif /* defined( __CUDACC__ ) */

#endif /* defined( _GPUCODE ) */

/* ------------------------------------------------------------------------- */

#if !defined( LDPROFILE_ARGPTR_DEC )
    #define LDPROFILE_ARGPTR_DEC
#endif /* defined( LDPROFILE_ARGPTR_DEC ) */

#if !defined( LDPROFILE_DATAPTR_DEC )
    #define LDPROFILE_DATAPTR_DEC
#endif /* defined( LDPROFILE_DATAPTR_DEC ) */

/* ------------------------------------------------------------------------- */

#if defined(__CUDACC__) // NVCC
    #define LDPROFILE_ALIGN(n) __align__((n))
#elif defined(__GNUC__) || defined(__clang__) // GCC, CLANG
    #define LDPROFILE_ALIGN(n) __attribute__((aligned((n))))
#elif defined(_MSC_VER) || defined(__INTEL_COMPILER) // MSVC, INTEL
    #define LDPROFILE_ALIGN(n) __declspec(align((n)))
#else
    #error "Please provide a definition for LDPROFILE_ALIGN macro for your host compiler!"
#endif /* LDPROFILE_ALIGN */

/* ------------------------------------------------------------------------- */

#if !defined( LDPROFILE_NULLPTR )
    #if  defined( __cplusplus ) && __cplusplus >= 201103L && \
        !defined( __CUDACC__  )
        #define LDPROFILE_NULLPTR nullptr
    #elif !defined( __cplusplus ) && defined( __CUDACC__ )
        #define LDPROFILE_NULLPTR NULL
    #else
        #define LDPROFILE_NULLPTR 0
    #endif /* nullptr */
#endif /* !defined( LDPROFILE_NULLPTR ) */

/* ------------------------------------------------------------------------- */

#if !defined( LDPROFILE_NOEXCEPT ) || !defined( LDPROFILE_NOEXCEPT_COND )
    #if defined( __cplusplus ) && ( __cplusplus >= 201103L )
        #if ( defined( __GNUC__   ) && ( ( __GNUC__ >= 5 ) || \
              ( ( __GNUC__ == 4   ) && ( __GNUC_MINOR__ >= 8 ) ) ) ) || \
            ( defined( __CUDACC__ ) && defined( CUDA_VERSION ) && \
                ( CUDA_VERSION >= 800 ) ) || \
            ( defined( _MSC_VER   ) && ( _MSC_VER >= 1900 ) ) || \
            ( defined( __clang__  ) && ( ( __clang_major__ > 3 ) || \
              ( ( __clang_major__ == 3 ) && ( __clang_minor__ >= 3 ) ) ) ) || \
            ( defined( __INTEL_COMPILER ) && ( __INTEL_COMPILER >= 14 ) )

            #if !defined( LDPROFILE_NOEXCEPT )
                #define LDPROFILE_NOEXCEPT noexcept
            #endif /* !defined( LDPROFILE_NOEXCEPT ) */

            #if !defined( LDPROFILE_NOEXCEPT_COND )
                #define LDPROFILE_NOEXCEPT_COND( cond ) noexcept( ( cond ) )
            #endif /* !defined( LDPROFILE_NOEXCEPT_COND ) */
        #endif /* compilers */
    #endif /*  defined( __cplusplus ) && ( __cplusplus >= 201103L ) */

    #if !defined( LDPROFILE_NOEXCEPT )
        #define LDPROFILE_NOEXCEPT
    #endif /* !defined( LDPROFILE_NOEXCEPT ) */

    #if !defined( LDPROFILE_NOEXCEPT_COND )
        #define LDPROFILE_NOEXCEPT_COND( cond )
    #endif /* !defined( LDPROFILE_NOEXCEPT_COND ) */
#endif /* !defined( LDPROFILE_NOEXCEPT ) || !defined( LDPROFILE_NOEXCEPT_COND ) */

/* ------------------------------------------------------------------------- */

#if !defined LDPROFILE_UNUSED
    #if defined( __cplusplus )
        #define LDPROFILE_UNUSED( arg ) /* can be omitted -> nothing to do here! */
    #elif ( ( defined( __GNUC__ ) && ( __GNUC__ >= 3 ) ) ) || \
          ( defined( __clang__ ) )
        #define LDPROFILE_UNUSED( arg ) arg __attribute__((unused))
    #else
        #define LDPROFILE_UNUSED( arg ) arg
    #endif /* C++ / compiler */
#endif /* !defined( LDPROFILE_UNUSED ) */
#endif /* LDPROFILE_DEFINITIONS_H__ */
