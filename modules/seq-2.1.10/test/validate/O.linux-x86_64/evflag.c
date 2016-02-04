/* Generated with snc from evflag.i */

/* Program "evflagTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 23 "../evflag.st"
	double anonymous;
	struct UserVar_read {
		double named;
	} UserVar_read;
	struct UserVar_write {
		double named;
		int n;
	} UserVar_write;
};

/* C code definitions */
# line 17 "../evflag.st"
#include "../testSupport.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
		0,
		{
			0,
		},
		{
# line 51 "../evflag.st"
			1.0,
# line 53 "../evflag.st"
			0,
		}
	};
	*pVar = pVarInit;
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 29 "../evflag.st"
	seq_test_init(0);
# line 30 "../evflag.st"
	seq_efClear(ssId, 1/*ef_named*/);
}

/****** Code for state "wait" in state set "read" ******/

/* Delay function for state "wait" in state set "read" */
static void D_read_0_wait(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "wait" in state set "read" */
static seqBool E_read_0_wait(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 39 "../evflag.st"
	if (seq_efTestAndClear(ssId, 1/*ef_named*/))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait" in state set "read" */
static void A_read_0_wait(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 40 "../evflag.st"
			pVar->anonymous = pVar->UserVar_read.named;
# line 41 "../evflag.st"
			seq_pvPut(ssId, 0/*anonymous*/, 0);
# line 42 "../evflag.st"
			testDiag("read: pvPut(anonymous=%.1f)", pVar->anonymous);
# line 43 "../evflag.st"
			epicsThreadSleep(0.1);
# line 45 "../evflag.st"
			testOk(pVar->UserVar_read.named == pVar->anonymous, "read: named=%.1f==%.1f=anonymous", pVar->UserVar_read.named, pVar->anonymous);
		}
		return;
	}
}

/****** Code for state "send" in state set "write" ******/

/* Delay function for state "send" in state set "write" */
static void D_write_1_send(SS_ID ssId, struct UserVar *pVar)
{
# line 57 "../evflag.st"
	seq_delayInit(ssId, 0, (0.01));
}

/* Event function for state "send" in state set "write" */
static seqBool E_write_1_send(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 55 "../evflag.st"
	if (pVar->UserVar_write.n > 10)
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
# line 57 "../evflag.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 1;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "send" in state set "write" */
static void A_write_1_send(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 58 "../evflag.st"
			pVar->UserVar_write.named = pVar->UserVar_write.n;
# line 59 "../evflag.st"
			seq_pvPut(ssId, 2/*named*/, 0);
# line 60 "../evflag.st"
			testDiag("write: pvPut(named=%.1f)", pVar->UserVar_write.named);
# line 61 "../evflag.st"
			pVar->anonymous = pVar->UserVar_write.named;
		}
		return;
	}
}

/****** Code for state "recv" in state set "write" ******/

/* Delay function for state "recv" in state set "write" */
static void D_write_1_recv(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "recv" in state set "write" */
static seqBool E_write_1_recv(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 65 "../evflag.st"
	if (seq_efTestAndClear(ssId, 2/*ef_anonymous*/))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "recv" in state set "write" */
static void A_write_1_recv(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 66 "../evflag.st"
			testOk(pVar->UserVar_write.named == pVar->anonymous, "write: named=%.1f==%.1f=anonymous", pVar->UserVar_write.named, pVar->anonymous);
# line 67 "../evflag.st"
			epicsThreadSleep(0.1);
# line 68 "../evflag.st"
			testOk(pVar->UserVar_write.named == pVar->anonymous, "write: named=%.1f==%.1f=anonymous", pVar->UserVar_write.named, pVar->anonymous);
# line 69 "../evflag.st"
			seq_pvGet(ssId, 0/*anonymous*/, 0);
# line 70 "../evflag.st"
			testOk(pVar->UserVar_write.named == pVar->anonymous, "write: named=%.1f==%.1f=anonymous", pVar->UserVar_write.named, pVar->anonymous);
# line 71 "../evflag.st"
			pVar->UserVar_write.n++;
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 77 "../evflag.st"
	seq_test_done();
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"", offsetof(struct UserVar, anonymous), "anonymous", "double", 1, 3, 2, 1, 0, 0},
	{"evflag", offsetof(struct UserVar, UserVar_read.named), "named", "double", 1, 4, 1, 1, 0, 0},
	{"evflag", offsetof(struct UserVar, UserVar_write.named), "named", "double", 1, 5, 0, 0, 0, 0}
};

/* Event masks for state set "read" */
static const seqMask	EM_read_0_wait[] = {
	0x00000002,
};

/* State table for state set "read" */
static seqState G_read_states[] = {
	{
	/* state name */        "wait",
	/* action function */   A_read_0_wait,
	/* event function */    E_read_0_wait,
	/* delay function */    D_read_0_wait,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_read_0_wait,
	/* state options */     (0)
	},
};

/* Event masks for state set "write" */
static const seqMask	EM_write_1_send[] = {
	0x00000000,
};
static const seqMask	EM_write_1_recv[] = {
	0x00000004,
};

/* State table for state set "write" */
static seqState G_write_states[] = {
	{
	/* state name */        "send",
	/* action function */   A_write_1_send,
	/* event function */    E_write_1_send,
	/* delay function */    D_write_1_send,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_write_1_send,
	/* state options */     (0)
	},
	{
	/* state name */        "recv",
	/* action function */   A_write_1_recv,
	/* event function */    E_write_1_recv,
	/* delay function */    D_write_1_recv,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_write_1_recv,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "read",
	/* states */            G_read_states,
	/* number of states */  1,
	/* number of delays */  0
	},

	{
	/* state set name */    "write",
	/* states */            G_write_states,
	/* number of states */  2,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram evflagTest = {
	/* magic number */      2001010,
	/* program name */      "evflagTest",
	/* channels */          G_channels,
	/* num. channels */     3,
	/* state sets */        G_state_sets,
	/* num. state sets */   2,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  2,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_SAFE | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        G_prog_entry,
	/* exit func */         G_prog_exit,
	/* num. queues */       0
};

#define PROG_NAME evflagTest
#include "seqMain.c"
