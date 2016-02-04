/* Generated with snc from pvGetAsync.i */

/* Program "pvGetAsyncTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar_pvGetAsync {
	int x;
	int old_x;
	int n;
} UserVar_pvGetAsync = {
# line 19 "../pvGetAsync.st"
	0,
# line 19 "../pvGetAsync.st"
	0,
	0,
};

/* C code definitions */
# line 9 "../pvGetAsync.st"
#include "../testSupport.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 14 "../pvGetAsync.st"
	seq_test_init(1);
# line 15 "../pvGetAsync.st"
	testDiag("start");
}

/****** Code for state "init" in state set "pvGetAsync" ******/

/* Delay function for state "init" in state set "pvGetAsync" */
static void D_pvGetAsync_0_init(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "init" in state set "pvGetAsync" */
static seqBool E_pvGetAsync_0_init(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "pvGetAsync" */
static void A_pvGetAsync_0_init(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 25 "../pvGetAsync.st"
			UserVar_pvGetAsync.n = 0;
		}
		return;
	}
}

/****** Code for state "get_async" in state set "pvGetAsync" ******/

/* Delay function for state "get_async" in state set "pvGetAsync" */
static void D_pvGetAsync_0_get_async(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "get_async" in state set "pvGetAsync" */
static seqBool E_pvGetAsync_0_get_async(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 29 "../pvGetAsync.st"
	if (UserVar_pvGetAsync.n == 100000)
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
	if (TRUE)
	{
		*pNextState = 2;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "get_async" in state set "pvGetAsync" */
static void A_pvGetAsync_0_get_async(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 30 "../pvGetAsync.st"
			testPass("pvGet completed %d times", 100000);
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/****** Code for state "wait_complete" in state set "pvGetAsync" ******/

/* Entry function for state "wait_complete" in state set "pvGetAsync" */
static void I_pvGetAsync_0_wait_complete(SS_ID ssId, struct UserVar *pVar)
{
# line 37 "../pvGetAsync.st"
	seq_pvGet(ssId, 0/*x*/, ASYNC);
}

/* Exit function for state "wait_complete" in state set "pvGetAsync" */
static void O_pvGetAsync_0_wait_complete(SS_ID ssId, struct UserVar *pVar)
{
# line 45 "../pvGetAsync.st"
	UserVar_pvGetAsync.n++;
}

/* Delay function for state "wait_complete" in state set "pvGetAsync" */
static void D_pvGetAsync_0_wait_complete(SS_ID ssId, struct UserVar *pVar)
{
# line 39 "../pvGetAsync.st"
	seq_delayInit(ssId, 0, (5.0));
}

/* Event function for state "wait_complete" in state set "pvGetAsync" */
static seqBool E_pvGetAsync_0_wait_complete(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 39 "../pvGetAsync.st"
	if (seq_delay(ssId, 0))
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
# line 42 "../pvGetAsync.st"
	if (seq_pvGetComplete(ssId, 0/*x*/))
	{
		*pNextState = 1;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait_complete" in state set "pvGetAsync" */
static void A_pvGetAsync_0_wait_complete(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 40 "../pvGetAsync.st"
			testFail("pvGet completion timeout");
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 51 "../pvGetAsync.st"
	testDiag("exit");
# line 52 "../pvGetAsync.st"
	seq_test_done();
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"pvGetAsync1", (size_t)&UserVar_pvGetAsync.x, "x", "int", 1, 1, 0, 0, 0, 0}
};

/* Event masks for state set "pvGetAsync" */
static const seqMask	EM_pvGetAsync_0_init[] = {
	0x00000000,
};
static const seqMask	EM_pvGetAsync_0_get_async[] = {
	0x00000000,
};
static const seqMask	EM_pvGetAsync_0_wait_complete[] = {
	0x00000002,
};

/* State table for state set "pvGetAsync" */
static seqState G_pvGetAsync_states[] = {
	{
	/* state name */        "init",
	/* action function */   A_pvGetAsync_0_init,
	/* event function */    E_pvGetAsync_0_init,
	/* delay function */    D_pvGetAsync_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_pvGetAsync_0_init,
	/* state options */     (0)
	},
	{
	/* state name */        "get_async",
	/* action function */   A_pvGetAsync_0_get_async,
	/* event function */    E_pvGetAsync_0_get_async,
	/* delay function */    D_pvGetAsync_0_get_async,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_pvGetAsync_0_get_async,
	/* state options */     (0)
	},
	{
	/* state name */        "wait_complete",
	/* action function */   A_pvGetAsync_0_wait_complete,
	/* event function */    E_pvGetAsync_0_wait_complete,
	/* delay function */    D_pvGetAsync_0_wait_complete,
	/* entry function */    I_pvGetAsync_0_wait_complete,
	/* exit function */     O_pvGetAsync_0_wait_complete,
	/* event mask array */  EM_pvGetAsync_0_wait_complete,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "pvGetAsync",
	/* states */            G_pvGetAsync_states,
	/* number of states */  3,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram pvGetAsyncTest = {
	/* magic number */      2001010,
	/* program name */      "pvGetAsyncTest",
	/* channels */          G_channels,
	/* num. channels */     1,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        G_prog_entry,
	/* exit func */         G_prog_exit,
	/* num. queues */       0
};

#define PROG_NAME pvGetAsyncTest
#include "seqMain.c"
