# 1 "../johng.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../johng.st"







program johng




double utc;
assign utc to "dcs0.utc";
monitor utc;


evflag utcFlag;
sync utc utcFlag;


double telfocus;
assign telfocus to "dcs0.telfocus";
monitor telfocus;


char *ring_str = "ring...\n";

option +s;
option -c;


ss utc {

    double telfocusSave;


    state start {

        int count = 0;


        when ( efTestAndClear( utcFlag ) ) {
            printf( "utc = %.3f\n", utc );
            count++;
        } state start


        when ( count == 10 ) {
            printf( "count has hit limit (telfocus = %g)\n", telfocus );
            telfocusSave = telfocus;
            count = 0;
        } state next
    }


    state next {


        when ( telfocus > telfocusSave ) {
            printf( "telfocus = %g\n", telfocus );
            telfocusSave = telfocus;
        } state next


        when ( delay ( 5 ) ) {
            printf( "timeout (telfocus didn't increase)\n" );
        } state start
    }
}


ss ring {
    state start {
        when ( delay( 1 ) ) {
            printf( "%s", ring_str );
        } state start
    }
}


ss RING {
    state start {
        int count2 = 1;
        entry {



            ring_str = "RING...\n";
        }
        when ( delay( count2 ) ) {
            printf( "%s", ring_str );
            if ( count2 < 16 ) count2 = 2 * count2; else count2 = 1;
        } state start
    }
}
