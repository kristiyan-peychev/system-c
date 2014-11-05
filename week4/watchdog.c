#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "FUCK AWf\n");
		return 1;
	}
	daemon(0, 0);
	pid_t ffdf;
	int f = 0;
	char **args = (char **) malloc((argc - 1) * sizeof(char *)); 
	while (f < argc - 1) {
		*(args + f) = *(argv + f + 1);
		f++;
	}
	*(args + f) = (char *) 0;
	ffdf = fork();
	if (!ffdf) {
		execvp(*args, args); /* Execute the command, we're leaking memory btw */
		perror("execvp"); /* This part will execute if the execute should fail */
		exit(EXIT_FAILURE);
	} else {
		printf("To kill the daemon kill pid %d\n", getpid());
		wait(&f);
		if (WIFEXITED(f)) {
			main(argc, argv);
		}
	}
return 0;
}
