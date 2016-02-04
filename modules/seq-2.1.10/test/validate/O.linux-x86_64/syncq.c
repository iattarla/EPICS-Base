/* Generated with snc from syncq.i */

/* Program "syncqTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 11 "../syncq.st"
	string s[3];
# line 17 "../syncq.st"
	string s1[1];
# line 24 "../syncq.st"
	int n;
};


/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
		{"","",""},
		{""},
# line 24 "../syncq.st"
		0,
	};
	*pVar = pVarInit;
}

/****** Code for state "get" in state set "get" ******/

/* Delay function for state "get" in state set "get" */
static void D_get_0_get(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "get" in state set "get" */
static seqBool E_get_0_get(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 30 "../syncq.st"
	if (seq_pvGetQ(ssId, 0/*s*/))
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "get" in state set "get" */
static void A_get_0_get(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 31 "../syncq.st"
			printf("got: [%s,%s,%s]\n", pVar->s[0], pVar->s[1], pVar->s[2]);
		}
		return;
	}
}

/****** Code for state "pause" in state set "get" ******/

/* Delay function for state "pause" in state set "get" */
static void D_get_0_pause(SS_ID ssId, struct UserVar *pVar)
{
# line 35 "../syncq.st"
	seq_delayInit(ssId, 0, (2));
}

/* Event function for state "pause" in state set "get" */
static seqBool E_get_0_pause(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 35 "../syncq.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "pause" in state set "get" */
static void A_get_0_pause(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "get" in state set "get1" ******/

/* Delay function for state "get" in state set "get1" */
static void D_get1_1_get(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "get" in state set "get1" */
static seqBool E_get1_1_get(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 42 "../syncq.st"
	if (seq_pvGetQ(ssId, 1/*s1*/))
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "get" in state set "get1" */
static void A_get1_1_get(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 43 "../syncq.st"
			printf("got: [%s]\n", pVar->s1[0]);
		}
		return;
	}
}

/****** Code for state "pause" in state set "get1" ******/

/* Delay function for state "pause" in state set "get1" */
static void D_get1_1_pause(SS_ID ssId, struct UserVar *pVar)
{
# line 47 "../syncq.st"
	seq_delayInit(ssId, 0, (2));
}

/* Event function for state "pause" in state set "get1" */
static seqBool E_get1_1_pause(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 47 "../syncq.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "pause" in state set "get1" */
static void A_get1_1_pause(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "put" in state set "put" ******/

/* Delay function for state "put" in state set "put" */
static void D_put_2_put(SS_ID ssId, struct UserVar *pVar)
{
# line 54 "../syncq.st"
	seq_delayInit(ssId, 0, (1));
}

/* Event function for state "put" in state set "put" */
static seqBool E_put_2_put(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 54 "../syncq.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "put" in state set "put" */
static void A_put_2_put(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 55 "../syncq.st"
			sprintf(pVar->s[0], "%d", pVar->n);
# line 56 "../syncq.st"
			sprintf(pVar->s[1], "%d", -pVar->n);
# line 57 "../syncq.st"
			sprintf(pVar->s[2], "%d", 2 * pVar->n);
# line 58 "../syncq.st"
			seq_pvPut(ssId, 0/*s*/, 0);
# line 59 "../syncq.st"
			pVar->n++;
# line 60 "../syncq.st"
			seq_pvPut(ssId, 2/*n*/, 0);
		}
		return;
	}
}

/****** Code for state "idle" in state set "flush" ******/

/* Delay function for state "idle" in state set "flush" */
static void D_flush_3_idle(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "idle" in state set "flush" */
static seqBool E_flush_3_idle(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 67 "../syncq.st"
	if (pVar->n % 20 == 0)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "idle" in state set "flush" */
static void A_flush_3_idle(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 68 "../syncq.st"
			printf("flush\n");
# line 69 "../syncq.st"
			seq_pvFlushQ(ssId, 0/*s*/);
# line 70 "../syncq.st"
			seq_pvFlushQ(ssId, 1/*s1*/);
		}
		return;
	}
}

/****** Code for state "flush" in state set "flush" ******/

/* Delay function for state "flush" in state set "flush" */
static void D_flush_3_flush(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "flush" in state set "flush" */
static seqBool E_flush_3_flush(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 74 "../syncq.st"
	if (pVar->n % 20 != 0)
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "flush" in state set "flush" */
static void A_flush_3_flush(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
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
	{"syncq", offsetof(struct UserVar, s), "s", "string", 3, 3, 1, 1, 5, 0},
	{"syncq", offsetof(struct UserVar, s1), "s1", "string", 1, 4, 2, 1, 5, 1},
	{"", offsetof(struct UserVar, n), "n", "int", 1, 5, 0, 1, 0, 0}
};

/* Event masks for state set "get" */
static const seqMask	EM_get_0_get[] = {
	0x00000008,
};
static const seqMask	EM_get_0_pause[] = {
	0x00000000,
};

/* State table for state set "get" */
static seqState G_get_states[] = {
	{
	/* state name */        "get",
	/* action function */   A_get_0_get,
	/* event function */    E_get_0_get,
	/* delay function */    D_get_0_get,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_get_0_get,
	/* state options */     (0)
	},
	{
	/* state name */        "pause",
	/* action function */   A_get_0_pause,
	/* event function */    E_get_0_pause,
	/* delay function */    D_get_0_pause,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_get_0_pause,
	/* state options */     (0)
	},
};

/* Event masks for state set "get1" */
static const seqMask	EM_get1_1_get[] = {
	0x00000010,
};
static const seqMask	EM_get1_1_pause[] = {
	0x00000000,
};

/* State table for state set "get1" */
static seqState G_get1_states[] = {
	{
	/* state name */        "get",
	/* action function */   A_get1_1_get,
	/* event function */    E_get1_1_get,
	/* delay function */    D_get1_1_get,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_get1_1_get,
	/* state options */     (0)
	},
	{
	/* state name */        "pause",
	/* action function */   A_get1_1_pause,
	/* event function */    E_get1_1_pause,
	/* delay function */    D_get1_1_pause,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_get1_1_pause,
	/* state options */     (0)
	},
};

/* Event masks for state set "put" */
static const seqMask	EM_put_2_put[] = {
	0x00000000,
};

/* State table for state set "put" */
static seqState G_put_states[] = {
	{
	/* state name */        "put",
	/* action function */   A_put_2_put,
	/* event function */    E_put_2_put,
	/* delay function */    D_put_2_put,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_put_2_put,
	/* state options */     (0)
	},
};

/* Event masks for state set "flush" */
static const seqMask	EM_flush_3_idle[] = {
	0x00000020,
};
static const seqMask	EM_flush_3_flush[] = {
	0x00000020,
};

/* State table for state set "flush" */
static seqState G_flush_states[] = {
	{
	/* state name */        "idle",
	/* action function */   A_flush_3_idle,
	/* event function */    E_flush_3_idle,
	/* delay function */    D_flush_3_idle,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_flush_3_idle,
	/* state options */     (0)
	},
	{
	/* state name */        "flush",
	/* action function */   A_flush_3_flush,
	/* event function */    E_flush_3_flush,
	/* delay function */    D_flush_3_flush,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_flush_3_flush,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "get",
	/* states */            G_get_states,
	/* number of states */  2,
	/* number of delays */  1
	},

	{
	/* state set name */    "get1",
	/* states */            G_get1_states,
	/* number of states */  2,
	/* number of delays */  1
	},

	{
	/* state set name */    "put",
	/* states */            G_put_states,
	/* number of states */  1,
	/* number of delays */  1
	},

	{
	/* state set name */    "flush",
	/* states */            G_flush_states,
	/* number of states */  2,
	/* number of delays */  0
	},
};

/* Program table (global) */
seqProgram syncqTest = {
	/* magic number */      2001010,
	/* program name */      "syncqTest",
	/* channels */          G_channels,
	/* num. channels */     3,
	/* state sets */        G_state_sets,
	/* num. state sets */   4,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  2,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_SAFE | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        NULL,
	/* exit func */         NULL,
	/* num. queues */       2
};

#define PROG_NAME syncqTest
#include "seqMain.c"
