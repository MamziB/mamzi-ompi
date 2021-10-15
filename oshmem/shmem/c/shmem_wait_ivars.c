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

#define SHMEM_TYPE_WAIT_UNTIL_ALL(type_name, type, code, prefix)    \
    void prefix##type_name##_wait_until_all(type *ivars, size_t nelems, const int *status, int cmp, type value)   \
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

#define SHMEM_TYPE_WAIT_UNTIL_ANY_VECTOR(type_name, type, code, prefix)    \
    size_t prefix##type_name##_wait_until_any_vector(type *ivars, size_t nelems, const int *status, int cmp, type *values)   \
    {                                                               \
        size_t rc = 0;                                    \
                                                                    \
        RUNTIME_CHECK_INIT();                                       \
                                                                    \
        rc = MCA_SPML_CALL(wait_until_##postfix(                    \
            (void*)ivars,                                           \
            cmp,                                                    \
            values,                                          \
            nelems, status, code));                                 \
        RUNTIME_CHECK_RC(rc);                                       \
                                                                    \
        return rc;                                                    \
    }

#define SHMEM_TYPE_WAIT_UNTIL_SOME_VECTOR(type_name, type, code, prefix)    \
    size_t prefix##type_name##_wait_until_some_vector(type *ivars, size_t nelems, size_t *indices, const int *status, int cmp, type *values)   \
    {                                                               \
        size_t rc = 0;                                              \
                                                                    \
        RUNTIME_CHECK_INIT();                                       \
                                                                    \
        rc = MCA_SPML_CALL(wait_until_##postfix(                    \
            (void*)ivars,                                           \
            cmp,                                                    \
            values,                                                 \
            nelems, indices, status, code));                        \
        RUNTIME_CHECK_RC(rc);                                       \
                                                                    \
        return rc;                                                  \
    }


#define SHMEM_TYPE_WAIT_UNTIL_ALL_VECTOR(type_name, type, code, prefix)    \
    void prefix##type_name##_wait_until_all_vector(type *ivars, size_t nelems, const int *status, int cmp, type *values)   \
    {                                                               \
        int rc = OSHMEM_SUCCESS;                                    \
                                                                    \
        RUNTIME_CHECK_INIT();                                       \
                                                                    \
        rc = MCA_SPML_CALL(wait_until_##postfix(                    \
            (void*)ivars,                                           \
            cmp,                                                    \
            values,                                          \
            nelems, status, code));                                 \
        RUNTIME_CHECK_RC(rc);                                       \
                                                                    \
        return ;                                                    \
    }

#define SHMEM_TYPE_WAIT_UNTIL_SOME(type_name, type, code, prefix)    \
    size_t  prefix##type_name##_wait_until_some(type *ivars, size_t nelems, size_t *indices, const int *status, int cmp, type value)   \
    {                                                               \
        size_t rc = 0;                                    \
                                                                    \
        RUNTIME_CHECK_INIT();                                       \
                                                                    \
        rc = MCA_SPML_CALL(wait_until_##postfix(                    \
            (void*)ivars,                                           \
            cmp,                                                    \
            (void*)&values,                                          \
            nelems, indices, status, code));                                 \
        RUNTIME_CHECK_RC(rc);                                       \
                                                                    \
        return rc;                                                    \
    }


#define SHMEM_TYPE_WAIT_UNTIL_ANY(type_name, type, code, prefix)    \
    size_t prefix##type_name##_wait_until_any(type *ivars, size_t nelems, const int *status, int cmp, type value)   \
    {                                                               \
        size_t rc = 0;                                    \
                                                                    \
        RUNTIME_CHECK_INIT();                                       \
                                                                    \
        rc = MCA_SPML_CALL(wait_until_##postfix(                    \
            (void*)ivars,                                           \
            cmp,                                                    \
            (void*)&values,                                          \
            nelems, status, code));                                 \
        RUNTIME_CHECK_RC(rc);                                       \
                                                                    \
        return rc;                                                    \
    }


SHMEM_TYPE_WAIT_UNTIL_ALL(_int, volatile int, SHMEM_INT, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL(_long, volatile long, SHMEM_LONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL(_longlong, volatile long long, SHMEM_LLONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL(_uint, volatile unsigned int, SHMEM_INT, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL(_ulong, volatile unsigned long, SHMEM_LONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL(_ulonglong, volatile unsigned long long, SHMEM_LLONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL(_int32, volatile int32_t, SHMEM_INT32_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL(_int64, volatile int64_t, SHMEM_INT64_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL(_uint32, volatile uint32_t, SHMEM_INT32_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL(_uint64, volatile uint64_t, SHMEM_INT64_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL(_size, volatile size_t, SHMEM_LLONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL(_ptrdiff, volatile ptrdiff_t, SHMEM_LLONG, shmem)

SHMEM_TYPE_WAIT_UNTIL_ANY(_int, volatile int, SHMEM_INT, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY(_long, volatile long, SHMEM_LONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY(_longlong, volatile long long, SHMEM_LLONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY(_uint, volatile unsigned int, SHMEM_INT, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY(_ulong, volatile unsigned long, SHMEM_LONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY(_ulonglong, volatile unsigned long long, SHMEM_LLONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY(_int32, volatile int32_t, SHMEM_INT32_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY(_int64, volatile int64_t, SHMEM_INT64_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY(_uint32, volatile uint32_t, SHMEM_INT32_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY(_uint64, volatile uint64_t, SHMEM_INT64_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY(_size, volatile size_t, SHMEM_LLONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY(_ptrdiff, volatile ptrdiff_t, SHMEM_LLONG, shmem)


SHMEM_TYPE_WAIT_UNTIL_SOME(_int, volatile int, SHMEM_INT, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME(_long, volatile long, SHMEM_LONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME(_longlong, volatile long long, SHMEM_LLONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME(_uint, volatile unsigned int, SHMEM_INT, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME(_ulong, volatile unsigned long, SHMEM_LONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME(_ulonglong, volatile unsigned long long, SHMEM_LLONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME(_int32, volatile int32_t, SHMEM_INT32_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME(_int64, volatile int64_t, SHMEM_INT64_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME(_uint32, volatile uint32_t, SHMEM_INT32_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME(_uint64, volatile uint64_t, SHMEM_INT64_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME(_size, volatile size_t, SHMEM_LLONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME(_ptrdiff, volatile ptrdiff_t, SHMEM_LLONG, shmem)


SHMEM_TYPE_WAIT_UNTIL_ALL_VECTOR(_int, volatile int, SHMEM_INT, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL_VECTOR(_long, volatile long, SHMEM_LONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL_VECTOR(_longlong, volatile long long, SHMEM_LLONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL_VECTOR(_uint, volatile unsigned int, SHMEM_INT, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL_VECTOR(_ulong, volatile unsigned long, SHMEM_LONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL_VECTOR(_ulonglong, volatile unsigned long long, SHMEM_LLONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL_VECTOR(_int32, volatile int32_t, SHMEM_INT32_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL_VECTOR(_int64, volatile int64_t, SHMEM_INT64_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL_VECTOR(_uint32, volatile uint32_t, SHMEM_INT32_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL_VECTOR(_uint64, volatile uint64_t, SHMEM_INT64_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL_VECTOR(_size, volatile size_t, SHMEM_LLONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ALL_VECTOR(_ptrdiff, volatile ptrdiff_t, SHMEM_LLONG, shmem)



SHMEM_TYPE_WAIT_UNTIL_ANY_VECTOR(_int, volatile int, SHMEM_INT, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY_VECTOR(_long, volatile long, SHMEM_LONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY_VECTOR(_longlong, volatile long long, SHMEM_LLONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY_VECTOR(_uint, volatile unsigned int, SHMEM_INT, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY_VECTOR(_ulong, volatile unsigned long, SHMEM_LONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY_VECTOR(_ulonglong, volatile unsigned long long, SHMEM_LLONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY_VECTOR(_int32, volatile int32_t, SHMEM_INT32_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY_VECTOR(_int64, volatile int64_t, SHMEM_INT64_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY_VECTOR(_uint32, volatile uint32_t, SHMEM_INT32_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY_VECTOR(_uint64, volatile uint64_t, SHMEM_INT64_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY_VECTOR(_size, volatile size_t, SHMEM_LLONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_ANY_VECTOR(_ptrdiff, volatile ptrdiff_t, SHMEM_LLONG, shmem)



SHMEM_TYPE_WAIT_UNTIL_SOME_VECTOR(_int, volatile int, SHMEM_INT, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME_VECTOR(_long, volatile long, SHMEM_LONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME_VECTOR(_longlong, volatile long long, SHMEM_LLONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME_VECTOR(_uint, volatile unsigned int, SHMEM_INT, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME_VECTOR(_ulong, volatile unsigned long, SHMEM_LONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME_VECTOR(_ulonglong, volatile unsigned long long, SHMEM_LLONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME_VECTOR(_int32, volatile int32_t, SHMEM_INT32_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME_VECTOR(_int64, volatile int64_t, SHMEM_INT64_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME_VECTOR(_uint32, volatile uint32_t, SHMEM_INT32_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME_VECTOR(_uint64, volatile uint64_t, SHMEM_INT64_T, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME_VECTOR(_size, volatile size_t, SHMEM_LLONG, shmem)
SHMEM_TYPE_WAIT_UNTIL_SOME_VECTOR(_ptrdiff, volatile ptrdiff_t, SHMEM_LLONG, shmem)


