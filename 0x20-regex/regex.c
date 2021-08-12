#include "regex.h"

/**
 * regex_match - Checks if a given pattern matches a given string according to
 *               Regex
 *
 * @str: Reference string (char const *).
 * @pattern: Pattern to scan - Regex (char const *).
 *
 * Return: -> 1 if the pattern matches the string (int).
 *         -> 0 if the pattern doesn't match the string (int).
 *
 */
int regex_match(char const *str, char const *pattern)
{
	int tmp = 0, temp = 0;

	if (!str || !pattern)
		return (0);

	tmp = *str && (*str == *pattern || *pattern == '.');
	temp = *(pattern + 1) == '*';

	if (!*str && !temp)
		return (*pattern ? 0 : 1);

	else if (tmp && temp)
		return (regex_match(str + 1, pattern) ||
			regex_match(str, pattern + 2));

	else if (tmp && !temp)
		return (regex_match(str + 1, pattern + 1));

	else if (temp)
		return (regex_match(str, pattern + 2));
	return (0);
}
