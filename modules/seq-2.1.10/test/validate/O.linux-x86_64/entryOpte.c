/* Generated with snc from entryOpte.i */

/* Program "entryOpteTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
# line 12 "../entryOpte.st"
static	float v = 0;

/* C code definitions */
# line 10 "../entryOpte.st"
#include "epicsThread.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
}

/****** Code for state "low" in state set "ss1" ******/

/* Entry function for state "low" in state set "ss1" */
static void I_ss1_0_low(SS_ID ssId, struct UserVar *pVar)
{
# line 21 "../entryOpte.st"
	printf("Pause on each entry to low, including 'iterations'\n");
# line 22 "../entryOpte.st"
	epicsThreadSleep(1.0);
}

/* Exit function for state "low" in state set "ss1" */
static void O_ss1_0_low(SS_ID ssId, struct UserVar *pVar)
{
# line 36 "../entryOpte.st"
	printf("low, print this on exit of low\n");
}

/* Delay function for state "low" in state set "ss1" */
static void D_ss1_0_low(SS_ID ssId, struct UserVar *pVar)
{
# line 28 "../entryOpte.st"
	seq_delayInit(ssId, 0, (2.0));
}

/* Event function for state "low" in state set "ss1" */
static seqBool E_ss1_0_low(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 24 "../entryOpte.st"
	if (v > 5.0)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
# line 28 "../entryOpte.st"
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
# line 26 "../entryOpte.st"
			printf("low, v = %g, now changing to high\n", v);
		}
		return;
	case 1:
		{
# line 30 "../entryOpte.st"
			printf("low, delay timeout, incr v and now reenter low\n");
# line 31 "../entryOpte.st"
			v = v + 1.0;
# line 32 "../entryOpte.st"
			printf("v = %g\n", v);
		}
		return;
	}
}

/****** Code for state "high" in state set "ss1" ******/

/* Entry function for state "high" in state set "ss1" */
static void I_ss1_0_high(SS_ID ssId, struct UserVar *pVar)
{
# line 43 "../entryOpte.st"
	printf("\nentered high\n");
}

/* Delay function for state "high" in state set "ss1" */
static void D_ss1_0_high(SS_ID ssId, struct UserVar *pVar)
{
# line 48 "../entryOpte.st"
	seq_delayInit(ssId, 0, (3.0));
}

/* Event function for state "high" in state set "ss1" */
static seqBool E_ss1_0_high(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 44 "../entryOpte.st"
	if (v == 0.0)
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
# line 48 "../entryOpte.st"
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
# line 46 "../entryOpte.st"
			printf("changing to low\n");
		}
		return;
	case 1:
		{
# line 50 "../entryOpte.st"
			printf("high, delay 3.0 timeout, resetting v\n");
# line 51 "../entryOpte.st"
			v = 0;
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
	/* state options */     (0 | OPT_DOENTRYFROMSELF)
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
seqProgram entryOpteTest = {
	/* magic number */      2001010,
	/* program name */      "entryOpteTest",
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

#define PROG_NAME entryOpteTest
#include "seqMain.c"
