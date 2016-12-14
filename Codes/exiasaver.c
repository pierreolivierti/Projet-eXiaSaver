#include "include/my.h"


int 		getRandom(struct s_stats *myStats) {
	srand(time(NULL));
	myStats->type = 1 + rand() % 3;
	return 0;
}

void		loadTermSaver(struct s_stats *myStats, char **env) {
	if (myStats->type == 1) {
		myStats->type_name = "static";
	}
	else if (myStats->type == 2) {
		myStats->type_name = "dynamic";
	}
	else if (myStats->type == 3) {
		myStats->type_name = "interactive";
	}
	getTime(myStats);
	printf("%s\n", myStats->date);
	printf("myStats.type = %d\n", myStats->type);
	start(myStats, env);
}

int		start(struct s_stats *myStats, char **env) {
	pid_t	pid;
	char	*args[] = {myStats->type_name, NULL};
	printf("myStats.type = %d\n", myStats->type);
	printf("myStats.name = %s\n", myStats->type_name);

	switch (pid = fork()) {
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			execve(args[0], args, env);
			exit(0);
			break;
		default: 
			wait(0);
	}
	return 0;
}

void		displayStats() {

}

int			main(int argc, char const *argv[], char **env)
{
	int 	termsaver;
	struct s_stats	myStats;
	if (argc < 2) {
		getRandom(&myStats);
		loadTermSaver(&myStats,env);
	} else if (strncmp(argv[1], "-stats", 6) == 0) {
		displayStats();
	} else {
		printf("Usage : ./eXiaSaver [-stats]\n");
	}
	return 0;
}
