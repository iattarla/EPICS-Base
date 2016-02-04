/* Generated with snc from local.i */

/* Program "localTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 16 "../local.st"
	int i;
	struct UserVar_start {
		int i;
		struct {
			int i;
		} UserVar_first;
	} UserVar_start;
};

/* C code definitions */
# line 10 "../local.st"
#include "../testSupport.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
# line 16 "../local.st"
		1,
		{
# line 24 "../local.st"
			2,
			{
# line 26 "../local.st"
				3
			},
		}
	};
	*pVar = pVarInit;
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 19 "../local.st"
	seq_test_init(5);
}

/****** Code for state "first" in state set "start" ******/

/* Delay function for state "first" in state set "start" */
static void D_start_0_first(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "first" in state set "start" */
static seqBool E_start_0_first(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 27 "../local.st"
	if (pVar->UserVar_start.UserVar_first.i < 5)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	if (TRUE)
	{
		seq_exit(ssId);
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "first" in state set "start" */
static void A_start_0_first(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 28 "../local.st"
			testOk(pVar->UserVar_start.UserVar_first.i >= 3, "state local i == %d >= 3", pVar->UserVar_start.UserVar_first.i);
# line 29 "../local.st"
			pVar->UserVar_start.UserVar_first.i = pVar->UserVar_start.UserVar_first.i + 1;
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/****** Code for state "last" in state set "start" ******/

/* Delay function for state "last" in state set "start" */
static void D_start_0_last(SS_ID ssId, struct UserVar *pVar)
{
# line 35 "../local.st"
	seq_delayInit(ssId, 0, (0.1));
}

/* Event function for state "last" in state set "start" */
static seqBool E_start_0_last(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 35 "../local.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "last" in state set "start" */
static void A_start_0_last(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 36 "../local.st"
			testOk(pVar->UserVar_start.i == 2, "state set local i==%d", pVar->UserVar_start.i);
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 43 "../local.st"
	testOk(pVar->i == 1, "global i==%d", pVar->i);
# line 44 "../local.st"
	seq_test_done();
}

/************************ Tables ************************/

/* No channel definitions */
#define G_channels NULL

/* Event masks for state set "start" */
static const seqMask	EM_start_0_first[] = {
	0x00000000,
};
static const seqMask	EM_start_0_last[] = {
	0x00000000,
};

/* State table for state set "start" */
static seqState G_start_states[] = {
	{
	/* state name */        "first",
	/* action function */   A_start_0_first,
	/* event function */    E_start_0_first,
	/* delay function */    D_start_0_first,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_start_0_first,
	/* state options */     (0)
	},
	{
	/* state name */        "last",
	/* action function */   A_start_0_last,
	/* event function */    E_start_0_last,
	/* delay function */    D_start_0_last,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_start_0_last,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "start",
	/* states */            G_start_states,
	/* number of states */  2,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram localTest = {
	/* magic number */      2001010,
	/* program name */      "localTest",
	/* channels */          G_channels,
	/* num. channels */     0,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        G_prog_entry,
	/* exit func */         G_prog_exit,
	/* num. queues */       0
};

#define PROG_NAME localTest
#include "seqMain.c"
