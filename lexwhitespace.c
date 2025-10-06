#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NONE -1
#define NUM 256

int lineno = 1;
int tokenval = NONE;

int lexan()
{
    int t;

    while (1) {
        t = getchar();

        if (t == EOF) {
            return EOF;
        }
        else if (t == ' ' || t == '\t') {
            ; // skip whitespace
        }
        else if (t == '\n') {
            lineno++;
        }
        else if (isdigit(t)) {
            tokenval = t - '0';
            t = getchar();
            while (isdigit(t)) {
                tokenval = 10 * tokenval + (t - '0');
                t = getchar();
            }
            ungetc(t, stdin);
            return NUM;
        }
        else {
            return t;
        }
    }
}

int main() {
    int t;
    while ((t = lexan()) != EOF) {
        if (t == NUM)
            printf("NUM(%d)\n", tokenval);
        else
            printf("TOKEN(%c)\n", t);
    }
    return 0;
}

/*
output:
2-2
NUM(2)
TOKEN(-)
NUM(2)
1+8
NUM(1)
TOKEN(+)
NUM(8)

*/