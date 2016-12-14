#include "include/my.h"

int	 		getTime(struct s_stats *myStats) {
    time_t 	now;
    struct tm* now_tm;
    char 	*t;

    time(&now);
    now_tm = localtime(&now);
    strftime (myStats->date, 80, "%d/%m/%Y %H:%M:%S", now_tm);

    return 0;
}