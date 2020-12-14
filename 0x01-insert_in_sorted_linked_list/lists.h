#ifndef LISTS_H
#define LISTS_H

/**========================================================================*/
/**-LIBRARIES--------------------------------------------------------------*/
/**========================================================================*/

#include <stdlib.h>
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

/** 1. Prints a linked list */
size_t print_listint(const listint_t *h);

/** 2. Adds a node in the end of a linked list */
listint_t *add_nodeint_end(listint_t **head, const int n);

/** 3. Frees the memory from a linked list */
void free_listint(listint_t *head);

/** 4. Adds a node in any position of a linked list */
listint_t *insert_node(listint_t **head, int number);

/**========================================================================*/
/**-SPECIAL NOTES & OTHERS-------------------------------------------------*/
/**========================================================================*/



/**========================================================================*/
/**-END--------------------------------------------------------------------*/
/**========================================================================*/
#endif
