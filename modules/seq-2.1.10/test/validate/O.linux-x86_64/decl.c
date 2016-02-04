/* Generated with snc from decl.i */

/* Program "declTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 15 "../decl.st"
	int *(*(*complicated)[2][3])[1];
# line 28 "../decl.st"
	int var;
	struct UserVar_one {
		struct {
			char *a[4];
			string b[4];
			int c[2];
			string s;
		} UserVar_one;
	} UserVar_one;
};

/* C code definitions */
# line 9 "../decl.st"
#include <stdlib.h>
# line 20 "../decl.st"
struct r { int x; } rv;
# line 25 "../decl.st"
TS_STAMP ts;

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
# line 15 "../decl.st"
		0,
		0,
		{
			{
# line 38 "../decl.st"
				{"1", "2", "3"},
# line 42 "../decl.st"
				{"1234567890123456789012345678901234567890", "abcdefghijabcdefghijabcdefghijabcdefghij", "ABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJ", "123"},
# line 49 "../decl.st"
				{123, 456},
# line 55 "../decl.st"
				"s"
			}
		}
	};
	*pVar = pVarInit;
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 32 "../decl.st"
	printf("%d\n", rv . x);
# line 33 "../decl.st"
	ts = seq_pvTimeStamp(ssId, 0/*var*/);
}

/****** Code for state "one" in state set "one" ******/

/* Entry function for state "one" in state set "one" */
static void I_one_0_one(SS_ID ssId, struct UserVar *pVar)
{
# line 58 "../decl.st"
	seq_pvPut(ssId, 1/*b*/, 0);
# line 59 "../decl.st"
	seq_pvPut(ssId, 2/*c*/, 0);
# line 60 "../decl.st"
	seq_pvPut(ssId, 3/*s*/, 0);
}

/* Delay function for state "one" in state set "one" */
static void D_one_0_one(SS_ID ssId, struct UserVar *pVar)
{
# line 62 "../decl.st"
	seq_delayInit(ssId, 0, (10));
# line 72 "../decl.st"
	seq_delayInit(ssId, 1, (0.1));
}

/* Event function for state "one" in state set "one" */
static seqBool E_one_0_one(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 62 "../decl.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
# line 64 "../decl.st"
	if (seq_efTestAndClear(ssId, 1/*ef*/))
	{
		*pNextState = 0;
		*pTransNum = 1;
		return TRUE;
	}
# line 72 "../decl.st"
	if (seq_delay(ssId, 1) && !pVar->complicated)
	{
		seq_exit(ssId);
		*pTransNum = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "one" in state set "one" */
static void A_one_0_one(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 65 "../decl.st"
			printf("Event on b or c\n");
			{
# line 68 "../decl.st"
				string s = "blub";
# line 69 "../decl.st"
				printf("s=%s\n", s);
			}
		}
		return;
	case 2:
		{
# line 73 "../decl.st"
			exit(0);
		}
		return;
	}
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"", offsetof(struct UserVar, var), "var", "int", 1, 2, 0, 0, 0, 0},
	{"", offsetof(struct UserVar, UserVar_one.UserVar_one.b), "b", "string", 4, 3, 1, 1, 0, 0},
	{"", offsetof(struct UserVar, UserVar_one.UserVar_one.c), "c", "int", 2, 4, 1, 1, 0, 0},
	{"", offsetof(struct UserVar, UserVar_one.UserVar_one.s), "s", "string", 1, 5, 0, 0, 0, 0}
};

/* Event masks for state set "one" */
static const seqMask	EM_one_0_one[] = {
	0x00000002,
};

/* State table for state set "one" */
static seqState G_one_states[] = {
	{
	/* state name */        "one",
	/* action function */   A_one_0_one,
	/* event function */    E_one_0_one,
	/* delay function */    D_one_0_one,
	/* entry function */    I_one_0_one,
	/* exit function */     0,
	/* event mask array */  EM_one_0_one,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "one",
	/* states */            G_one_states,
	/* number of states */  1,
	/* number of delays */  2
	},
};

/* Program table (global) */
seqProgram declTest = {
	/* magic number */      2001010,
	/* program name */      "declTest",
	/* channels */          G_channels,
	/* num. channels */     4,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  1,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_SAFE | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        G_prog_entry,
	/* exit func */         NULL,
	/* num. queues */       0
};

#define PROG_NAME declTest
#include "seqMain.c"
