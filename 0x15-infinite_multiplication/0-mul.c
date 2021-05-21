#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * check_int - checks if a given string is a digit.
 *
 * @num: String to check.
 *
 * Return: -> 1 if the string is a integer.
 *         -> 0 if the string is not an integer.
 *
 */
static int check_int(char *num)
{
	int i;

	for (i = 0; num[i]; i++)
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _strlen - Calculates the length of a string.
 *
 * @s: String to measure.
 *
 * Return: The length of the string.
 */
static int _strlen(char *s)
{
	return (*s != '\0' ? 1 + _strlen(++s) : 0);
}

/**
 * manual_mul - Multiplication.
 *
 * @total: Final value.
 * @argv: Argmuents passed from main.
 * @num1: First factor.
 * @num2: Second factor.
 *
 * Return: Lenght in int.
 *
 */
static void manual_mul(int *total, char *argv[], int num1, int num2)
{
	int prod, result, i, j;

	for (i = (num2 - 1); i >= 0; i--)
	{
		result = 0;
		for (j = (num1 - 1); j >= 0; j--)
		{
			prod = (argv[2][i] - '0') * (argv[1][j] - '0');
			result = (prod / 10);
			total[(i + j) + 1] += (prod % 10);

			if (total[(i + j) + 1] > 9)
			{
				total[i + j] += total[(i + j) + 1] / 10;
				total[(i + j) + 1] = total[(i + j) + 1] % 10;
			}
			total[(i + j)] += result;

		}
	}
}


/**
 * main - Program Entry Point
 *
 * @argc: Number of parameters.
 * @argv: Array of parameters.
 *
 * Return: -> 0 on success.
 *         -> 98 on failure (custom code).
 */
int main(int argc, char *argv[])
{
	int num1_len, num2_len, i;
	int *total;

	if (argc != 3 || !(check_int(argv[1])) || !(check_int(argv[2])))
	{
		puts("Error");
		exit(98);
	}

	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		printf("0\n");
		return (0);
	}

	num1_len = _strlen(argv[1]);
	num2_len = _strlen(argv[2]);

	total = calloc(num1_len + num2_len, sizeof(int));

	if (!total)
	{
		puts("Error");
		exit(98);
	}

	manual_mul(total, argv, num1_len, num2_len);
	i = *total == 0 ? 1 : 0;
	while (i < (num1_len + num2_len))
	{
		printf("%d", total[i]);
		i++;
	}
	printf("\n");
	free(total);
	return (0);

}
