// Řešení IJC-DU2, příklad 2)
// Datum: 20.4.2020
// Autor: Václav Sysel,VUT FIT
// Přeloženo: gcc 7.5.0

#include "htab.h"
#include "htab_structs.h"

htab_value_t htab_iterator_get_value(htab_iterator_t it)
{
	return it.ptr -> data;
}
