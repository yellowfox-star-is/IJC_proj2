// Řešení IJC-DU2, příklad 1),2)
// Datum: 20.4.2020
// Autor: Václav Sysel,VUT FIT
// Přeloženo: gcc 7.5.0
#include "htab.h"
#include "htab_structs.h"

htab_iterator_t htab_begin(const htab_t * t)
{
	htab_iterator_t it;
	it.t = t;
	it.idx = 0;
	it.ptr = t -> ptr[0];
	return it;
}
