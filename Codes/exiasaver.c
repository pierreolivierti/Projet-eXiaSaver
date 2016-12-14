#include "include/my.h"


int 			getRandom(struct s_stats *myStats) {
	srand(time(NULL));
	myStats->type = 1 + rand() % 3;
	return 0;
}

char 			*getRandomImage() {
	int 		image;
	static char name[11];

	srand(time(NULL));
	image = 1 + rand() % 5;
	if (image == 1) {
		strcpy(name, "dessin1.pbm");
	} else if (image == 2) {
		strcpy(name, "dessin2.pbm");
	} else if (image == 3) {
		strcpy(name, "dessin3.pbm");
	} else if (image == 4) {
		strcpy(name, "dessin4.pbm");
	} else if (image == 5) {
		strcpy(name, "dessin5.pbm");
	}
	return name;
}

void			loadTermSaver(struct s_stats *myStats) {
	char		*date;
	char 		*imgname;

	system("clear");
	if (myStats->type == 1) {
		myStats->type_name = "static";
		imgname = getRandomImage();
		myStats->img_name = imgname;
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
	char		*args[] = {myStats->type_name, myStats->img_name, NULL};

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
	char		*args[] = {"cat", "/home/mrflyinrocket/Desktop/Projet-eXiaSaver/Codes/historique.txt", NULL};

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

	if (argc < 3 && strlen(argv[1]) < 2 && atoi(argv[1]) < 5 && atoi(argv[1]) > 0) {
		printf("%d\n", atoi(argv[1]));
		if(atoi(argv[1]) == 1)
			myStats.type = 1;
		else if (atoi(argv[1]) == 2)
			myStats.type = 2;
		else if (atoi(argv[1]) == 3)
			myStats.type = 3;
		else if (atoi(argv[1]) == 4)
			getRandom(&myStats);
		loadTermSaver(&myStats);
	} else if (strncmp(argv[1], "-stats", 6) == 0) {
		displayStats();
	} else {
		printf("Usage : ./eXiaSaver [-stats] : Get some stats\n");
		printf("\t\t\t1	: Static mode\n");
		printf("\t\t\t2	: Dynamic mode\n");
		printf("\t\t\t3	: Interactive mode\n");
		printf("\t\t\t4	: Random mode\n");
	}
	return 0;
}
