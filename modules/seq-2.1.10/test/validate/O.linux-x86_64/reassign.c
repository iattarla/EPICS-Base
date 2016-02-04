/* Generated with snc from reassign.i */

/* Program "reassignTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 13 "../reassign.st"
	int x;
# line 13 "../reassign.st"
	int y;
# line 13 "../reassign.st"
	int z;
};

/* C code definitions */
# line 11 "../reassign.st"
#include "../testSupport.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
		0,
		0,
		0,
	};
	*pVar = pVarInit;
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 23 "../reassign.st"
	seq_test_init(30);
}

/****** Code for state "start" in state set "reassign" ******/

/* Delay function for state "start" in state set "reassign" */
static void D_reassign_0_start(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "start" in state set "reassign" */
static seqBool E_reassign_0_start(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "start" in state set "reassign" */
static void A_reassign_0_start(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 29 "../reassign.st"
			testDiag("start");
# line 30 "../reassign.st"
			testOk1(seq_pvChannelCount(ssId) == 3);
# line 31 "../reassign.st"
			testOk1(seq_pvAssignCount(ssId) == 2);
# line 32 "../reassign.st"
			testOk1(seq_pvConnectCount(ssId) == 2);
# line 33 "../reassign.st"
			testOk1(seq_pvAssign(ssId, 0/*x*/, "") == pvStatOK);
		}
		return;
	}
}

/****** Code for state "wait_x_nil" in state set "reassign" ******/

/* Delay function for state "wait_x_nil" in state set "reassign" */
static void D_reassign_0_wait_x_nil(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "wait_x_nil" in state set "reassign" */
static seqBool E_reassign_0_wait_x_nil(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 37 "../reassign.st"
	if (seq_pvAssignCount(ssId) == 1)
	{
		*pNextState = 2;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait_x_nil" in state set "reassign" */
static void A_reassign_0_wait_x_nil(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 38 "../reassign.st"
			testDiag("wait_x_nil");
# line 39 "../reassign.st"
			testOk1(seq_pvChannelCount(ssId) == 3);
# line 40 "../reassign.st"
			testOk1(seq_pvAssignCount(ssId) == 1);
# line 41 "../reassign.st"
			testOk1(seq_pvAssign(ssId, 0/*x*/, "pv1") == pvStatOK);
# line 42 "../reassign.st"
			testOk1(seq_pvAssignCount(ssId) == 2);
		}
		return;
	}
}

/****** Code for state "wait_x_pv1" in state set "reassign" ******/

/* Delay function for state "wait_x_pv1" in state set "reassign" */
static void D_reassign_0_wait_x_pv1(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "wait_x_pv1" in state set "reassign" */
static seqBool E_reassign_0_wait_x_pv1(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 46 "../reassign.st"
	if (seq_pvConnected(ssId, 0/*x*/))
	{
		*pNextState = 3;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait_x_pv1" in state set "reassign" */
static void A_reassign_0_wait_x_pv1(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 47 "../reassign.st"
			testDiag("wait_x_pv1");
# line 48 "../reassign.st"
			testOk1(seq_pvGet(ssId, 0/*x*/, 0) == pvStatOK);
# line 49 "../reassign.st"
			testOk1(seq_pvChannelCount(ssId) == 3);
# line 50 "../reassign.st"
			testOk1(seq_pvConnectCount(ssId) == 2);
# line 51 "../reassign.st"
			testOk1(seq_pvAssignCount(ssId) == 2);
# line 52 "../reassign.st"
			testOk1(seq_pvAssign(ssId, 0/*x*/, "pv2") == pvStatOK);
		}
		return;
	}
}

/****** Code for state "wait_x_pv2" in state set "reassign" ******/

/* Delay function for state "wait_x_pv2" in state set "reassign" */
static void D_reassign_0_wait_x_pv2(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "wait_x_pv2" in state set "reassign" */
static seqBool E_reassign_0_wait_x_pv2(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 56 "../reassign.st"
	if (seq_pvConnected(ssId, 0/*x*/))
	{
		*pNextState = 4;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait_x_pv2" in state set "reassign" */
static void A_reassign_0_wait_x_pv2(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 57 "../reassign.st"
			testDiag("wait_x_pv2");
# line 58 "../reassign.st"
			testOk1(seq_pvGet(ssId, 0/*x*/, 0) == pvStatOK);
# line 59 "../reassign.st"
			testOk1(seq_pvChannelCount(ssId) == 3);
# line 60 "../reassign.st"
			testOk1(seq_pvConnectCount(ssId) == 2);
# line 61 "../reassign.st"
			testOk1(seq_pvAssignCount(ssId) == 2);
# line 63 "../reassign.st"
			testOk1(seq_pvAssign(ssId, 1/*y*/, "") == pvStatOK);
# line 64 "../reassign.st"
			testOk1(seq_pvConnectCount(ssId) == 2);
# line 65 "../reassign.st"
			testOk1(seq_pvAssignCount(ssId) == 2);
# line 66 "../reassign.st"
			testOk1(seq_pvAssign(ssId, 1/*y*/, "pv1") == pvStatOK);
# line 67 "../reassign.st"
			testOk1(seq_pvAssignCount(ssId) == 3);
		}
		return;
	}
}

/****** Code for state "wait_y_pv1" in state set "reassign" ******/

/* Delay function for state "wait_y_pv1" in state set "reassign" */
static void D_reassign_0_wait_y_pv1(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "wait_y_pv1" in state set "reassign" */
static seqBool E_reassign_0_wait_y_pv1(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 71 "../reassign.st"
	if (seq_pvConnected(ssId, 1/*y*/))
	{
		*pNextState = 5;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait_y_pv1" in state set "reassign" */
static void A_reassign_0_wait_y_pv1(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 72 "../reassign.st"
			testDiag("wait_y_pv1");
# line 73 "../reassign.st"
			testOk1(seq_pvGet(ssId, 1/*y*/, 0) == pvStatOK);
# line 74 "../reassign.st"
			testOk1(seq_pvChannelCount(ssId) == 3);
# line 75 "../reassign.st"
			testOk1(seq_pvConnectCount(ssId) == 3);
# line 76 "../reassign.st"
			testOk1(seq_pvAssign(ssId, 2/*z*/, "pv2") == pvStatOK);
		}
		return;
	}
}

/****** Code for state "wait_z_pv2" in state set "reassign" ******/

/* Delay function for state "wait_z_pv2" in state set "reassign" */
static void D_reassign_0_wait_z_pv2(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "wait_z_pv2" in state set "reassign" */
static seqBool E_reassign_0_wait_z_pv2(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 80 "../reassign.st"
	if (seq_pvConnected(ssId, 2/*z*/))
	{
		*pNextState = 6;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait_z_pv2" in state set "reassign" */
static void A_reassign_0_wait_z_pv2(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 81 "../reassign.st"
			testDiag("wait_z_pv2");
# line 82 "../reassign.st"
			testOk1(seq_pvChannelCount(ssId) == 3);
# line 83 "../reassign.st"
			testOk1(seq_pvConnectCount(ssId) == 3);
# line 84 "../reassign.st"
			testOk1(seq_pvAssignCount(ssId) == 3);
# line 85 "../reassign.st"
			seqShow(epicsThreadGetIdSelf());
		}
		return;
	}
}

/****** Code for state "done" in state set "reassign" ******/

/* Delay function for state "done" in state set "reassign" */
static void D_reassign_0_done(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "done" in state set "reassign" */
static seqBool E_reassign_0_done(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 89 "../reassign.st"
	if (1)
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "done" in state set "reassign" */
static void A_reassign_0_done(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 90 "../reassign.st"
			testPass("ok");
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 96 "../reassign.st"
	seq_test_done();
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"pv1", offsetof(struct UserVar, x), "x", "int", 1, 1, 0, 0, 0, 0},
	{"", offsetof(struct UserVar, y), "y", "int", 1, 2, 0, 0, 0, 0},
	{"pv1", offsetof(struct UserVar, z), "z", "int", 1, 3, 0, 0, 0, 0}
};

/* Event masks for state set "reassign" */
static const seqMask	EM_reassign_0_start[] = {
	0x00000000,
};
static const seqMask	EM_reassign_0_wait_x_nil[] = {
	0x00000000,
};
static const seqMask	EM_reassign_0_wait_x_pv1[] = {
	0x00000002,
};
static const seqMask	EM_reassign_0_wait_x_pv2[] = {
	0x00000002,
};
static const seqMask	EM_reassign_0_wait_y_pv1[] = {
	0x00000004,
};
static const seqMask	EM_reassign_0_wait_z_pv2[] = {
	0x00000008,
};
static const seqMask	EM_reassign_0_done[] = {
	0x00000000,
};

/* State table for state set "reassign" */
static seqState G_reassign_states[] = {
	{
	/* state name */        "start",
	/* action function */   A_reassign_0_start,
	/* event function */    E_reassign_0_start,
	/* delay function */    D_reassign_0_start,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_reassign_0_start,
	/* state options */     (0)
	},
	{
	/* state name */        "wait_x_nil",
	/* action function */   A_reassign_0_wait_x_nil,
	/* event function */    E_reassign_0_wait_x_nil,
	/* delay function */    D_reassign_0_wait_x_nil,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_reassign_0_wait_x_nil,
	/* state options */     (0)
	},
	{
	/* state name */        "wait_x_pv1",
	/* action function */   A_reassign_0_wait_x_pv1,
	/* event function */    E_reassign_0_wait_x_pv1,
	/* delay function */    D_reassign_0_wait_x_pv1,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_reassign_0_wait_x_pv1,
	/* state options */     (0)
	},
	{
	/* state name */        "wait_x_pv2",
	/* action function */   A_reassign_0_wait_x_pv2,
	/* event function */    E_reassign_0_wait_x_pv2,
	/* delay function */    D_reassign_0_wait_x_pv2,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_reassign_0_wait_x_pv2,
	/* state options */     (0)
	},
	{
	/* state name */        "wait_y_pv1",
	/* action function */   A_reassign_0_wait_y_pv1,
	/* event function */    E_reassign_0_wait_y_pv1,
	/* delay function */    D_reassign_0_wait_y_pv1,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_reassign_0_wait_y_pv1,
	/* state options */     (0)
	},
	{
	/* state name */        "wait_z_pv2",
	/* action function */   A_reassign_0_wait_z_pv2,
	/* event function */    E_reassign_0_wait_z_pv2,
	/* delay function */    D_reassign_0_wait_z_pv2,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_reassign_0_wait_z_pv2,
	/* state options */     (0)
	},
	{
	/* state name */        "done",
	/* action function */   A_reassign_0_done,
	/* event function */    E_reassign_0_done,
	/* delay function */    D_reassign_0_done,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_reassign_0_done,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "reassign",
	/* states */            G_reassign_states,
	/* number of states */  7,
	/* number of delays */  0
	},
};

/* Program table (global) */
seqProgram reassignTest = {
	/* magic number */      2001010,
	/* program name */      "reassignTest",
	/* channels */          G_channels,
	/* num. channels */     3,
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

#define PROG_NAME reassignTest
#include "seqMain.c"
