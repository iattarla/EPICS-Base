# 1 "../evflag.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../evflag.st"
# 15 "../evflag.st"
program evflagTest

%%#include "../testSupport.h"

option +s;

evflag ef_named, ef_anonymous;

double anonymous;
assign anonymous;
monitor anonymous;
sync anonymous to ef_anonymous;

entry {
    seq_test_init(0);
    efClear(ef_named);
}

ss read {
    double named;
    assign named to "evflag";
    monitor named;
    sync named to ef_named;
    state wait {
        when (efTestAndClear(ef_named)) {
            anonymous = named;
            pvPut(anonymous);
            testDiag("read: pvPut(anonymous=%.1f)", anonymous);
            epicsThreadSleep(0.1);
            testOk(named==anonymous,
                "read: named=%.1f==%.1f=anonymous", named, anonymous);
        } state wait
    }
}

ss write {
    double named = 1.0;
    assign named to "evflag";
    int n=0;
    state send {
        when (n > 10) {
        } exit
        when (delay(0.01)) {
            named = n;
            pvPut(named);
            testDiag("write: pvPut(named=%.1f)", named);
            anonymous = named;
        } state recv
    }
    state recv {
        when (efTestAndClear(ef_anonymous)) {
            testOk(named==anonymous, "write: named=%.1f==%.1f=anonymous", named, anonymous);
            epicsThreadSleep(0.1);
            testOk(named==anonymous, "write: named=%.1f==%.1f=anonymous", named, anonymous);
            pvGet(anonymous);
            testOk(named==anonymous, "write: named=%.1f==%.1f=anonymous", named, anonymous);
            n++;
        } state send
    }
}

exit {
    seq_test_done();
}
