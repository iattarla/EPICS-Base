# 1 "../safeMonitor.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../safeMonitor.st"






program safeMonitorTest

%%#include "../testSupport.h"

option +s;

double cnt = 1.0;
assign cnt;
monitor cnt;
evflag ef_cnt;
sync cnt to ef_cnt;



entry {
    seq_test_init(10);
}

ss read {
    double on_entry;
    int n = 1;
    state react {
        when (n > 10) {
        } exit
        when (efTestAndClear(ef_cnt)) {
            on_entry = cnt;
            testDiag("read: enter action block, cnt=%.1f", cnt);
            epicsThreadSleep(0.1);
            testOk(on_entry==cnt,
                "read: exit action block, on_entry=%.1f==%.1f=cnt", on_entry, cnt);
            n++;
        } state react
    }
}

ss write {
    state send {
        when (delay(0.04)) {
            cnt += 1.0;
            pvPut(cnt);
            testDiag("write: pvPut(cnt=%.1f)", cnt);
        } state send
    }
}

exit {
    seq_test_done();
}
