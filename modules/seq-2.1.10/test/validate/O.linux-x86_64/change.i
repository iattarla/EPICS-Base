# 1 "../change.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../change.st"







program changeTest

option +r;

%%#include <time.h>
%%#include <stdlib.h>
%%#include "../testSupport.h"



entry {
    seq_test_init(50);


}

ss main {
    int x = 0;
    int n = 1;
    state zero {






        when (n > 50) {
        } exit
        when (delay(0.01)) {
            testOk(x == 0, "state=zero, x=%d", x);
            x = rand() % 10 - 5;
            testDiag("new random x=%d", x);
            n++;
            if (x > 0) {
                state pos;
            } else if (x < 0) {
                state neg;
            }
        } state zero






    }
    state pos {
        when (n > 50) {
        } exit
        when (delay(0.01)) {
            testOk(x > 0, "state=pos, x=%d", x);
            n++;
            x--;
            if (x == 0) state zero;
        } state pos
    }
    state neg {
        when (n > 50) {
        } exit
        when (delay(0.01)) {
            testOk(x < 0, "state=neg, x=%d", x);
            n++;
            x++;
            if (x == 0) state zero;
        } state neg
    }
}

exit {
    seq_test_done();
}
