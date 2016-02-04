/* Generated with snc from array.i */

/* Program "arrayTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar_array {
	struct {
		string a4a5s[4][5];
		string (*a4ps[4])[5];
	} UserVar_init;
} UserVar_array = {
	{
# line 17 "../array.st"
		{{"00", "01", "02", "03", "04"}, {"10", "11", "12", "13", "14"}, {"20", "21", "22", "23", "24"}, {"30", "31", "32", "33", "34"}},
# line 23 "../array.st"
		{&UserVar_array.UserVar_init.a4a5s[0], &UserVar_array.UserVar_init.a4a5s[1], &UserVar_array.UserVar_init.a4a5s[2], &UserVar_array.UserVar_init.a4a5s[3]}
	}
};

/* C code definitions */
# line 9 "../array.st"
#include "../testSupport.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 12 "../array.st"
	seq_test_init(20);
}

/****** Code for state "init" in state set "array" ******/

/* Delay function for state "init" in state set "array" */
static void D_array_0_init(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "init" in state set "array" */
static seqBool E_array_0_init(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "array" */
static void A_array_0_init(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 31 "../array.st"
			int i;
# line 31 "../array.st"
			int j;

# line 32 "../array.st"
			for (i = 0; i < 4; i++)
			{
# line 33 "../array.st"
				for (j = 0; j < 5; j++)
				{
# line 36 "../array.st"
					testOk(UserVar_array.UserVar_init.a4a5s[i][j] == (*UserVar_array.UserVar_init.a4ps[i])[j], "a4a5s[%d][%d]=%s==%s=(*a4ps[%d])[%d])", i, j, UserVar_array.UserVar_init.a4a5s[i][j], (*UserVar_array.UserVar_init.a4ps[i])[j], i, j);
				}
			}
# line 39 "../array.st"
			for (i = 0; i < 4; i++)
			{
# line 40 "../array.st"
				testDiag("a4ps[%d]=%p", i, UserVar_array.UserVar_init.a4ps[i]);
			}
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 47 "../array.st"
	seq_test_done();
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"", (size_t)&UserVar_array.UserVar_init.a4a5s[0], "a4a5s[0]", "string", 5, 1, 0, 0, 0, 0},
	{"", (size_t)&UserVar_array.UserVar_init.a4a5s[1], "a4a5s[1]", "string", 5, 2, 0, 0, 0, 0},
	{"", (size_t)&UserVar_array.UserVar_init.a4a5s[2], "a4a5s[2]", "string", 5, 3, 0, 0, 0, 0},
	{"", (size_t)&UserVar_array.UserVar_init.a4a5s[3], "a4a5s[3]", "string", 5, 4, 0, 0, 0, 0}
};

/* Event masks for state set "array" */
static const seqMask	EM_array_0_init[] = {
	0x00000000,
};

/* State table for state set "array" */
static seqState G_array_states[] = {
	{
	/* state name */        "init",
	/* action function */   A_array_0_init,
	/* event function */    E_array_0_init,
	/* delay function */    D_array_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_array_0_init,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "array",
	/* states */            G_array_states,
	/* number of states */  1,
	/* number of delays */  0
	},
};

/* Program table (global) */
seqProgram arrayTest = {
	/* magic number */      2001010,
	/* program name */      "arrayTest",
	/* channels */          G_channels,
	/* num. channels */     4,
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

#define PROG_NAME arrayTest
#include "seqMain.c"
