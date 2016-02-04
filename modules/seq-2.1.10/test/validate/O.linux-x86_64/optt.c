/* Generated with snc from optt.i */

/* Program "opttTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
# line 11 "../optt.st"
static	float v = 0;

/* C code definitions */
# line 9 "../optt.st"
#include "epicsThread.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
}

/****** Code for state "low" in state set "ss1" ******/

/* Entry function for state "low" in state set "ss1" */
static void I_ss1_0_low(SS_ID ssId, struct UserVar *pVar)
{
# line 22 "../optt.st"
	printf("Print something on entry to low\n");
# line 23 "../optt.st"
	printf("Also pause on entry to low\n");
# line 24 "../optt.st"
	epicsThreadSleep(1.0);
}

/* Exit function for state "low" in state set "ss1" */
static void O_ss1_0_low(SS_ID ssId, struct UserVar *pVar)
{
# line 38 "../optt.st"
	printf("low, print this on exit of low\n");
}

/* Delay function for state "low" in state set "ss1" */
static void D_ss1_0_low(SS_ID ssId, struct UserVar *pVar)
{
# line 30 "../optt.st"
	seq_delayInit(ssId, 0, (2.0));
}

/* Event function for state "low" in state set "ss1" */
static seqBool E_ss1_0_low(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 26 "../optt.st"
	if (v > 5.0)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
# line 30 "../optt.st"
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
# line 28 "../optt.st"
			printf("low, v = %g, now changing to high\n", v);
		}
		return;
	case 1:
		{
# line 32 "../optt.st"
			printf("low, delay timeout, incr v and now reenter low\n");
# line 33 "../optt.st"
			v = v + 1.0;
# line 34 "../optt.st"
			printf("v = %g\n", v);
		}
		return;
	}
}

/****** Code for state "high" in state set "ss1" ******/

/* Entry function for state "high" in state set "ss1" */
static void I_ss1_0_high(SS_ID ssId, struct UserVar *pVar)
{
# line 45 "../optt.st"
	printf("\nEntered high\n");
}

/* Delay function for state "high" in state set "ss1" */
static void D_ss1_0_high(SS_ID ssId, struct UserVar *pVar)
{
# line 50 "../optt.st"
	seq_delayInit(ssId, 0, (3.0));
}

/* Event function for state "high" in state set "ss1" */
static seqBool E_ss1_0_high(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 46 "../optt.st"
	if (v == 0)
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
# line 50 "../optt.st"
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
# line 48 "../optt.st"
			printf("changing to low\n");
		}
		return;
	case 1:
		{
# line 52 "../optt.st"
			printf("high, delay 3.0 timeout, decr v and re-enter high\n");
# line 53 "../optt.st"
			v = v - 1.0;
# line 54 "../optt.st"
			printf("v = %g\n", v);
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
	/* state options */     (0 | OPT_NORESETTIMERS)
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
seqProgram opttTest = {
	/* magic number */      2001010,
	/* program name */      "opttTest",
	/* channels */          G_channels,
	/* num. channels */     0,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        NULL,
	/* exit func */         NULL,
	/* num. queues */       0
};

#define PROG_NAME opttTest
#include "seqMain.c"
