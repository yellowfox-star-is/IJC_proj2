// Řešení IJC-DU2, příklad 1)
// Datum: 20.4.2020
// Autor: Václav Sysel,VUT FIT
// Přeloženo: gcc 7.5.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[])
{
	FILE * filestream = NULL;
	int nolines = 0; //number of lines
	int SendError = 1;

	//getting arguments
	if (argc != 1) //there are some arguments
	{
		for (int i = 1; i < argc; i++)
		{
			if ((strncmp(argv[i], "-n", 2) == 0)) //if argument is -n
			{
				if (i < argc) //and there is enough arguments behind it
				{
					if (nolines == 0) //and we have no number yet
					{
						nolines = abs(atoi(argv[i + 1]));
						if (nolines <= 0) //if nothing was convereted, make an error
						{
							fprintf(stderr, "Nothing was converted from argument after -n.\n");
							return 1;
						}
					}
					else //here we already have an -n argument
					{
						fprintf(stderr, "Too manny -n arguments.\n");
						if (filestream != NULL)
							fclose(filestream);
						return 1;
					}
				}
				else //there was no argument after -n
				{
					fprintf(stderr, "Found no argument after -n.\n");
					return 1;
				}
			}
			else //it is something else than -n
			{
				if (strncmp(argv[i - 1], "-n", 2) != 0) //check if there is -n before it if no, it is probably file name
				{
					if (filestream == NULL) //check if we already have some opened file
					{
						filestream = fopen(argv[i], "r");
						if (filestream == NULL)
						{
							fprintf(stderr, "Unable to open file: %s\n", argv[i]);
							return 1;
						}
					}
					else //here we already have a file
					{
						fprintf(stderr, "Too many file names.\n");
						fclose(filestream);
						return 1;
					}
				}
			}

		}
	}
	
	//check if we need tu supplement some arguments
	int IsStdin = 0;
	if (filestream == NULL)
	{
		filestream = stdin;
		IsStdin = 1;
	}
	if (nolines == 0)
		nolines = 10; //set by implementation

	//allocate memory
	char **output = NULL;
	output = malloc(nolines * sizeof(char *));
	if (output == NULL)
		goto memoryhell;
	int i = 0;
	while (i < nolines)
	{
		output[i] = calloc(1025, sizeof(char));
		if (output[i] == NULL)
			goto deepmemoryhell;
		output[i][0] = 0;
		i++;
	}

	//do the stuff
	
	int c = 0;
	int x = 0;
	char swap = 0;
	while ((c = fgetc(filestream)) != EOF)
	{
		if (swap)
		{
			swap = 0;
			char * temporary = output[0];
			for (int i = 1; i < nolines; i++)
			{
				output[i - 1] = output[i];
			}
			output[nolines - 1] = temporary;
		}

		if (x < 1023)
			output[nolines - 1][x] = c;
		x++;

		if (c == '\n' && x < 1023)
		{
			output[nolines - 1][x] = 0;
			x = 0;
			swap = 1;
		}
		else if (x == 1023)
		{
			output[nolines - 1][x] = '\n';
			output[nolines - 1][x + 1] = 0;
			if (SendError)
			{
				SendError = 0;
				fprintf(stderr, "Lines are longer than 1023 chars, these lines will be shortened to 1024 chars including newline.\n");
			}
		}
		else if (x > 1023)
		{
			x--;
			if (c == '\n')
			{
				swap = 1;
				x = 0;
			}
		}
	}

	for (int i = 0; i < nolines; i++)
	{
		printf("%s", output[i]);
	}

	for (int i = 0; i < nolines; i++)
	{
		free(output[i]);
	}

	free(output);
	if (!(IsStdin))
	    fclose(filestream);

	return 0;


	//errors
deepmemoryhell:
	while (i > 0)
	{
		free(output[i]);
		i--;
	}
	free(output);
memoryhell:
	if (!(IsStdin))
		fclose(filestream);
	fprintf(stderr, "The programm is currently in memory hell. There is nothing I can do.\n");

	return 1;
}
