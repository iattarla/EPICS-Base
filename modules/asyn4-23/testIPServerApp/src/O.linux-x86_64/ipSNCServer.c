/* Generated with snc from ipSNCServer.i */

/* Program "ipSNCServer" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 14 "../ipSNCServer.st"
	string input;
# line 15 "../ipSNCServer.st"
	string output;
# line 16 "../ipSNCServer.st"
	int connected;
# line 18 "../ipSNCServer.st"
	char *listenerPortName;
# line 19 "../ipSNCServer.st"
	char *IOPortName;
# line 20 "../ipSNCServer.st"
	int readStatus;
# line 21 "../ipSNCServer.st"
	int writeStatus;
# line 22 "../ipSNCServer.st"
	char *pasynUser;
# line 23 "../ipSNCServer.st"
	char *registrarPvt;
# line 24 "../ipSNCServer.st"
	char *eventId;
};

/* C code definitions */
# line 5 "../ipSNCServer.st"
#include <string.h>
# line 6 "../ipSNCServer.st"
#include <epicsString.h>
# line 7 "../ipSNCServer.st"
#include <epicsEvent.h>
# line 8 "../ipSNCServer.st"
#include <asynDriver.h>
# line 9 "../ipSNCServer.st"
#include <asynOctet.h>
# line 10 "../ipSNCServer.st"
#include <asynOctetSyncIO.h>
# line 27 "../ipSNCServer.st"
static void initialize(SS_ID ssId, struct UserVar *pVar);
# line 28 "../ipSNCServer.st"
static int readSocket(SS_ID ssId, struct UserVar *pVar);
# line 29 "../ipSNCServer.st"
static int writeSocket(SS_ID ssId, struct UserVar *pVar);

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
		"",
		"",
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
	};
	*pVar = pVarInit;
}

/****** Code for state "init" in state set "ipSNCServer" ******/

/* Delay function for state "init" in state set "ipSNCServer" */
static void D_ipSNCServer_0_init(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "init" in state set "ipSNCServer" */
static seqBool E_ipSNCServer_0_init(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "ipSNCServer" */
static void A_ipSNCServer_0_init(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 35 "../ipSNCServer.st"
			pVar->listenerPortName = seq_macValueGet(ssId, "PORT");
			initialize(ssId, pVar);
# line 37 "../ipSNCServer.st"
			pVar->connected = 0;
		}
		return;
	}
}

/****** Code for state "waitConnect" in state set "ipSNCServer" ******/

/* Delay function for state "waitConnect" in state set "ipSNCServer" */
static void D_ipSNCServer_0_waitConnect(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "waitConnect" in state set "ipSNCServer" */
static seqBool E_ipSNCServer_0_waitConnect(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		*pNextState = 2;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "waitConnect" in state set "ipSNCServer" */
static void A_ipSNCServer_0_waitConnect(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 43 "../ipSNCServer.st"
			seq_pvPut(ssId, 2/*connected*/, 0);
			epicsEventWait( (epicsEventId)pVar->eventId);
# line 45 "../ipSNCServer.st"
			seq_pvPut(ssId, 2/*connected*/, 0);
		}
		return;
	}
}

/****** Code for state "processCommands" in state set "ipSNCServer" ******/

/* Delay function for state "processCommands" in state set "ipSNCServer" */
static void D_ipSNCServer_0_processCommands(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "processCommands" in state set "ipSNCServer" */
static seqBool E_ipSNCServer_0_processCommands(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 50 "../ipSNCServer.st"
	if (pVar->connected)
	{
		*pNextState = 2;
		*pTransNum = 0;
		return TRUE;
	}
# line 62 "../ipSNCServer.st"
	if (!pVar->connected)
	{
		*pNextState = 1;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "processCommands" in state set "ipSNCServer" */
static void A_ipSNCServer_0_processCommands(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
			/* C code definitions */
# line 51 "../ipSNCServer.st"
			pVar->readStatus = readSocket(ssId, pVar);

# line 52 "../ipSNCServer.st"
			if (pVar->readStatus == 0)
			{
# line 53 "../ipSNCServer.st"
				seq_pvPut(ssId, 0/*input*/, 0);
# line 54 "../ipSNCServer.st"
				strcpy(pVar->output, "OK");
				pVar->writeStatus = writeSocket(ssId, pVar);
# line 56 "../ipSNCServer.st"
				if (pVar->writeStatus == 0)
				{
# line 57 "../ipSNCServer.st"
					seq_pvPut(ssId, 1/*output*/, 0);
				}
			}
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"{P}stringInput", offsetof(struct UserVar, input), "input", "string", 1, 1, 0, 0, 0, 0},
	{"{P}stringOutput", offsetof(struct UserVar, output), "output", "string", 1, 2, 0, 0, 0, 0},
	{"{P}connected", offsetof(struct UserVar, connected), "connected", "int", 1, 3, 0, 0, 0, 0}
};

/* Event masks for state set "ipSNCServer" */
static const seqMask	EM_ipSNCServer_0_init[] = {
	0x00000000,
};
static const seqMask	EM_ipSNCServer_0_waitConnect[] = {
	0x00000000,
};
static const seqMask	EM_ipSNCServer_0_processCommands[] = {
	0x00000008,
};

/* State table for state set "ipSNCServer" */
static seqState G_ipSNCServer_states[] = {
	{
	/* state name */        "init",
	/* action function */   A_ipSNCServer_0_init,
	/* event function */    E_ipSNCServer_0_init,
	/* delay function */    D_ipSNCServer_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_ipSNCServer_0_init,
	/* state options */     (0)
	},
	{
	/* state name */        "waitConnect",
	/* action function */   A_ipSNCServer_0_waitConnect,
	/* event function */    E_ipSNCServer_0_waitConnect,
	/* delay function */    D_ipSNCServer_0_waitConnect,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_ipSNCServer_0_waitConnect,
	/* state options */     (0)
	},
	{
	/* state name */        "processCommands",
	/* action function */   A_ipSNCServer_0_processCommands,
	/* event function */    E_ipSNCServer_0_processCommands,
	/* delay function */    D_ipSNCServer_0_processCommands,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_ipSNCServer_0_processCommands,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "ipSNCServer",
	/* states */            G_ipSNCServer_states,
	/* number of states */  3,
	/* number of delays */  0
	},
};

/* Program table (global) */
seqProgram ipSNCServer = {
	/* magic number */      2001010,
	/* program name */      "ipSNCServer",
	/* channels */          G_channels,
	/* num. channels */     3,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "P=testIPServer:=, PORT=P5000",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT),
	/* init func */         G_prog_init,
	/* entry func */        NULL,
	/* exit func */         NULL,
	/* num. queues */       0
};

/* Global C code */
# line 68 "../ipSNCServer.st"

static void connectionCallback(void *drvPvt, asynUser *pasynUserIn, char *portName, size_t len, int eomReason)
{
    struct UserVar *pVar = (struct UserVar *)drvPvt;
    asynUser *pasynUser;
    asynStatus status;

    pVar->IOPortName = epicsStrDup(portName);
    status = pasynOctetSyncIO->connect(portName, 0, &pasynUser, NULL);
    pVar->pasynUser = (char *)pasynUser;
    asynPrint(pasynUser, ASYN_TRACE_FLOW,
              "ipSNCServer: connectionCallback, portName=%s\n", portName);
    if (status) {
        asynPrint(pasynUser, ASYN_TRACE_ERROR,
                  "ipSNCServer:connectionCallback: unable to connect to port %s\n",
                  portName);
        return;
    }
    status = pasynOctetSyncIO->setInputEos(pasynUser, "\r\n", 2);
    if (status) {
        asynPrint(pasynUser, ASYN_TRACE_ERROR,
                  "ipSNCServer:connectionCallback: unable to set input EOS on %s: %s\n",
                  portName, pasynUser->errorMessage);
        return;
    }
    status = pasynOctetSyncIO->setOutputEos(pasynUser, "\r\n", 2);
    if (status) {
        asynPrint(pasynUser, ASYN_TRACE_ERROR,
                  "ipSNCServer:connectionCallback: unable to set output EOS on %s: %s\n",
                  portName, pasynUser->errorMessage);
        return;
    }

    pVar->connected = 1;
    epicsEventSignal( (epicsEventId)pVar->eventId);
}

static void initialize(SS_ID ssId, struct UserVar *pVar)
{
    int addr=0;
    asynInterface *pasynInterface;
    asynUser *pasynUser;
    asynOctet *pasynOctet;
    void *registrarPvt;
    int status;

    pVar->eventId = (char *)epicsEventCreate(epicsEventEmpty);
    pasynUser = pasynManager->createAsynUser(0,0);
    pVar->pasynUser = (char *)pasynUser;
    pasynUser->userPvt = pVar;
    status = pasynManager->connectDevice(pasynUser, pVar->listenerPortName, addr);
    if(status!=asynSuccess) {
        printf("can't connect to port %s: %s\n", pVar->listenerPortName, pasynUser->errorMessage);
        return;
    }
    pasynInterface = pasynManager->findInterface(pasynUser,asynOctetType,1);
    if(!pasynInterface) {
        printf("%s driver not supported\n",asynOctetType);
        return;
    }
    pasynOctet = (asynOctet *)pasynInterface->pinterface;
    status = pasynOctet->registerInterruptUser(
                 pasynInterface->drvPvt, pasynUser,
                 connectionCallback,pVar, &registrarPvt);
    pVar->registrarPvt = registrarPvt;
    if(status!=asynSuccess) {
        printf("ipSNCServer devAsynOctet registerInterruptUser %s\n",
               pasynUser->errorMessage);
    }
}

static int readSocket(SS_ID ssId, struct UserVar *pVar)
{
    char buffer[80];
    size_t nread;
    int eomReason;
    asynUser *pasynUser = (asynUser *)pVar->pasynUser;
    asynStatus status;

    status = pasynOctetSyncIO->read(pasynUser, buffer, 80,
                                    -1.0, &nread, &eomReason);
    if (status) {
        asynPrint(pasynUser, ASYN_TRACE_ERROR,
                  "ipSNCServer:readSocket: read error on: %s: %s\n",
                  pVar->IOPortName, pasynUser->errorMessage);
        pVar->connected = 0;
        strcpy(pVar->input, "");
    }
    else {
        asynPrint(pasynUser, ASYN_TRACEIO_DEVICE,
                  "ipSNCServer:readSocket: %s read %s\n",
                   pVar->IOPortName, buffer);
        strcpy(pVar->input, buffer);
    }
    return(status);
}

static int writeSocket(SS_ID ssId, struct UserVar *pVar)
{
    size_t nwrite;
    asynUser *pasynUser = (asynUser *)pVar->pasynUser;
    asynStatus status;

    status = pasynOctetSyncIO->write(pasynUser, pVar->output, strlen(pVar->output),
                                     0.0, &nwrite);
    if (status) {
        asynPrint(pasynUser, ASYN_TRACE_ERROR,
                  "ipSNCServer:writeSocket: write error on: %s: %s\n",
                  pVar->IOPortName, pasynUser->errorMessage);
        pVar->connected = 0;
    }
    else {
        asynPrint(pasynUser, ASYN_TRACEIO_DEVICE,
                   "ipSNCServer:writeSocket: %s write %s\n",
                   pVar->IOPortName, pVar->output);
    }
    return(status);
}



/* Register sequencer commands and program */
#include "epicsExport.h"
static void ipSNCServerRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&ipSNCServer);
}
epicsExportRegistrar(ipSNCServerRegistrar);
