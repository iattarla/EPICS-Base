/* Generated with snc from assign.i */

/* Program "assignTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 13 "../assign.st"
	int x;
	struct UserVar_w {
		int n;
	} UserVar_w;
};

/* C code definitions */
# line 11 "../assign.st"
#include "../testSupport.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
# line 13 "../assign.st"
		0,
		{
# line 25 "../assign.st"
			1,
		},
	};
	*pVar = pVarInit;
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 21 "../assign.st"
	seq_test_init(3);
}

/****** Code for state "w" in state set "w" ******/

/* Delay function for state "w" in state set "w" */
static void D_w_0_w(SS_ID ssId, struct UserVar *pVar)
{
# line 29 "../assign.st"
	seq_delayInit(ssId, 0, (0.01));
}

/* Event function for state "w" in state set "w" */
static seqBool E_w_0_w(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 27 "../assign.st"
	if (pVar->UserVar_w.n > 3)
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
# line 29 "../assign.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "w" in state set "w" */
static void A_w_0_w(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 30 "../assign.st"
			int status;

# line 31 "../assign.st"
			pVar->x = !pVar->x;
# line 32 "../assign.st"
			status = seq_pvPut(ssId, 0/*x*/, 0);
# line 33 "../assign.st"
			testOk1(status == pvStatERROR);
# line 34 "../assign.st"
			pVar->UserVar_w.n++;
		}
		return;
	}
}

/****** Code for state "yes" in state set "r" ******/

/* Delay function for state "yes" in state set "r" */
static void D_r_1_yes(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "yes" in state set "r" */
static seqBool E_r_1_yes(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 41 "../assign.st"
	if (!pVar->x)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "yes" in state set "r" */
static void A_r_1_yes(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "no" in state set "r" ******/

/* Delay function for state "no" in state set "r" */
static void D_r_1_no(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "no" in state set "r" */
static seqBool E_r_1_no(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 45 "../assign.st"
	if (pVar->x)
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "no" in state set "r" */
static void A_r_1_no(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
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
# line 51 "../assign.st"
	seq_test_done();
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"", offsetof(struct UserVar, x), "x", "int", 1, 1, 0, 0, 0, 0}
};

/* Event masks for state set "w" */
static const seqMask	EM_w_0_w[] = {
	0x00000000,
};

/* State table for state set "w" */
static seqState G_w_states[] = {
	{
	/* state name */        "w",
	/* action function */   A_w_0_w,
	/* event function */    E_w_0_w,
	/* delay function */    D_w_0_w,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_w_0_w,
	/* state options */     (0)
	},
};

/* Event masks for state set "r" */
static const seqMask	EM_r_1_yes[] = {
	0x00000002,
};
static const seqMask	EM_r_1_no[] = {
	0x00000002,
};

/* State table for state set "r" */
static seqState G_r_states[] = {
	{
	/* state name */        "yes",
	/* action function */   A_r_1_yes,
	/* event function */    E_r_1_yes,
	/* delay function */    D_r_1_yes,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_r_1_yes,
	/* state options */     (0)
	},
	{
	/* state name */        "no",
	/* action function */   A_r_1_no,
	/* event function */    E_r_1_no,
	/* delay function */    D_r_1_no,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_r_1_no,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "w",
	/* states */            G_w_states,
	/* number of states */  1,
	/* number of delays */  1
	},

	{
	/* state set name */    "r",
	/* states */            G_r_states,
	/* number of states */  2,
	/* number of delays */  0
	},
};

/* Program table (global) */
seqProgram assignTest = {
	/* magic number */      2001010,
	/* program name */      "assignTest",
	/* channels */          G_channels,
	/* num. channels */     1,
	/* state sets */        G_state_sets,
	/* num. state sets */   2,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        G_prog_entry,
	/* exit func */         G_prog_exit,
	/* num. queues */       0
};

#define PROG_NAME assignTest
#include "seqMain.c"
