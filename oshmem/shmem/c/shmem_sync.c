/*
 * Copyright (c) 2013-2018 Mellanox Technologies, Inc.
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

#include "oshmem/runtime/runtime.h"

#include "oshmem/mca/scoll/scoll.h"
#include "oshmem/mca/scoll/base/base.h"

#include "oshmem/proc/proc.h"


#if OSHMEM_PROFILING
#include "oshmem/include/pshmem.h"
#pragma weak shmem_sync_all = pshmem_sync_all
#include "oshmem/shmem/c/profile/defines.h"
#endif


void shmem_sync_all(void)
{
    int rc = OSHMEM_SUCCESS;

#if OSHMEM_SPEC_COMPAT == 1
    /* all outstanding puts must be completed */
    shmem_quiet();
#endif

    if (mca_scoll_sync_array) {
        rc = oshmem_group_all->g_scoll.scoll_barrier(oshmem_group_all,
                                                     mca_scoll_sync_array,
                                                     SCOLL_DEFAULT_ALG);
    }
    RUNTIME_CHECK_RC(rc);
}
