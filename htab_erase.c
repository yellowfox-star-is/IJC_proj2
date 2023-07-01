// Řešení IJC-DU2, příklad 2)
// Datum: 20.4.2020
// Autor: Václav Sysel,VUT FIT
// Přeloženo: gcc 7.5.0

#include "htab.h"
#include "htab_structs.h"
#include <stdlib.h>
#include <stdio.h>

void htab_erase(htab_t * t, htab_iterator_t it)
{
	struct htab_item *prev = t -> ptr[it.idx];
	if (prev == it.ptr)
	{
		t -> ptr[it.idx] = it.ptr -> next;
		free(it.ptr);
		it.ptr = NULL;
		return;
	}
	else
	{
		while (prev -> next != it.ptr)
		{
			if (prev == NULL)
			{
				fprintf(stderr, "Pointer in iterator wasn't found in index: %ld\n", it.idx);
				return;
			}
			prev = prev -> next;
		}
		prev -> next = it.ptr -> next;
		free(it.ptr);
		it.ptr = NULL;
	}
	return;
}
