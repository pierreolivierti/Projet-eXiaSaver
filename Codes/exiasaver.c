#include "include/eXiaSaver.h"

int 		getRandom() {
	int		termsavernb;
	srand(time(NULL));
	termsavernb = 1 + rand() % 3;
	return termsavernb;
}

void		loadTermSaver(int tsaver, char **env) {
	char 	*termsaver;
	if (tsaver == 1) {
		termsaver = "static";
	}
	else if (tsaver == 2) {
		termsaver = "dynamic";
	}
	else if (tsaver == 3) {
		termsaver = "interactive";
	}
	start(termsaver, env);
}

void		start(char *ts, char **env) {
	pid_t	pid;
	char	*args[] = {ts, NULL};
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
}

void		displayStats() {

}

int			main(int argc, char const *argv[], char **env)
{
	int 	termsaver;

	if (argc < 2) {
		termsaver = getRandom();
		loadTermSaver(termsaver, env);
	} else if (strncmp(argv[1], "-stats", 6) == 0) {
		displayStats();
	} else {
		printf("Usage : ./eXiaSaver [-stats]\n");
	}
	return 0;
}
