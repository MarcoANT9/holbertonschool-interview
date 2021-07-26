#include "holberton.h"

/**
 * wildcmp - Compares two strings with wildcards
 *
 * @s1: First string to compare.
 * @s2: Comparator string, may include wildcard.
 *
 * Description - Compares String 1 with String 2, which may contain the
 *               wildcard *, this wildcard can take any value.
 *
 * Return: → 1 if the strings are the same.
 *         → 0 if the strings are different.
 */

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}
	if (*s1 == *s2)
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
		{
			return (wildcmp(s1, s2 + 1));
		}
		else if (wildcmp(s1, s2 + 1))
		{
			return (1);
		}
		else
		{
			return (wildcmp(s1 + 1, s2));
		}
	}
	return (0);
}
