/* Generated with snc from entryVar.i */

/* Program "entryVarTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
# line 13 "../entryVar.st"
static	float v = 0;


/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
}

/****** Code for state "low" in state set "ss1" ******/

/* Entry function for state "low" in state set "ss1" */
static void I_ss1_0_low(SS_ID ssId, struct UserVar *pVar)
{
# line 23 "../entryVar.st"
	v = 20.0;
# line 24 "../entryVar.st"
	seq_pvPut(ssId, 0/*v*/, 0);
# line 25 "../entryVar.st"
	printf("Init v = %g on first entry to low\n", v);
}

/* Exit function for state "low" in state set "ss1" */
static void O_ss1_0_low(SS_ID ssId, struct UserVar *pVar)
{
# line 46 "../entryVar.st"
	printf("low, print this on exit of low\n");
}

/* Delay function for state "low" in state set "ss1" */
static void D_ss1_0_low(SS_ID ssId, struct UserVar *pVar)
{
# line 37 "../entryVar.st"
	seq_delayInit(ssId, 0, (2.0));
}

/* Event function for state "low" in state set "ss1" */
static seqBool E_ss1_0_low(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 27 "../entryVar.st"
	if (v < 11.0)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
# line 32 "../entryVar.st"
	if (v > 80)
	{
		*pNextState = 0;
		*pTransNum = 1;
		return TRUE;
	}
# line 37 "../entryVar.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 2;
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
# line 30 "../entryVar.st"
			printf("low, v = %g, now changing to high\n", v);
		}
		return;
	case 1:
		{
# line 34 "../entryVar.st"
			v = 20;
# line 35 "../entryVar.st"
			seq_pvPut(ssId, 0/*v*/, 0);
		}
		return;
	case 2:
		{
# line 39 "../entryVar.st"
			printf("low, delay timeout, incr v and now reenter low\n");
# line 40 "../entryVar.st"
			v = v + 1.0;
# line 41 "../entryVar.st"
			seq_pvPut(ssId, 0/*v*/, 0);
# line 42 "../entryVar.st"
			printf("v = %g\n", v);
		}
		return;
	}
}

/****** Code for state "high" in state set "ss1" ******/

/* Entry function for state "high" in state set "ss1" */
static void I_ss1_0_high(SS_ID ssId, struct UserVar *pVar)
{
# line 53 "../entryVar.st"
	printf("\nEntered high\n");
}

/* Delay function for state "high" in state set "ss1" */
static void D_ss1_0_high(SS_ID ssId, struct UserVar *pVar)
{
# line 58 "../entryVar.st"
	seq_delayInit(ssId, 0, (3.0));
}

/* Event function for state "high" in state set "ss1" */
static seqBool E_ss1_0_high(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 54 "../entryVar.st"
	if (v >= 20.0)
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
# line 58 "../entryVar.st"
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
# line 56 "../entryVar.st"
			printf("high, v = %g changing to low\n", v);
		}
		return;
	case 1:
		{
# line 60 "../entryVar.st"
			v = 20;
# line 61 "../entryVar.st"
			seq_pvPut(ssId, 0/*v*/, 0);
# line 62 "../entryVar.st"
			printf("high, delay timeout, resetting v = %g\n", v);
		}
		return;
	}
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"CD01:FD:PERIOD", (size_t)&v, "v", "float", 1, 1, 0, 1, 0, 0}
};

/* Event masks for state set "ss1" */
static const seqMask	EM_ss1_0_low[] = {
	0x00000002,
};
static const seqMask	EM_ss1_0_high[] = {
	0x00000002,
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
seqProgram entryVarTest = {
	/* magic number */      2001010,
	/* program name */      "entryVarTest",
	/* channels */          G_channels,
	/* num. channels */     1,
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

#define PROG_NAME entryVarTest
#include "seqMain.c"
