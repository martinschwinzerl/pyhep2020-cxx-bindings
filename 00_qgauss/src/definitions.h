#ifndef QGAUSS_DEFINITIONS_H__
#define QGAUSS_DEFINITIONS_H__

#if !defined(QGAUSS_EXTERN)
    #if !defined( __cplusplus ) && !defined(_GPUCODE)
        #define QGAUSS_EXTERN extern
    #else
        #define QGAUSS_EXTERN
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

#if !defined( QGAUSS_ARGPTR_DEC )
    #define QGAUSS_ARGPTR_DEC_UNDEF
    #define QGAUSS_ARGPTR_DEC
#endif /* defined( QGAUSS_ARGPTR_DEC ) */

#if !defined( QGAUSS_DATAPTR_DEC )
    #define QGAUSS_DATAPTR_DEC_UNDEF
    #define QGAUSS_DATAPTR_DEC
#endif /* defined( QGAUSS_DATAPTR_DEC ) */

#if !defined( QGAUSS_TRACK_RETURN )
    #define QGAUSS_TRACK_RETURN int
#endif /* !defined( QGAUSS_TRACK_RETURN ) */

#if defined( _GPUCODE )
    #if defined( __OPENCL_C_VERSION__ )
        #if __OPENCL_VERSION__ <= CL_VERSION_1_1
            #pragma OPENCL EXTENSION cl_khr_fp64 : enable
        #endif

        #if !defined( QGAUSS_NO_SYSTEM_INCLUDES )
            #define  QGAUSS_NO_SYSTEM_INCLUDES  1
        #endif /* !defined( QGAUSS_NO_SYSTEM_INCLUDES */

        #define QGAUSS_ALIGN_NUM 8u

        /* ---------------------------------------------------------------- */
        /* assert: */

        #if !defined( QGAUSS_ASSERT )
            #define QGAUSS_ASSERT( expr )
        #endif /* !defined( QGAUSS_ASSERT ) */

        /* ---------------------------------------------------------------- */
        /* Type decorators -> these go in front of the QGAUSS_*_T type   */

        #if !defined( QGAUSS_PRIVATE_DEC )
            #define QGAUSS_PRIVATE_DEC
        #endif /* !defined( QGAUSS_PRIVATE_DEC ) */

        #if !defined( QGAUSS_LOCAL_DEC )
            #define QGAUSS_SHARED_DEC __local
        #endif /* !defined( QGAUSS_LOCAL_DEC ) */

        #if !defined( QGAUSS_GLOBAL_DEC )
            #define QGAUSS_GLOBAL_DEC __global
        #endif /* !defined( QGAUSS_GLOBAL_DEC ) */

        #if !defined( QGAUSS_CONSTANT_DEC )
            #define QGAUSS_CONSTANT_DEC __constant
        #endif /* !defined( QGAUSS_CONSTANT_DEC ) */

        /* ---------------------------------------------------------------- */
        /* kernel and restrict key word for kernel parameters: */

        #if !defined( QGAUSS_GPUKERNEL )
            #define QGAUSS_GPUKERNEL __kernel
        #endif /* !defined( QGAUSS_GPU_KERNEL ) */

        #if !defined( QGAUSS_GPUKERNEL_RESTRICT )
            #define   QGAUSS_GPUKERNEL_RESTRICT restrict
        #endif /* !defined( QGAUSS_KERNELPARAM_RESTRICT ) */

        #if !defined( QGAUSS_GPUKERNEL_RESTRICT_REF )
            #define   QGAUSS_GPUKERNEL_RESTRICT_REF
        #endif /* !defined( QGAUSS_KERNELPARAM_RESTRICT_REF ) */

        /* ---------------------------------------------------------------- */
        /* static, inline and restrict keywords:                            */

        #if !defined( QGAUSS_RESTRICT )
            #define QGAUSS_RESTRICT QGAUSS_GPUKERNEL_RESTRICT
        #endif /* !defined( QGAUSS_RESTRICT ) */

        #if !defined( QGAUSS_RESTRICT_REF )
            #define QGAUSS_RESTRICT_REF
        #endif /* !defined( QGAUSS_RESTRICT_REF ) */

        #if !defined( QGAUSS_STATIC )
            #define QGAUSS_STATIC
        #endif /* !defined( QGAUSS_STATIC ) */

        #if !defined( QGAUSS_STATIC_VAR )
            #define QGAUSS_STATIC_VAR
        #endif /* !defined( QGAUSS_STATIC_VAR ) */

        #if !defined( QGAUSS_INLINE )
            #define QGAUSS_INLINE inline
        #endif /* !defined( QGAUSS_INLINE ) */

        /* ---------------------------------------------------------------- */
        /* Function header decorators:                                      */

        #if !defined( QGAUSS_HOST_FN )
            #define   QGAUSS_HOST_FN
        #endif /* QGAUSS_HOST_FN */

        #if !defined( QGAUSS_DEVICE_FN )
            #define   QGAUSS_DEVICE_FN
        #endif /* QGAUSS_DEVICE_FN */

        #if !defined( QGAUSS_FN )
            #define   QGAUSS_FN
        #endif /* QGAUSS_FN */

    #elif defined( __CUDACC__ )
        /* ---------------------------------------------------------------- */
        /* assert: */

        #if !defined( QGAUSS_ASSERT )
            #define QGAUSS_ASSERT( expr )
        #endif /* !defined( QGAUSS_ASSERT ) */

        /* ---------------------------------------------------------------- */
        /* Type decorators -> these go in front of the QGAUSS_*_T type   */

        #if !defined( QGAUSS_PRIVATE_DEC )
            #define QGAUSS_PRIVATE_DEC __local__
        #endif /* !defined( QGAUSS_PRIVATE_DEC ) */

        #if !defined( QGAUSS_LOCAL_DEC )
            #define QGAUSS_LOCAL_DEC __shared__
        #endif /* !defined( QGAUSS_LOCAL_DEC ) */

        #if !defined( QGAUSS_GLOBAL_DEC )
            #define QGAUSS_GLOBAL_DEC
        #endif /* !defined( QGAUSS_GLOBAL_DEC ) */

        #if !defined( QGAUSS_CONSTANT_DEC )
            #define QGAUSS_CONSTANT_DEC __constant__
        #endif /* !defined( QGAUSS_CONSTANT_DEC ) */

        /* ---------------------------------------------------------------- */
        /* kernel and restrict key word for kernel parameters: */

        #if !defined( QGAUSS_GPUKERNEL )
            #define QGAUSS_GPUKERNEL __global__
        #endif /* !defined( QGAUSS_GPU_KERNEL ) */

        #if !defined( QGAUSS_GPUKERNEL_RESTRICT )
            #define   QGAUSS_GPUKERNEL_RESTRICT __restrict__
        #endif /* !defined( QGAUSS_KERNELPARAM_RESTRICT ) */

        #if !defined( QGAUSS_GPUKERNEL_RESTRICT_REF )
            #define   QGAUSS_GPUKERNEL_RESTRICT_REF
        #endif /* !defined( QGAUSS_KERNELPARAM_RESTRICT_REF ) */

        /* ---------------------------------------------------------------- */
        /* static, inline and restrict keywords:                            */

        #if !defined( QGAUSS_RESTRICT )
            #define QGAUSS_RESTRICT QGAUSS_GPUKERNEL_RESTRICT
        #endif /* !defined( QGAUSS_RESTRICT ) */

        #if !defined( QGAUSS_RESTRICT_REF )
            #define QGAUSS_RESTRICT_REF
        #endif /* !defined( QGAUSS_RESTRICT_REF ) */

        #if !defined( QGAUSS_STATIC )
            #define QGAUSS_STATIC static
        #endif /* !defined( QGAUSS_STATIC ) */

        #if !defined( QGAUSS_STATIC_VAR )
            #define QGAUSS_STATIC_VAR
        #endif /* !defined( QGAUSS_STATIC_VAR ) */

        #if !defined( QGAUSS_INLINE )
            #define QGAUSS_INLINE inline
        #endif /* !defined( QGAUSS_INLINE ) */

        /* ---------------------------------------------------------------- */
        /* Function header decorators:                                      */

        #if !defined( QGAUSS_HOST_FN )
            #define   QGAUSS_HOST_FN __host__
        #endif /* QGAUSS_HOST_FN */

        #if !defined( QGAUSS_DEVICE_FN )
            #define   QGAUSS_DEVICE_FN __device__
        #endif /* QGAUSS_DEVICE_FN */

        #if !defined( QGAUSS_FN )
            #define   QGAUSS_FN __host__ __device__
        #endif /* QGAUSS_FN */

    #endif /* defined( __OPENCL_C_VERSION__ ) || defined( __CUDACC__ ) */

#else /* !defined( _GPUCODE ) */

    #define QGAUSS_ALIGN_NUM 8u

    /* ----------------------------------------------------------------- */
    /* assert */

    #if !defined( QGAUSS_ASSERT )
        #define QGAUSS_ASSERT( expr ) assert( ( expr ) )
    #endif /* !defined( QGAUSS_ASSERT ) */

    /* --------------------------------------------------------------------- */
    /* Type decorators -> these go in front of the QGAUSS_*_T type        */

    #if !defined( QGAUSS_PRIVATE_DEC )
        #define QGAUSS_PRIVATE_DEC
    #endif /* !defined( QGAUSS_PRIVATE_DEC ) */

    #if !defined( QGAUSS_LOCAL_DEC )
        #define QGAUSS_LOCAL_DEC
    #endif /* !defined( QGAUSS_LOCAL_DEC ) */

    #if !defined( QGAUSS_GLOBAL_DEC )
        #define QGAUSS_GLOBAL_DEC
    #endif /* !defined( QGAUSS_GLOBAL_DEC ) */

    #if !defined( QGAUSS_CONSTANT_DEC )
        #define QGAUSS_CONSTANT_DEC
    #endif /* !defined( QGAUSS_CONSTANT_DEC ) */

    /* ---------------------------------------------------------------- */
    /* static, inline and restrict keywords: */

    #if !defined( __CUDACC__ )
        #if !defined( QGAUSS_STATIC )
            #define QGAUSS_STATIC static
        #endif /* !defined( QGAUSS_STATIC ) */

        #if !defined( QGAUSS_STATIC_VAR )
                #define QGAUSS_STATIC_VAR static
        #endif /* !defined( QGAUSS_STATIC_VAR ) */

    #else /* !defined( __CUDACC__ ) */

        #if !defined( QGAUSS_STATIC )
            #define QGAUSS_STATIC static
        #endif /* !defined( QGAUSS_STATIC ) */

        #if !defined( QGAUSS_STATIC_VAR )
                #define QGAUSS_STATIC_VAR
        #endif /* !defined( QGAUSS_STATIC_VAR ) */

    #endif /* */

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    #if !defined( QGAUSS_INLINE )
        #define QGAUSS_INLINE inline
    #endif /* !defined( QGAUSS_INLINE ) */

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    #if defined( QGAUSS_RESTRICT )
        #undef  QGAUSS_RESTRICT
    #endif /* QGAUSS_RESTRICT */

    #if defined( QGAUSS_RESTRICT_REF )
        #undef  QGAUSS_RESTRICT_REF
    #endif /* QGAUSS_RESTRICT_REF */

    #ifdef __cplusplus
        #if ( ( defined( __clang__ ) ) || \
            ( ( ( defined( __GNUC__ ) ) && ( __GNUC__ >= 3 ) ) ) )
            #define QGAUSS_RESTRICT     __restrict__
            #define QGAUSS_RESTRICT_REF __restrict__
        #elif ( defined( _MSC_VER ) && _MSC_VER >= 1600 )
            #define QGAUSS_RESTRICT __restrict
        #endif /* ( defined( _MSC_VER ) && _MSC_VER >= 1600 ) */
    #else /* __cplusplus */
        #if ( ( defined( __clang__ ) ) || \
            ( ( ( defined( __GNUC__ ) ) && ( __GNUC__ >= 3 ) ) ) )
            #if ( __STDC_VERSION__ >= 199901L )
                #define QGAUSS_RESTRICT restrict
            #else
                #define QGAUSS_RESTRICT __restrict__
            #endif /* C99 support */

        #endif /* gcc/mingw or clang */
    #endif /*defined( __cplusplus ) */

    #ifndef QGAUSS_RESTRICT
        #define QGAUSS_RESTRICT
    #endif /* QGAUSS_RESTRICT */

    #ifndef QGAUSS_RESTRICT_REF
        #define QGAUSS_RESTRICT_REF
    #endif /* QGAUSS_RESTRICT_REF */

    /* --------------------------------------------------------------------- */
    /* kernel and restrict key word for kernel parameters: */

    #if !defined( QGAUSS_GPUKERNEL )
        #define QGAUSS_GPUKERNEL
    #endif /* !defined( QGAUSS_GPU_KERNEL ) */

    #if !defined( QGAUSS_GPUKERNEL_RESTRICT )
        #define   QGAUSS_GPUKERNEL_RESTRICT QGAUSS_RESTRICT
    #endif /* !defined( QGAUSS_KERNELPARAM_RESTRICT ) */

    #if !defined( QGAUSS_GPUKERNEL_RESTRICT_REF )
        #define   QGAUSS_GPUKERNEL_RESTRICT_REF QGAUSS_RESTRICT_REF
    #endif /* !defined( QGAUSS_KERNELPARAM_RESTRICT_REF ) */

    /* --------------------------------------------------------------------- */
    /* Function header decorators:                                           */

    #if !defined( __CUDACC__ )

        #if !defined( QGAUSS_HOST_FN )
            #define   QGAUSS_HOST_FN
        #endif /* QGAUSS_HOST_FN */

        #if !defined( QGAUSS_DEVICE_FN )
            #define   QGAUSS_DEVICE_FN
        #endif /* QGAUSS_DEVICE_FN */

        #if !defined( QGAUSS_FN )
            #define   QGAUSS_FN
        #endif /* QGAUSS_FN */

    #else /* defined( __CUDACC__ ) */

        #if !defined( QGAUSS_HOST_FN)
            #define   QGAUSS_HOST_FN __host__
        #endif /* QGAUSS_HOST_FN */

        #if !defined( QGAUSS_DEVICE_FN )
            #define   QGAUSS_DEVICE_FN __device__
        #endif /* QGAUSS_DEVICE_FN */

        #if !defined( QGAUSS_FN )
            #define   QGAUSS_FN __host__ __device__
        #endif /* QGAUSS_FN */

    #endif /* defined( __CUDACC__ ) */

#endif /* defined( _GPUCODE ) */

/* ------------------------------------------------------------------------- */

#if !defined( QGAUSS_ARGPTR_DEC )
    #define QGAUSS_ARGPTR_DEC
#endif /* defined( QGAUSS_ARGPTR_DEC ) */

#if !defined( QGAUSS_DATAPTR_DEC )
    #define QGAUSS_DATAPTR_DEC
#endif /* defined( QGAUSS_DATAPTR_DEC ) */

/* ------------------------------------------------------------------------- */

#if defined(__CUDACC__) // NVCC
    #define QGAUSS_ALIGN(n) __align__((n))
#elif defined(__GNUC__) || defined(__clang__) // GCC, CLANG
    #define QGAUSS_ALIGN(n) __attribute__((aligned((n))))
#elif defined(_MSC_VER) || defined(__INTEL_COMPILER) // MSVC, INTEL
    #define QGAUSS_ALIGN(n) __declspec(align((n)))
#else
    #error "Please provide a definition for QGAUSS_ALIGN macro for your host compiler!"
#endif /* QGAUSS_ALIGN */

/* ------------------------------------------------------------------------- */

#if !defined( QGAUSS_NULLPTR )
    #if  defined( __cplusplus ) && __cplusplus >= 201103L && \
        !defined( __CUDACC__  )
        #define QGAUSS_NULLPTR nullptr
    #elif !defined( __cplusplus ) && defined( __CUDACC__ )
        #define QGAUSS_NULLPTR NULL
    #else
        #define QGAUSS_NULLPTR 0
    #endif /* nullptr */
#endif /* !defined( QGAUSS_NULLPTR ) */

/* ------------------------------------------------------------------------- */

#if !defined( QGAUSS_NOEXCEPT ) || !defined( QGAUSS_NOEXCEPT_COND )
    #if defined( __cplusplus ) && ( __cplusplus >= 201103L )
        #if ( defined( __GNUC__   ) && ( ( __GNUC__ >= 5 ) || \
              ( ( __GNUC__ == 4   ) && ( __GNUC_MINOR__ >= 8 ) ) ) ) || \
            ( defined( __CUDACC__ ) && defined( CUDA_VERSION ) && \
                ( CUDA_VERSION >= 800 ) ) || \
            ( defined( _MSC_VER   ) && ( _MSC_VER >= 1900 ) ) || \
            ( defined( __clang__  ) && ( ( __clang_major__ > 3 ) || \
              ( ( __clang_major__ == 3 ) && ( __clang_minor__ >= 3 ) ) ) ) || \
            ( defined( __INTEL_COMPILER ) && ( __INTEL_COMPILER >= 14 ) )

            #if !defined( QGAUSS_NOEXCEPT )
                #define QGAUSS_NOEXCEPT noexcept
            #endif /* !defined( QGAUSS_NOEXCEPT ) */

            #if !defined( QGAUSS_NOEXCEPT_COND )
                #define QGAUSS_NOEXCEPT_COND( cond ) noexcept( ( cond ) )
            #endif /* !defined( QGAUSS_NOEXCEPT_COND ) */
        #endif /* compilers */
    #endif /*  defined( __cplusplus ) && ( __cplusplus >= 201103L ) */

    #if !defined( QGAUSS_NOEXCEPT )
        #define QGAUSS_NOEXCEPT
    #endif /* !defined( QGAUSS_NOEXCEPT ) */

    #if !defined( QGAUSS_NOEXCEPT_COND )
        #define QGAUSS_NOEXCEPT_COND( cond )
    #endif /* !defined( QGAUSS_NOEXCEPT_COND ) */
#endif /* !defined( QGAUSS_NOEXCEPT ) || !defined( QGAUSS_NOEXCEPT_COND ) */

/* ------------------------------------------------------------------------- */

#if !defined QGAUSS_UNUSED
    #if defined( __cplusplus )
        #define QGAUSS_UNUSED( arg ) /* can be omitted -> nothing to do here! */
    #elif ( ( defined( __GNUC__ ) && ( __GNUC__ >= 3 ) ) ) || \
          ( defined( __clang__ ) )
        #define QGAUSS_UNUSED( arg ) arg __attribute__((unused))
    #else
        #define QGAUSS_UNUSED( arg ) arg
    #endif /* C++ / compiler */
#endif /* !defined( QGAUSS_UNUSED ) */
#endif /* QGAUSS_DEFINITIONS_H__ */
