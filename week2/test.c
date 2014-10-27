#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, const char *argv[]) {
	int fd, c = 0;
	char b, fstr[32] = "";
	sprintf(fstr, "/proc/%d/mem", getpid());
	fd = open(fstr, O_RDONLY);
	while (read(fd, &b, 1) == 1) {
		printf("READ: %c\n", b);
		++c;
	}
	printf("End. %d\n", c);
return 0;
}
