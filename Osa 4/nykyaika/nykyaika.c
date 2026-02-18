#include <stdio.h>
#include <time.h>

int main(void) {
    time_t now;
    struct tm *local;
    
    const char *weekdays[] = {
        "Sunnuntai",
        "Maanantai",
        "Tiistai",
        "Keskiviikko",
        "Torstai",
        "Perjantai",
        "Lauantai"
    };

    time(&now);
    local = localtime(&now);

    if (local == NULL) {
        return 1;
    }

    printf("%s %02d.%02d.%04d klo %02d:%02d\n",
           weekdays[local->tm_wday],
           local->tm_mday,
           local->tm_mon + 1,
           local->tm_year + 1900,
           local->tm_hour,
           local->tm_min);

    return 0;
}