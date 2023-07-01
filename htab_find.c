// Řešení IJC-DU2, příklad 2)
// Datum: 20.4.2020
// Autor: Václav Sysel,VUT FIT
// Přeloženo: gcc 7.5.0

#include "htab.h"
#include "htab_structs.h"

htab_iterator_t htab_find (htab_t * t, htab_key_t key)
{
	htab_iterator_t iterator;
	iterator.t = t;
	iterator.idx = (htab_hash_fun(key) % t -> arr_size );

	iterator.ptr = t -> ptr[iterator.idx];
	while ( htab_iterator_valid(iterator) && (strcmp(iterator.ptr -> key, key) != 0))
	{
		iterator.ptr = iterator.ptr -> next;
	}

	if (!htab_iterator_valid(iterator))
		iterator = htab_end(t);
	return iterator;
}
