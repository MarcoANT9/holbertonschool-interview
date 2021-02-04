#ifndef LISTS_H
#define LISTS_H

/**========================================================================*/
/**-LIBRARIES--------------------------------------------------------------*/
/**========================================================================*/

#include <stdlib.h>

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

/** Prints a linked list on the standard output */
size_t print_listint(const listint_t *h);

/** Adds a node to the list */
listint_t *add_nodeint(listint_t **head, const int n);

/** Frees the list from the memory */
void free_listint(listint_t *head);

/** Determines if there is a cycle in the linked list */
int check_cycle(listint_t *list);


/**========================================================================*/
/**-SPECIAL NOTES & OTHERS-------------------------------------------------*/
/**========================================================================*/



/**========================================================================*/
/**-END--------------------------------------------------------------------*/
/**========================================================================*/
#endif
