// Řešení IJC-DU2, příklad 2)
// Datum: 20.4.2020
// Autor: Václav Sysel,VUT FIT
// Přeloženo: gcc 7.5.0

#include "htab.h"
#include "htab_structs.h"

size_t htab_bucket_count(const htab_t * t)
{
	return t -> arr_size;
}
