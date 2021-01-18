#ifndef LISTS_H
#define LISTS_H

/**========================================================================*/
/**-LIBRARIES--------------------------------------------------------------*/
/**========================================================================*/

#include <stdio.h>

/**========================================================================*/
/**-STRUCTURES & DEFINITIONS-----------------------------------------------*/
/**========================================================================*/

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;


/**========================================================================*/
/**-FUNCTIONS--------------------------------------------------------------*/
/**========================================================================*/

/** Prints a linked list  */
size_t print_listint(const listint_t *h);

/** Adds a node at the end of a linked list  */
listint_t *add_nodeint_end(listint_t **head, const int n);

/** Frees the mallocs of a linked list  */
void free_listint(listint_t *head);

/** Verifies if a linked list is a palindrome */
int is_palindrome(listint_t **head);


/**========================================================================*/
/**-SPECIAL NOTES & OTHERS-------------------------------------------------*/
/**========================================================================*/

/** I hate palindromes :( */

/**========================================================================*/
/**-END--------------------------------------------------------------------*/
/**========================================================================*/
#endif
