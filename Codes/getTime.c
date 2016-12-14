#include "include/my.h"

char	 	*getTime() {
    time_t 	now;
    struct  tm* now_tm;
    char 	*t;
    static char date[22];

    time(&now);
    now_tm = localtime(&now);
    strftime (date, 80, "%d/%m/%Y %H:%M:%S", now_tm);
    return date;
}