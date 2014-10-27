#ifndef LLIST_CZV9Y8XM

#define LLIST_CZV9Y8XM

#include <stdio.h>
#include <stdlib.h>

typedef struct llist_t llist;

typedef struct llist_t
{
	char chr;
	llist *next;
} llist;

llist *init_llist(char);
//char get_val_llist(llist *target) { return target->chr; }
llist *get_next(llist *);
void add_llist(llist *, char);
char get_offset_llist(llist *, size_t);
void destroy_llist(llist *target); /* recursive? */

#endif /* end of include guard: LLIST_CZV9Y8XM */
