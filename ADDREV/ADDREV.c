/*
* File: main.c
* Author: Mark Sikora
*
* Created on October 31, 2009, 6:14 PM
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int intrev(int n);
int pwr(int base, int exp);
 
int main(int argc, char** argv) {
    int test;
    int n1, n2;
    
    scanf("%d", &test);
    while (test--) {
        scanf("%d %d", &n1, &n2);
        
        printf("%d\n", intrev(intrev(n1)+intrev(n2)));
    }

    return (EXIT_SUCCESS);
}

int intrev(int n)
{
    int i, i2, lim, nbr, r;
    nbr = n;
    r = 0;
    
    for (i = 1, lim = 0; nbr / i; i *= 10, ++lim);

    for (i = 1, i2 = 10; i <= lim; ++i, i2 *= 10) {
        r += pwr(10, lim - i) * ((nbr % i2) / (i2/10));
        nbr -= nbr % i2;
    }
    
    return r;
}

int pwr(int base, int exp)
{
    int i, n;
    for (i = 0, n = 1; i < exp; ++i) {
        n *= base;
    }
    return n;
}
