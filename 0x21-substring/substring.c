#include "substring.h"

/**
 * find_substring -  Finds all the possible substrings containing a list.
 * @s: Is the string to scan.
 * @words: Is the array of words all substrings must be a concatenation.
 * @nb_words: Is the number of elements in the array words.
 * @n: Holds the address at which to store the number of elements in the
 * returned array.
 *
 * Return: -> An allocated array, storing each index in s, at which a substring
 *            was found.
 *         -> NULL If no solution is found.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int index, count, strL, wLen, check, i, j, k;
	int *match, *posArray;

	if (!s || !words || !n || nb_words == 0)
		return (NULL);

	strL = strlen(s);
	wLen = strlen(words[0]);
	posArray = malloc(strL * sizeof(int));
	if (!posArray)
		return (NULL);
	match = malloc(nb_words * sizeof(int));
	if (!match)
		return (NULL);

	for (i = count = 0; i <= strL - nb_words * wLen; i++)
	{
		memset(match, 0, nb_words * sizeof(int));
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				index = i + j * wLen;
				check = strncmp(s + index, *(words + k), wLen);
				if (!*(match + k) && !check)
				{
					*(match + k) = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			*(posArray + count) = i, count +=1;
	}
	free(match);
	*n = count;
	return (posArray);
}
