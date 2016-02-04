/* Generated with snc from commaOperator.i */

/* Program "commaOperatorTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */

/* C code definitions */
# line 9 "../commaOperator.st"
#include "../testSupport.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 12 "../commaOperator.st"
	seq_test_init(4);
}

/****** Code for state "doit" in state set "myss" ******/

/* Delay function for state "doit" in state set "myss" */
static void D_myss_0_doit(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "doit" in state set "myss" */
static seqBool E_myss_0_doit(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "doit" in state set "myss" */
static void A_myss_0_doit(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 18 "../commaOperator.st"
			int i = 0;

# line 21 "../commaOperator.st"
			testOk1(((i = 1) , testOk1(i == 1) , (i = 2) , testOk1(i == 2) , (i = 3)) == 3);
# line 22 "../commaOperator.st"
			testOk1(i == 3);
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 28 "../commaOperator.st"
	seq_test_done();
}

/************************ Tables ************************/

/* No channel definitions */
#define G_channels NULL

/* Event masks for state set "myss" */
static const seqMask	EM_myss_0_doit[] = {
	0x00000000,
};

/* State table for state set "myss" */
static seqState G_myss_states[] = {
	{
	/* state name */        "doit",
	/* action function */   A_myss_0_doit,
	/* event function */    E_myss_0_doit,
	/* delay function */    D_myss_0_doit,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_myss_0_doit,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "myss",
	/* states */            G_myss_states,
	/* number of states */  1,
	/* number of delays */  0
	},
};

/* Program table (global) */
seqProgram commaOperatorTest = {
	/* magic number */      2001010,
	/* program name */      "commaOperatorTest",
	/* channels */          G_channels,
	/* num. channels */     0,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        G_prog_entry,
	/* exit func */         G_prog_exit,
	/* num. queues */       0
};

#define PROG_NAME commaOperatorTest
#include "seqMain.c"
