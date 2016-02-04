# 1 "../stop.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../stop.st"






program stopTest

ss main {
    state start {
        when (delay(5)) {
            seqStop(epicsThreadGetIdSelf());
        } state start
    }
}

ss progress {
    state running {
        when (delay(1)) {
            printf("still running...\n");
        } state running
    }
}
