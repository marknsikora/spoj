/*
 * TOANDFRO
 * SPOJ Problem 400
 *
 * Author: Mark Sikora
 * Date: 2010/01/13 20:30
 *
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int cur, i, len, offset, range;
    char code[255], solution[255];
    
    while (scanf("%d", &range) && range) {
        scanf("%s", code);
        len = strlen(code);
        
        for (cur = 0, i = 0; i < len; i++) {
            if (i % range == 0 && i) {
                i += range;
                cur += range;
            }
            solution[cur++] = code[i];
        }
        for (cur = range * 2, i = range; i < len; ++i) {
            if (cur + range == i) {
                i += range;
                cur += range * 3;
            }
            solution[--cur] = code[i];
        }
        strcpy(code, solution);
        
        for (cur = 0, offset = 0; offset < range; offset++) {
            for (i = offset; i < len; i += range) {
                solution[cur++] = code[i];
            }
        }
        solution[cur] = '\0';
    
        printf("%s\n", solution);
    }
    return 0;
}

