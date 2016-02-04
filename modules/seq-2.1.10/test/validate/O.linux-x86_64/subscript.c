/* Generated with snc from subscript.i */

/* Program "subscriptTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
# line 9 "../subscript.st"
static	float single[2] = {0,0};
# line 12 "../subscript.st"
static	float multiple3[3] = {0,0,0};
# line 15 "../subscript.st"
static	int multiple2[2] = {0,0};


/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
}

/****** Code for state "test" in state set "test" ******/

/* Delay function for state "test" in state set "test" */
static void D_test_0_test(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "test" in state set "test" */
static seqBool E_test_0_test(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 22 "../subscript.st"
	if (FALSE)
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "test" in state set "test" */
static void A_test_0_test(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
			/* C code definitions */
# line 23 "../subscript.st"
			multiple2[0] = 0;

		}
		return;
	}
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"", (size_t)&single, "single", "float", 2, 1, 0, 0, 0, 0},
	{"x", (size_t)&multiple3[0], "multiple3[0]", "float", 1, 2, 0, 0, 0, 0},
	{"y", (size_t)&multiple3[1], "multiple3[1]", "float", 1, 3, 0, 0, 0, 0},
	{"", (size_t)&multiple3[2], "multiple3[2]", "float", 1, 4, 0, 0, 0, 0},
	{"", (size_t)&multiple2[0], "multiple2[0]", "int", 1, 5, 0, 1, 0, 0},
	{"", (size_t)&multiple2[1], "multiple2[1]", "int", 1, 6, 0, 1, 0, 0}
};

/* Event masks for state set "test" */
static const seqMask	EM_test_0_test[] = {
	0x00000000,
};

/* State table for state set "test" */
static seqState G_test_states[] = {
	{
	/* state name */        "test",
	/* action function */   A_test_0_test,
	/* event function */    E_test_0_test,
	/* delay function */    D_test_0_test,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_test_0_test,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "test",
	/* states */            G_test_states,
	/* number of states */  1,
	/* number of delays */  0
	},
};

/* Program table (global) */
seqProgram subscriptTest = {
	/* magic number */      2001010,
	/* program name */      "subscriptTest",
	/* channels */          G_channels,
	/* num. channels */     6,
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

#define PROG_NAME subscriptTest
#include "seqMain.c"
