#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

#ifndef _EXIASAVER_H_H
#define	_EXIASAVER_H_H

struct 		s_stats {
	char	*date;
	int		type;
	char	*filename;
	char	*size;
	char	*pos;
};

typedef struct s_stats T_STAT;

int			getRandom();
void		loadTermSaver(int tsaver, char **env);
int			start(char *ts, char **env);
void		displayStats();
int			getTime();

#endif
