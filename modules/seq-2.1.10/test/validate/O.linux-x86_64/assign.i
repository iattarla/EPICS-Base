# 1 "../assign.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../assign.st"






program assignTest

option +r;

%%#include "../testSupport.h"

int x = 0;
assign x;

foreign pvStatERROR;



entry {
    seq_test_init(3);
}

ss w {
    int n = 1;
    state w {
        when(n > 3) {
        } exit
        when (delay(0.01)) {
            int status;
            x = !x;
            status = pvPut(x);
            testOk1(status==pvStatERROR);
            n++;
        } state w
    }
}

ss r {
    state yes {
        when (!x) {
        } state no
    }
    state no {
        when (x) {
        } state yes
    }
}

exit {
    seq_test_done();
}
