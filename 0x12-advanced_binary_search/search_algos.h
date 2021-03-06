#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

/**========================================================================*/
/**-LIBRARIES--------------------------------------------------------------*/
/**========================================================================*/

#include <stdio.h>


/**========================================================================*/
/**-STRUCTURES & DEFINITIONS-----------------------------------------------*/
/**========================================================================*/



/**========================================================================*/
/**-FUNCTIONS--------------------------------------------------------------*/
/**========================================================================*/

/** 0. Advanced Binary Search */
int advanced_binary(int *array, size_t size, int value);

/** A. Recursive function to search the value */
int search_value (int *array, size_t first_index, size_t last_index, int value);


/**========================================================================*/
/**-SPECIAL NOTES & OTHERS-------------------------------------------------*/
/**========================================================================*/



/**========================================================================*/
/**-END--------------------------------------------------------------------*/
/**========================================================================*/
#endif
