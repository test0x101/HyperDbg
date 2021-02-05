/**
 * @file Mtf.c
 * @author Sina Karvandi (sina@rayanfam.com)
 * @brief Routines relating to Monitor Trap Flag (MTF)
 * @details 
 * @version 0.1
 * @date 2021-01-27
 * 
 * @copyright This project is released under the GNU Public License v3.
 * 
 */
#include "pch.h"

/**
 * @brief Handle Monitor Trap Flag vm-exits
 *
 * @param CurrentProcessorIndex
 * @param GuestRegs
 * @return VOID
 */
VOID
MtfHandleVmexit(ULONG CurrentProcessorIndex, PGUEST_REGS GuestRegs)
{
    //
    // Explicitly say that we want to unset MTFs
    //
    g_GuestState[CurrentProcessorIndex].IgnoreMtfUnset = FALSE;

    //
    // Monitor Trap Flag
    //
    if (g_GuestState[CurrentProcessorIndex].MtfEptHookRestorePoint)
    {
        //
        // Restore the previous state
        //
        EptHandleMonitorTrapFlag(g_GuestState[CurrentProcessorIndex].MtfEptHookRestorePoint);

        //
        // Set it to NULL
        //
        g_GuestState[CurrentProcessorIndex].MtfEptHookRestorePoint = NULL;
    }
    else if (g_GuestState[CurrentProcessorIndex].DebuggingState.WaitForStepOnMtf)
    {
        //
        //  Unset the MTF flag
        //
        g_GuestState[CurrentProcessorIndex].DebuggingState.WaitForStepOnMtf = FALSE;

        //
        // Handle the breakpoint
        //
        KdHandleBreakpointAndDebugBreakpoints(CurrentProcessorIndex,
                                              GuestRegs,
                                              DEBUGGEE_PAUSING_REASON_DEBUGGEE_STEPPED,
                                              g_GuestState[CurrentProcessorIndex].LastVmexitRip);
    }
    else if (g_GuestState[CurrentProcessorIndex].MtfTest)
    {
        SteppingsHandleThreadChanges(GuestRegs, CurrentProcessorIndex);
        g_GuestState[CurrentProcessorIndex].MtfTest = FALSE;
    }
    else
    {
        LogError("Why MTF occured ?!");
    }

    //
    // Redo the instruction
    //
    g_GuestState[CurrentProcessorIndex].IncrementRip = FALSE;

    if (!g_GuestState[CurrentProcessorIndex].IgnoreMtfUnset)
    {
        //
        // We don't need MTF anymore if it set to disable MTF
        //
        HvSetMonitorTrapFlag(FALSE);
    }
}