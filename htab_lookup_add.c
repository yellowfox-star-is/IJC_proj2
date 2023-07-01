// Řešení IJC-DU2, příklad 2)
// Datum: 20.4.2020
// Autor: Václav Sysel,VUT FIT
// Přeloženo: gcc 7.5.0

#include "htab.h"
#include "htab_structs.h"
#include <stdlib.h>

htab_iterator_t htab_lookup_add(htab_t * t, htab_key_t key)
{
	htab_iterator_t it = htab_find(t, key);
	htab_iterator_t end = htab_end(t);
	if (htab_iterator_equal(it, end))
	{
		char *string = malloc(sizeof(char) * strlen(key) + 1);
		struct htab_item * item = NULL;
		if (string == NULL)
			return end;

		it.idx = (htab_hash_fun(key) % t -> arr_size );

		item = malloc(sizeof(struct htab_item));
		if (item == NULL)
		{
			free(string);
			return end;
		}

		it.ptr=item;
		item->key=string;
		item->data=0;
		item->next=NULL;
        strcpy(string, key);

        struct htab_item *place;
		if (t -> ptr[it.idx] == NULL)
		{
            t->ptr[it.idx] = item;
        }
		else
		{
            place = t->ptr[it.idx];
            while (1)
            {
                if (place->next == NULL) {
                    place->next = item;
                    break;
                } else {
                    place = place->next;
                }
            }
        }

        t -> size=t -> size + 1;

		//old code
		/*
		it.ptr = t -> ptr[it.idx];
		while (it.ptr != NULL)
        {
		    it.ptr = it.ptr -> next;
        }
		it.ptr=item;
		strcpy(string, key);
		t -> ptr[it.idx] -> key = string;
		it.ptr = t -> ptr[it.idx];
		 */
		return it;
	}
	else
	{
		return it;
	}
}
