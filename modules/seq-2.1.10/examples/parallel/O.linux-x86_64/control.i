# 1 "../control.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../control.st"






program control







option +r;



int32_t init[6];
assign init to {"dcs:axeinit", "dcs:chpinit", "dcs:domeinit", "dcs:rotinit", "dcs:secinit", "dcs:tertinit"};


ss main {

    int32_t done[6];

    state inactive {
        when () {
            int i;
            for (i = 0; i < 6; i++) {
                init[i] = 1;
                pvPut(init[i], ASYNC);
            }
            printf("all init commands sent\n");
        } state active
    }

    state active {
        when (pvPutComplete(init, TRUE, done)) {
            int i;
            printf("init commands not all done:");
            for (i = 0; i < 6; i++)
                printf(" %d", done[i]);
            printf("\n");
        } state active

        when (pvPutComplete(init)) {
            printf("init commands all done\n");
        } state done

        when (delay(5)) {
            printf("timeout waiting for inits to complete\n");
        } state done
    }

    state done {
        when () {
            unsigned short i;
            for (i = 0; i < 6; i++) {
                printf("%s: done,stat,sevr,mess = %d,%d,%d,%s\n",
                    pvName(init[i]),
                    pvPutComplete(init[i]),
                    pvStatus(init[i]),
                    pvSeverity(init[i]),
                    pvMessage(init[i]) ? pvMessage(init[i]) : "");
            }
        } state wait
    }

    state wait {
        when (delay(5)) {
        } state inactive
    }
}
