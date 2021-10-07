/*
 * Copyright (c) 2013      Mellanox Technologies, Inc.
 *                         All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */
#include "oshmem_config.h"

#include "oshmem/constants.h"
#include "oshmem/include/shmem.h"
#include "oshmem/include/shmemx.h"

#include "oshmem/runtime/runtime.h"

#include "oshmem/mca/spml/spml.h"

/*
 * These routines provide a low latency mechanism to write basic types (short,
 * int, float, double, long) to symmetric data objects on remote PEs.
 * The shmem_TYPE_p() routines write value to a symmetric array element or scalar
 * data object of the remote PE indicated by the parameter pe. These routines start the remote
 * transfer and may return before the data is delivered to the remote PE.
 */

#define DO_SHMEM_TYPE_P(ctx, type, addr, value, pe) do {            \
        int rc = OSHMEM_SUCCESS;                                    \
        size_t size = 0;                                            \
                                                                    \
        RUNTIME_CHECK_INIT();                                       \
        RUNTIME_CHECK_PE(pe);                                       \
        RUNTIME_CHECK_ADDR(addr);                                   \
                                                                    \
        size = sizeof(type);                                        \
        rc = MCA_SPML_CALL(put(                                     \
            ctx,                                                    \
            (void*)addr,                                            \
            size,                                                   \
            (void*)&value,                                          \
            pe));                                                   \
        RUNTIME_CHECK_RC(rc);                                       \
    } while(0)

#define SHMEM_CTX_TYPE_P(type_name, type, prefix)                   \
    void prefix##_ctx##type_name##_p(shmem_ctx_t ctx, type *addr, type value, int pe) \
    {                                                               \
        DO_SHMEM_TYPE_P(ctx, type, addr, value, pe);                \
        return ;                                                    \
    }

#define SHMEM_TYPE_P(type_name, type, prefix)                       \
    void prefix##type_name##_p(type *addr, type value, int pe)      \
    {                                                               \
        DO_SHMEM_TYPE_P(oshmem_ctx_default, type, addr, value, pe);  \
        return ;                                                    \
    }

#if OSHMEM_PROFILING
#include "oshmem/include/pshmem.h"
#pragma weak shmem_ctx_char_p       = pshmem_ctx_char_p
#pragma weak shmem_ctx_short_p      = pshmem_ctx_short_p
#pragma weak shmem_ctx_int_p        = pshmem_ctx_int_p
#pragma weak shmem_ctx_long_p       = pshmem_ctx_long_p
#pragma weak shmem_ctx_float_p      = pshmem_ctx_float_p
#pragma weak shmem_ctx_double_p     = pshmem_ctx_double_p
#pragma weak shmem_ctx_longlong_p   = pshmem_ctx_longlong_p
#pragma weak shmem_ctx_schar_p      = pshmem_ctx_schar_p
#pragma weak shmem_ctx_uchar_p      = pshmem_ctx_uchar_p
#pragma weak shmem_ctx_ushort_p     = pshmem_ctx_ushort_p
#pragma weak shmem_ctx_uint_p       = pshmem_ctx_uint_p
#pragma weak shmem_ctx_ulong_p      = pshmem_ctx_ulong_p
#pragma weak shmem_ctx_ulonglong_p  = pshmem_ctx_ulonglong_p
#pragma weak shmem_ctx_longdouble_p = pshmem_ctx_longdouble_p
#pragma weak shmem_ctx_int8_p       = pshmem_ctx_int8_p
#pragma weak shmem_ctx_int16_p      = pshmem_ctx_int16_p
#pragma weak shmem_ctx_int32_p      = pshmem_ctx_int32_p
#pragma weak shmem_ctx_int64_p      = pshmem_ctx_int64_p
#pragma weak shmem_ctx_uint8_p      = pshmem_ctx_uint8_p
#pragma weak shmem_ctx_uint16_p     = pshmem_ctx_uint16_p
#pragma weak shmem_ctx_uint32_p     = pshmem_ctx_uint32_p
#pragma weak shmem_ctx_uint64_p     = pshmem_ctx_uint64_p
#pragma weak shmem_ctx_size_p       = pshmem_ctx_size_p
#pragma weak shmem_ctx_ptrdiff_p    = pshmem_ctx_ptrdiff_p

#pragma weak shmem_char_p           = pshmem_char_p
#pragma weak shmem_short_p          = pshmem_short_p
#pragma weak shmem_int_p            = pshmem_int_p
#pragma weak shmem_long_p           = pshmem_long_p
#pragma weak shmem_float_p          = pshmem_float_p
#pragma weak shmem_double_p         = pshmem_double_p
#pragma weak shmem_longlong_p       = pshmem_longlong_p
#pragma weak shmem_schar_p          = pshmem_schar_p
#pragma weak shmem_uchar_p          = pshmem_uchar_p
#pragma weak shmem_ushort_p         = pshmem_ushort_p
#pragma weak shmem_uint_p           = pshmem_uint_p
#pragma weak shmem_ulong_p          = pshmem_ulong_p
#pragma weak shmem_ulonglong_p      = pshmem_ulonglong_p
#pragma weak shmem_longdouble_p     = pshmem_longdouble_p
#pragma weak shmem_int8_p           = pshmem_int8_p
#pragma weak shmem_int16_p          = pshmem_int16_p
#pragma weak shmem_int32_p          = pshmem_int32_p
#pragma weak shmem_int64_p          = pshmem_int64_p
#pragma weak shmem_uint8_p          = pshmem_uint8_p
#pragma weak shmem_uint16_p         = pshmem_uint16_p
#pragma weak shmem_uint32_p         = pshmem_uint32_p
#pragma weak shmem_uint64_p         = pshmem_uint64_p
#pragma weak shmem_size_p           = pshmem_size_p
#pragma weak shmem_ptrdiff_p        = pshmem_ptrdiff_p

#pragma weak shmemx_int16_p = pshmemx_int16_p
#pragma weak shmemx_int32_p = pshmemx_int32_p
#pragma weak shmemx_int64_p = pshmemx_int64_p

#pragma weak shmem_ctx_char_put_signal             = pshmem_ctx_char_put_signal
#pragma weak shmem_ctx_short_put_signal            = pshmem_ctx_short_put_signal
#pragma weak shmem_ctx_int_put_signal              = pshmem_ctx_int_put_signal
#pragma weak shmem_ctx_long_put_signal             = pshmem_ctx_long_put_signal
#pragma weak shmem_ctx_float_put_signal            = pshmem_ctx_float_put_signal
#pragma weak shmem_ctx_double_put_signal           = pshmem_ctx_double_put_signal
#pragma weak shmem_ctx_longlong_put_signal         = pshmem_ctx_longlong_put_signal
#pragma weak shmem_ctx_schar_put_signal            = pshmem_ctx_schar_put_signal
#pragma weak shmem_ctx_uchar_put_signal            = pshmem_ctx_uchar_put_signal
#pragma weak shmem_ctx_ushort_put_signal           = pshmem_ctx_ushort_put_signal
#pragma weak shmem_ctx_uint_put_signal             = pshmem_ctx_uint_put_signal
#pragma weak shmem_ctx_ulong_put_signal            = pshmem_ctx_ulong_put_signal
#pragma weak shmem_ctx_ulonglong_put_signal        = pshmem_ctx_ulonglong_put_signal
#pragma weak shmem_ctx_longdouble_put_signal       = pshmem_ctx_longdouble_put_signal
#pragma weak shmem_ctx_int8_put_signal             = pshmem_ctx_int8_put_signal
#pragma weak shmem_ctx_int16_put_signal            = pshmem_ctx_int16_put_signal
#pragma weak shmem_ctx_int32_put_signal            = pshmem_ctx_int32_put_signal
#pragma weak shmem_ctx_int64_put_signal            = pshmem_ctx_int64_put_signal
#pragma weak shmem_ctx_uint8_put_signal            = pshmem_ctx_uint8_put_signal
#pragma weak shmem_ctx_uint16_put_signal           = pshmem_ctx_uint16_put_signal
#pragma weak shmem_ctx_uint32_put_signal           = pshmem_ctx_uint32_put_signal
#pragma weak shmem_ctx_uint64_put_signal           = pshmem_ctx_uint64_put_signal
#pragma weak shmem_ctx_size_put_signal             = pshmem_ctx_size_put_signal
#pragma weak shmem_ctx_ptrdiff_put_signal          = pshmem_ctx_ptrdiff_put_signal

#pragma weak shmem_char_put_signal                 = pshmem_char_put_signal
#pragma weak shmem_short_put_signal                = pshmem_short_put_signal
#pragma weak shmem_int_put_signal                  = pshmem_int_put_signal
#pragma weak shmem_long_put_signal                 = pshmem_long_put_signal
#pragma weak shmem_float_put_signal                = pshmem_float_put_signal
#pragma weak shmem_double_put_signal               = pshmem_double_put_signal
#pragma weak shmem_longlong_put_signal             = pshmem_longlong_put_signal
#pragma weak shmem_schar_put_signal                = pshmem_schar_put_signal
#pragma weak shmem_uchar_put_signal                = pshmem_uchar_put_signal
#pragma weak shmem_ushort_put_signal               = pshmem_ushort_put_signal
#pragma weak shmem_uint_put_signal                 = pshmem_uint_put_signal
#pragma weak shmem_ulong_put_signal                = pshmem_ulong_put_signal
#pragma weak shmem_ulonglong_put_signal            = pshmem_ulonglong_put_signal
#pragma weak shmem_longdouble_put_signal           = pshmem_longdouble_put_signal
#pragma weak shmem_int8_put_signal                 = pshmem_int8_put_signal
#pragma weak shmem_int16_put_signal                = pshmem_int16_put_signal
#pragma weak shmem_int32_put_signal                = pshmem_int32_put_signal
#pragma weak shmem_int64_put_signal                = pshmem_int64_put_signal
#pragma weak shmem_uint8_put_signal                = pshmem_uint8_put_signal
#pragma weak shmem_uint16_put_signal               = pshmem_uint16_put_signal
#pragma weak shmem_uint32_put_signal               = pshmem_uint32_put_signal
#pragma weak shmem_uint64_put_signal               = pshmem_uint64_put_signal
#pragma weak shmem_size_put_signal                 = pshmem_size_put_signal
#pragma weak shmem_ptrdiff_put_signal              = pshmem_ptrdiff_put_signal

#pragma weak shmem_put8_signal                     = pshmem_put8_signal
#pragma weak shmem_put16_signal                    = pshmem_put16_signal
#pragma weak shmem_put32_signal                    = pshmem_put32_signal
#pragma weak shmem_put64_signal                    = pshmem_put64_signal
#pragma weak shmem_put128_signal                   = pshmem_put128_signal

#pragma weak shmem_ctx_put8_signal                 = pshmem_ctx_put8_signal
#pragma weak shmem_ctx_put16_signal                = pshmem_ctx_put16_signal
#pragma weak shmem_ctx_put32_signal                = pshmem_ctx_put32_signal
#pragma weak shmem_ctx_put64_signal                = pshmem_ctx_put64_signal
#pragma weak shmem_ctx_put128_signal               = pshmem_ctx_put128_signal

#pragma weak shmem_putmem_signal                  = pshmem_putmem_signal
#pragma weak shmem_ctx_putmem_signal              = pshmem_ctx_putmem_signal

/*
 * Nonblocking signaled put routines
 */
#pragma weak shmem_ctx_char_put_signal_nbi             = pshmem_ctx_char_put_signal_nbi
#pragma weak shmem_ctx_short_put_signal_nbi            = pshmem_ctx_short_put_signal_nbi
#pragma weak shmem_ctx_int_put_signal_nbi              = pshmem_ctx_int_put_signal_nbi
#pragma weak shmem_ctx_long_put_signal_nbi             = pshmem_ctx_long_put_signal_nbi
#pragma weak shmem_ctx_float_put_signal_nbi            = pshmem_ctx_float_put_signal_nbi
#pragma weak shmem_ctx_double_put_signal_nbi           = pshmem_ctx_double_put_signal_nbi
#pragma weak shmem_ctx_longlong_put_signal_nbi         = pshmem_ctx_longlong_put_signal_nbi
#pragma weak shmem_ctx_schar_put_signal_nbi            = pshmem_ctx_schar_put_signal_nbi
#pragma weak shmem_ctx_uchar_put_signal_nbi            = pshmem_ctx_uchar_put_signal_nbi
#pragma weak shmem_ctx_ushort_put_signal_nbi           = pshmem_ctx_ushort_put_signal_nbi
#pragma weak shmem_ctx_uint_put_signal_nbi             = pshmem_ctx_uint_put_signal_nbi
#pragma weak shmem_ctx_ulong_put_signal_nbi            = pshmem_ctx_ulong_put_signal_nbi
#pragma weak shmem_ctx_ulonglong_put_signal_nbi        = pshmem_ctx_ulonglong_put_signal_nbi
#pragma weak shmem_ctx_longdouble_put_signal_nbi       = pshmem_ctx_longdouble_put_signal_nbi
#pragma weak shmem_ctx_int8_put_signal_nbi             = pshmem_ctx_int8_put_signal_nbi
#pragma weak shmem_ctx_int16_put_signal_nbi            = pshmem_ctx_int16_put_signal_nbi
#pragma weak shmem_ctx_int32_put_signal_nbi            = pshmem_ctx_int32_put_signal_nbi
#pragma weak shmem_ctx_int64_put_signal_nbi            = pshmem_ctx_int64_put_signal_nbi
#pragma weak shmem_ctx_uint8_put_signal_nbi            = pshmem_ctx_uint8_put_signal_nbi
#pragma weak shmem_ctx_uint16_put_signal_nbi           = pshmem_ctx_uint16_put_signal_nbi
#pragma weak shmem_ctx_uint32_put_signal_nbi           = pshmem_ctx_uint32_put_signal_nbi
#pragma weak shmem_ctx_uint64_put_signal_nbi           = pshmem_ctx_uint64_put_signal_nbi
#pragma weak shmem_ctx_size_put_signal_nbi             = pshmem_ctx_size_put_signal_nbi
#pragma weak shmem_ctx_ptrdiff_put_signal_nbi          = pshmem_ctx_ptrdiff_put_signal_nbi

#pragma weak shmem_char_put_signal_nbi                 = pshmem_char_put_signal_nbi
#pragma weak shmem_short_put_signal_nbi                = pshmem_short_put_signal_nbi
#pragma weak shmem_int_put_signal_nbi                  = pshmem_int_put_signal_nbi
#pragma weak shmem_long_put_signal_nbi                 = pshmem_long_put_signal_nbi
#pragma weak shmem_float_put_signal_nbi                = pshmem_float_put_signal_nbi
#pragma weak shmem_double_put_signal_nbi               = pshmem_double_put_signal_nbi
#pragma weak shmem_longlong_put_signal_nbi             = pshmem_longlong_put_signal_nbi
#pragma weak shmem_schar_put_signal_nbi                = pshmem_schar_put_signal_nbi
#pragma weak shmem_uchar_put_signal_nbi                = pshmem_uchar_put_signal_nbi
#pragma weak shmem_ushort_put_signal_nbi               = pshmem_ushort_put_signal_nbi
#pragma weak shmem_uint_put_signal_nbi                 = pshmem_uint_put_signal_nbi
#pragma weak shmem_ulong_put_signal_nbi                = pshmem_ulong_put_signal_nbi
#pragma weak shmem_ulonglong_put_signal_nbi            = pshmem_ulonglong_put_signal_nbi
#pragma weak shmem_longdouble_put_signal_nbi           = pshmem_longdouble_put_signal_nbi
#pragma weak shmem_int8_put_signal_nbi                 = pshmem_int8_put_signal_nbi
#pragma weak shmem_int16_put_signal_nbi                = pshmem_int16_put_signal_nbi
#pragma weak shmem_int32_put_signal_nbi                = pshmem_int32_put_signal_nbi
#pragma weak shmem_int64_put_signal_nbi                = pshmem_int64_put_signal_nbi
#pragma weak shmem_uint8_put_signal_nbi                = pshmem_uint8_put_signal_nbi
#pragma weak shmem_uint16_put_signal_nbi               = pshmem_uint16_put_signal_nbi
#pragma weak shmem_uint32_put_signal_nbi               = pshmem_uint32_put_signal_nbi
#pragma weak shmem_uint64_put_signal_nbi               = pshmem_uint64_put_signal_nbi
#pragma weak shmem_size_put_signal_nbi                 = pshmem_size_put_signal_nbi
#pragma weak shmem_ptrdiff_put_signal_nbi              = pshmem_ptrdiff_put_signal_nbi

#pragma weak shmem_put8_signal_nbi                     = pshmem_put8_signal_nbi
#pragma weak shmem_put16_signal_nbi                    = pshmem_put16_signal_nbi
#pragma weak shmem_put32_signal_nbi                    = pshmem_put32_signal_nbi
#pragma weak shmem_put64_signal_nbi                    = pshmem_put64_signal_nbi
#pragma weak shmem_put128_signal_nbi                   = pshmem_put128_signal_nbi

#pragma weak shmem_ctx_put8_signal_nbi                 = pshmem_ctx_put8_signal_nbi
#pragma weak shmem_ctx_put16_signal_nbi                = pshmem_ctx_put16_signal_nbi
#pragma weak shmem_ctx_put32_signal_nbi                = pshmem_ctx_put32_signal_nbi
#pragma weak shmem_ctx_put64_signal_nbi                = pshmem_ctx_put64_signal_nbi
#pragma weak shmem_ctx_put128_signal_nbi               = pshmem_ctx_put128_signal_nbi

#pragma weak shmem_putmem_signal_nbi                  = pshmem_putmem_signal_nbi
#pragma weak shmem_ctx_putmem_signal_nbi              = pshmem_ctx_putmem_signal_nbi

#include "oshmem/shmem/c/profile/defines.h"
#endif

SHMEM_CTX_TYPE_P(_char, char, shmem)
SHMEM_CTX_TYPE_P(_short, short, shmem)
SHMEM_CTX_TYPE_P(_int, int, shmem)
SHMEM_CTX_TYPE_P(_long, long, shmem)
SHMEM_CTX_TYPE_P(_longlong, long long, shmem)
SHMEM_CTX_TYPE_P(_schar, signed char, shmem)
SHMEM_CTX_TYPE_P(_uchar, unsigned char, shmem)
SHMEM_CTX_TYPE_P(_ushort, unsigned short, shmem)
SHMEM_CTX_TYPE_P(_uint, unsigned int, shmem)
SHMEM_CTX_TYPE_P(_ulong, unsigned long, shmem)
SHMEM_CTX_TYPE_P(_ulonglong, unsigned long long, shmem)
SHMEM_CTX_TYPE_P(_float, float, shmem)
SHMEM_CTX_TYPE_P(_double, double, shmem)
SHMEM_CTX_TYPE_P(_longdouble, long double, shmem)
SHMEM_CTX_TYPE_P(_int8, int8_t, shmem)
SHMEM_CTX_TYPE_P(_int16, int16_t, shmem)
SHMEM_CTX_TYPE_P(_int32, int32_t, shmem)
SHMEM_CTX_TYPE_P(_int64, int64_t, shmem)
SHMEM_CTX_TYPE_P(_uint8, uint8_t, shmem)
SHMEM_CTX_TYPE_P(_uint16, uint16_t, shmem)
SHMEM_CTX_TYPE_P(_uint32, uint32_t, shmem)
SHMEM_CTX_TYPE_P(_uint64, uint64_t, shmem)
SHMEM_CTX_TYPE_P(_size, size_t, shmem)
SHMEM_CTX_TYPE_P(_ptrdiff, ptrdiff_t, shmem)

SHMEM_TYPE_P(_char, char, shmem)
SHMEM_TYPE_P(_short, short, shmem)
SHMEM_TYPE_P(_int, int, shmem)
SHMEM_TYPE_P(_long, long, shmem)
SHMEM_TYPE_P(_longlong, long long, shmem)
SHMEM_TYPE_P(_schar, signed char, shmem)
SHMEM_TYPE_P(_uchar, unsigned char, shmem)
SHMEM_TYPE_P(_ushort, unsigned short, shmem)
SHMEM_TYPE_P(_uint, unsigned int, shmem)
SHMEM_TYPE_P(_ulong, unsigned long, shmem)
SHMEM_TYPE_P(_ulonglong, unsigned long long, shmem)
SHMEM_TYPE_P(_float, float, shmem)
SHMEM_TYPE_P(_double, double, shmem)
SHMEM_TYPE_P(_longdouble, long double, shmem)
SHMEM_TYPE_P(_int8, int8_t, shmem)
SHMEM_TYPE_P(_int16, int16_t, shmem)
SHMEM_TYPE_P(_int32, int32_t, shmem)
SHMEM_TYPE_P(_int64, int64_t, shmem)
SHMEM_TYPE_P(_uint8, uint8_t, shmem)
SHMEM_TYPE_P(_uint16, uint16_t, shmem)
SHMEM_TYPE_P(_uint32, uint32_t, shmem)
SHMEM_TYPE_P(_uint64, uint64_t, shmem)
SHMEM_TYPE_P(_size, size_t, shmem)
SHMEM_TYPE_P(_ptrdiff, ptrdiff_t, shmem)

SHMEM_TYPE_P(_int16, int16_t, shmemx)
SHMEM_TYPE_P(_int32, int32_t, shmemx)
SHMEM_TYPE_P(_int64, int64_t, shmemx)
