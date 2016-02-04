/* Generated with snc from stop.i */

/* Program "stopTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */


/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
}

/****** Code for state "start" in state set "main" ******/

/* Delay function for state "start" in state set "main" */
static void D_main_0_start(SS_ID ssId, struct UserVar *pVar)
{
# line 11 "../stop.st"
	seq_delayInit(ssId, 0, (5));
}

/* Event function for state "start" in state set "main" */
static seqBool E_main_0_start(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 11 "../stop.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "start" in state set "main" */
static void A_main_0_start(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 12 "../stop.st"
			seqStop(epicsThreadGetIdSelf());
		}
		return;
	}
}

/****** Code for state "running" in state set "progress" ******/

/* Delay function for state "running" in state set "progress" */
static void D_progress_1_running(SS_ID ssId, struct UserVar *pVar)
{
# line 19 "../stop.st"
	seq_delayInit(ssId, 0, (1));
}

/* Event function for state "running" in state set "progress" */
static seqBool E_progress_1_running(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 19 "../stop.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "running" in state set "progress" */
static void A_progress_1_running(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 20 "../stop.st"
			printf("still running...\n");
		}
		return;
	}
}

/************************ Tables ************************/

/* No channel definitions */
#define G_channels NULL

/* Event masks for state set "main" */
static const seqMask	EM_main_0_start[] = {
	0x00000000,
};

/* State table for state set "main" */
static seqState G_main_states[] = {
	{
	/* state name */        "start",
	/* action function */   A_main_0_start,
	/* event function */    E_main_0_start,
	/* delay function */    D_main_0_start,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_main_0_start,
	/* state options */     (0)
	},
};

/* Event masks for state set "progress" */
static const seqMask	EM_progress_1_running[] = {
	0x00000000,
};

/* State table for state set "progress" */
static seqState G_progress_states[] = {
	{
	/* state name */        "running",
	/* action function */   A_progress_1_running,
	/* event function */    E_progress_1_running,
	/* delay function */    D_progress_1_running,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_progress_1_running,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "main",
	/* states */            G_main_states,
	/* number of states */  1,
	/* number of delays */  1
	},

	{
	/* state set name */    "progress",
	/* states */            G_progress_states,
	/* number of states */  1,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram stopTest = {
	/* magic number */      2001010,
	/* program name */      "stopTest",
	/* channels */          G_channels,
	/* num. channels */     0,
	/* state sets */        G_state_sets,
	/* num. state sets */   2,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        NULL,
	/* exit func */         NULL,
	/* num. queues */       0
};

#define PROG_NAME stopTest
#include "seqMain.c"
