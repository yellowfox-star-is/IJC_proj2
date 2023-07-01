// Řešení IJC-DU2, příklad 2)
// Datum: 20.4.2020
// Autor: Václav Sysel,VUT FIT
// Přeloženo: gcc 7.5.0

#ifndef __HTAB_STRUCTS__
#define __HTAB_STRUCTS__

//#include "htab.h"

struct htab
{
	unsigned long size;
	unsigned long arr_size;
	struct htab_item * ptr[];
};

struct htab_item {
	htab_key_t key;
	htab_value_t data;
	struct htab_item * next;
};

#endif // __HTAB_STRUCTS__
