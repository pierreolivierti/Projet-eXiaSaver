#include "include/my.h"


int 		getRandom(struct s_stats *myStats) {
	srand(time(NULL));
	myStats->type = 1 + rand() % 3;
	return 0;
}

void		loadTermSaver(struct s_stats *myStats) {
	char	*date;
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
}

int		start(struct s_stats *myStats) {
	pid_t	pid;
	char	*args[] = {myStats->type_name, NULL};
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

void		displayStats() {

}

void		saveStats(struct s_stats *myStats) {
	FILE 	*stats;
	char	*buffer;
	char	*init;
	char 	*msg_tpye1;
	char	*msg_type2;
	char	*msg_type3;

	init = "HEYY";
	buffer = malloc(sizeof(char) * 255);
	stats = fopen("./statistiques.txt", "a");
	if (stats == NULL) {
		printf("Error, cannot open file\n");
	} 
	else {
		if (fgets(buffer, sizeof buffer, stats) == NULL) {
			fprintf(stats, "%s\n", init);
		} else {
			if (myStats->type == 1) {
				fprintf(stats, "%s%c%s%c%s\n", myStats->date, 59, myStats->type, 59, myStats->filename);
				printf("%s%c%s%c%s\n", myStats->date, 59, myStats->type, 59, myStats->filename);
			} else if (myStats->type == 2) {
				fprintf(stats, "%s\n", msg_type2);
				printf("%s%c%s%c%s\n", myStats->date, 59, myStats->type, 59, myStats->filename);
			} else if (myStats->type == 3) {
				fprintf(stats, "%s\n", msg_type3);
				printf("%s%c%s%c%s\n", myStats->date, 59, myStats->type, 59, myStats->filename);
			}
		}
	}
}

int			main(int argc, char const *argv[], char **env)
{
	int 	termsaver;
	struct s_stats	myStats;
	if (argc < 2) {
		getRandom(&myStats);
		loadTermSaver(&myStats);
		saveStats(&myStats);
	} else if (strncmp(argv[1], "-stats", 6) == 0) {
		displayStats();
	} else {
		printf("Usage : ./eXiaSaver [-stats]\n");
	}
	return 0;
}
