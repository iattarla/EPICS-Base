/* Generated with snc from entry.i */

/* Program "entryTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 14 "../entry.st"
	float v;
};

/* C code definitions */
# line 12 "../entry.st"
#include "epicsThread.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
		0,
	};
	*pVar = pVarInit;
}

/****** Code for state "low" in state set "ss1" ******/

/* Entry function for state "low" in state set "ss1" */
static void I_ss1_0_low(SS_ID ssId, struct UserVar *pVar)
{
# line 22 "../entry.st"
	printf("Print something on entry to low\n");
# line 23 "../entry.st"
	printf("Also pause on entry to low\n");
# line 24 "../entry.st"
	epicsThreadSleep(1.0);
}

/* Exit function for state "low" in state set "ss1" */
static void O_ss1_0_low(SS_ID ssId, struct UserVar *pVar)
{
# line 38 "../entry.st"
	printf("low, print this on exit of low\n");
}

/* Delay function for state "low" in state set "ss1" */
static void D_ss1_0_low(SS_ID ssId, struct UserVar *pVar)
{
# line 30 "../entry.st"
	seq_delayInit(ssId, 0, (2.0));
}

/* Event function for state "low" in state set "ss1" */
static seqBool E_ss1_0_low(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 26 "../entry.st"
	if (pVar->v > 5.0)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
# line 30 "../entry.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "low" in state set "ss1" */
static void A_ss1_0_low(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 28 "../entry.st"
			printf("low, v = %g, now changing to high\n", pVar->v);
		}
		return;
	case 1:
		{
# line 32 "../entry.st"
			printf("low, delay timeout, incr v and now reenter low\n");
# line 33 "../entry.st"
			pVar->v = pVar->v + 1.0;
# line 34 "../entry.st"
			printf("v = %g\n", pVar->v);
		}
		return;
	}
}

/****** Code for state "high" in state set "ss1" ******/

/* Entry function for state "high" in state set "ss1" */
static void I_ss1_0_high(SS_ID ssId, struct UserVar *pVar)
{
# line 45 "../entry.st"
	printf("\nentered high\n");
}

/* Delay function for state "high" in state set "ss1" */
static void D_ss1_0_high(SS_ID ssId, struct UserVar *pVar)
{
# line 50 "../entry.st"
	seq_delayInit(ssId, 0, (1.0));
}

/* Event function for state "high" in state set "ss1" */
static seqBool E_ss1_0_high(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 46 "../entry.st"
	if (pVar->v <= 5.0)
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
# line 50 "../entry.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 1;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "high" in state set "ss1" */
static void A_ss1_0_high(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 48 "../entry.st"
			printf("changing to low\n");
		}
		return;
	case 1:
		{
# line 52 "../entry.st"
			printf("high, delay timeout, resetting v\n");
# line 53 "../entry.st"
			pVar->v = 0;
		}
		return;
	}
}

/************************ Tables ************************/

/* No channel definitions */
#define G_channels NULL

/* Event masks for state set "ss1" */
static const seqMask	EM_ss1_0_low[] = {
	0x00000000,
};
static const seqMask	EM_ss1_0_high[] = {
	0x00000000,
};

/* State table for state set "ss1" */
static seqState G_ss1_states[] = {
	{
	/* state name */        "low",
	/* action function */   A_ss1_0_low,
	/* event function */    E_ss1_0_low,
	/* delay function */    D_ss1_0_low,
	/* entry function */    I_ss1_0_low,
	/* exit function */     O_ss1_0_low,
	/* event mask array */  EM_ss1_0_low,
	/* state options */     (0)
	},
	{
	/* state name */        "high",
	/* action function */   A_ss1_0_high,
	/* event function */    E_ss1_0_high,
	/* delay function */    D_ss1_0_high,
	/* entry function */    I_ss1_0_high,
	/* exit function */     0,
	/* event mask array */  EM_ss1_0_high,
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
};

/* Program table (global) */
seqProgram entryTest = {
	/* magic number */      2001010,
	/* program name */      "entryTest",
	/* channels */          G_channels,
	/* num. channels */     0,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_SAFE | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        NULL,
	/* exit func */         NULL,
	/* num. queues */       0
};

#define PROG_NAME entryTest
#include "seqMain.c"
