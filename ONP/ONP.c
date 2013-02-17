#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
 
#define MAX_LEN 401

int isopp(char c)
{
    switch (c) {
    case '+':
        return 1;
    case '-':
        return 2;
    case '*':
        return 3;
    case '/':
        return 4;
    case '^':
        return 5;
    default:
        return 0;
    }
}

int main(int argc, char **argv)
{
    int i, j, n, test;
    char stack[MAX_LEN], expression[MAX_LEN], RPN[MAX_LEN];
    
    scanf("%d", &test);
    while (test--) {
        scanf("%s", expression);
        for (i = 0, j = 0, n = 0; expression[i] != '\0'; i++) {
            if (isalpha(expression[i])) {
                RPN[j++] = expression[i];
            } else if (isopp(expression[i])) {
                stack[n++] = expression[i];
            } else if (expression[i] == ')') {
                RPN[j++] = stack[--n];
            }
        }
        RPN[j] = '\0';
        printf("%s\n", RPN);
    }
    return(EXIT_SUCCESS);
}
