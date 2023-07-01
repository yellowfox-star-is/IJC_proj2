// Řešení IJC-DU2, příklad 2)
// Datum: 20.4.2020
// Autor: Václav Sysel,VUT FIT
// Přeloženo: gcc 7.5.0

#include "htab.h"
#include "htab_structs.h"
#include <stdlib.h>
#include <stdio.h>

void htab_clear(htab_t * t)
{
	//t -> size = 0;
	struct htab_item *ptr;
	struct htab_item *mem;
	for (unsigned long i = 0; i < t -> arr_size; i++)
	{
		ptr = t -> ptr[i];
		while (ptr != NULL)
		{
			mem	= ptr -> next;
			free((void *) ptr -> key);
			free(ptr);
			t -> size = t -> size - 1;
			ptr = mem;
		}
		t -> ptr[i] = NULL;
	}

	if (t -> size > 0)
	{
		fprintf(stderr, "Not all items in table freed, memory probably lost.\n");
	}
}
