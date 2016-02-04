/* Generated with snc from opttVar.i */

/* Program "opttVarTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 20 "../opttVar.st"
	char msg[60];
	struct UserVar_low_high {
		struct {
			double d;
		} UserVar_low;
		struct {
			int v;
		} UserVar_high;
	} UserVar_low_high;
	struct UserVar_check {
		char *expected[20];
		char **xp;
		int repeat;
	} UserVar_check;
};

/* C code definitions */
# line 7 "../opttVar.st"
#include "../testSupport.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{
			{
				0
			},
			{
				0
			}
		},
		{
# line 77 "../opttVar.st"
			{"Entered low, initialize delay to 0.4 sec.", "low, delay timeout, reenter low", "low, waiting 0.6 secs to iterate", "low, delay timeout, reenter low", "low, waiting 0.8 secs to iterate", "low, delay timeout, reenter low", "low, waiting 1 secs to iterate", "low, delay timeout, reenter low", "low, waiting 1.2 secs to iterate", "low, delay = 1.2, now changing to high", "low, print this on exit of low", "Entered high", "high, delay 0.3 timeout, decr v and re-enter high", "v = 2", "high, delay 0.3 timeout, decr v and re-enter high", "v = 1", "high, delay 0.3 timeout, decr v and re-enter high", "v = 0", "changing to low", 0},
			0,
# line 100 "../opttVar.st"
			1,
		}
	};
	*pVar = pVarInit;
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 26 "../opttVar.st"
	seq_test_init(40);
}

/****** Code for state "low" in state set "low_high" ******/

/* Entry function for state "low" in state set "low_high" */
static void I_low_high_0_low(SS_ID ssId, struct UserVar *pVar)
{
# line 34 "../opttVar.st"
	pVar->UserVar_low_high.UserVar_low.d = 0.4;
# line 35 "../opttVar.st"
	sprintf(pVar->msg, "Entered low, initialize delay to %g sec.", pVar->UserVar_low_high.UserVar_low.d);
# line 36 "../opttVar.st"
	seq_pvPut(ssId, 0/*msg*/, 0);
}

/* Exit function for state "low" in state set "low_high" */
static void O_low_high_0_low(SS_ID ssId, struct UserVar *pVar)
{
# line 50 "../opttVar.st"
	sprintf(pVar->msg, "low, print this on exit of low");
# line 51 "../opttVar.st"
	seq_pvPut(ssId, 0/*msg*/, 0);
}

/* Delay function for state "low" in state set "low_high" */
static void D_low_high_0_low(SS_ID ssId, struct UserVar *pVar)
{
# line 42 "../opttVar.st"
	seq_delayInit(ssId, 0, (pVar->UserVar_low_high.UserVar_low.d));
}

/* Event function for state "low" in state set "low_high" */
static seqBool E_low_high_0_low(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 38 "../opttVar.st"
	if (pVar->UserVar_low_high.UserVar_low.d > 1.1)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
# line 42 "../opttVar.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "low" in state set "low_high" */
static void A_low_high_0_low(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 39 "../opttVar.st"
			sprintf(pVar->msg, "low, delay = %g, now changing to high", pVar->UserVar_low_high.UserVar_low.d);
# line 40 "../opttVar.st"
			seq_pvPut(ssId, 0/*msg*/, 0);
		}
		return;
	case 1:
		{
# line 43 "../opttVar.st"
			sprintf(pVar->msg, "low, delay timeout, reenter low");
# line 44 "../opttVar.st"
			seq_pvPut(ssId, 0/*msg*/, 0);
# line 45 "../opttVar.st"
			pVar->UserVar_low_high.UserVar_low.d += 0.2;
# line 46 "../opttVar.st"
			sprintf(pVar->msg, "low, waiting %g secs to iterate", pVar->UserVar_low_high.UserVar_low.d);
# line 47 "../opttVar.st"
			seq_pvPut(ssId, 0/*msg*/, 0);
		}
		return;
	}
}

/****** Code for state "high" in state set "low_high" ******/

/* Entry function for state "high" in state set "low_high" */
static void I_low_high_0_high(SS_ID ssId, struct UserVar *pVar)
{
# line 58 "../opttVar.st"
	pVar->UserVar_low_high.UserVar_high.v = 3;
# line 59 "../opttVar.st"
	sprintf(pVar->msg, "Entered high");
# line 60 "../opttVar.st"
	seq_pvPut(ssId, 0/*msg*/, 0);
}

/* Delay function for state "high" in state set "low_high" */
static void D_low_high_0_high(SS_ID ssId, struct UserVar *pVar)
{
# line 66 "../opttVar.st"
	seq_delayInit(ssId, 0, (0.3));
}

/* Event function for state "high" in state set "low_high" */
static seqBool E_low_high_0_high(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 62 "../opttVar.st"
	if (pVar->UserVar_low_high.UserVar_high.v == 0)
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
# line 66 "../opttVar.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 1;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "high" in state set "low_high" */
static void A_low_high_0_high(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 63 "../opttVar.st"
			sprintf(pVar->msg, "changing to low");
# line 64 "../opttVar.st"
			seq_pvPut(ssId, 0/*msg*/, 0);
		}
		return;
	case 1:
		{
# line 67 "../opttVar.st"
			sprintf(pVar->msg, "high, delay 0.3 timeout, decr v and re-enter high");
# line 68 "../opttVar.st"
			seq_pvPut(ssId, 0/*msg*/, 0);
# line 69 "../opttVar.st"
			pVar->UserVar_low_high.UserVar_high.v -= 1;
# line 70 "../opttVar.st"
			sprintf(pVar->msg, "v = %d", pVar->UserVar_low_high.UserVar_high.v);
# line 71 "../opttVar.st"
			seq_pvPut(ssId, 0/*msg*/, 0);
		}
		return;
	}
}

/****** Code for state "check_msg" in state set "check" ******/

/* Entry function for state "check_msg" in state set "check" */
static void I_check_1_check_msg(SS_ID ssId, struct UserVar *pVar)
{
# line 103 "../opttVar.st"
	pVar->UserVar_check.xp = pVar->UserVar_check.expected;
# line 104 "../opttVar.st"
	testPass("start 1st round...");
}

/* Delay function for state "check_msg" in state set "check" */
static void D_check_1_check_msg(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "check_msg" in state set "check" */
static seqBool E_check_1_check_msg(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 106 "../opttVar.st"
	if (pVar->UserVar_check.repeat && !*pVar->UserVar_check.xp)
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
# line 111 "../opttVar.st"
	if (!*pVar->UserVar_check.xp)
	{
		seq_exit(ssId);
		*pTransNum = 1;
		return TRUE;
	}
# line 113 "../opttVar.st"
	if (seq_pvGetQ(ssId, 0/*msg*/))
	{
		*pNextState = 0;
		*pTransNum = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "check_msg" in state set "check" */
static void A_check_1_check_msg(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 107 "../opttVar.st"
			pVar->UserVar_check.xp = pVar->UserVar_check.expected;
# line 108 "../opttVar.st"
			testPass("one more time...");
# line 109 "../opttVar.st"
			pVar->UserVar_check.repeat = 0;
		}
		return;
	case 1:
		{
		}
		return;
	case 2:
		{
# line 114 "../opttVar.st"
			testOk(strcmp(*pVar->UserVar_check.xp, pVar->msg) == 0, "msg=%s", pVar->msg);
# line 115 "../opttVar.st"
			pVar->UserVar_check.xp++;
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 121 "../opttVar.st"
	seq_test_done();
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"", offsetof(struct UserVar, msg), "msg", "char", 60, 1, 0, 1, 40, 0}
};

/* Event masks for state set "low_high" */
static const seqMask	EM_low_high_0_low[] = {
	0x00000000,
};
static const seqMask	EM_low_high_0_high[] = {
	0x00000000,
};

/* State table for state set "low_high" */
static seqState G_low_high_states[] = {
	{
	/* state name */        "low",
	/* action function */   A_low_high_0_low,
	/* event function */    E_low_high_0_low,
	/* delay function */    D_low_high_0_low,
	/* entry function */    I_low_high_0_low,
	/* exit function */     O_low_high_0_low,
	/* event mask array */  EM_low_high_0_low,
	/* state options */     (0 | OPT_NORESETTIMERS)
	},
	{
	/* state name */        "high",
	/* action function */   A_low_high_0_high,
	/* event function */    E_low_high_0_high,
	/* delay function */    D_low_high_0_high,
	/* entry function */    I_low_high_0_high,
	/* exit function */     0,
	/* event mask array */  EM_low_high_0_high,
	/* state options */     (0)
	},
};

/* Event masks for state set "check" */
static const seqMask	EM_check_1_check_msg[] = {
	0x00000002,
};

/* State table for state set "check" */
static seqState G_check_states[] = {
	{
	/* state name */        "check_msg",
	/* action function */   A_check_1_check_msg,
	/* event function */    E_check_1_check_msg,
	/* delay function */    D_check_1_check_msg,
	/* entry function */    I_check_1_check_msg,
	/* exit function */     0,
	/* event mask array */  EM_check_1_check_msg,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "low_high",
	/* states */            G_low_high_states,
	/* number of states */  2,
	/* number of delays */  1
	},

	{
	/* state set name */    "check",
	/* states */            G_check_states,
	/* number of states */  1,
	/* number of delays */  0
	},
};

/* Program table (global) */
seqProgram opttVarTest = {
	/* magic number */      2001010,
	/* program name */      "opttVarTest",
	/* channels */          G_channels,
	/* num. channels */     1,
	/* state sets */        G_state_sets,
	/* num. state sets */   2,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_SAFE | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        G_prog_entry,
	/* exit func */         G_prog_exit,
	/* num. queues */       1
};

#define PROG_NAME opttVarTest
#include "seqMain.c"
