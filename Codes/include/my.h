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
void		loadTermSaver(struct s_stats *myStats, char **env);
int			start(struct s_stats *myStats, char **env);
void		displayStats();
int			getTime(struct s_stats *myStats);

#endif
