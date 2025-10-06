#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int lookahead; //lookahead always holds the next character from input.

void expr();
void term();
void match(int t);

int main()
{
    lookahead = getchar(); //read first character into lookahead
    expr(); //start parsing
    putchar('\n'); //trailing new line character
    return 0;
}

void expr()
{
    /*
        grammar handled: expr → term { (+|-) term }
        meaning: a term, followed by zero or more + term or - term.
    */

    term();
    while (1) {
        if (lookahead == '+') {
            match('+');
            term();
            putchar('+');
        } else if (lookahead == '-') {
            match('-');
            term();
            putchar('-');
        } else {
            return;
        }
    }
}

void term()
{
    /*
        this program only supports single digit numbers as terms.
    */
    if(isdigit(lookahead)) {
        putchar(lookahead);
        match(lookahead);
    } else {
        printf("syntax error\n");
        exit(1);
    }
}

void match(int t)
{
    /*
        checks if the expected char is the current lookahead.
    */
    if (lookahead == t) {
        lookahead = getchar();
    } else {
        printf("syntax error\n");
        exit(1);
    }
}

/*
what is this code?
it’s a recursive descent parser that reads a simple arithmetic expression from stdin
(like 3+5-2) and prints its postfix form (reverse polish notation).
*/

//output : 35+2-
