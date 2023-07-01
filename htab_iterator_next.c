// Řešení IJC-DU2, příklad 2)
// Datum: 20.4.2020
// Autor: Václav Sysel,VUT FIT
// Přeloženo: gcc 7.5.0

#include "htab.h"
#include "htab_structs.h"

htab_iterator_t htab_iterator_next(htab_iterator_t it)
{
	do
	{
		if (it.ptr == NULL)
		{
			it.idx += 1;
			if (it.idx >= it.t -> arr_size)
			{
				break;
			}
			it.ptr = it.t -> ptr[it.idx];
		}
		else
		{
			it.ptr = it.ptr -> next;
		}
	} while (it.ptr == NULL);
	return it;
}
