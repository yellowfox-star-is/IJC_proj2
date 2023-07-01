// Řešení IJC-DU2, příklad 2)
// Datum: 20.4.2020
// Autor: Václav Sysel,VUT FIT
// Přeloženo: gcc 7.5.0

#include "htab.h"
#include "htab_structs.h"

htab_iterator_t htab_end(const htab_t * t)
{
	htab_iterator_t it;
	it.t = t;
	it.idx = t -> arr_size;

	//it.ptr = *(t -> ptr + t -> arr_size);
	it.ptr = NULL;

	return it;
}
