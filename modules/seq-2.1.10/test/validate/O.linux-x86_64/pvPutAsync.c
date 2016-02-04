/* Generated with snc from pvPutAsync.i */

/* Program "pvPutAsyncTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
# line 13 "../pvPutAsync.st"
static	int x = 0;
struct UserVar_test1 {
	struct {
		int i;
	} UserVar_put_async;
} UserVar_test1 = {
	{
		0
	},
};

/* C code definitions */
# line 9 "../pvPutAsync.st"
#include "../testSupport.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 17 "../pvPutAsync.st"
	seq_test_init(10);
}

/****** Code for state "put_async" in state set "test1" ******/

/* Entry function for state "put_async" in state set "test1" */
static void I_test1_0_put_async(SS_ID ssId, struct UserVar *pVar)
{
# line 24 "../pvPutAsync.st"
	UserVar_test1.UserVar_put_async.i = 0;
}

/* Delay function for state "put_async" in state set "test1" */
static void D_test1_0_put_async(SS_ID ssId, struct UserVar *pVar)
{
# line 28 "../pvPutAsync.st"
	seq_delayInit(ssId, 0, (0.4));
}

/* Event function for state "put_async" in state set "test1" */
static seqBool E_test1_0_put_async(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 26 "../pvPutAsync.st"
	if (UserVar_test1.UserVar_put_async.i == 5)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
# line 28 "../pvPutAsync.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "put_async" in state set "test1" */
static void A_test1_0_put_async(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 29 "../pvPutAsync.st"
			int status;

# line 30 "../pvPutAsync.st"
			x = 1;
# line 31 "../pvPutAsync.st"
			status = seq_pvPut(ssId, 0/*x*/, ASYNC);
# line 34 "../pvPutAsync.st"
			testOk((UserVar_test1.UserVar_put_async.i == 0) == (status == pvStatOK), "pvPut/ASYNC %d: result=%d (%s)", UserVar_test1.UserVar_put_async.i, status, status ? seq_pvMessage(ssId, 0/*x*/) : "");
# line 35 "../pvPutAsync.st"
			++UserVar_test1.UserVar_put_async.i;
		}
		return;
	}
}

/****** Code for state "wait_complete" in state set "test1" ******/

/* Delay function for state "wait_complete" in state set "test1" */
static void D_test1_0_wait_complete(SS_ID ssId, struct UserVar *pVar)
{
# line 39 "../pvPutAsync.st"
	seq_delayInit(ssId, 0, (5.0));
}

/* Event function for state "wait_complete" in state set "test1" */
static seqBool E_test1_0_wait_complete(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 39 "../pvPutAsync.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 2;
		*pTransNum = 0;
		return TRUE;
	}
# line 42 "../pvPutAsync.st"
	if (seq_pvPutComplete(ssId, 0/*x*/, 1, 0, 0))
	{
		*pNextState = 2;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait_complete" in state set "test1" */
static void A_test1_0_wait_complete(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 40 "../pvPutAsync.st"
			testFail("pvPut completion timeout");
		}
		return;
	case 1:
		{
# line 43 "../pvPutAsync.st"
			testPass("pvPut/ASYNC complete");
		}
		return;
	}
}

/****** Code for state "put_sync" in state set "test1" ******/

/* Entry function for state "put_sync" in state set "test1" */
static void I_test1_0_put_sync(SS_ID ssId, struct UserVar *pVar)
{
# line 48 "../pvPutAsync.st"
	int i = 0;
# line 49 "../pvPutAsync.st"
	for (i = 0; i < 4; i++)
	{
# line 50 "../pvPutAsync.st"
		int status = seq_pvPut(ssId, 0/*x*/, SYNC);
# line 53 "../pvPutAsync.st"
		testOk(status == pvStatOK, "pvPut/SYNC %d, status=%d (%s)", i, status, status ? seq_pvMessage(ssId, 0/*x*/) : "");
	}
}

/* Delay function for state "put_sync" in state set "test1" */
static void D_test1_0_put_sync(SS_ID ssId, struct UserVar *pVar)
{
# line 56 "../pvPutAsync.st"
	seq_delayInit(ssId, 0, (1));
}

/* Event function for state "put_sync" in state set "test1" */
static seqBool E_test1_0_put_sync(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 56 "../pvPutAsync.st"
	if (seq_delay(ssId, 0))
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "put_sync" in state set "test1" */
static void A_test1_0_put_sync(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 92 "../pvPutAsync.st"
	seq_test_done();
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"pvPutAsync1", (size_t)&x, "x", "int", 1, 1, 0, 0, 0, 0}
};

/* Event masks for state set "test1" */
static const seqMask	EM_test1_0_put_async[] = {
	0x00000000,
};
static const seqMask	EM_test1_0_wait_complete[] = {
	0x00000002,
};
static const seqMask	EM_test1_0_put_sync[] = {
	0x00000000,
};

/* State table for state set "test1" */
static seqState G_test1_states[] = {
	{
	/* state name */        "put_async",
	/* action function */   A_test1_0_put_async,
	/* event function */    E_test1_0_put_async,
	/* delay function */    D_test1_0_put_async,
	/* entry function */    I_test1_0_put_async,
	/* exit function */     0,
	/* event mask array */  EM_test1_0_put_async,
	/* state options */     (0)
	},
	{
	/* state name */        "wait_complete",
	/* action function */   A_test1_0_wait_complete,
	/* event function */    E_test1_0_wait_complete,
	/* delay function */    D_test1_0_wait_complete,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_test1_0_wait_complete,
	/* state options */     (0)
	},
	{
	/* state name */        "put_sync",
	/* action function */   A_test1_0_put_sync,
	/* event function */    E_test1_0_put_sync,
	/* delay function */    D_test1_0_put_sync,
	/* entry function */    I_test1_0_put_sync,
	/* exit function */     0,
	/* event mask array */  EM_test1_0_put_sync,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "test1",
	/* states */            G_test1_states,
	/* number of states */  3,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram pvPutAsyncTest = {
	/* magic number */      2001010,
	/* program name */      "pvPutAsyncTest",
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

#define PROG_NAME pvPutAsyncTest
#include "seqMain.c"
