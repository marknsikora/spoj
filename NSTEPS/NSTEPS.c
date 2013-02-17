#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int test, r, x, y;
    scanf("%d", &test);
    while(test--) {
        scanf("%d %d", &x, &y);

        /*
         * Esentially what we are trying to do is match whether or not
         * a point is on one of two lines. After that is a bit more
         * tricky. We have to calculate the value at that point based
         * on the coordinates, this can be seen in a sense as a
         * tranlation from R2 --> R1.
         *
         */

        if (y == x) {
            r = (4*x+((x+1)%2)*2-2)/2;
            printf("%d\n", r);
        } else if (y == x - 2) {
            r = (4*x+((x+1)%2)*2-6)/2;
            printf("%d\n", r);
        } else {
            printf("No Number\n");
        }
    }
    return EXIT_SUCCESS;
}
