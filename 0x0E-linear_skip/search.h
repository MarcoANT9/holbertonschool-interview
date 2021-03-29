#ifndef _SEARCH_H_
#define _SEARCH_H_

/**-LIBRARIES--------------------------------------------------------------*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/**-STRUCTURES & DEFINITIONS-----------------------------------------------*/

/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 * for Holberton project
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;


/**-FUNCTIONS--------------------------------------------------------------*/

/** A. Creates a skip list. */
skiplist_t *create_skiplist(int *array, size_t size);

/** B. Prints a skip list into the Standard Output. */
void print_skiplist(const skiplist_t *list);

/** C. Releases the memory used by a skip list. */
void free_skiplist(skiplist_t *list);

/** 0. Searches for an element in a sorted skip list. */
skiplist_t *linear_skip(skiplist_t *head, int value);


/**-SPECIAL NOTES & OTHERS-------------------------------------------------*/


/**-END OF FILE------------------------------------------------------------*/

#endif
