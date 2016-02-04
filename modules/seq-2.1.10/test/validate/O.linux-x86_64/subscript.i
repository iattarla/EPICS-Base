# 1 "../subscript.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../subscript.st"






program subscriptTest

float single[2];
assign single;

float multiple3[3];
assign multiple3 to {"x", "y"};

int multiple2[2];
assign multiple2 to {};

monitor multiple2;

ss test {
    state test {
        when (FALSE) {
            %%multiple2[0] = 0;
        } state test
    }
}
