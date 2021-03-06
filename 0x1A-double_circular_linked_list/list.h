#ifndef DOUBLE_CIRCULAR_LIST_H
#define DOUBLE_CIRCULAR_LIST_H

/**========================================================================*/
/**-LIBRARIES--------------------------------------------------------------*/
/**========================================================================*/

#include <stdlib.h>
#include <string.h>

/**========================================================================*/
/**-STRUCTURES & DEFINITIONS-----------------------------------------------*/
/**========================================================================*/

/**
 * struct List - doubly linked list
 * @str: string - (malloc'ed string)
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;


/**========================================================================*/
/**-FUNCTIONS--------------------------------------------------------------*/
/**========================================================================*/

/** 0-A. Creates a node at the end of a list. */
List *add_node_end(List **list, char *str);

/** 0-B. Creates a node at the beginning of a list. */
List *add_node_begin(List **list, char *str);

/** A. Creates a single node */
List *create_list(List **list, char *str);

/**========================================================================*/
/**-SPECIAL NOTES & OTHERS-------------------------------------------------*/
/**========================================================================*/



/**========================================================================*/
/**-END--------------------------------------------------------------------*/
/**========================================================================*/
#endif
