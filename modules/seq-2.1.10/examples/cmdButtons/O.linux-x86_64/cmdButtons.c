/* Generated with snc from cmdButtons.i */

/* Program "seqCmdBtns" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 26 "../cmdButtons.st"
	short startBtn;
# line 27 "../cmdButtons.st"
	short stopBtn;
# line 30 "../cmdButtons.st"
	string seqMsg;
# line 33 "../cmdButtons.st"
	int ix;
};


/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
		0,
		0,
		"",
		0,
	};
	*pVar = pVarInit;
}

/****** Code for state "init" in state set "seqCmdBtns" ******/

/* Delay function for state "init" in state set "seqCmdBtns" */
static void D_seqCmdBtns_0_init(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "init" in state set "seqCmdBtns" */
static seqBool E_seqCmdBtns_0_init(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 38 "../cmdButtons.st"
	if (seq_pvConnectCount(ssId) == seq_pvChannelCount(ssId))
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "seqCmdBtns" */
static void A_seqCmdBtns_0_init(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 39 "../cmdButtons.st"
			printf("seqCmdBtns: All channels connected.\n");
# line 40 "../cmdButtons.st"
			sprintf(pVar->seqMsg, "Ready");
# line 41 "../cmdButtons.st"
			seq_pvPut(ssId, 2/*seqMsg*/, 0);
		}
		return;
	}
}

/****** Code for state "idle" in state set "seqCmdBtns" ******/

/* Delay function for state "idle" in state set "seqCmdBtns" */
static void D_seqCmdBtns_0_idle(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "idle" in state set "seqCmdBtns" */
static seqBool E_seqCmdBtns_0_idle(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 46 "../cmdButtons.st"
	if (seq_pvConnectCount(ssId) < seq_pvChannelCount(ssId))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
# line 53 "../cmdButtons.st"
	if (pVar->startBtn)
	{
		*pNextState = 2;
		*pTransNum = 1;
		return TRUE;
	}
# line 59 "../cmdButtons.st"
	if (pVar->stopBtn)
	{
		*pNextState = 1;
		*pTransNum = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "idle" in state set "seqCmdBtns" */
static void A_seqCmdBtns_0_idle(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 47 "../cmdButtons.st"
			printf("seqCmdBtns: Lost pv connection.\n");
# line 48 "../cmdButtons.st"
			sprintf(pVar->seqMsg, "Lost connection");
# line 49 "../cmdButtons.st"
			seq_pvPut(ssId, 2/*seqMsg*/, 0);
		}
		return;
	case 1:
		{
# line 54 "../cmdButtons.st"
			sprintf(pVar->seqMsg, "0 s");
# line 55 "../cmdButtons.st"
			seq_pvPut(ssId, 2/*seqMsg*/, 0);
		}
		return;
	case 2:
		{
# line 60 "../cmdButtons.st"
			pVar->stopBtn = 0;
# line 61 "../cmdButtons.st"
			seq_pvPut(ssId, 1/*stopBtn*/, 0);
		}
		return;
	}
}

/****** Code for state "start" in state set "seqCmdBtns" ******/

/* Delay function for state "start" in state set "seqCmdBtns" */
static void D_seqCmdBtns_0_start(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "start" in state set "seqCmdBtns" */
static seqBool E_seqCmdBtns_0_start(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 69 "../cmdButtons.st"
	if (pVar->startBtn)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "start" in state set "seqCmdBtns" */
static void A_seqCmdBtns_0_start(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 70 "../cmdButtons.st"
			for (pVar->ix = 1; pVar->ix <= 10; pVar->ix++)
			{
# line 71 "../cmdButtons.st"
				if (pVar->stopBtn)
				{
# line 72 "../cmdButtons.st"
					pVar->stopBtn = 0;
# line 73 "../cmdButtons.st"
					seq_pvPut(ssId, 1/*stopBtn*/, 0);
					break;
				}
				else
				{
# line 76 "../cmdButtons.st"
					epicsThreadSleep(1);
# line 77 "../cmdButtons.st"
					sprintf(pVar->seqMsg, "%d s", pVar->ix);
# line 78 "../cmdButtons.st"
					seq_pvPut(ssId, 2/*seqMsg*/, 0);
				}
			}
# line 84 "../cmdButtons.st"
			pVar->startBtn = 0;
# line 85 "../cmdButtons.st"
			seq_pvPut(ssId, 0/*startBtn*/, 0);
		}
		return;
	}
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"{P}start", offsetof(struct UserVar, startBtn), "startBtn", "short", 1, 1, 0, 1, 0, 0},
	{"{P}stop", offsetof(struct UserVar, stopBtn), "stopBtn", "short", 1, 2, 0, 1, 0, 0},
	{"{P}seqMsg", offsetof(struct UserVar, seqMsg), "seqMsg", "string", 1, 3, 0, 0, 0, 0}
};

/* Event masks for state set "seqCmdBtns" */
static const seqMask	EM_seqCmdBtns_0_init[] = {
	0x00000000,
};
static const seqMask	EM_seqCmdBtns_0_idle[] = {
	0x00000006,
};
static const seqMask	EM_seqCmdBtns_0_start[] = {
	0x00000002,
};

/* State table for state set "seqCmdBtns" */
static seqState G_seqCmdBtns_states[] = {
	{
	/* state name */        "init",
	/* action function */   A_seqCmdBtns_0_init,
	/* event function */    E_seqCmdBtns_0_init,
	/* delay function */    D_seqCmdBtns_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_seqCmdBtns_0_init,
	/* state options */     (0)
	},
	{
	/* state name */        "idle",
	/* action function */   A_seqCmdBtns_0_idle,
	/* event function */    E_seqCmdBtns_0_idle,
	/* delay function */    D_seqCmdBtns_0_idle,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_seqCmdBtns_0_idle,
	/* state options */     (0)
	},
	{
	/* state name */        "start",
	/* action function */   A_seqCmdBtns_0_start,
	/* event function */    E_seqCmdBtns_0_start,
	/* delay function */    D_seqCmdBtns_0_start,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_seqCmdBtns_0_start,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "seqCmdBtns",
	/* states */            G_seqCmdBtns_states,
	/* number of states */  3,
	/* number of delays */  0
	},
};

/* Program table (global) */
seqProgram seqCmdBtns = {
	/* magic number */      2001010,
	/* program name */      "seqCmdBtns",
	/* channels */          G_channels,
	/* num. channels */     3,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "P=cmdBtns:",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_NEWEF | OPT_REENT),
	/* init func */         G_prog_init,
	/* entry func */        NULL,
	/* exit func */         NULL,
	/* num. queues */       0
};

/* Register sequencer commands and program */
#include "epicsExport.h"
static void seqCmdBtnsRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&seqCmdBtns);
}
epicsExportRegistrar(seqCmdBtnsRegistrar);
