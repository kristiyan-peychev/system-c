#include <stdlib.h>

int main(int argc, const char *argv[]) {
	char *pointer = (char *) malloc(6563875 * sizeof(char)); 
	printf("memleak\n");
return 0;
}
