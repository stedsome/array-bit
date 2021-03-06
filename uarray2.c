/*
 * COMP 40 HW 2
 * X. Victor Gao and Yifan Yang
 * uarray.c : implementations of uarray2
 */

#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "except.h"
#include "uarray.h"

#include "uarray2.h"

struct UArray2_T {
	int width;
	int height;
	int size;
	UArray_T myArray;
};

#define T UArray2_T
/*
 * UArray_new : initialize a 2D array by given with and height 
 * Parameters - width of 2D array
 *              height of 2D array
 *              element size
 * Return Values - a pointer to UArray2
 * CHecked Runtime Error - width or height to be negative
 *                         size to be nonpositive    
 */
T UArray2_new (int width, int height, int size)
{
  
        assert(width >=0 || height >= 0);
        assert(size > 0);
  
        T myArray2 = malloc(sizeof(*myArray2));
        myArray2->width  = width;
        myArray2->height = height;
        myArray2->size   = size;
        myArray2->myArray = UArray_new(width * height, size);
  
        return myArray2;
}

/*
 * UArray2_free : free the allocated memory in heap
 * Parameters - a double pointer to UArray2
 * Return Values - void
 * Checked Runtime Error - passed pointer is NULL
 */
void UArray2_free (T *uarray2)
{
        assert(uarray2 && *uarray2);
        
        UArray_free(&((*uarray2)->myArray));
        free(*uarray2);
        return;
}

/*
 * UArray2_width : return the width of the 2D array
 * UArray2_height : return the height of the 2D array
 * Uarray2_size : return the bytes of the element type
 * Parameter - a pointer to 2D array
 * Return values - the width/height/element_size of the 2D array
 * Check Runtime Error - passed pointer is NULL
 */
int UArray2_width (T uarray2)
{
        assert(uarray2);
        return uarray2->width;
}

int UArray2_height (T uarray2)
{
        assert(uarray2);
        return uarray2->height;
}

int UArray2_size (T uarray2)
{
        assert(uarray2);
        return uarray2->size;
}

/*
 * UArray2_at : return a pointer to the element at position (i,j)
 * Parameter - a pointer to 2D array
 *             column index i
 *             row index j
 * Return Value - an pointer to element at (i,j)
 * Checked Runtime Error - i or j is out of bound
 *                         passed array pointer is null 
 */
void *UArray2_at (T uarray2, int i, int j)
{
        assert(uarray2);
        assert(i >= 0 && i < uarray2->width);
        assert(j >= 0 && j < uarray2->height);
        int k = i + j * uarray2->width;
        return UArray_at(uarray2->myArray, k);
}

/*
 * UArray2_map_row_major : call the apply function for each element 
 *                         in the 2D array in row-major-order
 * UArray2_map_col_major : call the apply function for each element 
 *                         in the 2D array in column-major-order
 * Parameters - column and row indices (i,j)
 *              function pointer
 *              application-specific pointer
 * Return values - void
 * Checked Runtime Error - index out of bound
 *                         passed array pointer is NULL             
 */
void UArray2_map_row_major  (T uarray2,
        void apply (int i, int j, T uarray2, void *elem, void *cl),
        void *cl)
{
        assert(uarray2);
  
        for (int j = 0; j < uarray2->height; j++) 
                for (int i = 0; i < uarray2->width; i++) 
                        apply(i, j, uarray2, UArray2_at(uarray2, i, j) ,cl);

        return;
}

void UArray2_map_col_major  (T uarray2,
        void apply (int i, int j, T uarray2, void *elem, void *cl),
        void *cl)
{
        assert(uarray2);
  /*assert(uarray2);*/
        for (int i = 0; i < uarray2->width; i++) 
                for (int j = 0; j < uarray2->height; j++) 
                        apply(i, j, uarray2, UArray2_at(uarray2, i, j) , cl);

  return;
}

#undef T


