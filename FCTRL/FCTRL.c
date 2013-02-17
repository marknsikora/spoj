/*
 * File: main.c
 * Author: Mark Sikora
 *
 * Created on October 10, 2009, 1:47 PM
 */
     
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

int main(int argc, char** argv) {
    int count, fct, i, n, test;
    
    scanf("%d", &test);
    
    while (test--) {
        scanf("%d", &n);
        
        for(i = 5, count = 0; i <= n; i *= 5) {
            count += n / i;
        }
        printf("%d\n", count);
    }
    
    return (EXIT_SUCCESS);
}

