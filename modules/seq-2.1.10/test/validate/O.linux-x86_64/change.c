/* Generated with snc from change.i */

/* Program "changeTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
	struct UserVar_main {
		int x;
		int n;
	} UserVar_main;
};

/* C code definitions */
# line 12 "../change.st"
#include <time.h>
# line 13 "../change.st"
#include <stdlib.h>
# line 14 "../change.st"
#include "../testSupport.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
		{
# line 25 "../change.st"
			0,
# line 26 "../change.st"
			1,
		}
	};
	*pVar = pVarInit;
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 19 "../change.st"
	seq_test_init(50);
}

/****** Code for state "zero" in state set "main" ******/

/* Delay function for state "zero" in state set "main" */
static void D_main_0_zero(SS_ID ssId, struct UserVar *pVar)
{
# line 36 "../change.st"
	seq_delayInit(ssId, 0, (0.01));
}

/* Event function for state "zero" in state set "main" */
static seqBool E_main_0_zero(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 34 "../change.st"
	if (pVar->UserVar_main.n > 50)
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
# line 36 "../change.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "zero" in state set "main" */
static void A_main_0_zero(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 37 "../change.st"
			testOk(pVar->UserVar_main.x == 0, "state=zero, x=%d", pVar->UserVar_main.x);
# line 38 "../change.st"
			pVar->UserVar_main.x = rand() % 10 - 5;
# line 39 "../change.st"
			testDiag("new random x=%d", pVar->UserVar_main.x);
# line 40 "../change.st"
			pVar->UserVar_main.n++;
# line 41 "../change.st"
			if (pVar->UserVar_main.x > 0)
			{
				{*pNextState = 1; return;}
			}
			else
# line 43 "../change.st"
				if (pVar->UserVar_main.x < 0)
				{
					{*pNextState = 2; return;}
				}
		}
		return;
	}
}

/****** Code for state "pos" in state set "main" ******/

/* Delay function for state "pos" in state set "main" */
static void D_main_0_pos(SS_ID ssId, struct UserVar *pVar)
{
# line 57 "../change.st"
	seq_delayInit(ssId, 0, (0.01));
}

/* Event function for state "pos" in state set "main" */
static seqBool E_main_0_pos(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 55 "../change.st"
	if (pVar->UserVar_main.n > 50)
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
# line 57 "../change.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 1;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "pos" in state set "main" */
static void A_main_0_pos(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 58 "../change.st"
			testOk(pVar->UserVar_main.x > 0, "state=pos, x=%d", pVar->UserVar_main.x);
# line 59 "../change.st"
			pVar->UserVar_main.n++;
# line 60 "../change.st"
			pVar->UserVar_main.x--;
# line 61 "../change.st"
			if (pVar->UserVar_main.x == 0)
				{*pNextState = 0; return;}
		}
		return;
	}
}

/****** Code for state "neg" in state set "main" ******/

/* Delay function for state "neg" in state set "main" */
static void D_main_0_neg(SS_ID ssId, struct UserVar *pVar)
{
# line 67 "../change.st"
	seq_delayInit(ssId, 0, (0.01));
}

/* Event function for state "neg" in state set "main" */
static seqBool E_main_0_neg(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 65 "../change.st"
	if (pVar->UserVar_main.n > 50)
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
# line 67 "../change.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 2;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "neg" in state set "main" */
static void A_main_0_neg(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 68 "../change.st"
			testOk(pVar->UserVar_main.x < 0, "state=neg, x=%d", pVar->UserVar_main.x);
# line 69 "../change.st"
			pVar->UserVar_main.n++;
# line 70 "../change.st"
			pVar->UserVar_main.x++;
# line 71 "../change.st"
			if (pVar->UserVar_main.x == 0)
				{*pNextState = 0; return;}
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 77 "../change.st"
	seq_test_done();
}

/************************ Tables ************************/

/* No channel definitions */
#define G_channels NULL

/* Event masks for state set "main" */
static const seqMask	EM_main_0_zero[] = {
	0x00000000,
};
static const seqMask	EM_main_0_pos[] = {
	0x00000000,
};
static const seqMask	EM_main_0_neg[] = {
	0x00000000,
};

/* State table for state set "main" */
static seqState G_main_states[] = {
	{
	/* state name */        "zero",
	/* action function */   A_main_0_zero,
	/* event function */    E_main_0_zero,
	/* delay function */    D_main_0_zero,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_main_0_zero,
	/* state options */     (0)
	},
	{
	/* state name */        "pos",
	/* action function */   A_main_0_pos,
	/* event function */    E_main_0_pos,
	/* delay function */    D_main_0_pos,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_main_0_pos,
	/* state options */     (0)
	},
	{
	/* state name */        "neg",
	/* action function */   A_main_0_neg,
	/* event function */    E_main_0_neg,
	/* delay function */    D_main_0_neg,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_main_0_neg,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "main",
	/* states */            G_main_states,
	/* number of states */  3,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram changeTest = {
	/* magic number */      2001010,
	/* program name */      "changeTest",
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

#define PROG_NAME changeTest
#include "seqMain.c"
