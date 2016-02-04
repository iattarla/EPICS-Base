/* Generated with snc from bittypes.i */

/* Program "bittypesTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
# line 11 "../bittypes.st"
static	epicsInt8 i8 = 0;
# line 12 "../bittypes.st"
static	epicsUInt8 ui8 = 0;
# line 13 "../bittypes.st"
static	epicsInt16 i16 = 0;
# line 14 "../bittypes.st"
static	epicsUInt16 ui16 = 0;
# line 15 "../bittypes.st"
static	epicsInt32 i32 = 0;
# line 16 "../bittypes.st"
static	epicsUInt32 ui32 = 0;
struct UserVar_test {
	struct {
		epicsInt8 xi8;
		epicsUInt8 xui8;
		epicsInt16 xi16;
		epicsUInt16 xui16;
		epicsInt32 xi32;
		epicsUInt32 xui32;
	} UserVar_conversion;
} UserVar_test = {
	{
# line 41 "../bittypes.st"
		-1,
# line 42 "../bittypes.st"
		-1,
# line 43 "../bittypes.st"
		-1,
# line 44 "../bittypes.st"
		-1,
# line 45 "../bittypes.st"
		-1,
# line 46 "../bittypes.st"
		-1
	}
};

/* C code definitions */
# line 9 "../bittypes.st"
#include "../testSupport.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 26 "../bittypes.st"
	seq_test_init(12);
}

/****** Code for state "sizes" in state set "test" ******/

/* Delay function for state "sizes" in state set "test" */
static void D_test_0_sizes(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "sizes" in state set "test" */
static seqBool E_test_0_sizes(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "sizes" in state set "test" */
static void A_test_0_sizes(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 32 "../bittypes.st"
			testOk1(sizeof(i8) == 1);
# line 33 "../bittypes.st"
			testOk1(sizeof(ui8) == 1);
# line 34 "../bittypes.st"
			testOk1(sizeof(i16) == 2);
# line 35 "../bittypes.st"
			testOk1(sizeof(ui16) == 2);
# line 36 "../bittypes.st"
			testOk1(sizeof(i32) == 4);
# line 37 "../bittypes.st"
			testOk1(sizeof(ui32) == 4);
		}
		return;
	}
}

/****** Code for state "conversion" in state set "test" ******/

/* Delay function for state "conversion" in state set "test" */
static void D_test_0_conversion(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "conversion" in state set "test" */
static seqBool E_test_0_conversion(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "conversion" in state set "test" */
static void A_test_0_conversion(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 48 "../bittypes.st"
			i8 = UserVar_test.UserVar_conversion.xi8;
# line 49 "../bittypes.st"
			seq_pvPut(ssId, 0/*i8*/, SYNC);
# line 50 "../bittypes.st"
			seq_pvGet(ssId, 0/*i8*/, 0);
# line 51 "../bittypes.st"
			testOk1(i8 == UserVar_test.UserVar_conversion.xi8);
# line 52 "../bittypes.st"
			ui8 = UserVar_test.UserVar_conversion.xui8;
# line 53 "../bittypes.st"
			seq_pvPut(ssId, 1/*ui8*/, SYNC);
# line 54 "../bittypes.st"
			seq_pvGet(ssId, 1/*ui8*/, 0);
# line 55 "../bittypes.st"
			testOk1(ui8 == UserVar_test.UserVar_conversion.xui8);
# line 56 "../bittypes.st"
			i16 = UserVar_test.UserVar_conversion.xi16;
# line 57 "../bittypes.st"
			seq_pvPut(ssId, 2/*i16*/, SYNC);
# line 58 "../bittypes.st"
			seq_pvGet(ssId, 2/*i16*/, 0);
# line 59 "../bittypes.st"
			testOk1(i16 == UserVar_test.UserVar_conversion.xi16);
# line 60 "../bittypes.st"
			ui16 = UserVar_test.UserVar_conversion.xui16;
# line 61 "../bittypes.st"
			seq_pvPut(ssId, 3/*ui16*/, SYNC);
# line 62 "../bittypes.st"
			seq_pvGet(ssId, 3/*ui16*/, 0);
# line 63 "../bittypes.st"
			testOk1(ui16 == UserVar_test.UserVar_conversion.xui16);
# line 64 "../bittypes.st"
			i32 = UserVar_test.UserVar_conversion.xi32;
# line 65 "../bittypes.st"
			seq_pvPut(ssId, 4/*i32*/, SYNC);
# line 66 "../bittypes.st"
			seq_pvGet(ssId, 4/*i32*/, 0);
# line 67 "../bittypes.st"
			testOk1(i32 != UserVar_test.UserVar_conversion.xi32);
# line 68 "../bittypes.st"
			ui32 = UserVar_test.UserVar_conversion.xui32;
# line 69 "../bittypes.st"
			seq_pvPut(ssId, 5/*ui32*/, SYNC);
# line 70 "../bittypes.st"
			seq_pvGet(ssId, 5/*ui32*/, 0);
# line 71 "../bittypes.st"
			testOk1(ui32 != UserVar_test.UserVar_conversion.xui32);
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 77 "../bittypes.st"
	seq_test_done();
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"ushort", (size_t)&i8, "i8", "epicsInt8", 1, 1, 0, 0, 0, 0},
	{"ushort", (size_t)&ui8, "ui8", "epicsUInt8", 1, 2, 0, 0, 0, 0},
	{"ushort", (size_t)&i16, "i16", "epicsInt16", 1, 3, 0, 0, 0, 0},
	{"ushort", (size_t)&ui16, "ui16", "epicsUInt16", 1, 4, 0, 0, 0, 0},
	{"ushort", (size_t)&i32, "i32", "epicsInt32", 1, 5, 0, 0, 0, 0},
	{"ushort", (size_t)&ui32, "ui32", "epicsUInt32", 1, 6, 0, 0, 0, 0}
};

/* Event masks for state set "test" */
static const seqMask	EM_test_0_sizes[] = {
	0x00000000,
};
static const seqMask	EM_test_0_conversion[] = {
	0x00000000,
};

/* State table for state set "test" */
static seqState G_test_states[] = {
	{
	/* state name */        "sizes",
	/* action function */   A_test_0_sizes,
	/* event function */    E_test_0_sizes,
	/* delay function */    D_test_0_sizes,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_test_0_sizes,
	/* state options */     (0)
	},
	{
	/* state name */        "conversion",
	/* action function */   A_test_0_conversion,
	/* event function */    E_test_0_conversion,
	/* delay function */    D_test_0_conversion,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_test_0_conversion,
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
};

/* Program table (global) */
seqProgram bittypesTest = {
	/* magic number */      2001010,
	/* program name */      "bittypesTest",
	/* channels */          G_channels,
	/* num. channels */     6,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        G_prog_entry,
	/* exit func */         G_prog_exit,
	/* num. queues */       0
};

#define PROG_NAME bittypesTest
#include "seqMain.c"
