# 1 "../local.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../local.st"







program localTest

%%#include "../testSupport.h"


option +r;


int i = 1;

entry {
    seq_test_init(5);
}


ss start {
    int i = 2;
    state first {
        int i = 3;
        when (i < 5) {
            testOk(i>=3, "state local i == %d >= 3", i);
            i = i+1;
        } state last
        when () {
        } exit
    }
    state last {
        when ( delay( 0.1 ) ) {
            testOk(i==2,"state set local i==%d", i);
        } state first
    }
}


exit {
    testOk(i==1, "global i==%d", i);
    seq_test_done();
}
