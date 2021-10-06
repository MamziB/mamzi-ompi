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

#include "oshmem/mca/atomic/atomic.h"

/*
 * shmem_cswap performs an nonblocking atomic conditional swap operation.
 * The conditional swap routines write value to address target on PE pe, and return the previous
 * contents of target. The replacement must occur only if cond is equal to target;
 * otherwise target is left unchanged. In either case, the routine must return the initial value
 * of target. The operation must be completed without the possibility of another process updating
 * target between the time of the fetch and the update.
 */
#define DO_SHMEM_TYPE_ATOMIC_COMPARE_SWAP_NBI(ctx, type, fetch, target, cond, value, pe, out_value) do { \
        int rc = OSHMEM_SUCCESS;                                    \
        size_t size = 0;                                            \
                                                                    \
        RUNTIME_CHECK_INIT();                                       \
        RUNTIME_CHECK_PE(pe);                                       \
        RUNTIME_CHECK_ADDR(target);                                 \
                                                                    \
        size = sizeof(value);                                       \
        rc = MCA_ATOMIC_CALL(cswap_nb(                              \
            ctx,                                                    \
            fetch,                                                  \
            (void*)target,                                          \
            (uint64_t*)&out_value,                                  \
            OSHMEM_ATOMIC_PTR_2_INT(&cond, sizeof(cond)),           \
            OSHMEM_ATOMIC_PTR_2_INT(&value, sizeof(value)),         \
            size,                                                   \
            pe));                                                   \
        RUNTIME_CHECK_RC(rc);                                       \
    } while (0)

#define SHMEM_CTX_TYPE_ATOMIC_COMPARE_SWAP_NBI(type_name, type, prefix)                  \
    void prefix##_ctx##type_name##_atomic_compare_swap_nbi(shmem_ctx_t ctx, type *fetch, type *target, type cond, type value, int pe) \
    {                                                                                    \
        type out_value;                                                                  \
        DO_SHMEM_TYPE_ATOMIC_COMPARE_SWAP_NBI(ctx, type, fetch, target, cond, value,     \
                                   pe, out_value);                                       \
        return ;                                                                \
    }

#define SHMEM_TYPE_ATOMIC_COMPARE_SWAP_NBI(type_name, type, prefix)                      \
    void prefix##type_name##_atomic_compare_swap_nbi(type *fetch, type *target, type cond, type value, int pe) \
    {                                                                                    \
        type out_value;                                                                  \
        DO_SHMEM_TYPE_ATOMIC_COMPARE_SWAP_NBI(oshmem_ctx_default, type, fetch, target,   \
                                   cond, value, pe, out_value);                          \
        return ;                                                                \
    }

#if OSHMEM_PROFILING
#include "oshmem/include/pshmem.h"

/* Nonblocking Atomic Compare Swap */
#pragma weak shmem_ctx_int_atomic_compare_swap_nbi               = pshmem_ctx_int_atomic_compare_swap_nbi
#pragma weak shmem_ctx_long_atomic_compare_swap_nbi              = pshmem_ctx_long_atomic_compare_swap_nbi
#pragma weak shmem_ctx_longlong_atomic_compare_swap_nbi          = pshmem_ctx_longlong_atomic_compare_swap_nbi
#pragma weak shmem_ctx_uint_atomic_compare_swap_nbi              = pshmem_ctx_uint_atomic_compare_swap_nbi
#pragma weak shmem_ctx_ulong_atomic_compare_swap_nbi             = pshmem_ctx_ulong_atomic_compare_swap_nbi
#pragma weak shmem_ctx_ulonglong_atomic_compare_swap_nbi         = pshmem_ctx_ulonglong_atomic_compare_swap_nbi
#pragma weak shmem_ctx_int32_atomic_compare_swap_nbi             = pshmem_ctx_int32_atomic_compare_swap_nbi
#pragma weak shmem_ctx_int64_atomic_compare_swap_nbi             = pshmem_ctx_int64_atomic_compare_swap_nbi
#pragma weak shmem_ctx_uint32_atomic_compare_swap_nbi            = pshmem_ctx_uint32_atomic_compare_swap_nbi
#pragma weak shmem_ctx_uint64_atomic_compare_swap_nbi            = pshmem_ctx_uint64_atomic_compare_swap_nbi
#pragma weak shmem_ctx_size_atomic_compare_swap_nbi              = pshmem_ctx_size_atomic_compare_swap_nbi
#pragma weak shmem_ctx_ptrdiff_atomic_compare_swap_nbi           = pshmem_ctx_ptrdiff_atomic_compare_swap_nbi

#pragma weak shmem_int_atomic_compare_swap_nbi        			 = pshmem_int_atomic_compare_swap_nbi
#pragma weak shmem_long_atomic_compare_swap_nbi       			 = pshmem_long_atomic_compare_swap_nbi
#pragma weak shmem_longlong_atomic_compare_swap_nbi   			 = pshmem_longlong_atomic_compare_swap_nbi
#pragma weak shmem_uint_atomic_compare_swap_nbi       			 = pshmem_uint_atomic_compare_swap_nbi
#pragma weak shmem_ulong_atomic_compare_swap_nbi      			 = pshmem_ulong_atomic_compare_swap_nbi
#pragma weak shmem_ulonglong_atomic_compare_swap_nbi  			 = pshmem_ulonglong_atomic_compare_swap_nbi
#pragma weak shmem_int32_atomic_compare_swap_nbi      			 = pshmem_int32_atomic_compare_swap_nbi
#pragma weak shmem_int64_atomic_compare_swap_nbi      			 = pshmem_int64_atomic_compare_swap_nbi
#pragma weak shmem_uint32_atomic_compare_swap_nbi     			 = pshmem_uint32_atomic_compare_swap_nbi
#pragma weak shmem_uint64_atomic_compare_swap_nbi     			 = pshmem_uint64_atomic_compare_swap_nbi
#pragma weak shmem_size_atomic_compare_swap_nbi       			 = pshmem_size_atomic_compare_swap_nbi
#pragma weak shmem_ptrdiff_atomic_compare_swap_nbi    			 = pshmem_ptrdiff_atomic_compare_swap_nbi


#include "oshmem/shmem/c/profile/defines.h"
#endif

SHMEM_CTX_TYPE_ATOMIC_COMPARE_SWAP_NBI(_int, int, shmem)
SHMEM_CTX_TYPE_ATOMIC_COMPARE_SWAP_NBI(_long, long, shmem)
SHMEM_CTX_TYPE_ATOMIC_COMPARE_SWAP_NBI(_longlong, long long, shmem)
SHMEM_CTX_TYPE_ATOMIC_COMPARE_SWAP_NBI(_uint, unsigned int, shmem)
SHMEM_CTX_TYPE_ATOMIC_COMPARE_SWAP_NBI(_ulong, unsigned long, shmem)
SHMEM_CTX_TYPE_ATOMIC_COMPARE_SWAP_NBI(_ulonglong, unsigned long long, shmem)
SHMEM_CTX_TYPE_ATOMIC_COMPARE_SWAP_NBI(_int32, int32_t, shmem)
SHMEM_CTX_TYPE_ATOMIC_COMPARE_SWAP_NBI(_int64, int64_t, shmem)
SHMEM_CTX_TYPE_ATOMIC_COMPARE_SWAP_NBI(_uint32, uint32_t, shmem)
SHMEM_CTX_TYPE_ATOMIC_COMPARE_SWAP_NBI(_uint64, uint64_t, shmem)
SHMEM_CTX_TYPE_ATOMIC_COMPARE_SWAP_NBI(_size, size_t, shmem)
SHMEM_CTX_TYPE_ATOMIC_COMPARE_SWAP_NBI(_ptrdiff, ptrdiff_t, shmem)

SHMEM_TYPE_ATOMIC_COMPARE_SWAP_NBI(_int, int, shmem)
SHMEM_TYPE_ATOMIC_COMPARE_SWAP_NBI(_long, long, shmem)
SHMEM_TYPE_ATOMIC_COMPARE_SWAP_NBI(_longlong, long long, shmem)
SHMEM_TYPE_ATOMIC_COMPARE_SWAP_NBI(_uint, unsigned int, shmem)
SHMEM_TYPE_ATOMIC_COMPARE_SWAP_NBI(_ulong, unsigned long, shmem)
SHMEM_TYPE_ATOMIC_COMPARE_SWAP_NBI(_ulonglong, unsigned long long, shmem)
SHMEM_TYPE_ATOMIC_COMPARE_SWAP_NBI(_int32, int32_t, shmem)
SHMEM_TYPE_ATOMIC_COMPARE_SWAP_NBI(_int64, int64_t, shmem)
SHMEM_TYPE_ATOMIC_COMPARE_SWAP_NBI(_uint32, uint32_t, shmem)
SHMEM_TYPE_ATOMIC_COMPARE_SWAP_NBI(_uint64, uint64_t, shmem)
SHMEM_TYPE_ATOMIC_COMPARE_SWAP_NBI(_size, size_t, shmem)
SHMEM_TYPE_ATOMIC_COMPARE_SWAP_NBI(_ptrdiff, ptrdiff_t, shmem)

    
