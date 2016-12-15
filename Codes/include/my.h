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

int 		rand_a_b(int a, int b);
int			getRandom();
void		loadTermSaver(struct s_stats *myStats);
int			start(struct s_stats *myStats);
int			displayStats();
char		*getTime();
void		saveStats(struct s_stats *myStats);
char 		*getRandomImage();
FILE* 		getFichier(int valeur);
void 		displayTime(FILE* fichier0, FILE* fichier1, FILE* fichier2, FILE* fichier3, FILE* fichier4, FILE* fichier5, FILE* fichierX, int sizeX, int sizeY, int size);


#endif
