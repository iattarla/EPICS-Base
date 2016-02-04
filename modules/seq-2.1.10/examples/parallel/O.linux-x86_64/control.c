/* Generated with snc from control.i */

/* Program "control" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 19 "../control.st"
	epicsInt32 init[6];
	struct UserVar_main {
		epicsInt32 done[6];
	} UserVar_main;
};


/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
		{0,0,0,0,0,0},
		{
			{0,0,0,0,0,0},
		}
	};
	*pVar = pVarInit;
}

/****** Code for state "inactive" in state set "main" ******/

/* Delay function for state "inactive" in state set "main" */
static void D_main_0_inactive(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "inactive" in state set "main" */
static seqBool E_main_0_inactive(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "inactive" in state set "main" */
static void A_main_0_inactive(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 29 "../control.st"
			int i;

# line 30 "../control.st"
			for (i = 0; i < 6; i++)
			{
# line 31 "../control.st"
				pVar->init[i] = 1;
# line 32 "../control.st"
				seq_pvPut(ssId, 0/*init*/ + (VAR_ID)(i), ASYNC);
			}
# line 34 "../control.st"
			printf("all init commands sent\n");
		}
		return;
	}
}

/****** Code for state "active" in state set "main" ******/

/* Delay function for state "active" in state set "main" */
static void D_main_0_active(SS_ID ssId, struct UserVar *pVar)
{
# line 51 "../control.st"
	seq_delayInit(ssId, 0, (5));
}

/* Event function for state "active" in state set "main" */
static seqBool E_main_0_active(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 39 "../control.st"
	if (seq_pvPutComplete(ssId, 0/*init*/, 6, TRUE, pVar->UserVar_main.done))
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
# line 47 "../control.st"
	if (seq_pvPutComplete(ssId, 0/*init*/, 6, 0, 0))
	{
		*pNextState = 2;
		*pTransNum = 1;
		return TRUE;
	}
# line 51 "../control.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 2;
		*pTransNum = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "active" in state set "main" */
static void A_main_0_active(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 40 "../control.st"
			int i;

# line 41 "../control.st"
			printf("init commands not all done:");
# line 42 "../control.st"
			for (i = 0; i < 6; i++)
# line 43 "../control.st"
				printf(" %d", pVar->UserVar_main.done[i]);
# line 44 "../control.st"
			printf("\n");
		}
		return;
	case 1:
		{
# line 48 "../control.st"
			printf("init commands all done\n");
		}
		return;
	case 2:
		{
# line 52 "../control.st"
			printf("timeout waiting for inits to complete\n");
		}
		return;
	}
}

/****** Code for state "done" in state set "main" ******/

/* Delay function for state "done" in state set "main" */
static void D_main_0_done(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "done" in state set "main" */
static seqBool E_main_0_done(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		*pNextState = 3;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "done" in state set "main" */
static void A_main_0_done(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 58 "../control.st"
			unsigned short i;

# line 59 "../control.st"
			for (i = 0; i < 6; i++)
			{
# line 65 "../control.st"
				printf("%s: done,stat,sevr,mess = %d,%d,%d,%s\n", seq_pvName(ssId, 0/*init*/ + (VAR_ID)(i)), seq_pvPutComplete(ssId, 0/*init*/ + (VAR_ID)(i), 1, 0, 0), seq_pvStatus(ssId, 0/*init*/ + (VAR_ID)(i)), seq_pvSeverity(ssId, 0/*init*/ + (VAR_ID)(i)), seq_pvMessage(ssId, 0/*init*/ + (VAR_ID)(i)) ? seq_pvMessage(ssId, 0/*init*/ + (VAR_ID)(i)) : "");
			}
		}
		return;
	}
}

/****** Code for state "wait" in state set "main" ******/

/* Delay function for state "wait" in state set "main" */
static void D_main_0_wait(SS_ID ssId, struct UserVar *pVar)
{
# line 71 "../control.st"
	seq_delayInit(ssId, 0, (5));
}

/* Event function for state "wait" in state set "main" */
static seqBool E_main_0_wait(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 71 "../control.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait" in state set "main" */
static void A_main_0_wait(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	}
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"dcs:axeinit", offsetof(struct UserVar, init[0]), "init[0]", "epicsInt32", 1, 1, 0, 0, 0, 0},
	{"dcs:chpinit", offsetof(struct UserVar, init[1]), "init[1]", "epicsInt32", 1, 2, 0, 0, 0, 0},
	{"dcs:domeinit", offsetof(struct UserVar, init[2]), "init[2]", "epicsInt32", 1, 3, 0, 0, 0, 0},
	{"dcs:rotinit", offsetof(struct UserVar, init[3]), "init[3]", "epicsInt32", 1, 4, 0, 0, 0, 0},
	{"dcs:secinit", offsetof(struct UserVar, init[4]), "init[4]", "epicsInt32", 1, 5, 0, 0, 0, 0},
	{"dcs:tertinit", offsetof(struct UserVar, init[5]), "init[5]", "epicsInt32", 1, 6, 0, 0, 0, 0}
};

/* Event masks for state set "main" */
static const seqMask	EM_main_0_inactive[] = {
	0x00000000,
};
static const seqMask	EM_main_0_active[] = {
	0x0000007e,
};
static const seqMask	EM_main_0_done[] = {
	0x00000000,
};
static const seqMask	EM_main_0_wait[] = {
	0x00000000,
};

/* State table for state set "main" */
static seqState G_main_states[] = {
	{
	/* state name */        "inactive",
	/* action function */   A_main_0_inactive,
	/* event function */    E_main_0_inactive,
	/* delay function */    D_main_0_inactive,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_main_0_inactive,
	/* state options */     (0)
	},
	{
	/* state name */        "active",
	/* action function */   A_main_0_active,
	/* event function */    E_main_0_active,
	/* delay function */    D_main_0_active,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_main_0_active,
	/* state options */     (0)
	},
	{
	/* state name */        "done",
	/* action function */   A_main_0_done,
	/* event function */    E_main_0_done,
	/* delay function */    D_main_0_done,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_main_0_done,
	/* state options */     (0)
	},
	{
	/* state name */        "wait",
	/* action function */   A_main_0_wait,
	/* event function */    E_main_0_wait,
	/* delay function */    D_main_0_wait,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_main_0_wait,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "main",
	/* states */            G_main_states,
	/* number of states */  4,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram control = {
	/* magic number */      2001010,
	/* program name */      "control",
	/* channels */          G_channels,
	/* num. channels */     6,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        NULL,
	/* exit func */         NULL,
	/* num. queues */       0
};

#define PROG_NAME control
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void controlRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&control);
}
epicsExportRegistrar(controlRegistrar);
