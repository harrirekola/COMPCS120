#include <limits.h>

#include "gotokoe.h"

int max2D(int **t2d, int kork, int lev)
{
    int i = 0, j;
    int max = INT_MIN;

    OUTER_LOOP_START:
        if (!(i < kork)) goto END;
        j = 0;

    INNER_LOOP_START:
        if (!(j < lev)) goto NEXT_ROW;
        if (!(t2d[i][j] > max)) goto SKIP_UPDATE;
        max = t2d[i][j];

    SKIP_UPDATE:
        j++;
        goto INNER_LOOP_START;

    NEXT_ROW:
        i++;
        goto OUTER_LOOP_START;

    END:
        return max;

}
