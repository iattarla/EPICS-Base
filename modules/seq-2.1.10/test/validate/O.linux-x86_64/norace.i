# 1 "../norace.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../norace.st"






program noraceTest

option +s;

# 1 "../raceCommon.st" 1






%%#include "../testSupport.h"

string x;
assign x to "x";
monitor x;

string y;
assign y to "";

evflag efx;
sync x to efx;

foreign MAX_STRING_SIZE;



entry {
    seq_test_init(10);
    testDiag("This test will run for %d seconds...", 10);
}

ss race1 {
    state init {
        when () {
            x[0] = 0;
        } state wait
    }
    state wait {
        string z;
        assign z to "";

        when (delay(0.001)) {
            int j;
            for (j=0; j <1000; j++) {
                int i;
                for (i=0; i<MAX_STRING_SIZE; i++) {

                    if (!x[i]) break;
                    if (x[i] != x[0]) {

                        testFail("x[0]=%c!=%c=x[%d]",x[0],x[i],i);
                        break;
                    }
                }
            }
        } state wait
        when ( (x[0] && x[1] && x[0] != x[1])
            || (y[0] && y[1] && y[0] != y[1])
            || (z[0] && z[1] && z[0] != z[1]) ) {

            testFail("%c/%c",x[0],x[1]);
        } state wait
    }
}

ss race2 {
    state init {
        when () {
            x[0] = 0;
        } state wait
    }
    state wait {
        when (delay(0.001)) {
            int j;
            for (j=0; j <1000; j++) {
                int i;
                for (i=0; i<MAX_STRING_SIZE; i++) {

                    if (!x[i]) break;
                    if (x[i] != x[0]) {

                        testFail("x[0]=%c!=%c=x[%d]",x[0],x[i],i);
                        break;
                    }
                }
            }
        } state wait
        when (delay(0.002)) {
            int j;
            for (j=0; j <1000; j++) {
                int i;
                for (i=0; i<MAX_STRING_SIZE; i++) {

                    if (!x[i]) break;
                    if (x[i] != x[0]) {

                        testFail("x[0]=%c!=%c=x[%d]",x[0],x[i],i);
                        break;
                    }
                }
            }
        } state wait
        when (x[0] && x[1] && x[0] != x[1]) {

            testFail("x[0]=%c!=%c=x[1]",x[0],x[1]);
        } state wait
    }
}

ss race3 {
    state init {
        when () {
            x[0] = 0;
        } state wait
    }
    state wait {
        string z;
        assign z to "";

        when (delay(0.001)) {
            int j;
            for (j=0; j <1000; j++) {
                int i;
                for (i=0; i<MAX_STRING_SIZE; i++) {

                    if (!x[i]) break;
                    if (x[i] != x[0]) {

                        testFail("x[0]=%c!=%c=x[%d]",x[0],x[i],i);
                        break;
                    }
                }
            }
        } state wait
        when (x[0] && x[1] && x[0] != x[1]) {

            testFail("x[0]=%c!=%c=x[1]",x[0],x[1]);
        } state wait
    }
}

ss stop {
    int seconds = 10;
    state count {
        when (seconds == 0) {
        } exit
        when (delay(1.0)) {
            seconds -= 1;
            testPass("%d seconds left", seconds);
        } state count
    }
}

exit {
    seq_test_done();
}
# 11 "../norace.st" 2
