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
void		loadTermSaver(struct s_stats *myStats);
int			start(struct s_stats *myStats);
int			displayStats();
char		*getTime();
void		saveStats(struct s_stats *myStats);

#endif
