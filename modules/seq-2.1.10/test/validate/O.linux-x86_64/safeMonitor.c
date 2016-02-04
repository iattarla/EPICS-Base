/* Generated with snc from safeMonitor.i */

/* Program "safeMonitorTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 13 "../safeMonitor.st"
	double cnt;
	struct UserVar_read {
		double on_entry;
		int n;
	} UserVar_read;
};

/* C code definitions */
# line 9 "../safeMonitor.st"
#include "../testSupport.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
# line 13 "../safeMonitor.st"
		1.0,
		{
			0,
# line 27 "../safeMonitor.st"
			1,
		},
	};
	*pVar = pVarInit;
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 22 "../safeMonitor.st"
	seq_test_init(10);
}

/****** Code for state "react" in state set "read" ******/

/* Delay function for state "react" in state set "read" */
static void D_read_0_react(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "react" in state set "read" */
static seqBool E_read_0_react(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 29 "../safeMonitor.st"
	if (pVar->UserVar_read.n > 10)
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
# line 31 "../safeMonitor.st"
	if (seq_efTestAndClear(ssId, 1/*ef_cnt*/))
	{
		*pNextState = 0;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "react" in state set "read" */
static void A_read_0_react(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 32 "../safeMonitor.st"
			pVar->UserVar_read.on_entry = pVar->cnt;
# line 33 "../safeMonitor.st"
			testDiag("read: enter action block, cnt=%.1f", pVar->cnt);
# line 34 "../safeMonitor.st"
			epicsThreadSleep(0.1);
# line 36 "../safeMonitor.st"
			testOk(pVar->UserVar_read.on_entry == pVar->cnt, "read: exit action block, on_entry=%.1f==%.1f=cnt", pVar->UserVar_read.on_entry, pVar->cnt);
# line 37 "../safeMonitor.st"
			pVar->UserVar_read.n++;
		}
		return;
	}
}

/****** Code for state "send" in state set "write" ******/

/* Delay function for state "send" in state set "write" */
static void D_write_1_send(SS_ID ssId, struct UserVar *pVar)
{
# line 44 "../safeMonitor.st"
	seq_delayInit(ssId, 0, (0.04));
}

/* Event function for state "send" in state set "write" */
static seqBool E_write_1_send(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 44 "../safeMonitor.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "send" in state set "write" */
static void A_write_1_send(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 45 "../safeMonitor.st"
			pVar->cnt += 1.0;
# line 46 "../safeMonitor.st"
			seq_pvPut(ssId, 0/*cnt*/, 0);
# line 47 "../safeMonitor.st"
			testDiag("write: pvPut(cnt=%.1f)", pVar->cnt);
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 53 "../safeMonitor.st"
	seq_test_done();
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"", offsetof(struct UserVar, cnt), "cnt", "double", 1, 2, 1, 1, 0, 0}
};

/* Event masks for state set "read" */
static const seqMask	EM_read_0_react[] = {
	0x00000002,
};

/* State table for state set "read" */
static seqState G_read_states[] = {
	{
	/* state name */        "react",
	/* action function */   A_read_0_react,
	/* event function */    E_read_0_react,
	/* delay function */    D_read_0_react,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_read_0_react,
	/* state options */     (0)
	},
};

/* Event masks for state set "write" */
static const seqMask	EM_write_1_send[] = {
	0x00000000,
};

/* State table for state set "write" */
static seqState G_write_states[] = {
	{
	/* state name */        "send",
	/* action function */   A_write_1_send,
	/* event function */    E_write_1_send,
	/* delay function */    D_write_1_send,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_write_1_send,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "read",
	/* states */            G_read_states,
	/* number of states */  1,
	/* number of delays */  0
	},

	{
	/* state set name */    "write",
	/* states */            G_write_states,
	/* number of states */  1,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram safeMonitorTest = {
	/* magic number */      2001010,
	/* program name */      "safeMonitorTest",
	/* channels */          G_channels,
	/* num. channels */     1,
	/* state sets */        G_state_sets,
	/* num. state sets */   2,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  1,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_SAFE | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        G_prog_entry,
	/* exit func */         G_prog_exit,
	/* num. queues */       0
};

#define PROG_NAME safeMonitorTest
#include "seqMain.c"
