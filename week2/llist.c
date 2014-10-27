#include "llist.h"

void add_llist(llist *target, char f)
{
	while (target->next != NULL) 
		target = target->next;
	target->next = init_llist(f);
}

llist *init_llist(char f) 
{
	llist *ret;
	ret = (llist *) malloc(1 * sizeof(llist));
	ret->chr = f;
	ret->next = NULL;
return ret;
}

void destroy_llist(llist *target)
{
	if (target == NULL) 
		return;
	if (target->next != NULL)
		destroy_llist(target->next);
	free(target);
}

char get_offset_llist(llist *target, size_t size)
{
	if (size > 0) 
		return get_offset_llist(target->next, size - 1);
	else 
		return target->chr;
}

