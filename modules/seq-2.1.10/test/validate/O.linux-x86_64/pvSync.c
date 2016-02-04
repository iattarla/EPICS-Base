/* Generated with snc from pvSync.i */

/* Program "pvSyncTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 15 "../pvSync.st"
	int x;
# line 19 "../pvSync.st"
	int i;
# line 23 "../pvSync.st"
	double a[1000];
	struct UserVar_pvSyncMonitor {
		struct {
			int y;
		} UserVar_idle;
	} UserVar_pvSyncMonitor;
};

/* C code definitions */
# line 9 "../pvSync.st"
#include "../testSupport.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
# line 15 "../pvSync.st"
		0,
		0,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{
			{
# line 53 "../pvSync.st"
				0
			}
		},
	};
	*pVar = pVarInit;
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 34 "../pvSync.st"
	seq_test_init(4 * 1000);
# line 35 "../pvSync.st"
	seq_pvSync(ssId, 0/*x*/, 1/*ef_x*/);
# line 36 "../pvSync.st"
	seq_efSet(ssId, 4/*ef_putx*/);
# line 37 "../pvSync.st"
	seq_efClear(ssId, 3/*ef_i*/);
# line 38 "../pvSync.st"
	seq_efClear(ssId, 2/*ef_a*/);
}

/****** Code for state "one" in state set "pvSyncPut" ******/

/* Delay function for state "one" in state set "pvSyncPut" */
static void D_pvSyncPut_0_one(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "one" in state set "pvSyncPut" */
static seqBool E_pvSyncPut_0_one(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 43 "../pvSync.st"
	if (seq_efTestAndClear(ssId, 4/*ef_putx*/))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "one" in state set "pvSyncPut" */
static void A_pvSyncPut_0_one(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 44 "../pvSync.st"
			pVar->x++;
# line 45 "../pvSync.st"
			testDiag("set: x=%d", pVar->x);
# line 46 "../pvSync.st"
			seq_pvPut(ssId, 0/*x*/, 0);
		}
		return;
	}
}

/****** Code for state "idle" in state set "pvSyncMonitor" ******/

/* Delay function for state "idle" in state set "pvSyncMonitor" */
static void D_pvSyncMonitor_1_idle(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "idle" in state set "pvSyncMonitor" */
static seqBool E_pvSyncMonitor_1_idle(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 54 "../pvSync.st"
	if (seq_efTestAndClear(ssId, 1/*ef_x*/))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "idle" in state set "pvSyncMonitor" */
static void A_pvSyncMonitor_1_idle(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 55 "../pvSync.st"
			pVar->UserVar_pvSyncMonitor.UserVar_idle.y++;
# line 56 "../pvSync.st"
			testDiag("test: x=%d", pVar->x);
# line 57 "../pvSync.st"
			testOk(pVar->x == pVar->UserVar_pvSyncMonitor.UserVar_idle.y, "test: x=%d==%d=y", pVar->x, pVar->UserVar_pvSyncMonitor.UserVar_idle.y);
# line 58 "../pvSync.st"
			pVar->i = pVar->x - 1;
# line 59 "../pvSync.st"
			seq_pvPut(ssId, 1/*i*/, 0);
		}
		return;
	}
}

/****** Code for state "pvSync" in state set "pvSyncY" ******/

/* Delay function for state "pvSync" in state set "pvSyncY" */
static void D_pvSyncY_2_pvSync(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "pvSync" in state set "pvSyncY" */
static seqBool E_pvSyncY_2_pvSync(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 66 "../pvSync.st"
	if (seq_efTestAndClear(ssId, 3/*ef_i*/))
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "pvSync" in state set "pvSyncY" */
static void A_pvSyncY_2_pvSync(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 67 "../pvSync.st"
			testPass("event on i=%d", pVar->i);
# line 68 "../pvSync.st"
			seq_pvSync(ssId, 2/*a*/, 2/*ef_a*/);
# line 69 "../pvSync.st"
			testDiag("after pvSync(a, ef_a)");
# line 70 "../pvSync.st"
			pVar->a[pVar->i] = pVar->i;
# line 71 "../pvSync.st"
			testOk1(seq_pvPut(ssId, 2/*a*/, 0) == pvStatOK);
# line 72 "../pvSync.st"
			testDiag("after pvPut(a[i])");
		}
		return;
	}
}

/****** Code for state "pvUnsync" in state set "pvSyncY" ******/

/* Delay function for state "pvUnsync" in state set "pvSyncY" */
static void D_pvSyncY_2_pvUnsync(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "pvUnsync" in state set "pvSyncY" */
static seqBool E_pvSyncY_2_pvUnsync(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 76 "../pvSync.st"
	if (seq_efTestAndClear(ssId, 2/*ef_a*/) && testOk1(pVar->a[pVar->i] == pVar->i))
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "pvUnsync" in state set "pvSyncY" */
static void A_pvSyncY_2_pvUnsync(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 80 "../pvSync.st"
			if (pVar->i >= 1000 - 1)
			{
				{*pNextState = 2; return;}
			}
# line 83 "../pvSync.st"
			seq_pvSync(ssId, 2/*a*/, NOEVFLAG);
# line 84 "../pvSync.st"
			seq_efSet(ssId, 4/*ef_putx*/);
		}
		return;
	}
}

/****** Code for state "done" in state set "pvSyncY" ******/

/* Delay function for state "done" in state set "pvSyncY" */
static void D_pvSyncY_2_done(SS_ID ssId, struct UserVar *pVar)
{
# line 88 "../pvSync.st"
	seq_delayInit(ssId, 0, (0.5));
}

/* Event function for state "done" in state set "pvSyncY" */
static seqBool E_pvSyncY_2_done(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 88 "../pvSync.st"
	if (seq_delay(ssId, 0))
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "done" in state set "pvSyncY" */
static void A_pvSyncY_2_done(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 94 "../pvSync.st"
	seq_test_done();
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"", offsetof(struct UserVar, x), "x", "int", 1, 5, 0, 1, 0, 0},
	{"", offsetof(struct UserVar, i), "i", "int", 1, 6, 3, 1, 0, 0},
	{"", offsetof(struct UserVar, a[0]), "a[0]", "double", 1, 7, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[1]), "a[1]", "double", 1, 8, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[2]), "a[2]", "double", 1, 9, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[3]), "a[3]", "double", 1, 10, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[4]), "a[4]", "double", 1, 11, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[5]), "a[5]", "double", 1, 12, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[6]), "a[6]", "double", 1, 13, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[7]), "a[7]", "double", 1, 14, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[8]), "a[8]", "double", 1, 15, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[9]), "a[9]", "double", 1, 16, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[10]), "a[10]", "double", 1, 17, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[11]), "a[11]", "double", 1, 18, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[12]), "a[12]", "double", 1, 19, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[13]), "a[13]", "double", 1, 20, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[14]), "a[14]", "double", 1, 21, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[15]), "a[15]", "double", 1, 22, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[16]), "a[16]", "double", 1, 23, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[17]), "a[17]", "double", 1, 24, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[18]), "a[18]", "double", 1, 25, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[19]), "a[19]", "double", 1, 26, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[20]), "a[20]", "double", 1, 27, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[21]), "a[21]", "double", 1, 28, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[22]), "a[22]", "double", 1, 29, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[23]), "a[23]", "double", 1, 30, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[24]), "a[24]", "double", 1, 31, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[25]), "a[25]", "double", 1, 32, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[26]), "a[26]", "double", 1, 33, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[27]), "a[27]", "double", 1, 34, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[28]), "a[28]", "double", 1, 35, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[29]), "a[29]", "double", 1, 36, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[30]), "a[30]", "double", 1, 37, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[31]), "a[31]", "double", 1, 38, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[32]), "a[32]", "double", 1, 39, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[33]), "a[33]", "double", 1, 40, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[34]), "a[34]", "double", 1, 41, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[35]), "a[35]", "double", 1, 42, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[36]), "a[36]", "double", 1, 43, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[37]), "a[37]", "double", 1, 44, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[38]), "a[38]", "double", 1, 45, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[39]), "a[39]", "double", 1, 46, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[40]), "a[40]", "double", 1, 47, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[41]), "a[41]", "double", 1, 48, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[42]), "a[42]", "double", 1, 49, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[43]), "a[43]", "double", 1, 50, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[44]), "a[44]", "double", 1, 51, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[45]), "a[45]", "double", 1, 52, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[46]), "a[46]", "double", 1, 53, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[47]), "a[47]", "double", 1, 54, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[48]), "a[48]", "double", 1, 55, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[49]), "a[49]", "double", 1, 56, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[50]), "a[50]", "double", 1, 57, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[51]), "a[51]", "double", 1, 58, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[52]), "a[52]", "double", 1, 59, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[53]), "a[53]", "double", 1, 60, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[54]), "a[54]", "double", 1, 61, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[55]), "a[55]", "double", 1, 62, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[56]), "a[56]", "double", 1, 63, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[57]), "a[57]", "double", 1, 64, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[58]), "a[58]", "double", 1, 65, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[59]), "a[59]", "double", 1, 66, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[60]), "a[60]", "double", 1, 67, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[61]), "a[61]", "double", 1, 68, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[62]), "a[62]", "double", 1, 69, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[63]), "a[63]", "double", 1, 70, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[64]), "a[64]", "double", 1, 71, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[65]), "a[65]", "double", 1, 72, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[66]), "a[66]", "double", 1, 73, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[67]), "a[67]", "double", 1, 74, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[68]), "a[68]", "double", 1, 75, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[69]), "a[69]", "double", 1, 76, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[70]), "a[70]", "double", 1, 77, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[71]), "a[71]", "double", 1, 78, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[72]), "a[72]", "double", 1, 79, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[73]), "a[73]", "double", 1, 80, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[74]), "a[74]", "double", 1, 81, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[75]), "a[75]", "double", 1, 82, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[76]), "a[76]", "double", 1, 83, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[77]), "a[77]", "double", 1, 84, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[78]), "a[78]", "double", 1, 85, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[79]), "a[79]", "double", 1, 86, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[80]), "a[80]", "double", 1, 87, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[81]), "a[81]", "double", 1, 88, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[82]), "a[82]", "double", 1, 89, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[83]), "a[83]", "double", 1, 90, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[84]), "a[84]", "double", 1, 91, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[85]), "a[85]", "double", 1, 92, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[86]), "a[86]", "double", 1, 93, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[87]), "a[87]", "double", 1, 94, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[88]), "a[88]", "double", 1, 95, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[89]), "a[89]", "double", 1, 96, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[90]), "a[90]", "double", 1, 97, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[91]), "a[91]", "double", 1, 98, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[92]), "a[92]", "double", 1, 99, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[93]), "a[93]", "double", 1, 100, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[94]), "a[94]", "double", 1, 101, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[95]), "a[95]", "double", 1, 102, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[96]), "a[96]", "double", 1, 103, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[97]), "a[97]", "double", 1, 104, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[98]), "a[98]", "double", 1, 105, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[99]), "a[99]", "double", 1, 106, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[100]), "a[100]", "double", 1, 107, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[101]), "a[101]", "double", 1, 108, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[102]), "a[102]", "double", 1, 109, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[103]), "a[103]", "double", 1, 110, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[104]), "a[104]", "double", 1, 111, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[105]), "a[105]", "double", 1, 112, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[106]), "a[106]", "double", 1, 113, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[107]), "a[107]", "double", 1, 114, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[108]), "a[108]", "double", 1, 115, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[109]), "a[109]", "double", 1, 116, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[110]), "a[110]", "double", 1, 117, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[111]), "a[111]", "double", 1, 118, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[112]), "a[112]", "double", 1, 119, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[113]), "a[113]", "double", 1, 120, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[114]), "a[114]", "double", 1, 121, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[115]), "a[115]", "double", 1, 122, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[116]), "a[116]", "double", 1, 123, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[117]), "a[117]", "double", 1, 124, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[118]), "a[118]", "double", 1, 125, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[119]), "a[119]", "double", 1, 126, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[120]), "a[120]", "double", 1, 127, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[121]), "a[121]", "double", 1, 128, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[122]), "a[122]", "double", 1, 129, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[123]), "a[123]", "double", 1, 130, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[124]), "a[124]", "double", 1, 131, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[125]), "a[125]", "double", 1, 132, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[126]), "a[126]", "double", 1, 133, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[127]), "a[127]", "double", 1, 134, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[128]), "a[128]", "double", 1, 135, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[129]), "a[129]", "double", 1, 136, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[130]), "a[130]", "double", 1, 137, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[131]), "a[131]", "double", 1, 138, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[132]), "a[132]", "double", 1, 139, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[133]), "a[133]", "double", 1, 140, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[134]), "a[134]", "double", 1, 141, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[135]), "a[135]", "double", 1, 142, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[136]), "a[136]", "double", 1, 143, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[137]), "a[137]", "double", 1, 144, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[138]), "a[138]", "double", 1, 145, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[139]), "a[139]", "double", 1, 146, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[140]), "a[140]", "double", 1, 147, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[141]), "a[141]", "double", 1, 148, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[142]), "a[142]", "double", 1, 149, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[143]), "a[143]", "double", 1, 150, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[144]), "a[144]", "double", 1, 151, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[145]), "a[145]", "double", 1, 152, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[146]), "a[146]", "double", 1, 153, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[147]), "a[147]", "double", 1, 154, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[148]), "a[148]", "double", 1, 155, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[149]), "a[149]", "double", 1, 156, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[150]), "a[150]", "double", 1, 157, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[151]), "a[151]", "double", 1, 158, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[152]), "a[152]", "double", 1, 159, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[153]), "a[153]", "double", 1, 160, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[154]), "a[154]", "double", 1, 161, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[155]), "a[155]", "double", 1, 162, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[156]), "a[156]", "double", 1, 163, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[157]), "a[157]", "double", 1, 164, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[158]), "a[158]", "double", 1, 165, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[159]), "a[159]", "double", 1, 166, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[160]), "a[160]", "double", 1, 167, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[161]), "a[161]", "double", 1, 168, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[162]), "a[162]", "double", 1, 169, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[163]), "a[163]", "double", 1, 170, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[164]), "a[164]", "double", 1, 171, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[165]), "a[165]", "double", 1, 172, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[166]), "a[166]", "double", 1, 173, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[167]), "a[167]", "double", 1, 174, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[168]), "a[168]", "double", 1, 175, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[169]), "a[169]", "double", 1, 176, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[170]), "a[170]", "double", 1, 177, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[171]), "a[171]", "double", 1, 178, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[172]), "a[172]", "double", 1, 179, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[173]), "a[173]", "double", 1, 180, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[174]), "a[174]", "double", 1, 181, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[175]), "a[175]", "double", 1, 182, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[176]), "a[176]", "double", 1, 183, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[177]), "a[177]", "double", 1, 184, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[178]), "a[178]", "double", 1, 185, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[179]), "a[179]", "double", 1, 186, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[180]), "a[180]", "double", 1, 187, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[181]), "a[181]", "double", 1, 188, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[182]), "a[182]", "double", 1, 189, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[183]), "a[183]", "double", 1, 190, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[184]), "a[184]", "double", 1, 191, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[185]), "a[185]", "double", 1, 192, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[186]), "a[186]", "double", 1, 193, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[187]), "a[187]", "double", 1, 194, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[188]), "a[188]", "double", 1, 195, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[189]), "a[189]", "double", 1, 196, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[190]), "a[190]", "double", 1, 197, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[191]), "a[191]", "double", 1, 198, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[192]), "a[192]", "double", 1, 199, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[193]), "a[193]", "double", 1, 200, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[194]), "a[194]", "double", 1, 201, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[195]), "a[195]", "double", 1, 202, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[196]), "a[196]", "double", 1, 203, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[197]), "a[197]", "double", 1, 204, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[198]), "a[198]", "double", 1, 205, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[199]), "a[199]", "double", 1, 206, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[200]), "a[200]", "double", 1, 207, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[201]), "a[201]", "double", 1, 208, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[202]), "a[202]", "double", 1, 209, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[203]), "a[203]", "double", 1, 210, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[204]), "a[204]", "double", 1, 211, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[205]), "a[205]", "double", 1, 212, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[206]), "a[206]", "double", 1, 213, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[207]), "a[207]", "double", 1, 214, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[208]), "a[208]", "double", 1, 215, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[209]), "a[209]", "double", 1, 216, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[210]), "a[210]", "double", 1, 217, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[211]), "a[211]", "double", 1, 218, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[212]), "a[212]", "double", 1, 219, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[213]), "a[213]", "double", 1, 220, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[214]), "a[214]", "double", 1, 221, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[215]), "a[215]", "double", 1, 222, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[216]), "a[216]", "double", 1, 223, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[217]), "a[217]", "double", 1, 224, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[218]), "a[218]", "double", 1, 225, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[219]), "a[219]", "double", 1, 226, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[220]), "a[220]", "double", 1, 227, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[221]), "a[221]", "double", 1, 228, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[222]), "a[222]", "double", 1, 229, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[223]), "a[223]", "double", 1, 230, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[224]), "a[224]", "double", 1, 231, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[225]), "a[225]", "double", 1, 232, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[226]), "a[226]", "double", 1, 233, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[227]), "a[227]", "double", 1, 234, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[228]), "a[228]", "double", 1, 235, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[229]), "a[229]", "double", 1, 236, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[230]), "a[230]", "double", 1, 237, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[231]), "a[231]", "double", 1, 238, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[232]), "a[232]", "double", 1, 239, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[233]), "a[233]", "double", 1, 240, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[234]), "a[234]", "double", 1, 241, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[235]), "a[235]", "double", 1, 242, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[236]), "a[236]", "double", 1, 243, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[237]), "a[237]", "double", 1, 244, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[238]), "a[238]", "double", 1, 245, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[239]), "a[239]", "double", 1, 246, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[240]), "a[240]", "double", 1, 247, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[241]), "a[241]", "double", 1, 248, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[242]), "a[242]", "double", 1, 249, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[243]), "a[243]", "double", 1, 250, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[244]), "a[244]", "double", 1, 251, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[245]), "a[245]", "double", 1, 252, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[246]), "a[246]", "double", 1, 253, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[247]), "a[247]", "double", 1, 254, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[248]), "a[248]", "double", 1, 255, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[249]), "a[249]", "double", 1, 256, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[250]), "a[250]", "double", 1, 257, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[251]), "a[251]", "double", 1, 258, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[252]), "a[252]", "double", 1, 259, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[253]), "a[253]", "double", 1, 260, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[254]), "a[254]", "double", 1, 261, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[255]), "a[255]", "double", 1, 262, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[256]), "a[256]", "double", 1, 263, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[257]), "a[257]", "double", 1, 264, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[258]), "a[258]", "double", 1, 265, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[259]), "a[259]", "double", 1, 266, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[260]), "a[260]", "double", 1, 267, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[261]), "a[261]", "double", 1, 268, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[262]), "a[262]", "double", 1, 269, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[263]), "a[263]", "double", 1, 270, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[264]), "a[264]", "double", 1, 271, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[265]), "a[265]", "double", 1, 272, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[266]), "a[266]", "double", 1, 273, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[267]), "a[267]", "double", 1, 274, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[268]), "a[268]", "double", 1, 275, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[269]), "a[269]", "double", 1, 276, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[270]), "a[270]", "double", 1, 277, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[271]), "a[271]", "double", 1, 278, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[272]), "a[272]", "double", 1, 279, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[273]), "a[273]", "double", 1, 280, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[274]), "a[274]", "double", 1, 281, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[275]), "a[275]", "double", 1, 282, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[276]), "a[276]", "double", 1, 283, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[277]), "a[277]", "double", 1, 284, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[278]), "a[278]", "double", 1, 285, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[279]), "a[279]", "double", 1, 286, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[280]), "a[280]", "double", 1, 287, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[281]), "a[281]", "double", 1, 288, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[282]), "a[282]", "double", 1, 289, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[283]), "a[283]", "double", 1, 290, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[284]), "a[284]", "double", 1, 291, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[285]), "a[285]", "double", 1, 292, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[286]), "a[286]", "double", 1, 293, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[287]), "a[287]", "double", 1, 294, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[288]), "a[288]", "double", 1, 295, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[289]), "a[289]", "double", 1, 296, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[290]), "a[290]", "double", 1, 297, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[291]), "a[291]", "double", 1, 298, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[292]), "a[292]", "double", 1, 299, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[293]), "a[293]", "double", 1, 300, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[294]), "a[294]", "double", 1, 301, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[295]), "a[295]", "double", 1, 302, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[296]), "a[296]", "double", 1, 303, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[297]), "a[297]", "double", 1, 304, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[298]), "a[298]", "double", 1, 305, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[299]), "a[299]", "double", 1, 306, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[300]), "a[300]", "double", 1, 307, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[301]), "a[301]", "double", 1, 308, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[302]), "a[302]", "double", 1, 309, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[303]), "a[303]", "double", 1, 310, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[304]), "a[304]", "double", 1, 311, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[305]), "a[305]", "double", 1, 312, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[306]), "a[306]", "double", 1, 313, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[307]), "a[307]", "double", 1, 314, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[308]), "a[308]", "double", 1, 315, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[309]), "a[309]", "double", 1, 316, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[310]), "a[310]", "double", 1, 317, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[311]), "a[311]", "double", 1, 318, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[312]), "a[312]", "double", 1, 319, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[313]), "a[313]", "double", 1, 320, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[314]), "a[314]", "double", 1, 321, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[315]), "a[315]", "double", 1, 322, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[316]), "a[316]", "double", 1, 323, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[317]), "a[317]", "double", 1, 324, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[318]), "a[318]", "double", 1, 325, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[319]), "a[319]", "double", 1, 326, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[320]), "a[320]", "double", 1, 327, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[321]), "a[321]", "double", 1, 328, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[322]), "a[322]", "double", 1, 329, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[323]), "a[323]", "double", 1, 330, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[324]), "a[324]", "double", 1, 331, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[325]), "a[325]", "double", 1, 332, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[326]), "a[326]", "double", 1, 333, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[327]), "a[327]", "double", 1, 334, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[328]), "a[328]", "double", 1, 335, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[329]), "a[329]", "double", 1, 336, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[330]), "a[330]", "double", 1, 337, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[331]), "a[331]", "double", 1, 338, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[332]), "a[332]", "double", 1, 339, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[333]), "a[333]", "double", 1, 340, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[334]), "a[334]", "double", 1, 341, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[335]), "a[335]", "double", 1, 342, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[336]), "a[336]", "double", 1, 343, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[337]), "a[337]", "double", 1, 344, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[338]), "a[338]", "double", 1, 345, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[339]), "a[339]", "double", 1, 346, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[340]), "a[340]", "double", 1, 347, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[341]), "a[341]", "double", 1, 348, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[342]), "a[342]", "double", 1, 349, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[343]), "a[343]", "double", 1, 350, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[344]), "a[344]", "double", 1, 351, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[345]), "a[345]", "double", 1, 352, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[346]), "a[346]", "double", 1, 353, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[347]), "a[347]", "double", 1, 354, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[348]), "a[348]", "double", 1, 355, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[349]), "a[349]", "double", 1, 356, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[350]), "a[350]", "double", 1, 357, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[351]), "a[351]", "double", 1, 358, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[352]), "a[352]", "double", 1, 359, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[353]), "a[353]", "double", 1, 360, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[354]), "a[354]", "double", 1, 361, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[355]), "a[355]", "double", 1, 362, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[356]), "a[356]", "double", 1, 363, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[357]), "a[357]", "double", 1, 364, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[358]), "a[358]", "double", 1, 365, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[359]), "a[359]", "double", 1, 366, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[360]), "a[360]", "double", 1, 367, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[361]), "a[361]", "double", 1, 368, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[362]), "a[362]", "double", 1, 369, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[363]), "a[363]", "double", 1, 370, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[364]), "a[364]", "double", 1, 371, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[365]), "a[365]", "double", 1, 372, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[366]), "a[366]", "double", 1, 373, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[367]), "a[367]", "double", 1, 374, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[368]), "a[368]", "double", 1, 375, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[369]), "a[369]", "double", 1, 376, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[370]), "a[370]", "double", 1, 377, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[371]), "a[371]", "double", 1, 378, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[372]), "a[372]", "double", 1, 379, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[373]), "a[373]", "double", 1, 380, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[374]), "a[374]", "double", 1, 381, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[375]), "a[375]", "double", 1, 382, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[376]), "a[376]", "double", 1, 383, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[377]), "a[377]", "double", 1, 384, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[378]), "a[378]", "double", 1, 385, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[379]), "a[379]", "double", 1, 386, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[380]), "a[380]", "double", 1, 387, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[381]), "a[381]", "double", 1, 388, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[382]), "a[382]", "double", 1, 389, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[383]), "a[383]", "double", 1, 390, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[384]), "a[384]", "double", 1, 391, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[385]), "a[385]", "double", 1, 392, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[386]), "a[386]", "double", 1, 393, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[387]), "a[387]", "double", 1, 394, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[388]), "a[388]", "double", 1, 395, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[389]), "a[389]", "double", 1, 396, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[390]), "a[390]", "double", 1, 397, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[391]), "a[391]", "double", 1, 398, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[392]), "a[392]", "double", 1, 399, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[393]), "a[393]", "double", 1, 400, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[394]), "a[394]", "double", 1, 401, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[395]), "a[395]", "double", 1, 402, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[396]), "a[396]", "double", 1, 403, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[397]), "a[397]", "double", 1, 404, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[398]), "a[398]", "double", 1, 405, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[399]), "a[399]", "double", 1, 406, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[400]), "a[400]", "double", 1, 407, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[401]), "a[401]", "double", 1, 408, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[402]), "a[402]", "double", 1, 409, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[403]), "a[403]", "double", 1, 410, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[404]), "a[404]", "double", 1, 411, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[405]), "a[405]", "double", 1, 412, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[406]), "a[406]", "double", 1, 413, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[407]), "a[407]", "double", 1, 414, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[408]), "a[408]", "double", 1, 415, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[409]), "a[409]", "double", 1, 416, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[410]), "a[410]", "double", 1, 417, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[411]), "a[411]", "double", 1, 418, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[412]), "a[412]", "double", 1, 419, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[413]), "a[413]", "double", 1, 420, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[414]), "a[414]", "double", 1, 421, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[415]), "a[415]", "double", 1, 422, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[416]), "a[416]", "double", 1, 423, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[417]), "a[417]", "double", 1, 424, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[418]), "a[418]", "double", 1, 425, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[419]), "a[419]", "double", 1, 426, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[420]), "a[420]", "double", 1, 427, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[421]), "a[421]", "double", 1, 428, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[422]), "a[422]", "double", 1, 429, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[423]), "a[423]", "double", 1, 430, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[424]), "a[424]", "double", 1, 431, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[425]), "a[425]", "double", 1, 432, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[426]), "a[426]", "double", 1, 433, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[427]), "a[427]", "double", 1, 434, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[428]), "a[428]", "double", 1, 435, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[429]), "a[429]", "double", 1, 436, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[430]), "a[430]", "double", 1, 437, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[431]), "a[431]", "double", 1, 438, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[432]), "a[432]", "double", 1, 439, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[433]), "a[433]", "double", 1, 440, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[434]), "a[434]", "double", 1, 441, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[435]), "a[435]", "double", 1, 442, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[436]), "a[436]", "double", 1, 443, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[437]), "a[437]", "double", 1, 444, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[438]), "a[438]", "double", 1, 445, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[439]), "a[439]", "double", 1, 446, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[440]), "a[440]", "double", 1, 447, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[441]), "a[441]", "double", 1, 448, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[442]), "a[442]", "double", 1, 449, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[443]), "a[443]", "double", 1, 450, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[444]), "a[444]", "double", 1, 451, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[445]), "a[445]", "double", 1, 452, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[446]), "a[446]", "double", 1, 453, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[447]), "a[447]", "double", 1, 454, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[448]), "a[448]", "double", 1, 455, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[449]), "a[449]", "double", 1, 456, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[450]), "a[450]", "double", 1, 457, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[451]), "a[451]", "double", 1, 458, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[452]), "a[452]", "double", 1, 459, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[453]), "a[453]", "double", 1, 460, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[454]), "a[454]", "double", 1, 461, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[455]), "a[455]", "double", 1, 462, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[456]), "a[456]", "double", 1, 463, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[457]), "a[457]", "double", 1, 464, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[458]), "a[458]", "double", 1, 465, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[459]), "a[459]", "double", 1, 466, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[460]), "a[460]", "double", 1, 467, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[461]), "a[461]", "double", 1, 468, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[462]), "a[462]", "double", 1, 469, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[463]), "a[463]", "double", 1, 470, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[464]), "a[464]", "double", 1, 471, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[465]), "a[465]", "double", 1, 472, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[466]), "a[466]", "double", 1, 473, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[467]), "a[467]", "double", 1, 474, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[468]), "a[468]", "double", 1, 475, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[469]), "a[469]", "double", 1, 476, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[470]), "a[470]", "double", 1, 477, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[471]), "a[471]", "double", 1, 478, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[472]), "a[472]", "double", 1, 479, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[473]), "a[473]", "double", 1, 480, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[474]), "a[474]", "double", 1, 481, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[475]), "a[475]", "double", 1, 482, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[476]), "a[476]", "double", 1, 483, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[477]), "a[477]", "double", 1, 484, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[478]), "a[478]", "double", 1, 485, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[479]), "a[479]", "double", 1, 486, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[480]), "a[480]", "double", 1, 487, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[481]), "a[481]", "double", 1, 488, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[482]), "a[482]", "double", 1, 489, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[483]), "a[483]", "double", 1, 490, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[484]), "a[484]", "double", 1, 491, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[485]), "a[485]", "double", 1, 492, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[486]), "a[486]", "double", 1, 493, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[487]), "a[487]", "double", 1, 494, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[488]), "a[488]", "double", 1, 495, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[489]), "a[489]", "double", 1, 496, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[490]), "a[490]", "double", 1, 497, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[491]), "a[491]", "double", 1, 498, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[492]), "a[492]", "double", 1, 499, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[493]), "a[493]", "double", 1, 500, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[494]), "a[494]", "double", 1, 501, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[495]), "a[495]", "double", 1, 502, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[496]), "a[496]", "double", 1, 503, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[497]), "a[497]", "double", 1, 504, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[498]), "a[498]", "double", 1, 505, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[499]), "a[499]", "double", 1, 506, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[500]), "a[500]", "double", 1, 507, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[501]), "a[501]", "double", 1, 508, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[502]), "a[502]", "double", 1, 509, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[503]), "a[503]", "double", 1, 510, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[504]), "a[504]", "double", 1, 511, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[505]), "a[505]", "double", 1, 512, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[506]), "a[506]", "double", 1, 513, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[507]), "a[507]", "double", 1, 514, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[508]), "a[508]", "double", 1, 515, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[509]), "a[509]", "double", 1, 516, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[510]), "a[510]", "double", 1, 517, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[511]), "a[511]", "double", 1, 518, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[512]), "a[512]", "double", 1, 519, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[513]), "a[513]", "double", 1, 520, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[514]), "a[514]", "double", 1, 521, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[515]), "a[515]", "double", 1, 522, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[516]), "a[516]", "double", 1, 523, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[517]), "a[517]", "double", 1, 524, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[518]), "a[518]", "double", 1, 525, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[519]), "a[519]", "double", 1, 526, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[520]), "a[520]", "double", 1, 527, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[521]), "a[521]", "double", 1, 528, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[522]), "a[522]", "double", 1, 529, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[523]), "a[523]", "double", 1, 530, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[524]), "a[524]", "double", 1, 531, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[525]), "a[525]", "double", 1, 532, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[526]), "a[526]", "double", 1, 533, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[527]), "a[527]", "double", 1, 534, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[528]), "a[528]", "double", 1, 535, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[529]), "a[529]", "double", 1, 536, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[530]), "a[530]", "double", 1, 537, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[531]), "a[531]", "double", 1, 538, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[532]), "a[532]", "double", 1, 539, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[533]), "a[533]", "double", 1, 540, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[534]), "a[534]", "double", 1, 541, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[535]), "a[535]", "double", 1, 542, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[536]), "a[536]", "double", 1, 543, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[537]), "a[537]", "double", 1, 544, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[538]), "a[538]", "double", 1, 545, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[539]), "a[539]", "double", 1, 546, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[540]), "a[540]", "double", 1, 547, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[541]), "a[541]", "double", 1, 548, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[542]), "a[542]", "double", 1, 549, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[543]), "a[543]", "double", 1, 550, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[544]), "a[544]", "double", 1, 551, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[545]), "a[545]", "double", 1, 552, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[546]), "a[546]", "double", 1, 553, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[547]), "a[547]", "double", 1, 554, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[548]), "a[548]", "double", 1, 555, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[549]), "a[549]", "double", 1, 556, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[550]), "a[550]", "double", 1, 557, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[551]), "a[551]", "double", 1, 558, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[552]), "a[552]", "double", 1, 559, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[553]), "a[553]", "double", 1, 560, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[554]), "a[554]", "double", 1, 561, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[555]), "a[555]", "double", 1, 562, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[556]), "a[556]", "double", 1, 563, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[557]), "a[557]", "double", 1, 564, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[558]), "a[558]", "double", 1, 565, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[559]), "a[559]", "double", 1, 566, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[560]), "a[560]", "double", 1, 567, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[561]), "a[561]", "double", 1, 568, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[562]), "a[562]", "double", 1, 569, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[563]), "a[563]", "double", 1, 570, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[564]), "a[564]", "double", 1, 571, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[565]), "a[565]", "double", 1, 572, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[566]), "a[566]", "double", 1, 573, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[567]), "a[567]", "double", 1, 574, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[568]), "a[568]", "double", 1, 575, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[569]), "a[569]", "double", 1, 576, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[570]), "a[570]", "double", 1, 577, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[571]), "a[571]", "double", 1, 578, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[572]), "a[572]", "double", 1, 579, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[573]), "a[573]", "double", 1, 580, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[574]), "a[574]", "double", 1, 581, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[575]), "a[575]", "double", 1, 582, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[576]), "a[576]", "double", 1, 583, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[577]), "a[577]", "double", 1, 584, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[578]), "a[578]", "double", 1, 585, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[579]), "a[579]", "double", 1, 586, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[580]), "a[580]", "double", 1, 587, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[581]), "a[581]", "double", 1, 588, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[582]), "a[582]", "double", 1, 589, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[583]), "a[583]", "double", 1, 590, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[584]), "a[584]", "double", 1, 591, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[585]), "a[585]", "double", 1, 592, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[586]), "a[586]", "double", 1, 593, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[587]), "a[587]", "double", 1, 594, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[588]), "a[588]", "double", 1, 595, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[589]), "a[589]", "double", 1, 596, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[590]), "a[590]", "double", 1, 597, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[591]), "a[591]", "double", 1, 598, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[592]), "a[592]", "double", 1, 599, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[593]), "a[593]", "double", 1, 600, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[594]), "a[594]", "double", 1, 601, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[595]), "a[595]", "double", 1, 602, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[596]), "a[596]", "double", 1, 603, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[597]), "a[597]", "double", 1, 604, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[598]), "a[598]", "double", 1, 605, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[599]), "a[599]", "double", 1, 606, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[600]), "a[600]", "double", 1, 607, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[601]), "a[601]", "double", 1, 608, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[602]), "a[602]", "double", 1, 609, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[603]), "a[603]", "double", 1, 610, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[604]), "a[604]", "double", 1, 611, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[605]), "a[605]", "double", 1, 612, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[606]), "a[606]", "double", 1, 613, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[607]), "a[607]", "double", 1, 614, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[608]), "a[608]", "double", 1, 615, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[609]), "a[609]", "double", 1, 616, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[610]), "a[610]", "double", 1, 617, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[611]), "a[611]", "double", 1, 618, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[612]), "a[612]", "double", 1, 619, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[613]), "a[613]", "double", 1, 620, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[614]), "a[614]", "double", 1, 621, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[615]), "a[615]", "double", 1, 622, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[616]), "a[616]", "double", 1, 623, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[617]), "a[617]", "double", 1, 624, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[618]), "a[618]", "double", 1, 625, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[619]), "a[619]", "double", 1, 626, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[620]), "a[620]", "double", 1, 627, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[621]), "a[621]", "double", 1, 628, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[622]), "a[622]", "double", 1, 629, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[623]), "a[623]", "double", 1, 630, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[624]), "a[624]", "double", 1, 631, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[625]), "a[625]", "double", 1, 632, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[626]), "a[626]", "double", 1, 633, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[627]), "a[627]", "double", 1, 634, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[628]), "a[628]", "double", 1, 635, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[629]), "a[629]", "double", 1, 636, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[630]), "a[630]", "double", 1, 637, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[631]), "a[631]", "double", 1, 638, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[632]), "a[632]", "double", 1, 639, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[633]), "a[633]", "double", 1, 640, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[634]), "a[634]", "double", 1, 641, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[635]), "a[635]", "double", 1, 642, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[636]), "a[636]", "double", 1, 643, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[637]), "a[637]", "double", 1, 644, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[638]), "a[638]", "double", 1, 645, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[639]), "a[639]", "double", 1, 646, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[640]), "a[640]", "double", 1, 647, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[641]), "a[641]", "double", 1, 648, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[642]), "a[642]", "double", 1, 649, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[643]), "a[643]", "double", 1, 650, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[644]), "a[644]", "double", 1, 651, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[645]), "a[645]", "double", 1, 652, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[646]), "a[646]", "double", 1, 653, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[647]), "a[647]", "double", 1, 654, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[648]), "a[648]", "double", 1, 655, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[649]), "a[649]", "double", 1, 656, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[650]), "a[650]", "double", 1, 657, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[651]), "a[651]", "double", 1, 658, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[652]), "a[652]", "double", 1, 659, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[653]), "a[653]", "double", 1, 660, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[654]), "a[654]", "double", 1, 661, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[655]), "a[655]", "double", 1, 662, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[656]), "a[656]", "double", 1, 663, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[657]), "a[657]", "double", 1, 664, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[658]), "a[658]", "double", 1, 665, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[659]), "a[659]", "double", 1, 666, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[660]), "a[660]", "double", 1, 667, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[661]), "a[661]", "double", 1, 668, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[662]), "a[662]", "double", 1, 669, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[663]), "a[663]", "double", 1, 670, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[664]), "a[664]", "double", 1, 671, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[665]), "a[665]", "double", 1, 672, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[666]), "a[666]", "double", 1, 673, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[667]), "a[667]", "double", 1, 674, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[668]), "a[668]", "double", 1, 675, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[669]), "a[669]", "double", 1, 676, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[670]), "a[670]", "double", 1, 677, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[671]), "a[671]", "double", 1, 678, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[672]), "a[672]", "double", 1, 679, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[673]), "a[673]", "double", 1, 680, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[674]), "a[674]", "double", 1, 681, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[675]), "a[675]", "double", 1, 682, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[676]), "a[676]", "double", 1, 683, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[677]), "a[677]", "double", 1, 684, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[678]), "a[678]", "double", 1, 685, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[679]), "a[679]", "double", 1, 686, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[680]), "a[680]", "double", 1, 687, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[681]), "a[681]", "double", 1, 688, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[682]), "a[682]", "double", 1, 689, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[683]), "a[683]", "double", 1, 690, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[684]), "a[684]", "double", 1, 691, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[685]), "a[685]", "double", 1, 692, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[686]), "a[686]", "double", 1, 693, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[687]), "a[687]", "double", 1, 694, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[688]), "a[688]", "double", 1, 695, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[689]), "a[689]", "double", 1, 696, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[690]), "a[690]", "double", 1, 697, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[691]), "a[691]", "double", 1, 698, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[692]), "a[692]", "double", 1, 699, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[693]), "a[693]", "double", 1, 700, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[694]), "a[694]", "double", 1, 701, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[695]), "a[695]", "double", 1, 702, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[696]), "a[696]", "double", 1, 703, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[697]), "a[697]", "double", 1, 704, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[698]), "a[698]", "double", 1, 705, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[699]), "a[699]", "double", 1, 706, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[700]), "a[700]", "double", 1, 707, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[701]), "a[701]", "double", 1, 708, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[702]), "a[702]", "double", 1, 709, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[703]), "a[703]", "double", 1, 710, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[704]), "a[704]", "double", 1, 711, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[705]), "a[705]", "double", 1, 712, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[706]), "a[706]", "double", 1, 713, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[707]), "a[707]", "double", 1, 714, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[708]), "a[708]", "double", 1, 715, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[709]), "a[709]", "double", 1, 716, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[710]), "a[710]", "double", 1, 717, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[711]), "a[711]", "double", 1, 718, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[712]), "a[712]", "double", 1, 719, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[713]), "a[713]", "double", 1, 720, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[714]), "a[714]", "double", 1, 721, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[715]), "a[715]", "double", 1, 722, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[716]), "a[716]", "double", 1, 723, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[717]), "a[717]", "double", 1, 724, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[718]), "a[718]", "double", 1, 725, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[719]), "a[719]", "double", 1, 726, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[720]), "a[720]", "double", 1, 727, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[721]), "a[721]", "double", 1, 728, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[722]), "a[722]", "double", 1, 729, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[723]), "a[723]", "double", 1, 730, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[724]), "a[724]", "double", 1, 731, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[725]), "a[725]", "double", 1, 732, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[726]), "a[726]", "double", 1, 733, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[727]), "a[727]", "double", 1, 734, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[728]), "a[728]", "double", 1, 735, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[729]), "a[729]", "double", 1, 736, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[730]), "a[730]", "double", 1, 737, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[731]), "a[731]", "double", 1, 738, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[732]), "a[732]", "double", 1, 739, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[733]), "a[733]", "double", 1, 740, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[734]), "a[734]", "double", 1, 741, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[735]), "a[735]", "double", 1, 742, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[736]), "a[736]", "double", 1, 743, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[737]), "a[737]", "double", 1, 744, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[738]), "a[738]", "double", 1, 745, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[739]), "a[739]", "double", 1, 746, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[740]), "a[740]", "double", 1, 747, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[741]), "a[741]", "double", 1, 748, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[742]), "a[742]", "double", 1, 749, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[743]), "a[743]", "double", 1, 750, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[744]), "a[744]", "double", 1, 751, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[745]), "a[745]", "double", 1, 752, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[746]), "a[746]", "double", 1, 753, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[747]), "a[747]", "double", 1, 754, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[748]), "a[748]", "double", 1, 755, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[749]), "a[749]", "double", 1, 756, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[750]), "a[750]", "double", 1, 757, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[751]), "a[751]", "double", 1, 758, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[752]), "a[752]", "double", 1, 759, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[753]), "a[753]", "double", 1, 760, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[754]), "a[754]", "double", 1, 761, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[755]), "a[755]", "double", 1, 762, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[756]), "a[756]", "double", 1, 763, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[757]), "a[757]", "double", 1, 764, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[758]), "a[758]", "double", 1, 765, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[759]), "a[759]", "double", 1, 766, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[760]), "a[760]", "double", 1, 767, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[761]), "a[761]", "double", 1, 768, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[762]), "a[762]", "double", 1, 769, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[763]), "a[763]", "double", 1, 770, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[764]), "a[764]", "double", 1, 771, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[765]), "a[765]", "double", 1, 772, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[766]), "a[766]", "double", 1, 773, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[767]), "a[767]", "double", 1, 774, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[768]), "a[768]", "double", 1, 775, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[769]), "a[769]", "double", 1, 776, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[770]), "a[770]", "double", 1, 777, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[771]), "a[771]", "double", 1, 778, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[772]), "a[772]", "double", 1, 779, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[773]), "a[773]", "double", 1, 780, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[774]), "a[774]", "double", 1, 781, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[775]), "a[775]", "double", 1, 782, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[776]), "a[776]", "double", 1, 783, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[777]), "a[777]", "double", 1, 784, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[778]), "a[778]", "double", 1, 785, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[779]), "a[779]", "double", 1, 786, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[780]), "a[780]", "double", 1, 787, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[781]), "a[781]", "double", 1, 788, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[782]), "a[782]", "double", 1, 789, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[783]), "a[783]", "double", 1, 790, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[784]), "a[784]", "double", 1, 791, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[785]), "a[785]", "double", 1, 792, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[786]), "a[786]", "double", 1, 793, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[787]), "a[787]", "double", 1, 794, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[788]), "a[788]", "double", 1, 795, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[789]), "a[789]", "double", 1, 796, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[790]), "a[790]", "double", 1, 797, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[791]), "a[791]", "double", 1, 798, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[792]), "a[792]", "double", 1, 799, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[793]), "a[793]", "double", 1, 800, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[794]), "a[794]", "double", 1, 801, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[795]), "a[795]", "double", 1, 802, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[796]), "a[796]", "double", 1, 803, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[797]), "a[797]", "double", 1, 804, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[798]), "a[798]", "double", 1, 805, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[799]), "a[799]", "double", 1, 806, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[800]), "a[800]", "double", 1, 807, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[801]), "a[801]", "double", 1, 808, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[802]), "a[802]", "double", 1, 809, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[803]), "a[803]", "double", 1, 810, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[804]), "a[804]", "double", 1, 811, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[805]), "a[805]", "double", 1, 812, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[806]), "a[806]", "double", 1, 813, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[807]), "a[807]", "double", 1, 814, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[808]), "a[808]", "double", 1, 815, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[809]), "a[809]", "double", 1, 816, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[810]), "a[810]", "double", 1, 817, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[811]), "a[811]", "double", 1, 818, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[812]), "a[812]", "double", 1, 819, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[813]), "a[813]", "double", 1, 820, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[814]), "a[814]", "double", 1, 821, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[815]), "a[815]", "double", 1, 822, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[816]), "a[816]", "double", 1, 823, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[817]), "a[817]", "double", 1, 824, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[818]), "a[818]", "double", 1, 825, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[819]), "a[819]", "double", 1, 826, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[820]), "a[820]", "double", 1, 827, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[821]), "a[821]", "double", 1, 828, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[822]), "a[822]", "double", 1, 829, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[823]), "a[823]", "double", 1, 830, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[824]), "a[824]", "double", 1, 831, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[825]), "a[825]", "double", 1, 832, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[826]), "a[826]", "double", 1, 833, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[827]), "a[827]", "double", 1, 834, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[828]), "a[828]", "double", 1, 835, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[829]), "a[829]", "double", 1, 836, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[830]), "a[830]", "double", 1, 837, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[831]), "a[831]", "double", 1, 838, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[832]), "a[832]", "double", 1, 839, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[833]), "a[833]", "double", 1, 840, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[834]), "a[834]", "double", 1, 841, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[835]), "a[835]", "double", 1, 842, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[836]), "a[836]", "double", 1, 843, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[837]), "a[837]", "double", 1, 844, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[838]), "a[838]", "double", 1, 845, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[839]), "a[839]", "double", 1, 846, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[840]), "a[840]", "double", 1, 847, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[841]), "a[841]", "double", 1, 848, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[842]), "a[842]", "double", 1, 849, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[843]), "a[843]", "double", 1, 850, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[844]), "a[844]", "double", 1, 851, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[845]), "a[845]", "double", 1, 852, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[846]), "a[846]", "double", 1, 853, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[847]), "a[847]", "double", 1, 854, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[848]), "a[848]", "double", 1, 855, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[849]), "a[849]", "double", 1, 856, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[850]), "a[850]", "double", 1, 857, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[851]), "a[851]", "double", 1, 858, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[852]), "a[852]", "double", 1, 859, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[853]), "a[853]", "double", 1, 860, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[854]), "a[854]", "double", 1, 861, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[855]), "a[855]", "double", 1, 862, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[856]), "a[856]", "double", 1, 863, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[857]), "a[857]", "double", 1, 864, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[858]), "a[858]", "double", 1, 865, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[859]), "a[859]", "double", 1, 866, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[860]), "a[860]", "double", 1, 867, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[861]), "a[861]", "double", 1, 868, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[862]), "a[862]", "double", 1, 869, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[863]), "a[863]", "double", 1, 870, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[864]), "a[864]", "double", 1, 871, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[865]), "a[865]", "double", 1, 872, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[866]), "a[866]", "double", 1, 873, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[867]), "a[867]", "double", 1, 874, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[868]), "a[868]", "double", 1, 875, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[869]), "a[869]", "double", 1, 876, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[870]), "a[870]", "double", 1, 877, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[871]), "a[871]", "double", 1, 878, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[872]), "a[872]", "double", 1, 879, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[873]), "a[873]", "double", 1, 880, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[874]), "a[874]", "double", 1, 881, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[875]), "a[875]", "double", 1, 882, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[876]), "a[876]", "double", 1, 883, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[877]), "a[877]", "double", 1, 884, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[878]), "a[878]", "double", 1, 885, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[879]), "a[879]", "double", 1, 886, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[880]), "a[880]", "double", 1, 887, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[881]), "a[881]", "double", 1, 888, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[882]), "a[882]", "double", 1, 889, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[883]), "a[883]", "double", 1, 890, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[884]), "a[884]", "double", 1, 891, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[885]), "a[885]", "double", 1, 892, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[886]), "a[886]", "double", 1, 893, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[887]), "a[887]", "double", 1, 894, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[888]), "a[888]", "double", 1, 895, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[889]), "a[889]", "double", 1, 896, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[890]), "a[890]", "double", 1, 897, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[891]), "a[891]", "double", 1, 898, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[892]), "a[892]", "double", 1, 899, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[893]), "a[893]", "double", 1, 900, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[894]), "a[894]", "double", 1, 901, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[895]), "a[895]", "double", 1, 902, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[896]), "a[896]", "double", 1, 903, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[897]), "a[897]", "double", 1, 904, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[898]), "a[898]", "double", 1, 905, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[899]), "a[899]", "double", 1, 906, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[900]), "a[900]", "double", 1, 907, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[901]), "a[901]", "double", 1, 908, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[902]), "a[902]", "double", 1, 909, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[903]), "a[903]", "double", 1, 910, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[904]), "a[904]", "double", 1, 911, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[905]), "a[905]", "double", 1, 912, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[906]), "a[906]", "double", 1, 913, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[907]), "a[907]", "double", 1, 914, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[908]), "a[908]", "double", 1, 915, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[909]), "a[909]", "double", 1, 916, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[910]), "a[910]", "double", 1, 917, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[911]), "a[911]", "double", 1, 918, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[912]), "a[912]", "double", 1, 919, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[913]), "a[913]", "double", 1, 920, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[914]), "a[914]", "double", 1, 921, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[915]), "a[915]", "double", 1, 922, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[916]), "a[916]", "double", 1, 923, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[917]), "a[917]", "double", 1, 924, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[918]), "a[918]", "double", 1, 925, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[919]), "a[919]", "double", 1, 926, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[920]), "a[920]", "double", 1, 927, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[921]), "a[921]", "double", 1, 928, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[922]), "a[922]", "double", 1, 929, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[923]), "a[923]", "double", 1, 930, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[924]), "a[924]", "double", 1, 931, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[925]), "a[925]", "double", 1, 932, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[926]), "a[926]", "double", 1, 933, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[927]), "a[927]", "double", 1, 934, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[928]), "a[928]", "double", 1, 935, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[929]), "a[929]", "double", 1, 936, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[930]), "a[930]", "double", 1, 937, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[931]), "a[931]", "double", 1, 938, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[932]), "a[932]", "double", 1, 939, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[933]), "a[933]", "double", 1, 940, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[934]), "a[934]", "double", 1, 941, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[935]), "a[935]", "double", 1, 942, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[936]), "a[936]", "double", 1, 943, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[937]), "a[937]", "double", 1, 944, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[938]), "a[938]", "double", 1, 945, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[939]), "a[939]", "double", 1, 946, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[940]), "a[940]", "double", 1, 947, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[941]), "a[941]", "double", 1, 948, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[942]), "a[942]", "double", 1, 949, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[943]), "a[943]", "double", 1, 950, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[944]), "a[944]", "double", 1, 951, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[945]), "a[945]", "double", 1, 952, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[946]), "a[946]", "double", 1, 953, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[947]), "a[947]", "double", 1, 954, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[948]), "a[948]", "double", 1, 955, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[949]), "a[949]", "double", 1, 956, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[950]), "a[950]", "double", 1, 957, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[951]), "a[951]", "double", 1, 958, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[952]), "a[952]", "double", 1, 959, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[953]), "a[953]", "double", 1, 960, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[954]), "a[954]", "double", 1, 961, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[955]), "a[955]", "double", 1, 962, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[956]), "a[956]", "double", 1, 963, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[957]), "a[957]", "double", 1, 964, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[958]), "a[958]", "double", 1, 965, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[959]), "a[959]", "double", 1, 966, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[960]), "a[960]", "double", 1, 967, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[961]), "a[961]", "double", 1, 968, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[962]), "a[962]", "double", 1, 969, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[963]), "a[963]", "double", 1, 970, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[964]), "a[964]", "double", 1, 971, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[965]), "a[965]", "double", 1, 972, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[966]), "a[966]", "double", 1, 973, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[967]), "a[967]", "double", 1, 974, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[968]), "a[968]", "double", 1, 975, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[969]), "a[969]", "double", 1, 976, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[970]), "a[970]", "double", 1, 977, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[971]), "a[971]", "double", 1, 978, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[972]), "a[972]", "double", 1, 979, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[973]), "a[973]", "double", 1, 980, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[974]), "a[974]", "double", 1, 981, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[975]), "a[975]", "double", 1, 982, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[976]), "a[976]", "double", 1, 983, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[977]), "a[977]", "double", 1, 984, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[978]), "a[978]", "double", 1, 985, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[979]), "a[979]", "double", 1, 986, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[980]), "a[980]", "double", 1, 987, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[981]), "a[981]", "double", 1, 988, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[982]), "a[982]", "double", 1, 989, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[983]), "a[983]", "double", 1, 990, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[984]), "a[984]", "double", 1, 991, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[985]), "a[985]", "double", 1, 992, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[986]), "a[986]", "double", 1, 993, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[987]), "a[987]", "double", 1, 994, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[988]), "a[988]", "double", 1, 995, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[989]), "a[989]", "double", 1, 996, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[990]), "a[990]", "double", 1, 997, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[991]), "a[991]", "double", 1, 998, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[992]), "a[992]", "double", 1, 999, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[993]), "a[993]", "double", 1, 1000, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[994]), "a[994]", "double", 1, 1001, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[995]), "a[995]", "double", 1, 1002, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[996]), "a[996]", "double", 1, 1003, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[997]), "a[997]", "double", 1, 1004, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[998]), "a[998]", "double", 1, 1005, 2, 1, 0, 0},
	{"", offsetof(struct UserVar, a[999]), "a[999]", "double", 1, 1006, 2, 1, 0, 0}
};

/* Event masks for state set "pvSyncPut" */
static const seqMask	EM_pvSyncPut_0_one[] = {
	0x00000010,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
};

/* State table for state set "pvSyncPut" */
static seqState G_pvSyncPut_states[] = {
	{
	/* state name */        "one",
	/* action function */   A_pvSyncPut_0_one,
	/* event function */    E_pvSyncPut_0_one,
	/* delay function */    D_pvSyncPut_0_one,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_pvSyncPut_0_one,
	/* state options */     (0)
	},
};

/* Event masks for state set "pvSyncMonitor" */
static const seqMask	EM_pvSyncMonitor_1_idle[] = {
	0x00000002,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
};

/* State table for state set "pvSyncMonitor" */
static seqState G_pvSyncMonitor_states[] = {
	{
	/* state name */        "idle",
	/* action function */   A_pvSyncMonitor_1_idle,
	/* event function */    E_pvSyncMonitor_1_idle,
	/* delay function */    D_pvSyncMonitor_1_idle,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_pvSyncMonitor_1_idle,
	/* state options */     (0)
	},
};

/* Event masks for state set "pvSyncY" */
static const seqMask	EM_pvSyncY_2_pvSync[] = {
	0x00000008,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
};
static const seqMask	EM_pvSyncY_2_pvUnsync[] = {
	0xffffffc4,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0x00007fff,
};
static const seqMask	EM_pvSyncY_2_done[] = {
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
};

/* State table for state set "pvSyncY" */
static seqState G_pvSyncY_states[] = {
	{
	/* state name */        "pvSync",
	/* action function */   A_pvSyncY_2_pvSync,
	/* event function */    E_pvSyncY_2_pvSync,
	/* delay function */    D_pvSyncY_2_pvSync,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_pvSyncY_2_pvSync,
	/* state options */     (0)
	},
	{
	/* state name */        "pvUnsync",
	/* action function */   A_pvSyncY_2_pvUnsync,
	/* event function */    E_pvSyncY_2_pvUnsync,
	/* delay function */    D_pvSyncY_2_pvUnsync,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_pvSyncY_2_pvUnsync,
	/* state options */     (0)
	},
	{
	/* state name */        "done",
	/* action function */   A_pvSyncY_2_done,
	/* event function */    E_pvSyncY_2_done,
	/* delay function */    D_pvSyncY_2_done,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_pvSyncY_2_done,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "pvSyncPut",
	/* states */            G_pvSyncPut_states,
	/* number of states */  1,
	/* number of delays */  0
	},

	{
	/* state set name */    "pvSyncMonitor",
	/* states */            G_pvSyncMonitor_states,
	/* number of states */  1,
	/* number of delays */  0
	},

	{
	/* state set name */    "pvSyncY",
	/* states */            G_pvSyncY_states,
	/* number of states */  3,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram pvSyncTest = {
	/* magic number */      2001010,
	/* program name */      "pvSyncTest",
	/* channels */          G_channels,
	/* num. channels */     1002,
	/* state sets */        G_state_sets,
	/* num. state sets */   3,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  4,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_SAFE | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        G_prog_entry,
	/* exit func */         G_prog_exit,
	/* num. queues */       0
};

#define PROG_NAME pvSyncTest
#include "seqMain.c"
