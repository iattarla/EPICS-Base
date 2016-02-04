/* Generated with snc from pvGet.i */

/* Program "pvGetTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 19 "../pvGet.st"
	int anon;
	struct UserVar_read_named {
		int named;
		int expected;
		int n;
	} UserVar_read_named;
	struct UserVar_read_anon {
		int expected;
		int n;
	} UserVar_read_anon;
	struct UserVar_read_named_sync {
		int named;
		int expected;
		int n;
	} UserVar_read_named_sync;
	struct UserVar_read_anon_sync {
		int expected;
		int n;
	} UserVar_read_anon_sync;
	struct UserVar_write {
		int out;
	} UserVar_write;
};

/* C code definitions */
# line 9 "../pvGet.st"
#include "../testSupport.h"
# line 14 "../pvGet.st"
int shared = 0;
# line 15 "../pvGet.st"
epicsMutexId mutex;

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
		0,
		{
			0,
			0,
# line 35 "../pvGet.st"
			0,
		},
		{
			0,
# line 75 "../pvGet.st"
			0,
		},
		{
			0,
			0,
# line 117 "../pvGet.st"
			0,
		},
		{
			0,
# line 153 "../pvGet.st"
			0,
		},
		{
# line 188 "../pvGet.st"
			0,
		}
	};
	*pVar = pVarInit;
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 27 "../pvGet.st"
	seq_test_init(5 * 4 * 3);
# line 28 "../pvGet.st"
	mutex = epicsMutexMustCreate();
}

/****** Code for state "get" in state set "read_named" ******/

/* Delay function for state "get" in state set "read_named" */
static void D_read_named_0_get(SS_ID ssId, struct UserVar *pVar)
{
# line 41 "../pvGet.st"
	seq_delayInit(ssId, 0, (0.2));
}

/* Event function for state "get" in state set "read_named" */
static seqBool E_read_named_0_get(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 38 "../pvGet.st"
	if (pVar->UserVar_read_named.n == 5)
	{
		*pNextState = 2;
		*pTransNum = 0;
		return TRUE;
	}
# line 41 "../pvGet.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 1;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "get" in state set "read_named" */
static void A_read_named_0_get(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 39 "../pvGet.st"
			seq_efSet(ssId, 1/*ef_read_named*/);
		}
		return;
	case 1:
		{
# line 42 "../pvGet.st"
			epicsMutexMustLock(mutex);
# line 43 "../pvGet.st"
			pVar->UserVar_read_named.expected = shared;
# line 44 "../pvGet.st"
			seq_pvGet(ssId, 1/*named*/, ASYNC);
# line 45 "../pvGet.st"
			epicsMutexUnlock(mutex);
# line 46 "../pvGet.st"
			if (seq_pvGetComplete(ssId, 1/*named*/))
			{
# line 48 "../pvGet.st"
				testOk(pVar->UserVar_read_named.expected == pVar->UserVar_read_named.named, "immediate completion:      expected=%d==%d=named", pVar->UserVar_read_named.expected, pVar->UserVar_read_named.named);
			}
			else
			{
# line 50 "../pvGet.st"
				testSkip(1, "no immediate completion");
			}
# line 52 "../pvGet.st"
			epicsThreadSleep(0.1);
# line 53 "../pvGet.st"
			if (seq_pvGetComplete(ssId, 1/*named*/))
			{
# line 55 "../pvGet.st"
				testOk(pVar->UserVar_read_named.expected == pVar->UserVar_read_named.named, "completion after delay:    expected=%d==%d=named", pVar->UserVar_read_named.expected, pVar->UserVar_read_named.named);
			}
			else
			{
# line 57 "../pvGet.st"
				testSkip(1, "no completion after delay");
			}
		}
		return;
	}
}

/****** Code for state "wait" in state set "read_named" ******/

/* Delay function for state "wait" in state set "read_named" */
static void D_read_named_0_wait(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "wait" in state set "read_named" */
static seqBool E_read_named_0_wait(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 62 "../pvGet.st"
	if (seq_pvGetComplete(ssId, 1/*named*/))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait" in state set "read_named" */
static void A_read_named_0_wait(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 64 "../pvGet.st"
			testOk(pVar->UserVar_read_named.expected == pVar->UserVar_read_named.named, "completion after sync:     expected=%d==%d=named", pVar->UserVar_read_named.expected, pVar->UserVar_read_named.named);
# line 65 "../pvGet.st"
			pVar->UserVar_read_named.n++;
		}
		return;
	}
}

/****** Code for state "done" in state set "read_named" ******/

/* Delay function for state "done" in state set "read_named" */
static void D_read_named_0_done(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "done" in state set "read_named" */
static seqBool E_read_named_0_done(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 69 "../pvGet.st"
	if (FALSE)
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "done" in state set "read_named" */
static void A_read_named_0_done(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "get" in state set "read_anon" ******/

/* Delay function for state "get" in state set "read_anon" */
static void D_read_anon_1_get(SS_ID ssId, struct UserVar *pVar)
{
# line 81 "../pvGet.st"
	seq_delayInit(ssId, 0, (0.2));
}

/* Event function for state "get" in state set "read_anon" */
static seqBool E_read_anon_1_get(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 78 "../pvGet.st"
	if (pVar->UserVar_read_anon.n == 5)
	{
		*pNextState = 2;
		*pTransNum = 0;
		return TRUE;
	}
# line 81 "../pvGet.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 1;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "get" in state set "read_anon" */
static void A_read_anon_1_get(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 79 "../pvGet.st"
			seq_efSet(ssId, 2/*ef_read_anon*/);
		}
		return;
	case 1:
		{
# line 82 "../pvGet.st"
			epicsMutexMustLock(mutex);
# line 83 "../pvGet.st"
			pVar->UserVar_read_anon.expected = shared;
# line 84 "../pvGet.st"
			seq_pvGet(ssId, 0/*anon*/, ASYNC);
# line 85 "../pvGet.st"
			epicsMutexUnlock(mutex);
# line 86 "../pvGet.st"
			if (seq_pvGetComplete(ssId, 0/*anon*/))
			{
# line 88 "../pvGet.st"
				testOk(pVar->UserVar_read_anon.expected == pVar->anon, "immediate completion:      expected=%d==%d=anon", pVar->UserVar_read_anon.expected, pVar->anon);
			}
			else
			{
# line 90 "../pvGet.st"
				testSkip(1, "no immediate completion");
			}
# line 92 "../pvGet.st"
			epicsThreadSleep(0.1);
# line 93 "../pvGet.st"
			if (seq_pvGetComplete(ssId, 0/*anon*/))
			{
# line 95 "../pvGet.st"
				testOk(pVar->UserVar_read_anon.expected == pVar->anon, "completion after delay:    expected=%d==%d=anon", pVar->UserVar_read_anon.expected, pVar->anon);
			}
			else
			{
# line 97 "../pvGet.st"
				testSkip(1, "no completion after delay");
			}
		}
		return;
	}
}

/****** Code for state "wait" in state set "read_anon" ******/

/* Delay function for state "wait" in state set "read_anon" */
static void D_read_anon_1_wait(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "wait" in state set "read_anon" */
static seqBool E_read_anon_1_wait(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 102 "../pvGet.st"
	if (seq_pvGetComplete(ssId, 0/*anon*/))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait" in state set "read_anon" */
static void A_read_anon_1_wait(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 104 "../pvGet.st"
			testOk(pVar->UserVar_read_anon.expected == pVar->anon, "completion after sync:     expected=%d==%d=anon", pVar->UserVar_read_anon.expected, pVar->anon);
# line 105 "../pvGet.st"
			pVar->UserVar_read_anon.n++;
		}
		return;
	}
}

/****** Code for state "done" in state set "read_anon" ******/

/* Delay function for state "done" in state set "read_anon" */
static void D_read_anon_1_done(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "done" in state set "read_anon" */
static seqBool E_read_anon_1_done(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 109 "../pvGet.st"
	if (FALSE)
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "done" in state set "read_anon" */
static void A_read_anon_1_done(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "get" in state set "read_named_sync" ******/

/* Delay function for state "get" in state set "read_named_sync" */
static void D_read_named_sync_2_get(SS_ID ssId, struct UserVar *pVar)
{
# line 123 "../pvGet.st"
	seq_delayInit(ssId, 0, (0.2));
}

/* Event function for state "get" in state set "read_named_sync" */
static seqBool E_read_named_sync_2_get(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 120 "../pvGet.st"
	if (pVar->UserVar_read_named_sync.n == 5)
	{
		*pNextState = 2;
		*pTransNum = 0;
		return TRUE;
	}
# line 123 "../pvGet.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 1;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "get" in state set "read_named_sync" */
static void A_read_named_sync_2_get(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 121 "../pvGet.st"
			seq_efSet(ssId, 3/*ef_read_named_sync*/);
		}
		return;
	case 1:
		{
# line 124 "../pvGet.st"
			epicsMutexMustLock(mutex);
# line 125 "../pvGet.st"
			pVar->UserVar_read_named_sync.expected = shared;
# line 126 "../pvGet.st"
			seq_pvGet(ssId, 2/*named*/, SYNC);
# line 127 "../pvGet.st"
			epicsMutexUnlock(mutex);
# line 129 "../pvGet.st"
			testOk(pVar->UserVar_read_named_sync.expected == pVar->UserVar_read_named_sync.named, "synchronous get:           expected=%d==%d=named", pVar->UserVar_read_named_sync.expected, pVar->UserVar_read_named_sync.named);
# line 130 "../pvGet.st"
			epicsThreadSleep(0.1);
# line 131 "../pvGet.st"
			epicsMutexMustLock(mutex);
# line 132 "../pvGet.st"
			pVar->UserVar_read_named_sync.expected = shared;
# line 133 "../pvGet.st"
			seq_pvGet(ssId, 2/*named*/, SYNC);
# line 134 "../pvGet.st"
			epicsMutexUnlock(mutex);
# line 136 "../pvGet.st"
			testOk(pVar->UserVar_read_named_sync.expected == pVar->UserVar_read_named_sync.named, "repeat get after delay:    expected=%d==%d=named", pVar->UserVar_read_named_sync.expected, pVar->UserVar_read_named_sync.named);
		}
		return;
	}
}

/****** Code for state "wait" in state set "read_named_sync" ******/

/* Delay function for state "wait" in state set "read_named_sync" */
static void D_read_named_sync_2_wait(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "wait" in state set "read_named_sync" */
static seqBool E_read_named_sync_2_wait(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait" in state set "read_named_sync" */
static void A_read_named_sync_2_wait(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 142 "../pvGet.st"
			testOk(pVar->UserVar_read_named_sync.expected == pVar->UserVar_read_named_sync.named, "after sync:                expected=%d==%d=named", pVar->UserVar_read_named_sync.expected, pVar->UserVar_read_named_sync.named);
# line 143 "../pvGet.st"
			pVar->UserVar_read_named_sync.n++;
		}
		return;
	}
}

/****** Code for state "done" in state set "read_named_sync" ******/

/* Delay function for state "done" in state set "read_named_sync" */
static void D_read_named_sync_2_done(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "done" in state set "read_named_sync" */
static seqBool E_read_named_sync_2_done(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 147 "../pvGet.st"
	if (FALSE)
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "done" in state set "read_named_sync" */
static void A_read_named_sync_2_done(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "get" in state set "read_anon_sync" ******/

/* Delay function for state "get" in state set "read_anon_sync" */
static void D_read_anon_sync_3_get(SS_ID ssId, struct UserVar *pVar)
{
# line 159 "../pvGet.st"
	seq_delayInit(ssId, 0, (0.2));
}

/* Event function for state "get" in state set "read_anon_sync" */
static seqBool E_read_anon_sync_3_get(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 156 "../pvGet.st"
	if (pVar->UserVar_read_anon_sync.n == 5)
	{
		*pNextState = 2;
		*pTransNum = 0;
		return TRUE;
	}
# line 159 "../pvGet.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 1;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "get" in state set "read_anon_sync" */
static void A_read_anon_sync_3_get(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 157 "../pvGet.st"
			seq_efSet(ssId, 4/*ef_read_anon_sync*/);
		}
		return;
	case 1:
		{
# line 160 "../pvGet.st"
			epicsMutexMustLock(mutex);
# line 161 "../pvGet.st"
			pVar->UserVar_read_anon_sync.expected = shared;
# line 162 "../pvGet.st"
			seq_pvGet(ssId, 0/*anon*/, SYNC);
# line 163 "../pvGet.st"
			epicsMutexUnlock(mutex);
# line 165 "../pvGet.st"
			testOk(pVar->UserVar_read_anon_sync.expected == pVar->anon, "synchronous get:           expected=%d==%d=anon", pVar->UserVar_read_anon_sync.expected, pVar->anon);
# line 166 "../pvGet.st"
			epicsThreadSleep(0.1);
# line 167 "../pvGet.st"
			epicsMutexMustLock(mutex);
# line 168 "../pvGet.st"
			pVar->UserVar_read_anon_sync.expected = shared;
# line 169 "../pvGet.st"
			seq_pvGet(ssId, 0/*anon*/, SYNC);
# line 170 "../pvGet.st"
			epicsMutexUnlock(mutex);
# line 172 "../pvGet.st"
			testOk(pVar->UserVar_read_anon_sync.expected == pVar->anon, "repeat get after delay:    expected=%d==%d=anon", pVar->UserVar_read_anon_sync.expected, pVar->anon);
		}
		return;
	}
}

/****** Code for state "wait" in state set "read_anon_sync" ******/

/* Delay function for state "wait" in state set "read_anon_sync" */
static void D_read_anon_sync_3_wait(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "wait" in state set "read_anon_sync" */
static seqBool E_read_anon_sync_3_wait(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait" in state set "read_anon_sync" */
static void A_read_anon_sync_3_wait(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 178 "../pvGet.st"
			testOk(pVar->UserVar_read_anon_sync.expected == pVar->anon, "after sync:                expected=%d==%d=anon", pVar->UserVar_read_anon_sync.expected, pVar->anon);
# line 179 "../pvGet.st"
			pVar->UserVar_read_anon_sync.n++;
		}
		return;
	}
}

/****** Code for state "done" in state set "read_anon_sync" ******/

/* Delay function for state "done" in state set "read_anon_sync" */
static void D_read_anon_sync_3_done(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "done" in state set "read_anon_sync" */
static seqBool E_read_anon_sync_3_done(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 183 "../pvGet.st"
	if (FALSE)
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "done" in state set "read_anon_sync" */
static void A_read_anon_sync_3_done(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "run" in state set "write" ******/

/* Delay function for state "run" in state set "write" */
static void D_write_4_run(SS_ID ssId, struct UserVar *pVar)
{
# line 195 "../pvGet.st"
	seq_delayInit(ssId, 0, (0.07));
}

/* Event function for state "run" in state set "write" */
static seqBool E_write_4_run(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 193 "../pvGet.st"
	if (seq_efTest(ssId, 1/*ef_read_named*/) && seq_efTest(ssId, 2/*ef_read_anon*/) && seq_efTest(ssId, 3/*ef_read_named_sync*/) && seq_efTest(ssId, 4/*ef_read_anon_sync*/))
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
# line 195 "../pvGet.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 0;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "run" in state set "write" */
static void A_write_4_run(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 196 "../pvGet.st"
			epicsMutexMustLock(mutex);
# line 197 "../pvGet.st"
			shared = pVar->UserVar_write.out;
# line 198 "../pvGet.st"
			seq_pvPut(ssId, 3/*out*/, 0);
# line 199 "../pvGet.st"
			pVar->anon = pVar->UserVar_write.out;
# line 200 "../pvGet.st"
			seq_pvPut(ssId, 0/*anon*/, 0);
# line 201 "../pvGet.st"
			epicsMutexUnlock(mutex);
# line 202 "../pvGet.st"
			pVar->UserVar_write.out++;
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 208 "../pvGet.st"
	seq_test_done();
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"", offsetof(struct UserVar, anon), "anon", "int", 1, 5, 0, 0, 0, 0},
	{"pvGet1", offsetof(struct UserVar, UserVar_read_named.named), "named", "int", 1, 6, 0, 0, 0, 0},
	{"pvGet1", offsetof(struct UserVar, UserVar_read_named_sync.named), "named", "int", 1, 7, 0, 0, 0, 0},
	{"pvGet1", offsetof(struct UserVar, UserVar_write.out), "out", "int", 1, 8, 0, 0, 0, 0}
};

/* Event masks for state set "read_named" */
static const seqMask	EM_read_named_0_get[] = {
	0x00000000,
};
static const seqMask	EM_read_named_0_wait[] = {
	0x00000040,
};
static const seqMask	EM_read_named_0_done[] = {
	0x00000000,
};

/* State table for state set "read_named" */
static seqState G_read_named_states[] = {
	{
	/* state name */        "get",
	/* action function */   A_read_named_0_get,
	/* event function */    E_read_named_0_get,
	/* delay function */    D_read_named_0_get,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_read_named_0_get,
	/* state options */     (0)
	},
	{
	/* state name */        "wait",
	/* action function */   A_read_named_0_wait,
	/* event function */    E_read_named_0_wait,
	/* delay function */    D_read_named_0_wait,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_read_named_0_wait,
	/* state options */     (0)
	},
	{
	/* state name */        "done",
	/* action function */   A_read_named_0_done,
	/* event function */    E_read_named_0_done,
	/* delay function */    D_read_named_0_done,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_read_named_0_done,
	/* state options */     (0)
	},
};

/* Event masks for state set "read_anon" */
static const seqMask	EM_read_anon_1_get[] = {
	0x00000000,
};
static const seqMask	EM_read_anon_1_wait[] = {
	0x00000020,
};
static const seqMask	EM_read_anon_1_done[] = {
	0x00000000,
};

/* State table for state set "read_anon" */
static seqState G_read_anon_states[] = {
	{
	/* state name */        "get",
	/* action function */   A_read_anon_1_get,
	/* event function */    E_read_anon_1_get,
	/* delay function */    D_read_anon_1_get,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_read_anon_1_get,
	/* state options */     (0)
	},
	{
	/* state name */        "wait",
	/* action function */   A_read_anon_1_wait,
	/* event function */    E_read_anon_1_wait,
	/* delay function */    D_read_anon_1_wait,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_read_anon_1_wait,
	/* state options */     (0)
	},
	{
	/* state name */        "done",
	/* action function */   A_read_anon_1_done,
	/* event function */    E_read_anon_1_done,
	/* delay function */    D_read_anon_1_done,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_read_anon_1_done,
	/* state options */     (0)
	},
};

/* Event masks for state set "read_named_sync" */
static const seqMask	EM_read_named_sync_2_get[] = {
	0x00000000,
};
static const seqMask	EM_read_named_sync_2_wait[] = {
	0x00000000,
};
static const seqMask	EM_read_named_sync_2_done[] = {
	0x00000000,
};

/* State table for state set "read_named_sync" */
static seqState G_read_named_sync_states[] = {
	{
	/* state name */        "get",
	/* action function */   A_read_named_sync_2_get,
	/* event function */    E_read_named_sync_2_get,
	/* delay function */    D_read_named_sync_2_get,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_read_named_sync_2_get,
	/* state options */     (0)
	},
	{
	/* state name */        "wait",
	/* action function */   A_read_named_sync_2_wait,
	/* event function */    E_read_named_sync_2_wait,
	/* delay function */    D_read_named_sync_2_wait,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_read_named_sync_2_wait,
	/* state options */     (0)
	},
	{
	/* state name */        "done",
	/* action function */   A_read_named_sync_2_done,
	/* event function */    E_read_named_sync_2_done,
	/* delay function */    D_read_named_sync_2_done,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_read_named_sync_2_done,
	/* state options */     (0)
	},
};

/* Event masks for state set "read_anon_sync" */
static const seqMask	EM_read_anon_sync_3_get[] = {
	0x00000000,
};
static const seqMask	EM_read_anon_sync_3_wait[] = {
	0x00000000,
};
static const seqMask	EM_read_anon_sync_3_done[] = {
	0x00000000,
};

/* State table for state set "read_anon_sync" */
static seqState G_read_anon_sync_states[] = {
	{
	/* state name */        "get",
	/* action function */   A_read_anon_sync_3_get,
	/* event function */    E_read_anon_sync_3_get,
	/* delay function */    D_read_anon_sync_3_get,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_read_anon_sync_3_get,
	/* state options */     (0)
	},
	{
	/* state name */        "wait",
	/* action function */   A_read_anon_sync_3_wait,
	/* event function */    E_read_anon_sync_3_wait,
	/* delay function */    D_read_anon_sync_3_wait,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_read_anon_sync_3_wait,
	/* state options */     (0)
	},
	{
	/* state name */        "done",
	/* action function */   A_read_anon_sync_3_done,
	/* event function */    E_read_anon_sync_3_done,
	/* delay function */    D_read_anon_sync_3_done,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_read_anon_sync_3_done,
	/* state options */     (0)
	},
};

/* Event masks for state set "write" */
static const seqMask	EM_write_4_run[] = {
	0x0000001e,
};

/* State table for state set "write" */
static seqState G_write_states[] = {
	{
	/* state name */        "run",
	/* action function */   A_write_4_run,
	/* event function */    E_write_4_run,
	/* delay function */    D_write_4_run,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_write_4_run,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "read_named",
	/* states */            G_read_named_states,
	/* number of states */  3,
	/* number of delays */  1
	},

	{
	/* state set name */    "read_anon",
	/* states */            G_read_anon_states,
	/* number of states */  3,
	/* number of delays */  1
	},

	{
	/* state set name */    "read_named_sync",
	/* states */            G_read_named_sync_states,
	/* number of states */  3,
	/* number of delays */  1
	},

	{
	/* state set name */    "read_anon_sync",
	/* states */            G_read_anon_sync_states,
	/* number of states */  3,
	/* number of delays */  1
	},

	{
	/* state set name */    "write",
	/* states */            G_write_states,
	/* number of states */  1,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram pvGetTest = {
	/* magic number */      2001010,
	/* program name */      "pvGetTest",
	/* channels */          G_channels,
	/* num. channels */     4,
	/* state sets */        G_state_sets,
	/* num. state sets */   5,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  4,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_SAFE | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        G_prog_entry,
	/* exit func */         G_prog_exit,
	/* num. queues */       0
};

#define PROG_NAME pvGetTest
#include "seqMain.c"
