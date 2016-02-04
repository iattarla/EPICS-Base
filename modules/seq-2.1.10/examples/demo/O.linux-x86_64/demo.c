/* Generated with snc from demo.i */

/* Program "demo" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 42 "../demo.st"
	int light;
# line 45 "../demo.st"
	double lightOn;
# line 49 "../demo.st"
	double lightOff;
# line 54 "../demo.st"
	double voltage;
# line 58 "../demo.st"
	double loLimit;
# line 64 "../demo.st"
	double hiLimit;
};

/* C code definitions */
# line 36 "../demo.st"
#include "errlog.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
		0,
		0,
		0,
		0,
		0,
		0,
	};
	*pVar = pVarInit;
}

/****** Code for state "START" in state set "light" ******/

/* Delay function for state "START" in state set "light" */
static void D_light_0_START(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "START" in state set "light" */
static seqBool E_light_0_START(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "START" in state set "light" */
static void A_light_0_START(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 75 "../demo.st"
			pVar->light = 0;
# line 76 "../demo.st"
			seq_pvPut(ssId, 0/*light*/, 0);
		}
		return;
	}
}

/****** Code for state "LIGHT_OFF" in state set "light" ******/

/* Delay function for state "LIGHT_OFF" in state set "light" */
static void D_light_0_LIGHT_OFF(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "LIGHT_OFF" in state set "light" */
static seqBool E_light_0_LIGHT_OFF(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 81 "../demo.st"
	if (pVar->voltage > pVar->lightOn)
	{
		*pNextState = 2;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "LIGHT_OFF" in state set "light" */
static void A_light_0_LIGHT_OFF(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 82 "../demo.st"
			pVar->light = 1;
# line 83 "../demo.st"
			seq_pvPut(ssId, 0/*light*/, 0);
# line 84 "../demo.st"
			errlogPrintf("light_off -> light_on\n");
		}
		return;
	}
}

/****** Code for state "LIGHT_ON" in state set "light" ******/

/* Delay function for state "LIGHT_ON" in state set "light" */
static void D_light_0_LIGHT_ON(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "LIGHT_ON" in state set "light" */
static seqBool E_light_0_LIGHT_ON(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 89 "../demo.st"
	if (pVar->voltage < pVar->lightOff)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "LIGHT_ON" in state set "light" */
static void A_light_0_LIGHT_ON(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 90 "../demo.st"
			pVar->light = 0;
# line 91 "../demo.st"
			seq_pvPut(ssId, 0/*light*/, 0);
# line 92 "../demo.st"
			errlogPrintf("light_on -> light_off\n");
		}
		return;
	}
}

/****** Code for state "START" in state set "ramp" ******/

/* Delay function for state "START" in state set "ramp" */
static void D_ramp_1_START(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "START" in state set "ramp" */
static seqBool E_ramp_1_START(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "START" in state set "ramp" */
static void A_ramp_1_START(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 101 "../demo.st"
			pVar->voltage = pVar->loLimit;
# line 102 "../demo.st"
			seq_pvPut(ssId, 3/*voltage*/, 0);
# line 103 "../demo.st"
			errlogPrintf("start -> ramp_up\n");
		}
		return;
	}
}

/****** Code for state "RAMP_UP" in state set "ramp" ******/

/* Delay function for state "RAMP_UP" in state set "ramp" */
static void D_ramp_1_RAMP_UP(SS_ID ssId, struct UserVar *pVar)
{
# line 112 "../demo.st"
	seq_delayInit(ssId, 0, (0.1));
}

/* Event function for state "RAMP_UP" in state set "ramp" */
static seqBool E_ramp_1_RAMP_UP(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 108 "../demo.st"
	if (pVar->voltage > pVar->hiLimit)
	{
		*pNextState = 2;
		*pTransNum = 0;
		return TRUE;
	}
# line 112 "../demo.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 1;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "RAMP_UP" in state set "ramp" */
static void A_ramp_1_RAMP_UP(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 109 "../demo.st"
			errlogPrintf("ramp_up -> ramp_down\n");
		}
		return;
	case 1:
		{
# line 113 "../demo.st"
			pVar->voltage += 0.1;
# line 114 "../demo.st"
			if (seq_pvPut(ssId, 3/*voltage*/, 0) < 0)
# line 115 "../demo.st"
				errlogPrintf("pvPut( voltage ) failed\n");
		}
		return;
	}
}

/****** Code for state "RAMP_DOWN" in state set "ramp" ******/

/* Delay function for state "RAMP_DOWN" in state set "ramp" */
static void D_ramp_1_RAMP_DOWN(SS_ID ssId, struct UserVar *pVar)
{
# line 125 "../demo.st"
	seq_delayInit(ssId, 0, (0.1));
}

/* Event function for state "RAMP_DOWN" in state set "ramp" */
static seqBool E_ramp_1_RAMP_DOWN(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 121 "../demo.st"
	if (pVar->voltage < pVar->loLimit)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
# line 125 "../demo.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 2;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "RAMP_DOWN" in state set "ramp" */
static void A_ramp_1_RAMP_DOWN(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 122 "../demo.st"
			errlogPrintf("ramp_down -> ramp_up\n");
		}
		return;
	case 1:
		{
# line 126 "../demo.st"
			pVar->voltage -= 0.1;
# line 127 "../demo.st"
			if (seq_pvPut(ssId, 3/*voltage*/, 0) < 0)
# line 128 "../demo.st"
				errlogPrintf("pvPut( voltage ) failed\n");
		}
		return;
	}
}

/****** Code for state "START" in state set "limit" ******/

/* Delay function for state "START" in state set "limit" */
static void D_limit_2_START(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "START" in state set "limit" */
static seqBool E_limit_2_START(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 137 "../demo.st"
	if (seq_efTestAndClear(ssId, 1/*loFlag*/) && pVar->loLimit > pVar->hiLimit)
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
# line 142 "../demo.st"
	if (seq_efTestAndClear(ssId, 2/*hiFlag*/) && pVar->hiLimit < pVar->loLimit)
	{
		*pNextState = 0;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "START" in state set "limit" */
static void A_limit_2_START(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 138 "../demo.st"
			pVar->hiLimit = pVar->loLimit;
# line 139 "../demo.st"
			seq_pvPut(ssId, 5/*hiLimit*/, 0);
		}
		return;
	case 1:
		{
# line 143 "../demo.st"
			pVar->loLimit = pVar->hiLimit;
# line 144 "../demo.st"
			seq_pvPut(ssId, 4/*loLimit*/, 0);
		}
		return;
	}
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"{prefix}:light", offsetof(struct UserVar, light), "light", "int", 1, 3, 0, 0, 0, 0},
	{"{prefix}:lightOn", offsetof(struct UserVar, lightOn), "lightOn", "double", 1, 4, 0, 1, 0, 0},
	{"{prefix}:lightOff", offsetof(struct UserVar, lightOff), "lightOff", "double", 1, 5, 0, 1, 0, 0},
	{"{prefix}:voltage", offsetof(struct UserVar, voltage), "voltage", "double", 1, 6, 0, 1, 0, 0},
	{"{prefix}:loLimit", offsetof(struct UserVar, loLimit), "loLimit", "double", 1, 7, 1, 1, 0, 0},
	{"{prefix}:hiLimit", offsetof(struct UserVar, hiLimit), "hiLimit", "double", 1, 8, 2, 1, 0, 0}
};

/* Event masks for state set "light" */
static const seqMask	EM_light_0_START[] = {
	0x00000000,
};
static const seqMask	EM_light_0_LIGHT_OFF[] = {
	0x00000050,
};
static const seqMask	EM_light_0_LIGHT_ON[] = {
	0x00000060,
};

/* State table for state set "light" */
static seqState G_light_states[] = {
	{
	/* state name */        "START",
	/* action function */   A_light_0_START,
	/* event function */    E_light_0_START,
	/* delay function */    D_light_0_START,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_light_0_START,
	/* state options */     (0)
	},
	{
	/* state name */        "LIGHT_OFF",
	/* action function */   A_light_0_LIGHT_OFF,
	/* event function */    E_light_0_LIGHT_OFF,
	/* delay function */    D_light_0_LIGHT_OFF,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_light_0_LIGHT_OFF,
	/* state options */     (0)
	},
	{
	/* state name */        "LIGHT_ON",
	/* action function */   A_light_0_LIGHT_ON,
	/* event function */    E_light_0_LIGHT_ON,
	/* delay function */    D_light_0_LIGHT_ON,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_light_0_LIGHT_ON,
	/* state options */     (0)
	},
};

/* Event masks for state set "ramp" */
static const seqMask	EM_ramp_1_START[] = {
	0x00000000,
};
static const seqMask	EM_ramp_1_RAMP_UP[] = {
	0x00000140,
};
static const seqMask	EM_ramp_1_RAMP_DOWN[] = {
	0x000000c0,
};

/* State table for state set "ramp" */
static seqState G_ramp_states[] = {
	{
	/* state name */        "START",
	/* action function */   A_ramp_1_START,
	/* event function */    E_ramp_1_START,
	/* delay function */    D_ramp_1_START,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_ramp_1_START,
	/* state options */     (0)
	},
	{
	/* state name */        "RAMP_UP",
	/* action function */   A_ramp_1_RAMP_UP,
	/* event function */    E_ramp_1_RAMP_UP,
	/* delay function */    D_ramp_1_RAMP_UP,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_ramp_1_RAMP_UP,
	/* state options */     (0)
	},
	{
	/* state name */        "RAMP_DOWN",
	/* action function */   A_ramp_1_RAMP_DOWN,
	/* event function */    E_ramp_1_RAMP_DOWN,
	/* delay function */    D_ramp_1_RAMP_DOWN,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_ramp_1_RAMP_DOWN,
	/* state options */     (0)
	},
};

/* Event masks for state set "limit" */
static const seqMask	EM_limit_2_START[] = {
	0x00000186,
};

/* State table for state set "limit" */
static seqState G_limit_states[] = {
	{
	/* state name */        "START",
	/* action function */   A_limit_2_START,
	/* event function */    E_limit_2_START,
	/* delay function */    D_limit_2_START,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_limit_2_START,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "light",
	/* states */            G_light_states,
	/* number of states */  3,
	/* number of delays */  0
	},

	{
	/* state set name */    "ramp",
	/* states */            G_ramp_states,
	/* number of states */  3,
	/* number of delays */  1
	},

	{
	/* state set name */    "limit",
	/* states */            G_limit_states,
	/* number of states */  1,
	/* number of delays */  0
	},
};

/* Program table (global) */
seqProgram demo = {
	/* magic number */      2001010,
	/* program name */      "demo",
	/* channels */          G_channels,
	/* num. channels */     6,
	/* state sets */        G_state_sets,
	/* num. state sets */   3,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "pvsys=ca",
	/* num. event flags */  2,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT),
	/* init func */         G_prog_init,
	/* entry func */        NULL,
	/* exit func */         NULL,
	/* num. queues */       0
};

/* Register sequencer commands and program */
#include "epicsExport.h"
static void demoRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&demo);
}
epicsExportRegistrar(demoRegistrar);
