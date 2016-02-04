/* Generated with snc from monitorEvflag.i */

/* Program "monitorEvflagTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 12 "../monitorEvflag.st"
	int requested;
# line 15 "../monitorEvflag.st"
	int actual;
	struct UserVar_monitorEvflagTest {
		int cycleCount;
		int error;
	} UserVar_monitorEvflagTest;
};

/* C code definitions */
# line 5 "../monitorEvflag.st"
#include "../testSupport.h"
# line 6 "../monitorEvflag.st"
#include <stdio.h>

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
		0,
		0,
		{
# line 27 "../monitorEvflag.st"
			1,
# line 28 "../monitorEvflag.st"
			0,
		}
	};
	*pVar = pVarInit;
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 23 "../monitorEvflag.st"
	seq_test_init(1);
}

/****** Code for state "init" in state set "monitorEvflagTest" ******/

/* Delay function for state "init" in state set "monitorEvflagTest" */
static void D_monitorEvflagTest_0_init(SS_ID ssId, struct UserVar *pVar)
{
# line 30 "../monitorEvflag.st"
	seq_delayInit(ssId, 0, (1.0));
}

/* Event function for state "init" in state set "monitorEvflagTest" */
static seqBool E_monitorEvflagTest_0_init(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 30 "../monitorEvflag.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "monitorEvflagTest" */
static void A_monitorEvflagTest_0_init(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 31 "../monitorEvflag.st"
			seq_efClear(ssId, 1/*actualChanged*/);
		}
		return;
	}
}

/****** Code for state "makeRequest" in state set "monitorEvflagTest" ******/

/* Delay function for state "makeRequest" in state set "monitorEvflagTest" */
static void D_monitorEvflagTest_0_makeRequest(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "makeRequest" in state set "monitorEvflagTest" */
static seqBool E_monitorEvflagTest_0_makeRequest(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 35 "../monitorEvflag.st"
	if (pVar->UserVar_monitorEvflagTest.error)
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
# line 37 "../monitorEvflag.st"
	if (pVar->UserVar_monitorEvflagTest.cycleCount > (20 * 500))
	{
		seq_exit(ssId);
		*pTransNum = 1;
		return TRUE;
	}
# line 40 "../monitorEvflag.st"
	if (pVar->UserVar_monitorEvflagTest.cycleCount <= (20 * 500))
	{
		*pNextState = 2;
		*pTransNum = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "makeRequest" in state set "monitorEvflagTest" */
static void A_monitorEvflagTest_0_makeRequest(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 38 "../monitorEvflag.st"
			testPass("no error in %d cycles", (20 * 500));
		}
		return;
	case 2:
		{
# line 41 "../monitorEvflag.st"
			pVar->requested = pVar->UserVar_monitorEvflagTest.cycleCount;
# line 42 "../monitorEvflag.st"
			seq_pvPut(ssId, 0/*requested*/, 0);
		}
		return;
	}
}

/****** Code for state "waitForActualToEqualRequested" in state set "monitorEvflagTest" ******/

/* Delay function for state "waitForActualToEqualRequested" in state set "monitorEvflagTest" */
static void D_monitorEvflagTest_0_waitForActualToEqualRequested(SS_ID ssId, struct UserVar *pVar)
{
# line 55 "../monitorEvflag.st"
	seq_delayInit(ssId, 0, (1.0));
}

/* Event function for state "waitForActualToEqualRequested" in state set "monitorEvflagTest" */
static seqBool E_monitorEvflagTest_0_waitForActualToEqualRequested(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 46 "../monitorEvflag.st"
	if (seq_efTestAndClear(ssId, 1/*actualChanged*/) && pVar->actual == pVar->requested)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
# line 55 "../monitorEvflag.st"
	if (seq_delay(ssId, 0))
	{
		seq_exit(ssId);
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "waitForActualToEqualRequested" in state set "monitorEvflagTest" */
static void A_monitorEvflagTest_0_waitForActualToEqualRequested(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 47 "../monitorEvflag.st"
			if (pVar->actual != pVar->requested)
			{
# line 48 "../monitorEvflag.st"
				testFail("requested(%d)!=actual(%d)", pVar->requested, pVar->actual);
# line 49 "../monitorEvflag.st"
				pVar->UserVar_monitorEvflagTest.error = TRUE;
			}
			else
# line 50 "../monitorEvflag.st"
				if (pVar->UserVar_monitorEvflagTest.cycleCount % 500 == 0)
				{
# line 51 "../monitorEvflag.st"
					testDiag("passed %d cycles", pVar->UserVar_monitorEvflagTest.cycleCount);
				}
# line 53 "../monitorEvflag.st"
			pVar->UserVar_monitorEvflagTest.cycleCount++;
		}
		return;
	case 1:
		{
# line 57 "../monitorEvflag.st"
			testFail("timeout in cycle %d/%d (requested=%d, actual=%d)", pVar->UserVar_monitorEvflagTest.cycleCount + 1, (20 * 500), pVar->requested, pVar->actual);
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 63 "../monitorEvflag.st"
	seq_test_done();
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"requested", offsetof(struct UserVar, requested), "requested", "int", 1, 2, 0, 0, 0, 0},
	{"actual", offsetof(struct UserVar, actual), "actual", "int", 1, 3, 1, 1, 0, 0}
};

/* Event masks for state set "monitorEvflagTest" */
static const seqMask	EM_monitorEvflagTest_0_init[] = {
	0x00000000,
};
static const seqMask	EM_monitorEvflagTest_0_makeRequest[] = {
	0x00000000,
};
static const seqMask	EM_monitorEvflagTest_0_waitForActualToEqualRequested[] = {
	0x0000000e,
};

/* State table for state set "monitorEvflagTest" */
static seqState G_monitorEvflagTest_states[] = {
	{
	/* state name */        "init",
	/* action function */   A_monitorEvflagTest_0_init,
	/* event function */    E_monitorEvflagTest_0_init,
	/* delay function */    D_monitorEvflagTest_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_monitorEvflagTest_0_init,
	/* state options */     (0)
	},
	{
	/* state name */        "makeRequest",
	/* action function */   A_monitorEvflagTest_0_makeRequest,
	/* event function */    E_monitorEvflagTest_0_makeRequest,
	/* delay function */    D_monitorEvflagTest_0_makeRequest,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_monitorEvflagTest_0_makeRequest,
	/* state options */     (0)
	},
	{
	/* state name */        "waitForActualToEqualRequested",
	/* action function */   A_monitorEvflagTest_0_waitForActualToEqualRequested,
	/* event function */    E_monitorEvflagTest_0_waitForActualToEqualRequested,
	/* delay function */    D_monitorEvflagTest_0_waitForActualToEqualRequested,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_monitorEvflagTest_0_waitForActualToEqualRequested,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "monitorEvflagTest",
	/* states */            G_monitorEvflagTest_states,
	/* number of states */  3,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram monitorEvflagTest = {
	/* magic number */      2001010,
	/* program name */      "monitorEvflagTest",
	/* channels */          G_channels,
	/* num. channels */     2,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  1,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_SAFE | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        G_prog_entry,
	/* exit func */         G_prog_exit,
	/* num. queues */       0
};

#define PROG_NAME monitorEvflagTest
#include "seqMain.c"
