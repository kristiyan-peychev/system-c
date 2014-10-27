#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "llist.h"

char *extract_string(llist *list, size_t n) 
{
	char *ret = (char *) malloc(n * sizeof(char)); 
	size_t cc = 0;
	llist *itr = list;
	while (cc < n) {
		ret[cc++] = itr->chr;
		itr = itr->next;
	}
return ret;
}

int strlistncmp(char *str, llist *list, size_t n) 
{
	llist *itr = list;
	char *asd = extract_string(list, n);
	int r;
	while (!(r = strncmp(asd, str, n)) && list != NULL) {
		free(asd);
		list = list->next;
		asd = extract_string(list, n);
	}
	free(asd);
	if (list != NULL) {
		return r;
	} else {
		return 2;
	}
}

int main(int argc, const char *argv[]) {
	int fd = open("/dev/urandom", O_RDONLY);
	size_t rd_sz = 123;
	char b;
	llist *list = init_llist(0), *lul; // FOR TEH LULZ
	while (read(fd, &b, 1) == 1 && rd_sz) {
		add_llist(list, b);
		--rd_sz;
	}
	lul = list;
	list = list->next;
	free(lul);
	destroy_llist(list);
return 0;
}

