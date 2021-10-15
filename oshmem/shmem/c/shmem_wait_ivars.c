/*
 * Copyright (c) 2013      Mellanox Technologies, Inc.
 *                         All rights reserved.
 * Copyright (c) 2019      IBM Corporation.  All rights reserved.
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


#if OSHMEM_PROFILING
#include "oshmem/include/pshmem.h"

#pragma weak shmem_int_wait_until_all         = pshmem_int_wait_until_all
#pragma weak shmem_long_wait_until_all        = pshmem_long_wait_until_all
#pragma weak shmem_longlong_wait_until_all    = pshmem_longlong_wait_until_all
#pragma weak shmem_uint_wait_until_all        = pshmem_uint_wait_until_all
#pragma weak shmem_ulong_wait_until_all       = pshmem_ulong_wait_until_all
#pragma weak shmem_ulonglong_wait_until_all   = pshmem_ulonglong_wait_until_all
#pragma weak shmem_int32_wait_until_all       = pshmem_int32_wait_until_all
#pragma weak shmem_int64_wait_until_all       = pshmem_int64_wait_until_all
#pragma weak shmem_uint32_wait_until_all      = pshmem_uint32_wait_until_all
#pragma weak shmem_uint64_wait_until_all      = pshmem_uint64_wait_until_all
#pragma weak shmem_size_wait_until_all        = pshmem_size_wait_until_all
#pragma weak shmem_ptrdiff_wait_until_all     = pshmem_ptrdiff_wait_until_all


#pragma weak shmem_int_wait_until_any         = pshmem_int_wait_until_any
#pragma weak shmem_long_wait_until_any        = pshmem_long_wait_until_any
#pragma weak shmem_longlong_wait_until_any    = pshmem_longlong_wait_until_any
#pragma weak shmem_uint_wait_until_any        = pshmem_uint_wait_until_any
#pragma weak shmem_ulong_wait_until_any       = pshmem_ulong_wait_until_any
#pragma weak shmem_ulonglong_wait_until_any   = pshmem_ulonglong_wait_until_any
#pragma weak shmem_int32_wait_until_any       = pshmem_int32_wait_until_any
#pragma weak shmem_int64_wait_until_any       = pshmem_int64_wait_until_any
#pragma weak shmem_uint32_wait_until_any      = pshmem_uint32_wait_until_any
#pragma weak shmem_uint64_wait_until_any      = pshmem_uint64_wait_until_any
#pragma weak shmem_size_wait_until_any        = pshmem_size_wait_until_any
#pragma weak shmem_ptrdiff_wait_until_any     = pshmem_ptrdiff_wait_until_any


#pragma weak shmem_int_wait_until_some         = pshmem_int_wait_until_some
#pragma weak shmem_long_wait_until_some        = pshmem_long_wait_until_some
#pragma weak shmem_longlong_wait_until_some    = pshmem_longlong_wait_until_some
#pragma weak shmem_uint_wait_until_some        = pshmem_uint_wait_until_some
#pragma weak shmem_ulong_wait_until_some       = pshmem_ulong_wait_until_some
#pragma weak shmem_ulonglong_wait_until_some   = pshmem_ulonglong_wait_until_some
#pragma weak shmem_int32_wait_until_some       = pshmem_int32_wait_until_some
#pragma weak shmem_int64_wait_until_some       = pshmem_int64_wait_until_some
#pragma weak shmem_uint32_wait_until_some      = pshmem_uint32_wait_until_some
#pragma weak shmem_uint64_wait_until_some      = pshmem_uint64_wait_until_some
#pragma weak shmem_size_wait_until_some        = pshmem_size_wait_until_some
#pragma weak shmem_ptrdiff_wait_until_some     = pshmem_ptrdiff_wait_until_some


#pragma weak shmem_int_wait_until_all_vector         = pshmem_int_wait_until_all_vector
#pragma weak shmem_long_wait_until_all_vector        = pshmem_long_wait_until_all_vector
#pragma weak shmem_longlong_wait_until_all_vector    = pshmem_longlong_wait_until_all_vector
#pragma weak shmem_uint_wait_until_all_vector        = pshmem_uint_wait_until_all_vector
#pragma weak shmem_ulong_wait_until_all_vector       = pshmem_ulong_wait_until_all_vector
#pragma weak shmem_ulonglong_wait_until_all_vector   = pshmem_ulonglong_wait_until_all_vector
#pragma weak shmem_int32_wait_until_all_vector       = pshmem_int32_wait_until_all_vector
#pragma weak shmem_int64_wait_until_all_vector       = pshmem_int64_wait_until_all_vector
#pragma weak shmem_uint32_wait_until_all_vector      = pshmem_uint32_wait_until_all_vector
#pragma weak shmem_uint64_wait_until_all_vector      = pshmem_uint64_wait_until_all_vector
#pragma weak shmem_size_wait_until_all_vector        = pshmem_size_wait_until_all_vector
#pragma weak shmem_ptrdiff_wait_until_all_vector     = pshmem_ptrdiff_wait_until_all_vector


#pragma weak shmem_int_wait_until_any_vector         = pshmem_int_wait_until_any_vector
#pragma weak shmem_long_wait_until_any_vector        = pshmem_long_wait_until_any_vector
#pragma weak shmem_longlong_wait_until_any_vector    = pshmem_longlong_wait_until_any_vector
#pragma weak shmem_uint_wait_until_any_vector        = pshmem_uint_wait_until_any_vector
#pragma weak shmem_ulong_wait_until_any_vector       = pshmem_ulong_wait_until_any_vector
#pragma weak shmem_ulonglong_wait_until_any_vector   = pshmem_ulonglong_wait_until_any_vector
#pragma weak shmem_int32_wait_until_any_vector       = pshmem_int32_wait_until_any_vector
#pragma weak shmem_int64_wait_until_any_vector       = pshmem_int64_wait_until_any_vector
#pragma weak shmem_uint32_wait_until_any_vector      = pshmem_uint32_wait_until_any_vector
#pragma weak shmem_uint64_wait_until_any_vector      = pshmem_uint64_wait_until_any_vector
#pragma weak shmem_size_wait_until_any_vector        = pshmem_size_wait_until_any_vector
#pragma weak shmem_ptrdiff_wait_until_any_vector     = pshmem_ptrdiff_wait_until_any_vector


#pragma weak shmem_int_wait_until_some_vector         = pshmem_int_wait_until_some_vector
#pragma weak shmem_long_wait_until_some_vector        = pshmem_long_wait_until_some_vector
#pragma weak shmem_longlong_wait_until_some_vector    = pshmem_longlong_wait_until_some_vector
#pragma weak shmem_uint_wait_until_some_vector        = pshmem_uint_wait_until_some_vector
#pragma weak shmem_ulong_wait_until_some_vector       = pshmem_ulong_wait_until_some_vector
#pragma weak shmem_ulonglong_wait_until_some_vector   = pshmem_ulonglong_wait_until_some_vector
#pragma weak shmem_int32_wait_until_some_vector       = pshmem_int32_wait_until_some_vector
#pragma weak shmem_int64_wait_until_some_vector       = pshmem_int64_wait_until_some_vector
#pragma weak shmem_uint32_wait_until_some_vector      = pshmem_uint32_wait_until_some_vector
#pragma weak shmem_uint64_wait_until_some_vector      = pshmem_uint64_wait_until_some_vector
#pragma weak shmem_size_wait_until_some_vector        = pshmem_size_wait_until_some_vector
#pragma weak shmem_ptrdiff_wait_until_some_vector     = pshmem_ptrdiff_wait_until_some_vector


#include "oshmem/shmem/c/profile/defines.h"
#endif

#define SHMEM_TYPE_WAIT_UNTIL_IVARS(type_name, type, code, prefix, postfix)    \
    void prefix##type_name##_wait_until_##postfix(type *ivars, size_t nelems, const int *status, int cmp, type value)   \
    {                                                               \
        int rc = OSHMEM_SUCCESS;                                    \
                                                                    \
        RUNTIME_CHECK_INIT();                                       \
                                                                    \
        rc = MCA_SPML_CALL(wait_until_##postfix(                    \
            (void*)ivars,                                           \
            cmp,                                                    \
            (void*)&value,                                          \
            nelems, status, code));                                 \
        RUNTIME_CHECK_RC(rc);                                       \
                                                                    \
        return ;                                                    \
    }

SHMEM_TYPE_WAIT_UNTIL_IVARS(_int, volatile int, SHMEM_INT, shmem, all)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_long, volatile long, SHMEM_LONG, shmem, all)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_longlong, volatile long long, SHMEM_LLONG, shmem, all)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_uint, volatile unsigned int, SHMEM_INT, shmem, all)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_ulong, volatile unsigned long, SHMEM_LONG, shmem, all)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_ulonglong, volatile unsigned long long, SHMEM_LLONG, shmem, all)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_int32, volatile int32_t, SHMEM_INT32_T, shmem, all)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_int64, volatile int64_t, SHMEM_INT64_T, shmem, all)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_uint32, volatile uint32_t, SHMEM_INT32_T, shmem, all)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_uint64, volatile uint64_t, SHMEM_INT64_T, shmem, all)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_size, volatile size_t, SHMEM_LLONG, shmem, all)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_ptrdiff, volatile ptrdiff_t, SHMEM_LLONG, shmem, all)

SHMEM_TYPE_WAIT_UNTIL_IVARS(_int, volatile int, SHMEM_INT, shmem, any)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_long, volatile long, SHMEM_LONG, shmem, any)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_longlong, volatile long long, SHMEM_LLONG, shmem, any)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_uint, volatile unsigned int, SHMEM_INT, shmem, any)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_ulong, volatile unsigned long, SHMEM_LONG, shmem, any)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_ulonglong, volatile unsigned long long, SHMEM_LLONG, shmem, any)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_int32, volatile int32_t, SHMEM_INT32_T, shmem, any)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_int64, volatile int64_t, SHMEM_INT64_T, shmem, any)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_uint32, volatile uint32_t, SHMEM_INT32_T, shmem, any)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_uint64, volatile uint64_t, SHMEM_INT64_T, shmem, any)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_size, volatile size_t, SHMEM_LLONG, shmem, any)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_ptrdiff, volatile ptrdiff_t, SHMEM_LLONG, shmem, any)


SHMEM_TYPE_WAIT_UNTIL_IVARS(_int, volatile int, SHMEM_INT, shmem, some)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_long, volatile long, SHMEM_LONG, shmem, some)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_longlong, volatile long long, SHMEM_LLONG, shmem, some)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_uint, volatile unsigned int, SHMEM_INT, shmem, some)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_ulong, volatile unsigned long, SHMEM_LONG, shmem, some)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_ulonglong, volatile unsigned long long, SHMEM_LLONG, shmem, some)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_int32, volatile int32_t, SHMEM_INT32_T, shmem, some)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_int64, volatile int64_t, SHMEM_INT64_T, shmem, some)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_uint32, volatile uint32_t, SHMEM_INT32_T, shmem, some)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_uint64, volatile uint64_t, SHMEM_INT64_T, shmem, some)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_size, volatile size_t, SHMEM_LLONG, shmem, some)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_ptrdiff, volatile ptrdiff_t, SHMEM_LLONG, shmem, some)


SHMEM_TYPE_WAIT_UNTIL_IVARS(_int, volatile int, SHMEM_INT, shmem, all_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_long, volatile long, SHMEM_LONG, shmem, all_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_longlong, volatile long long, SHMEM_LLONG, shmem, all_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_uint, volatile unsigned int, SHMEM_INT, shmem, all_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_ulong, volatile unsigned long, SHMEM_LONG, shmem, all_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_ulonglong, volatile unsigned long long, SHMEM_LLONG, shmem, all_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_int32, volatile int32_t, SHMEM_INT32_T, shmem, all_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_int64, volatile int64_t, SHMEM_INT64_T, shmem, all_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_uint32, volatile uint32_t, SHMEM_INT32_T, shmem, all_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_uint64, volatile uint64_t, SHMEM_INT64_T, shmem, all_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_size, volatile size_t, SHMEM_LLONG, shmem, all_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_ptrdiff, volatile ptrdiff_t, SHMEM_LLONG, shmem, all_vector)



SHMEM_TYPE_WAIT_UNTIL_IVARS(_int, volatile int, SHMEM_INT, shmem, any_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_long, volatile long, SHMEM_LONG, shmem, any_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_longlong, volatile long long, SHMEM_LLONG, shmem, any_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_uint, volatile unsigned int, SHMEM_INT, shmem, any_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_ulong, volatile unsigned long, SHMEM_LONG, shmem, any_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_ulonglong, volatile unsigned long long, SHMEM_LLONG, shmem, any_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_int32, volatile int32_t, SHMEM_INT32_T, shmem, any_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_int64, volatile int64_t, SHMEM_INT64_T, shmem, any_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_uint32, volatile uint32_t, SHMEM_INT32_T, shmem, any_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_uint64, volatile uint64_t, SHMEM_INT64_T, shmem, any_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_size, volatile size_t, SHMEM_LLONG, shmem, any_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_ptrdiff, volatile ptrdiff_t, SHMEM_LLONG, shmem, any_vector)



SHMEM_TYPE_WAIT_UNTIL_IVARS(_int, volatile int, SHMEM_INT, shmem, some_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_long, volatile long, SHMEM_LONG, shmem, some_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_longlong, volatile long long, SHMEM_LLONG, shmem, some_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_uint, volatile unsigned int, SHMEM_INT, shmem, some_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_ulong, volatile unsigned long, SHMEM_LONG, shmem, some_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_ulonglong, volatile unsigned long long, SHMEM_LLONG, shmem, some_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_int32, volatile int32_t, SHMEM_INT32_T, shmem, some_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_int64, volatile int64_t, SHMEM_INT64_T, shmem, some_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_uint32, volatile uint32_t, SHMEM_INT32_T, shmem, some_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_uint64, volatile uint64_t, SHMEM_INT64_T, shmem, some_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_size, volatile size_t, SHMEM_LLONG, shmem, some_vector)
SHMEM_TYPE_WAIT_UNTIL_IVARS(_ptrdiff, volatile ptrdiff_t, SHMEM_LLONG, shmem, some_vector)


