# 1 "../cmdButtons.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../cmdButtons.st"
# 18 "../cmdButtons.st"
program seqCmdBtns ("P=cmdBtns:")

option -c;
option +r;




short startBtn; assign startBtn to "{P}start"; monitor startBtn;
short stopBtn; assign stopBtn to "{P}stop"; monitor stopBtn;


string seqMsg; assign seqMsg to "{P}seqMsg";


int ix;

ss seqCmdBtns {

  state init {
    when (pvConnectCount() == pvChannelCount()) {
        printf("seqCmdBtns: All channels connected.\n");
        sprintf(seqMsg, "Ready");
        pvPut(seqMsg);
    } state idle
  }

  state idle {
    when (pvConnectCount() < pvChannelCount() ) {
        printf("seqCmdBtns: Lost pv connection.\n");
        sprintf(seqMsg, "Lost connection");
        pvPut(seqMsg);
    } state init


    when (startBtn) {
        sprintf(seqMsg, "0 s");
        pvPut(seqMsg);
    } state start


    when (stopBtn) {
        stopBtn = 0;
        pvPut(stopBtn);
    } state idle


  }

  state start {

    when (startBtn) {
        for (ix=1; ix<=10; ix++) {
            if (stopBtn) {
                stopBtn = 0;
                pvPut(stopBtn);
                break;
            } else {
                epicsThreadSleep(1);
                sprintf(seqMsg, "%d s", ix);
                pvPut(seqMsg);

            }
        }


        startBtn = 0;
        pvPut(startBtn);
    } state idle
  }
}
