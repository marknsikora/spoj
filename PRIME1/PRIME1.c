/*
 * SPOJ Problem 2: Prime Generator
 *
 * Author: Mark Sikora
 * Date: 2010/02/26 18:30
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 1000000000
#define STEP_SIZE 50

int main(int argc, char **argv)
{
    int count, i, len, max, min, n, r, *seed, test;
    
    count = 0;
    len = STEP_SIZE;
    r = sqrt(MAX_NUM);
    seed = malloc(len*sizeof(int));
    if (seed == NULL)
        exit(EXIT_FAILURE);
    seed[count++] = 2;
    for (i = 3; i <= r; i++) {
        for (n = 0; n < count; n++) {
            if (i % seed[n] == 0) {
                break;
            }
        }
        if (n == count)
            seed[count++] = i;
        if (count == len-1) {
            len += STEP_SIZE;
            seed = realloc(seed, len*sizeof(int));
            if (seed == NULL) {
                exit(EXIT_FAILURE);
            }
        }
    }
    
    scanf("%d", &test);
    while (test--) {
        scanf("%d %d", &min, &max);
        for (n = min; n <= max; n++) {
            r = sqrt(n);
            for (i = 0; seed[i] <= r; i++) {
                if (n % seed[i] == 0) {
                    break;
                }
            }
            if (seed[i] > r && n != 1) {
                printf("%d\n", n);
            }
        }
        printf("\n");
    }
    return(EXIT_SUCCESS);
}
