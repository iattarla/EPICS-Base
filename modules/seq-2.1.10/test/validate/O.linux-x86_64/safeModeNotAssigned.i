# 1 "../safeModeNotAssigned.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../safeModeNotAssigned.st"






program safeModeNotAssignedTest

%%#include "../testSupport.h"

option +s;

int v = 0;



entry {
    seq_test_init(10*2);
}

ss ss1 {
    int i = 0;
    state idle {
        when (delay(0.1)) {
            testOk(v == i, "ss1: v=%d==%d=i", v, i);
            v++;
            i++;
        } state idle
        when (v==10) {
        } state done
    }
    state done {
        when (delay(0.2)) {
        } exit
    }
}

ss ss2 {
    state idle {
        int i;
        when (delay(0.1)) {
            if (i < 10) {
                testOk(v == 0, "ss2: v=%d==0", v);
            }
            i++;
        } state idle
    }
}

exit {
    seq_test_done();
}
