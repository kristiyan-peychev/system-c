#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, const char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "FUCK AWf\n");
		return 1;
	}
	daemon(0, 0);
	pid_t ffdf;
	int f;
	ffdf = fork();
	if (!ffdf) {
		execvp(argv[1], (char * const *) argv[1]);
	} else {
		do {
			wait(&f);
			if (WIFEXITED(f)) {
				main(argc, argv);
			}
		} while (1);
	}
return 0;
}
