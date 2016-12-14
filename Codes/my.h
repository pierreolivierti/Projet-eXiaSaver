#ifndef MY_H_
# define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "struct.h"

int			getRandom();
void		loadTermSaver(t_stats *myStats, int tsaver, char **env);
int			start(char *ts, char **env);
void		displayStats();
int			getTime(t_stats *myStats);

#endif
