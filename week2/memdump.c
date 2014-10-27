#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
	unsigned long long offset = 0;
	char b;
	int memfd = open("/dev/mem", O_RDONLY);
	/*offset = 1231;*/
	while (read(memfd, &b, 1) == 1) {
		/*printf("%d :%c(%d)\n", offset, b, b);*/
		++offset;
	}
return 0;
}

