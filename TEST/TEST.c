#include <stdio.h>

int main(void)
{
    int c;

    for (c = 0; scanf("%d", &c) && c != 42; printf("%d\n", c));

    return 0;
} 
