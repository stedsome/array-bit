/* bit2.c 
 * by Yifan Yang and Xiang Gao
 * 02-08-18
 * This is the implementation of ADT Bit2. It implements all the promised
 * functions in the ADT interface.  
 */

#include <bit2.h>


struct Bit2_T {
    int width;
    int height;
    Bit_T myBit;
};

#define T Bit2_T

/*
 * Bit2_new(): Creates a new 2D array with dimensions given by the parameters
 * Parameters: - an integer that sets the width of the 2D array
 *             - an integer that sets the height of the 2D array
 * Return Value: 
 *             - a pointer to the 2D array recreated
 * Checked Runtime Error: 
 *             It is a CRE for width or height to be negative values
 */
extern T Bit2_new(int width, int height)
{
        assert(width > 0 && height > 0);
        T myBit2;
        myBit2 = malloc(sizeof(*myBit2));
        myBit2->width = width;
        myBit2->height = height;
        myBit2->myBit = Bit_new( width * height );

        return myBit2;
}

/*
 * Bit2_free(): frees up the memory asscoiated with a 2D array
 * Parameter(s): 
 *             - a pointer to the pointer that points to the 2D array
 * Return Value: 
 *             - none
 * Checked Runtime Error: 
 *             It is a CRE for bit2 or its dereferenced value to be NULL
 */
extern void Bit2_free(T *bit2)
{
        assert(bit2 && *bit2);
        Bit_free(&((*bit2)->myBit));
        free(*bit2);
}

/*
 * Bit2_width(): returns the width of the 2D array
 * Parameter(s): 
 *             - a pointer to the 2D array
 * Return Value: 
 *             - an integer that is the width of this 2D array
 * Checked Runtime Error: 
 *             It is a CRE for the pointer passed to be NULL
 */
extern int Bit2_width(T bit2)
{
        assert (bit2);
        return bit2->width;
}

/*
 * Bit2_height(): returns the height of the 2D array
 * Parameter(s): 
 *             - a pointer to the 2D array
 * Return Value: 
 *             - an integer that is the height of this 2D array
 * Checked Runtime Error: 
 *             It is a CRE for the pointer passed to be NULL
 */

extern int Bit2_height(T bit2)
{
        assert (bit2);
        return bit2->height;
}

/*
 * Bit2_count(): Counts how many bits in the array that are 1
 * Parameter(s): 
 *             - a pointer to the 2D array
 * Return Value: 
 *             - the count of how many 1s are there in the array
 * Checked Runtime Error: 
 *             It is a CRE for the pointer passed to be NULL
 */

extern int Bit2_count(T bit2)
{
        assert (bit2);
        return Bit_count(bit2->myBit);
}


/*
 * Bit2_get(): gets the bit value at the given index in the 2D array
 * Parameter(s): 
 *             - a pointer to the 2D array
 *             - sets the x component of the index
 *             - sets the y component of the index
 * Return Value: 
 *             - the bit value at the given index
 * Checked Runtime Error: 
 *             It is a CRE for the pointer passed to be NULL or
 *             for col or row to be negative or to be equal to or 
 *             greater than the width/height. 
 */

extern int Bit2_get(T bit2, int col, int row)
{
        assert (bit2)
        assert (col >= 0 && col < bit2 -> width);
        assert (row >= 0 && row < bit2 -> height);
        return Bit_get(bit2->myBit, row * bit2->width + col);
}

/*
 * Bit2_get(): sets the bit value at the given index in the 2D array
 *              and returns the previous value at that index
 * Parameter(s): 
 *             - a pointer to the 2D array
 *             - sets the x component of the index
 *             - sets the y component of the index
 *             - the bit value to be put
 * Return Value: 
 *             - the previous bit value at the given index
 * Checked Runtime Error: 
 *             It is a CRE for the pointer passed to be NULL or
 *             for col or row to be negative or to be equal to or 
 *             greater than the width/height. 
 */

extern int Bit2_put(T bit2, int col, int row, int bit)
{
        assert ( col >= 0 && col < bit2 -> width);
        assert ( row >= 0 && row < bit2 -> height);
        assert (bit == 1 || bit == 0);
        return Bit_put(bit2->myBit, row * bit2->width + col, bit);
}

/*
 * Bit2_get(): sets the bit value at the given index in the 2D array
 *              and returns the previous value at that index
 * Parameter(s): 
 *             - a pointer to the 2D array
 *             - sets the x component of the index
 *             - sets the y component of the index
 *             - the bit value to be put
 * Return Value: 
 *             - the previous bit value at the given index
 * Checked Runtime Error: 
 *             It is a CRE for the pointer passed to be NULL or
 *             for col or row to be negative or to be equal to or 
 *             greater than the width/height. 
 */
extern void  Bit2_map_row_major(T bit2,
                void apply(int col, int row, int bit, void *cl),
                void *cl)
{
        assert(bit2 && apply);
        for (int j = 0; j < bit2->height; j++)
        {
                for (int i = 0; i < bit2->width; i++)
                {
                        apply(i, j, Bit2_get(bit2, i, j), cl);
                }
        }
}

extern void  Bit2_map_col_major(T bit2,
                void apply(int col, int row, int bit, void *cl),
                void *cl)
{
        for (int i = 0; i < bit2->width; i++)
        {
                for (int j = 0; j < bit2->height; j++)
                {
                        apply(i, j, Bit2_get(bit2, i, j), cl);
                }
        }
}


#undef T