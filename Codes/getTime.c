#include <time.h>
#include <stdio.h>
#include <string.h>

char	 	getTime() {
    char 	*Time;
    int 	i;
    int		j;
    int		timelen;
    char	ftime[9];
    time_t 	mytime;

    i = 0;
    j = 0;
    mytime = time(NULL);
    Time = ctime(&mytime);
    i = strlen(Time);
    timelen = i - 6;
    i = i - 14;
    while (i < timelen) {
    	ftime[j] = Time[i];
		i++;
		j++;
    }
    return ftime;
}