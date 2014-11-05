#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <pthread.h>

int wfd;

void *filez(void *ar) 
{
	int a;
	char wat[1024];
	int fd = open((char *) ar, O_RDONLY);
	printf("%d\n", 1);
	while ((a = read(fd, wat, 1023)) > 0) {
		printf("%d asdd\n", fd);
		write(wfd, wat, a);
	}
	close(fd);
}

int main(int argc, const char *argv[]) {
	pthread_t threads[5];
	int a;
	char wat[1024];
	char *files_list[] = 
	{ 	"/home/kawaguchi/FC42CFAF/src/containers/_class.c",
		"/home/kawaguchi/FC42CFAF/src/containers/_func_nfo.c",
		"/home/kawaguchi/FC42CFAF/src/containers/_method_nfo.c",
		"/home/kawaguchi/FC42CFAF/src/containers/_template.c",
		"/home/kawaguchi/FC42CFAF/src/containers/substr.c" 
	};
	int i = 0;
	wfd = open("/falos/DELETE_ME", O_CREAT | O_WRONLY);
	while (i < 5) {
		pthread_create(&threads[i], NULL, filez, (void *) files_list[i]);
		printf("asd %d\n", i);
		i++;
	}
	close(wfd);
return 0;
}

