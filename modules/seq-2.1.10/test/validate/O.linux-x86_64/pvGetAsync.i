# 1 "../pvGetAsync.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../pvGetAsync.st"






program pvGetAsyncTest

%%#include "../testSupport.h"



entry {
    seq_test_init(1);
    testDiag("start");
}

ss pvGetAsync {
    int x = 0, old_x = 0;
    assign x to "pvGetAsync1";
    int n;

    state init {
        when () {
            n = 0;
        } state get_async
    }
    state get_async {
        when (n == 100000) {
            testPass("pvGet completed %d times", 100000);
        } exit
        when () {
        } state wait_complete
    }
    state wait_complete {
        entry {
            pvGet(x,ASYNC);
        }
        when (delay(5.0)) {
            testFail("pvGet completion timeout");
        } exit
        when (pvGetComplete(x)) {
        } state get_async
        exit {
            n++;
        }
    }
}

exit {
    testDiag("exit");
    seq_test_done();
}
