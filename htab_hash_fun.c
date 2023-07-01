// Řešení IJC-DU2, příklad 2)
// Datum: 20.4.2020
// Autor: Václav Sysel,VUT FIT
// Přeloženo: gcc 7.5.0

#include "htab.h"
#include <stdint.h>

#ifdef HASHTEST

//a random
//very bad function, hash is not big enough for big tables
size_t htab_hash_fun(htab_key_t str)
{
	uint32_t hash=0;
	const unsigned char * pointer;
	uint32_t mult = 1;
	for (pointer = str; *pointer != '\0'; pointer++)
	{
		hash = *pointer * mult
		mult += 11;
	}

	return hash;
}

#else

//hash functions sdbm
size_t htab_hash_fun(htab_key_t str)
{
	uint32_t hash=0;
	const unsigned char * pointer;
	for (pointer = (const unsigned char*) str; *pointer != '\0'; pointer++)
		hash = 65599*hash + *pointer;
	return hash;
}

#endif //HASHTEST
