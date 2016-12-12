#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#ifndef _EXIASAVER_H_H
#define	_EXIASAVER_H_H

typedef struct s_stats {
	int		ts_type;
	int		nbtotal;
	char	*filename;
	int		sizeClock;
	int		initPlane;
}			t_stats;

int			getRandom();
void		loadTermSaver(int tsaver, char **env);
void		start(char *ts, char **env);
void		displayStats();

#endif
