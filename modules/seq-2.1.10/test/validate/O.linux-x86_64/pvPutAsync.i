# 1 "../pvPutAsync.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../pvPutAsync.st"






program pvPutAsyncTest

%%#include "../testSupport.h"

foreign pvStatOK;

int x;
assign x to "pvPutAsync1";

entry {
    seq_test_init(10);
}

ss test1 {
    state put_async {
        int i;
        entry {
            i = 0;
        }
        when (i == 5) {
        } state wait_complete
        when (delay(0.4)) {
            int status;
            x = 1;
            status = pvPut(x,ASYNC);

            testOk((i==0)==(status==pvStatOK), "pvPut/ASYNC %d: result=%d (%s)",
                i, status, status ? pvMessage(x) : "");
            ++i;
        } state put_async
    }
    state wait_complete {
        when (delay(5.0)) {
            testFail("pvPut completion timeout");
        } state put_sync
        when (pvPutComplete(x)) {
            testPass("pvPut/ASYNC complete");
        } state put_sync
    }
    state put_sync {
        entry {
            int i = 0;
            for (i=0; i<4; i++) {
                int status = pvPut(x,SYNC);

                testOk(status==pvStatOK, "pvPut/SYNC %d, status=%d (%s)",
                    i, status, status ? pvMessage(x) : "");
            }
        }
        when (delay(1)) {
        } exit
    }
}
# 91 "../pvPutAsync.st"
exit {
    seq_test_done();
}
