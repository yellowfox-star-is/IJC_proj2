// Řešení IJC-DU2, příklad 2)
// Datum: 20.4.2020
// Autor: Václav Sysel,VUT FIT
// Přeloženo: gcc 7.5.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htab.h"
#include "io.h"

#define max 127


int main ()
{
    htab_t * hasht = htab_init(8192);
	//poznámka ke zvolené velikosti:
	//pokud velikost je příliš malá, program rychle zaplní volná místa a prakticky začíná procházet lineární seznam
	//pokud velikost překročí určitou velikost, program pouze plýtvá pamětí a rychlost programu je konstantní
	//tuto velikost jsem zvolil, protože je dostatečně velká pro většinu velkých souborů
	//pro vetšinu normálních souborů dokonče příliš velká
    if (hasht == NULL)
	{
        return 1;
	}

    htab_iterator_t it = htab_begin(hasht);
    htab_iterator_t end = htab_end(hasht);
    char s[max + 1];
	s[0]=0;
    while (get_word(s, max, stdin) != EOF)
    {
        it = htab_lookup_add(hasht, s);
        if (htab_iterator_equal(it, end))
		{
            free(hasht);
			return 1;
		}
        //printf("%d", it.idx); //DEBUGGING
        htab_iterator_set_value(it, htab_iterator_get_value(it) + 1);
    }

    it = htab_begin(hasht);
    while (it.idx != end.idx)
    {
        if (htab_iterator_valid(it))
        {
            printf("%s\t%d\n", htab_iterator_get_key(it), htab_iterator_get_value(it));
        }
        it = htab_iterator_next(it);
    }

    htab_free(hasht);
    return 0;
}
