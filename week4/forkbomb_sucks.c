#include <unistd.h>
#include <stdlib.h>

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int daemon( int nochdir, int noclose )
{
	pid_t pid;
	if ( !nochdir && chdir("/") != 0 )
		return -1;
	if ( !noclose ) {
		int fd = open("/dev/null", O_RDWR);
		if ( fd < 0 )
			return -1;
		if ( dup2( fd, 0 ) < 0 ||
				dup2( fd, 1 ) < 0 ||
				dup2( fd, 2 ) < 0 )
		{
			close(fd);
			return -1;
		}
		close(fd);
	}
	pid = fork();
	if (pid < 0)
		return -1;
	if (pid > 0)
		_exit(0);
	if ( setsid() < 0 )
		return -1;

	return 0;
}

int dodo() 
{
	int *asdr = (int *) malloc(123123);
	pid_t pid1 = fork();
	pid_t pid2 = fork();
	if (pid1 == 0) 
		dodo();
	if (pid2 == 0)
		dodo();
	wait(1); /* Cuz yeah */
}

int main(int argc, const char *argv[]) {
	daemon(0, 0);
	dodo();
	return 0;
}
