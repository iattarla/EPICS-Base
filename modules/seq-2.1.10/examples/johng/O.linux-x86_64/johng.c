/* Generated with snc from johng.i */

/* Program "johng" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 13 "../johng.st"
	double utc;
# line 22 "../johng.st"
	double telfocus;
# line 27 "../johng.st"
	char *ring_str;
	struct UserVar_utc {
		double telfocusSave;
		struct {
			int count;
		} UserVar_start;
	} UserVar_utc;
	struct UserVar_RING {
		struct {
			int count2;
		} UserVar_start;
	} UserVar_RING;
};


/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
		0,
		0,
# line 27 "../johng.st"
		"ring...\n",
		{
			0,
			{
# line 40 "../johng.st"
				0
			},
		},
		{
			{
# line 84 "../johng.st"
				1
			}
		}
	};
	*pVar = pVarInit;
}

/****** Code for state "start" in state set "utc" ******/

/* Delay function for state "start" in state set "utc" */
static void D_utc_0_start(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "start" in state set "utc" */
static seqBool E_utc_0_start(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 43 "../johng.st"
	if (seq_efTestAndClear(ssId, 1/*utcFlag*/))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
# line 49 "../johng.st"
	if (pVar->UserVar_utc.UserVar_start.count == 10)
	{
		*pNextState = 1;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "start" in state set "utc" */
static void A_utc_0_start(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 44 "../johng.st"
			printf("utc = %.3f\n", pVar->utc);
# line 45 "../johng.st"
			pVar->UserVar_utc.UserVar_start.count++;
		}
		return;
	case 1:
		{
# line 50 "../johng.st"
			printf("count has hit limit (telfocus = %g)\n", pVar->telfocus);
# line 51 "../johng.st"
			pVar->UserVar_utc.telfocusSave = pVar->telfocus;
# line 52 "../johng.st"
			pVar->UserVar_utc.UserVar_start.count = 0;
		}
		return;
	}
}

/****** Code for state "next" in state set "utc" ******/

/* Delay function for state "next" in state set "utc" */
static void D_utc_0_next(SS_ID ssId, struct UserVar *pVar)
{
# line 66 "../johng.st"
	seq_delayInit(ssId, 0, (5));
}

/* Event function for state "next" in state set "utc" */
static seqBool E_utc_0_next(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 60 "../johng.st"
	if (pVar->telfocus > pVar->UserVar_utc.telfocusSave)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
# line 66 "../johng.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "next" in state set "utc" */
static void A_utc_0_next(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 61 "../johng.st"
			printf("telfocus = %g\n", pVar->telfocus);
# line 62 "../johng.st"
			pVar->UserVar_utc.telfocusSave = pVar->telfocus;
		}
		return;
	case 1:
		{
# line 67 "../johng.st"
			printf("timeout (telfocus didn't increase)\n");
		}
		return;
	}
}

/****** Code for state "start" in state set "ring" ******/

/* Delay function for state "start" in state set "ring" */
static void D_ring_1_start(SS_ID ssId, struct UserVar *pVar)
{
# line 75 "../johng.st"
	seq_delayInit(ssId, 0, (1));
}

/* Event function for state "start" in state set "ring" */
static seqBool E_ring_1_start(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 75 "../johng.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "start" in state set "ring" */
static void A_ring_1_start(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 76 "../johng.st"
			printf("%s", pVar->ring_str);
		}
		return;
	}
}

/****** Code for state "start" in state set "RING" ******/

/* Entry function for state "start" in state set "RING" */
static void I_RING_2_start(SS_ID ssId, struct UserVar *pVar)
{
# line 89 "../johng.st"
	pVar->ring_str = "RING...\n";
}

/* Delay function for state "start" in state set "RING" */
static void D_RING_2_start(SS_ID ssId, struct UserVar *pVar)
{
# line 91 "../johng.st"
	seq_delayInit(ssId, 0, (pVar->UserVar_RING.UserVar_start.count2));
}

/* Event function for state "start" in state set "RING" */
static seqBool E_RING_2_start(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 91 "../johng.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "start" in state set "RING" */
static void A_RING_2_start(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 92 "../johng.st"
			printf("%s", pVar->ring_str);
# line 93 "../johng.st"
			if (pVar->UserVar_RING.UserVar_start.count2 < 16)
# line 93 "../johng.st"
				pVar->UserVar_RING.UserVar_start.count2 = 2 * pVar->UserVar_RING.UserVar_start.count2;
			else
# line 93 "../johng.st"
				pVar->UserVar_RING.UserVar_start.count2 = 1;
		}
		return;
	}
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"dcs0.utc", offsetof(struct UserVar, utc), "utc", "double", 1, 2, 1, 1, 0, 0},
	{"dcs0.telfocus", offsetof(struct UserVar, telfocus), "telfocus", "double", 1, 3, 0, 1, 0, 0}
};

/* Event masks for state set "utc" */
static const seqMask	EM_utc_0_start[] = {
	0x00000002,
};
static const seqMask	EM_utc_0_next[] = {
	0x00000008,
};

/* State table for state set "utc" */
static seqState G_utc_states[] = {
	{
	/* state name */        "start",
	/* action function */   A_utc_0_start,
	/* event function */    E_utc_0_start,
	/* delay function */    D_utc_0_start,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_utc_0_start,
	/* state options */     (0)
	},
	{
	/* state name */        "next",
	/* action function */   A_utc_0_next,
	/* event function */    E_utc_0_next,
	/* delay function */    D_utc_0_next,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_utc_0_next,
	/* state options */     (0)
	},
};

/* Event masks for state set "ring" */
static const seqMask	EM_ring_1_start[] = {
	0x00000000,
};

/* State table for state set "ring" */
static seqState G_ring_states[] = {
	{
	/* state name */        "start",
	/* action function */   A_ring_1_start,
	/* event function */    E_ring_1_start,
	/* delay function */    D_ring_1_start,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_ring_1_start,
	/* state options */     (0)
	},
};

/* Event masks for state set "RING" */
static const seqMask	EM_RING_2_start[] = {
	0x00000000,
};

/* State table for state set "RING" */
static seqState G_RING_states[] = {
	{
	/* state name */        "start",
	/* action function */   A_RING_2_start,
	/* event function */    E_RING_2_start,
	/* delay function */    D_RING_2_start,
	/* entry function */    I_RING_2_start,
	/* exit function */     0,
	/* event mask array */  EM_RING_2_start,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "utc",
	/* states */            G_utc_states,
	/* number of states */  2,
	/* number of delays */  1
	},

	{
	/* state set name */    "ring",
	/* states */            G_ring_states,
	/* number of states */  1,
	/* number of delays */  1
	},

	{
	/* state set name */    "RING",
	/* states */            G_RING_states,
	/* number of states */  1,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram johng = {
	/* magic number */      2001010,
	/* program name */      "johng",
	/* channels */          G_channels,
	/* num. channels */     2,
	/* state sets */        G_state_sets,
	/* num. state sets */   3,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  1,
	/* encoded options */   (0 | OPT_NEWEF | OPT_REENT | OPT_SAFE | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        NULL,
	/* exit func */         NULL,
	/* num. queues */       0
};

#define PROG_NAME johng
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void johngRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&johng);
}
epicsExportRegistrar(johngRegistrar);
