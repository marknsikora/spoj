/*
 * File: main.c
 * Author: Mark Sikora
 *
 * Created on October 23, 2009, 9:06 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char** argv) {
    int i, j, k, len, n, test;
    int fctrl[158];
    
    scanf("%d", &test);
    while (test--) {
        scanf("%d", &n);
        for (i = 1; i < 158; ++i) {
            fctrl[i] = 0;
        }
        fctrl[0] = 1;
        for (i = 1, len = 0; i <= n; ++i) {
            for (j = 0; j < 158; ++j) {
                fctrl[j] *= i;
            }
            for (j = 0, k = 0; j < 158; ++j) {
                fctrl[j] += k;
                for (k = 0; fctrl[j] >= 10; ++k) {
                    fctrl[j] -= 10;
                }
                if (k > 0 && i == n) {
                    len = j + 1;
                }
            }
        }
        for (i = len; i >= 0; --i) {
            printf("%d", fctrl[i]);
        }
        printf("\n");
    }
     
    return (EXIT_SUCCESS);
}
