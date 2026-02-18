#include "viikko.h"
#include <stdio.h>
#include <time.h>

void viikko(int pv, int kk, int vuosi) {
    struct tm t;
    int days_since_monday;
    int i;
    char buf[128];

    t.tm_sec   = 0;
    t.tm_min   = 0;
    t.tm_hour  = 12;
    t.tm_mday  = pv;
    t.tm_mon   = kk - 1;
    t.tm_year  = vuosi - 1900;
    t.tm_isdst = -1;

    mktime(&t);

    days_since_monday = (t.tm_wday + 6) % 7;
    t.tm_mday -= days_since_monday;
    mktime(&t);

    for (i = 0; i < 7; i++) {
        strftime(buf, sizeof(buf), "%A %d. %B %Y", &t);
        printf("%s\n", buf);
        t.tm_mday++;
        mktime(&t);
    }
}