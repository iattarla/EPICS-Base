/* Generated with snc from userfunc.i */

/* Program "userfuncTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 22 "../userfunc.st"
	int i;
	struct UserVar_myss {
		struct {
			int i_saved;
		} UserVar_doit;
	} UserVar_myss;
};

/* C code definitions */
# line 9 "../userfunc.st"
#include "../testSupport.h"
# line 13 "../userfunc.st"

static void incr(SS_ID ssId, int *pv, VAR_ID v)
{
    seq_pvGet(ssId, v, SYNC);
    *pv += 1;
    seq_pvPut(ssId, v, SYNC);
}


/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
# line 22 "../userfunc.st"
		0,
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
# line 29 "../userfunc.st"
	seq_test_init(10);
}

/****** Code for state "doit" in state set "myss" ******/

/* Delay function for state "doit" in state set "myss" */
static void D_myss_0_doit(SS_ID ssId, struct UserVar *pVar)
{
# line 35 "../userfunc.st"
	seq_delayInit(ssId, 0, (0.1));
}

/* Event function for state "doit" in state set "myss" */
static seqBool E_myss_0_doit(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 35 "../userfunc.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
# line 40 "../userfunc.st"
	if (pVar->i == 10)
	{
		seq_exit(ssId);
		*pTransNum = 1;
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
# line 36 "../userfunc.st"
			incr(ssId, &pVar->i, seq_pvIndex(ssId, 0/*i*/));
# line 37 "../userfunc.st"
			testOk1(pVar->UserVar_myss.UserVar_doit.i_saved == pVar->i - 1);
# line 38 "../userfunc.st"
			pVar->UserVar_myss.UserVar_doit.i_saved = pVar->i;
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 46 "../userfunc.st"
	seq_test_done();
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"", offsetof(struct UserVar, i), "i", "int", 1, 1, 0, 1, 0, 0}
};

/* Event masks for state set "myss" */
static const seqMask	EM_myss_0_doit[] = {
	0x00000002,
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
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram userfuncTest = {
	/* magic number */      2001010,
	/* program name */      "userfuncTest",
	/* channels */          G_channels,
	/* num. channels */     1,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_SAFE | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        G_prog_entry,
	/* exit func */         G_prog_exit,
	/* num. queues */       0
};

#define PROG_NAME userfuncTest
#include "seqMain.c"
