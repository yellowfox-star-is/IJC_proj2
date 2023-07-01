// Řešení IJC-DU2, příklad 2)
// Datum: 20.4.2020
// Autor: Václav Sysel,VUT FIT
// Přeloženo: gcc 7.5.0

#include <stdio.h>
#include <ctype.h>
#include "io.h"

int get_word(char *s, int max, FILE *f)
{
	static int sent = 0;
	int x = 0;
	int c = 0;
	while ( x <= max - 1) {
        c = getc(f);

        if (x != 0 || isspace(c) == 0) //if x == 0 and input is space, skip this part
        {
            if (c == EOF || isspace(c) != 0) {
                s[x] = 0;
                break;
            }

            s[x] = c;
            x++;
        }
	}

	if (x >= max /*&& s[x] != 0*/)
	{
		s[x] = 0;
		if (sent == 0)
		{
			fprintf(stderr, "Word exceeded maximum (%d chars), all words will be shorten to the max - 1.\n", max);
			sent = 1;
		}
		while ((isspace(c) == 0 && c != EOF))
		{
			c = getc(f);
		}
	}

	if (x == 0 && c == EOF)
	{
		return EOF;
	}

	return x;
}
