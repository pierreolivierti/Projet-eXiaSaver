#include "include/eXiaSaver.h"

int	 		getTime() {
	T_STAT	myStats;
    time_t 	now;
    struct tm* now_tm;
    char 	date[80];
    char 	*t;

    time(&now);
    now_tm = localtime(&now);
    strftime (date, 80, "%d/%m/%Y %H:%M:%S", now_tm);
    printf("%s\n", date);
    myStats.date = date;
    printf("%s\n", myStats.date);
    return 0;
}