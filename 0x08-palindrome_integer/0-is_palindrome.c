#include "palindrome.h"

/**
 * is_palindrome - Determines if an unsigned number is a palindrome.
 *
 * @n: unsigned integer to check if it is a palindrome.
 *
 *
 *
 * Description - This function takes a number and determines if it is a
 *               palindrome, that is, if it's the same when readed backwards
 *               as it is when readed normally. It returns 1 if the number
 *               is a palindrome and 0 if the number is not a palindrome.
 *
 * Return: -> 1 if the number is a palindrome.
 *         -> 0 if the number is not a palindrome.
 *
 */
int is_palindrome(unsigned long n)
{
	unsigned long digits = 0, sup = n;

	while (sup != 0)
	{
		digits *= 10;
		digits += (sup % 10);
		sup /= 10;

	}

	if (digits == n)
		return (1);
	return (0);
}
