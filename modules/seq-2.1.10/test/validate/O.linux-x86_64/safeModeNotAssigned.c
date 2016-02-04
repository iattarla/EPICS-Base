/* Generated with snc from safeModeNotAssigned.i */

/* Program "safeModeNotAssignedTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 13 "../safeModeNotAssigned.st"
	int v;
	struct UserVar_ss1 {
		int i;
	} UserVar_ss1;
	struct UserVar_ss2 {
		struct {
			int i;
		} UserVar_idle;
	} UserVar_ss2;
};

/* C code definitions */
# line 9 "../safeModeNotAssigned.st"
#include "../testSupport.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
# line 13 "../safeModeNotAssigned.st"
		0,
		{
# line 22 "../safeModeNotAssigned.st"
			0,
		},
		{
			{
				0
			}
		}
	};
	*pVar = pVarInit;
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 18 "../safeModeNotAssigned.st"
	seq_test_init(10 * 2);
}

/****** Code for state "idle" in state set "ss1" ******/

/* Delay function for state "idle" in state set "ss1" */
static void D_ss1_0_idle(SS_ID ssId, struct UserVar *pVar)
{
# line 24 "../safeModeNotAssigned.st"
	seq_delayInit(ssId, 0, (0.1));
}

/* Event function for state "idle" in state set "ss1" */
static seqBool E_ss1_0_idle(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 24 "../safeModeNotAssigned.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
# line 29 "../safeModeNotAssigned.st"
	if (pVar->v == 10)
	{
		*pNextState = 1;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "idle" in state set "ss1" */
static void A_ss1_0_idle(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 25 "../safeModeNotAssigned.st"
			testOk(pVar->v == pVar->UserVar_ss1.i, "ss1: v=%d==%d=i", pVar->v, pVar->UserVar_ss1.i);
# line 26 "../safeModeNotAssigned.st"
			pVar->v++;
# line 27 "../safeModeNotAssigned.st"
			pVar->UserVar_ss1.i++;
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/****** Code for state "done" in state set "ss1" ******/

/* Delay function for state "done" in state set "ss1" */
static void D_ss1_0_done(SS_ID ssId, struct UserVar *pVar)
{
# line 33 "../safeModeNotAssigned.st"
	seq_delayInit(ssId, 0, (0.2));
}

/* Event function for state "done" in state set "ss1" */
static seqBool E_ss1_0_done(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 33 "../safeModeNotAssigned.st"
	if (seq_delay(ssId, 0))
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "done" in state set "ss1" */
static void A_ss1_0_done(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "idle" in state set "ss2" ******/

/* Delay function for state "idle" in state set "ss2" */
static void D_ss2_1_idle(SS_ID ssId, struct UserVar *pVar)
{
# line 41 "../safeModeNotAssigned.st"
	seq_delayInit(ssId, 0, (0.1));
}

/* Event function for state "idle" in state set "ss2" */
static seqBool E_ss2_1_idle(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 41 "../safeModeNotAssigned.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "idle" in state set "ss2" */
static void A_ss2_1_idle(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 42 "../safeModeNotAssigned.st"
			if (pVar->UserVar_ss2.UserVar_idle.i < 10)
			{
# line 43 "../safeModeNotAssigned.st"
				testOk(pVar->v == 0, "ss2: v=%d==0", pVar->v);
			}
# line 45 "../safeModeNotAssigned.st"
			pVar->UserVar_ss2.UserVar_idle.i++;
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 51 "../safeModeNotAssigned.st"
	seq_test_done();
}

/************************ Tables ************************/

/* No channel definitions */
#define G_channels NULL

/* Event masks for state set "ss1" */
static const seqMask	EM_ss1_0_idle[] = {
	0x00000000,
};
static const seqMask	EM_ss1_0_done[] = {
	0x00000000,
};

/* State table for state set "ss1" */
static seqState G_ss1_states[] = {
	{
	/* state name */        "idle",
	/* action function */   A_ss1_0_idle,
	/* event function */    E_ss1_0_idle,
	/* delay function */    D_ss1_0_idle,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_ss1_0_idle,
	/* state options */     (0)
	},
	{
	/* state name */        "done",
	/* action function */   A_ss1_0_done,
	/* event function */    E_ss1_0_done,
	/* delay function */    D_ss1_0_done,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_ss1_0_done,
	/* state options */     (0)
	},
};

/* Event masks for state set "ss2" */
static const seqMask	EM_ss2_1_idle[] = {
	0x00000000,
};

/* State table for state set "ss2" */
static seqState G_ss2_states[] = {
	{
	/* state name */        "idle",
	/* action function */   A_ss2_1_idle,
	/* event function */    E_ss2_1_idle,
	/* delay function */    D_ss2_1_idle,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_ss2_1_idle,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "ss1",
	/* states */            G_ss1_states,
	/* number of states */  2,
	/* number of delays */  1
	},

	{
	/* state set name */    "ss2",
	/* states */            G_ss2_states,
	/* number of states */  1,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram safeModeNotAssignedTest = {
	/* magic number */      2001010,
	/* program name */      "safeModeNotAssignedTest",
	/* channels */          G_channels,
	/* num. channels */     0,
	/* state sets */        G_state_sets,
	/* num. state sets */   2,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_SAFE | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        G_prog_entry,
	/* exit func */         G_prog_exit,
	/* num. queues */       0
};

#define PROG_NAME safeModeNotAssignedTest
#include "seqMain.c"
