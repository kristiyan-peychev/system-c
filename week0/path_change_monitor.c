#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

#define WAIT_TIME 2

void sigint_handle(int s) 
{
	printf("\nCaught interrupt signal, ending monitoring.\n");
	exit(EXIT_SUCCESS);
}

char diff_tm(struct tm *f, struct tm *s) {
return 	s->tm_sec != f->tm_sec ||
	s->tm_min != f->tm_min || 
	s->tm_hour != f->tm_hour ||
	s->tm_mday != f->tm_mday ||
	s->tm_mon != f->tm_mon || 
	s->tm_year != f->tm_year ||
	s->tm_wday != f->tm_wday || 
	s->tm_yday != f->tm_yday || 
	s->tm_isdst != f->tm_isdst;
}

void copy_tm(struct tm *f, struct tm *s) 
{
	s->tm_sec = f->tm_sec;
	s->tm_min = f->tm_min;
	s->tm_hour = f->tm_hour;
	s->tm_mday = f->tm_mday;
	s->tm_mon = f->tm_mon;
	s->tm_year = f->tm_year;
	s->tm_wday = f->tm_wday;
	s->tm_yday = f->tm_yday;
	s->tm_isdst = f->tm_isdst;
}

int run_stat(const char *path, struct stat *sp) 
{
	if (stat(path, sp) == -1) {
		perror("stat");
		return 1;
	}
return 0;
}

int main(int argc, const char *argv[]) {
	struct stat stat_buffer;
	struct tm *time_ch, *time_co;
	time_co = (struct tm *) malloc(1 * sizeof(struct tm *)); 
	signal(SIGINT, sigint_handle);
	if (argc != 2) {
		fprintf(stderr, "Usage: `%s <directory path>` \n", *argv);
		return 1;
	}
	if (run_stat(argv[1], &stat_buffer) == 1) 
		exit(EXIT_FAILURE);
	time_ch = gmtime(&stat_buffer.st_mtime);   // Get the time at which the object 
	copy_tm(time_ch, time_co); 		// we are monitoring was last changed 
	do {
		if (run_stat(argv[1], &stat_buffer) == 1) 
			exit(EXIT_FAILURE);
		time_ch = gmtime(&stat_buffer.st_mtime);
		if (diff_tm(time_ch, time_co)) {
			printf("Change detected in `%s`\n", argv[1]);
			copy_tm(time_ch, time_co);
		}
		sleep(WAIT_TIME); // Sleep for WAIT_TIME seconds TODO argument editing
	} while (1);
return 0;
}

