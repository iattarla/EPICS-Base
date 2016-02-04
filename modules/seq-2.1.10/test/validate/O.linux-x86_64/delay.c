/* Generated with snc from delay.i */

/* Program "delayTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 13 "../delay.st"
	float v;
	struct UserVar_test {
		float thr;
		float hyst;
	} UserVar_test;
	struct UserVar_ramp {
		float lo;
		float hi;
		float step;
		float dt;
		float t;
	} UserVar_ramp;
};

/* C code definitions */
# line 11 "../delay.st"
#include "errlog.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
# line 13 "../delay.st"
		0,
		{
# line 17 "../delay.st"
			5.0,
# line 18 "../delay.st"
			0.45,
		},
		{
# line 40 "../delay.st"
			4.0,
# line 41 "../delay.st"
			6.0,
# line 42 "../delay.st"
			0.1,
# line 43 "../delay.st"
			0.1,
# line 44 "../delay.st"
			0.0,
		}
	};
	*pVar = pVarInit;
}

/****** Code for state "low" in state set "test" ******/

/* Entry function for state "low" in state set "test" */
static void I_test_0_low(SS_ID ssId, struct UserVar *pVar)
{
# line 21 "../delay.st"
	errlogPrintf("state low: v = %g\n", pVar->v);
# line 22 "../delay.st"
	errlogPrintf("state low: thr = %g, hyst = %g\n", pVar->UserVar_test.thr, pVar->UserVar_test.hyst);
}

/* Delay function for state "low" in state set "test" */
static void D_test_0_low(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "low" in state set "test" */
static seqBool E_test_0_low(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 24 "../delay.st"
	if (pVar->v >= pVar->UserVar_test.thr + pVar->UserVar_test.hyst)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "low" in state set "test" */
static void A_test_0_low(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 25 "../delay.st"
			errlogPrintf("low, v = %g, transition to high\n", pVar->v);
		}
		return;
	}
}

/****** Code for state "high" in state set "test" ******/

/* Entry function for state "high" in state set "test" */
static void I_test_0_high(SS_ID ssId, struct UserVar *pVar)
{
# line 30 "../delay.st"
	errlogPrintf("state high: v = %g\n", pVar->v);
# line 31 "../delay.st"
	errlogPrintf("state high: thr = %g, hyst = %g\n", pVar->UserVar_test.thr, pVar->UserVar_test.hyst);
}

/* Delay function for state "high" in state set "test" */
static void D_test_0_high(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "high" in state set "test" */
static seqBool E_test_0_high(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 33 "../delay.st"
	if (pVar->v <= pVar->UserVar_test.thr - pVar->UserVar_test.hyst)
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "high" in state set "test" */
static void A_test_0_high(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 34 "../delay.st"
			errlogPrintf("high, v = %g, transition to low\n", pVar->v);
		}
		return;
	}
}

/****** Code for state "up" in state set "ramp" ******/

/* Delay function for state "up" in state set "ramp" */
static void D_ramp_1_up(SS_ID ssId, struct UserVar *pVar)
{
# line 51 "../delay.st"
	seq_delayInit(ssId, 0, (pVar->UserVar_ramp.dt));
}

/* Event function for state "up" in state set "ramp" */
static seqBool E_ramp_1_up(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 46 "../delay.st"
	if (pVar->v >= pVar->UserVar_ramp.hi)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
# line 51 "../delay.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "up" in state set "ramp" */
static void A_ramp_1_up(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 47 "../delay.st"
			pVar->v = pVar->UserVar_ramp.hi;
# line 48 "../delay.st"
			errlogPrintf("go down, v = %g, t = %g\n", pVar->v, pVar->UserVar_ramp.t);
# line 49 "../delay.st"
			seq_pvPut(ssId, 0/*v*/, 0);
		}
		return;
	case 1:
		{
# line 52 "../delay.st"
			pVar->UserVar_ramp.t += pVar->UserVar_ramp.dt;
# line 53 "../delay.st"
			pVar->v += pVar->UserVar_ramp.step;
# line 54 "../delay.st"
			errlogPrintf("up, v = %g, t = %g\n", pVar->v, pVar->UserVar_ramp.t);
# line 55 "../delay.st"
			seq_pvPut(ssId, 0/*v*/, 0);
		}
		return;
	}
}

/****** Code for state "down" in state set "ramp" ******/

/* Delay function for state "down" in state set "ramp" */
static void D_ramp_1_down(SS_ID ssId, struct UserVar *pVar)
{
# line 64 "../delay.st"
	seq_delayInit(ssId, 0, (pVar->UserVar_ramp.dt));
}

/* Event function for state "down" in state set "ramp" */
static seqBool E_ramp_1_down(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 59 "../delay.st"
	if (pVar->v <= pVar->UserVar_ramp.lo)
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
# line 64 "../delay.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 1;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "down" in state set "ramp" */
static void A_ramp_1_down(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 60 "../delay.st"
			pVar->v = pVar->UserVar_ramp.lo;
# line 61 "../delay.st"
			errlogPrintf("go up, v = %g, t = %g\n", pVar->v, pVar->UserVar_ramp.t);
# line 62 "../delay.st"
			seq_pvPut(ssId, 0/*v*/, 0);
		}
		return;
	case 1:
		{
# line 65 "../delay.st"
			pVar->v -= pVar->UserVar_ramp.step;
# line 66 "../delay.st"
			pVar->UserVar_ramp.t += pVar->UserVar_ramp.dt;
# line 67 "../delay.st"
			errlogPrintf("down, v = %g, t = %g\n", pVar->v, pVar->UserVar_ramp.t);
# line 68 "../delay.st"
			seq_pvPut(ssId, 0/*v*/, 0);
		}
		return;
	}
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"", offsetof(struct UserVar, v), "v", "float", 1, 1, 0, 0, 0, 0}
};

/* Event masks for state set "test" */
static const seqMask	EM_test_0_low[] = {
	0x00000002,
};
static const seqMask	EM_test_0_high[] = {
	0x00000002,
};

/* State table for state set "test" */
static seqState G_test_states[] = {
	{
	/* state name */        "low",
	/* action function */   A_test_0_low,
	/* event function */    E_test_0_low,
	/* delay function */    D_test_0_low,
	/* entry function */    I_test_0_low,
	/* exit function */     0,
	/* event mask array */  EM_test_0_low,
	/* state options */     (0)
	},
	{
	/* state name */        "high",
	/* action function */   A_test_0_high,
	/* event function */    E_test_0_high,
	/* delay function */    D_test_0_high,
	/* entry function */    I_test_0_high,
	/* exit function */     0,
	/* event mask array */  EM_test_0_high,
	/* state options */     (0)
	},
};

/* Event masks for state set "ramp" */
static const seqMask	EM_ramp_1_up[] = {
	0x00000002,
};
static const seqMask	EM_ramp_1_down[] = {
	0x00000002,
};

/* State table for state set "ramp" */
static seqState G_ramp_states[] = {
	{
	/* state name */        "up",
	/* action function */   A_ramp_1_up,
	/* event function */    E_ramp_1_up,
	/* delay function */    D_ramp_1_up,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_ramp_1_up,
	/* state options */     (0)
	},
	{
	/* state name */        "down",
	/* action function */   A_ramp_1_down,
	/* event function */    E_ramp_1_down,
	/* delay function */    D_ramp_1_down,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_ramp_1_down,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "test",
	/* states */            G_test_states,
	/* number of states */  2,
	/* number of delays */  0
	},

	{
	/* state set name */    "ramp",
	/* states */            G_ramp_states,
	/* number of states */  2,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram delayTest = {
	/* magic number */      2001010,
	/* program name */      "delayTest",
	/* channels */          G_channels,
	/* num. channels */     1,
	/* state sets */        G_state_sets,
	/* num. state sets */   2,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_SAFE | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        NULL,
	/* exit func */         NULL,
	/* num. queues */       0
};

#define PROG_NAME delayTest
#include "seqMain.c"
