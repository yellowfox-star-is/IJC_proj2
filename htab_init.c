// Řešení IJC-DU2, příklad 2)
// Datum: 20.4.2020
// Autor: Václav Sysel,VUT FIT
// Přeloženo: gcc 7.5.0

#include "htab.h"
#include "htab_structs.h"
#include <stdlib.h>

htab_t *htab_init(size_t n)
{
	htab_t * hashtable = malloc(sizeof(htab_t) + (sizeof(struct htab_item *) * n));
	if (hashtable == NULL)
		return NULL;
	
	hashtable -> size = 0;
	hashtable -> arr_size = n;
	//hashtable -> ptr = malloc(sizeof(struct htab_item *) * n); //will be alocated thanks to flexible array member
	
	for (unsigned long i = 0; i < hashtable -> arr_size; i++)
	{
		hashtable -> ptr[i] = NULL;
	}
	return hashtable;
}
