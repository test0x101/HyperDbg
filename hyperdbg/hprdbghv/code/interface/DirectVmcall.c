/**
 * @file DirectVmcall.c
 * @author Sina Karvandi (sina@hyperdbg.org)
 * @brief Direct VMCALL routines
 * @details
 *
 * @version 0.7
 * @date 2023-10-19
 *
 * @copyright This project is released under the GNU Public License v3.
 *
 */
#include "pch.h"

/**
 * @brief routines for test direct VMCALL
 * @details Should be called from VMX root-mode
 *
 * @param CoreId
 * @param DirectVmcallOptions
 *
 * @return NTSTATUS
 */
NTSTATUS
DirectVmcallTest(UINT32                     CoreId,
                 DIRECT_VMCALL_PARAMETERS * DirectVmcallOptions)
{
    //
    // Call the VMCALL handler (directly)
    //
    return VmxVmcallDirectVmcallHandler(&g_GuestState[CoreId], VMCALL_TEST, DirectVmcallOptions);
}

/**
 * @brief routines for changing MSR Bitmap (Read)
 * @details Should be called from VMX root-mode
 *
 * @param CoreId
 * @param DirectVmcallOptions
 *
 * @return NTSTATUS
 */
NTSTATUS
DirectVmcallChangeMsrBitmapRead(UINT32                     CoreId,
                                DIRECT_VMCALL_PARAMETERS * DirectVmcallOptions)
{
    //
    // Call the VMCALL handler (directly)
    //
    return VmxVmcallDirectVmcallHandler(&g_GuestState[CoreId], VMCALL_CHANGE_MSR_BITMAP_READ, DirectVmcallOptions);
}

/**
 * @brief routines for changing MSR Bitmap (Write)
 * @details Should be called from VMX root-mode
 *
 * @param CoreId
 * @param DirectVmcallOptions
 *
 * @return NTSTATUS
 */
NTSTATUS
DirectVmcallChangeMsrBitmapWrite(UINT32                     CoreId,
                                 DIRECT_VMCALL_PARAMETERS * DirectVmcallOptions)
{
    //
    // Call the VMCALL handler (directly)
    //
    return VmxVmcallDirectVmcallHandler(&g_GuestState[CoreId], VMCALL_CHANGE_MSR_BITMAP_WRITE, DirectVmcallOptions);
}

/**
 * @brief routines for changing IO Bitmap
 * @details Should be called from VMX root-mode
 *
 * @param CoreId
 * @param DirectVmcallOptions
 *
 * @return NTSTATUS
 */
NTSTATUS
DirectVmcallChangeIoBitmap(UINT32                     CoreId,
                           DIRECT_VMCALL_PARAMETERS * DirectVmcallOptions)
{
    //
    // Call the VMCALL handler (directly)
    //
    return VmxVmcallDirectVmcallHandler(&g_GuestState[CoreId], VMCALL_CHANGE_IO_BITMAP, DirectVmcallOptions);
}

/**
 * @brief routines for enabling rdpmc exiting
 * @details Should be called from VMX root-mode
 *
 * @param CoreId
 * @param DirectVmcallOptions
 *
 * @return NTSTATUS
 */
NTSTATUS
DirectVmcallEnableRdpmcExiting(UINT32                     CoreId,
                               DIRECT_VMCALL_PARAMETERS * DirectVmcallOptions)
{
    //
    // Call the VMCALL handler (directly)
    //
    return VmxVmcallDirectVmcallHandler(&g_GuestState[CoreId], VMCALL_SET_RDPMC_EXITING, DirectVmcallOptions);
}

/**
 * @brief routines for enabling rdtsc/rdtscp exiting
 * @details Should be called from VMX root-mode
 *
 * @param CoreId
 * @param DirectVmcallOptions
 *
 * @return NTSTATUS
 */
NTSTATUS
DirectVmcallEnableRdtscpExiting(UINT32                     CoreId,
                                DIRECT_VMCALL_PARAMETERS * DirectVmcallOptions)
{
    //
    // Call the VMCALL handler (directly)
    //
    return VmxVmcallDirectVmcallHandler(&g_GuestState[CoreId], VMCALL_SET_RDTSC_EXITING, DirectVmcallOptions);
}

/**
 * @brief routines for enabling mov to debug registers exiting
 * @details Should be called from VMX root-mode
 *
 * @param CoreId
 * @param DirectVmcallOptions
 *
 * @return NTSTATUS
 */
NTSTATUS
DirectVmcallEnableMov2DebugRegsExiting(UINT32                     CoreId,
                                       DIRECT_VMCALL_PARAMETERS * DirectVmcallOptions)
{
    //
    // Call the VMCALL handler (directly)
    //
    return VmxVmcallDirectVmcallHandler(&g_GuestState[CoreId], VMCALL_ENABLE_MOV_TO_DEBUG_REGS_EXITING, DirectVmcallOptions);
}

/**
 * @brief routines for setting exception bitmap
 * @details Should be called from VMX root-mode
 *
 * @param CoreId
 * @param DirectVmcallOptions
 *
 * @return NTSTATUS
 */
NTSTATUS
DirectVmcallSetExceptionBitmap(UINT32                     CoreId,
                               DIRECT_VMCALL_PARAMETERS * DirectVmcallOptions)
{
    //
    // Call the VMCALL handler (directly)
    //
    return VmxVmcallDirectVmcallHandler(&g_GuestState[CoreId], VMCALL_SET_EXCEPTION_BITMAP, DirectVmcallOptions);
}

/**
 * @brief routines for enabling external interrupt exiting
 * @details Should be called from VMX root-mode
 *
 * @param CoreId
 * @param DirectVmcallOptions
 *
 * @return NTSTATUS
 */
NTSTATUS
DirectVmcallEnableExternalInterruptExiting(UINT32                     CoreId,
                                           DIRECT_VMCALL_PARAMETERS * DirectVmcallOptions)
{
    //
    // Call the VMCALL handler (directly)
    //
    return VmxVmcallDirectVmcallHandler(&g_GuestState[CoreId], VMCALL_ENABLE_EXTERNAL_INTERRUPT_EXITING, DirectVmcallOptions);
}

/**
 * @brief routines for enabling mov to CR exiting
 * @details Should be called from VMX root-mode
 *
 * @param CoreId
 * @param DirectVmcallOptions
 *
 * @return NTSTATUS
 */
NTSTATUS
DirectVmcallEnableMovToCrExiting(UINT32                     CoreId,
                                 DIRECT_VMCALL_PARAMETERS * DirectVmcallOptions)
{
    //
    // Call the VMCALL handler (directly)
    //
    return VmxVmcallDirectVmcallHandler(&g_GuestState[CoreId], VMCALL_ENABLE_MOV_TO_CONTROL_REGS_EXITING, DirectVmcallOptions);
}

/**
 * @brief routines for enabling syscall hook using EFER SCE bit
 * @details Should be called from VMX root-mode
 *
 * @param CoreId
 * @param DirectVmcallOptions
 *
 * @return NTSTATUS
 */
NTSTATUS
DirectVmcallEnableEferSyscall(UINT32                     CoreId,
                              DIRECT_VMCALL_PARAMETERS * DirectVmcallOptions)
{
    //
    // Call the VMCALL handler (directly)
    //
    return VmxVmcallDirectVmcallHandler(&g_GuestState[CoreId], VMCALL_ENABLE_SYSCALL_HOOK_EFER, DirectVmcallOptions);
}
