# 1 "../commaOperator.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../commaOperator.st"






program commaOperatorTest

%%#include "../testSupport.h"

entry {
    seq_test_init(4);
}

ss myss {
    state doit {
        when () {
            int i = 0;

            testOk1(((i = 1), testOk1(i==1), (i = 2), testOk1(i==2),
                (i = 3)) == 3);
            testOk1(i == 3);
        } exit
    }
}

exit {
    seq_test_done();
}
