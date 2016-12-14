#include "include/my.h"


int 			getRandom(struct s_stats *myStats) {
	srand(time(NULL));
	myStats->type = 1 + rand() % 3;
	return 0;
}

void			loadTermSaver(struct s_stats *myStats) {
	char		*date;

	if (myStats->type == 1) {
		myStats->type_name = "static";
	}
	else if (myStats->type == 2) {
		myStats->type_name = "dynamic";
	}
	else if (myStats->type == 3) {
		myStats->type_name = "interactive";
	}
	date = getTime();
	myStats->date = date;
	start(myStats);
	saveStats(myStats);
}

int				start(struct s_stats *myStats) {
	pid_t		pid;
	char		*args[] = {myStats->type_name, NULL};

	printf("myStats.type = %d\n", myStats->type);
	printf("myStats.name = %s\n", myStats->type_name);
	pid = fork();
	if (pid == -1) {
		perror("fork");
	} else if (pid == 0) {
		execv(args[0], args);
		exit(0);
	} else if (pid > 0) {
		wait(&pid);
	}
	return 0;
}

int			displayStats() {
	pid_t 		pid;
	char		*args[] = {"cat", "/home/mrflyinrocket/Desktop/Projet-eXiaSaver/Codes/statistiques.txt", NULL};

	pid = fork();
	if (pid == -1) {
		perror("fork");
	} else if (pid == 0){
		execv("/bin/cat", args);
		exit(0);
	} else if (pid > 0) {
		wait(&pid);
	}
	return 0;
}

void			saveStats(struct s_stats *myStats) {
	FILE 		*stats;
	char		*buffer;
	char		*init;
	int 		i;

	init = "#Format de chaque ligne avec séparateur\
			\n#Date format jj/mm/yyyy HH:MM:ss;\
			\n#Niveau : 1=statique, 2=dynamique, 3=interactif;\
			\n#Si 1, nom fichier ; Si 2, taille d’affichage ; Si 3, position initiale avion sur la console\n";
	buffer = malloc(sizeof(char) * 255);
	stats = fopen("./statistiques.txt", "a+");
	i = 1;
	if (stats == NULL) {
		printf("Error, cannot open file\n");
	} 
	else {
		if (fgets(buffer, sizeof buffer * 255, stats) == NULL) {
			fprintf(stats, "%s\n", init);
		}
		rewind(stats);
		while (fgets(buffer, 255, stats) != NULL) {
			i = i + 1;
		}
		i = i - 5;
		if (myStats->type == 1) {
			fprintf(stats, "%d : %s;%d\n", i, myStats->date, myStats->type/*, myStats->img_name*/);
		} else if (myStats->type == 2) {
			fprintf(stats, "%d : %s;%d\n", i, myStats->date, myStats->type/*, myStats->size*/);
		} else if (myStats->type == 3) {
			fprintf(stats, "%d : %s;%d\n", i, myStats->date, myStats->type/*, myStats->pos*/);
		}
		fclose(stats);
	}
}

int				main(int argc, char const *argv[], char **env)
{
	int 		termsaver;
	struct s_stats	myStats;
	if (argc < 2) {
		getRandom(&myStats);
		loadTermSaver(&myStats);
	} else if (strncmp(argv[1], "-stats", 6) == 0) {
		displayStats();
	} else {
		printf("Usage : ./eXiaSaver [-stats]\n");
	}
	return 0;
}
