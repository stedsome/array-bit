/*
 * COMP 40 HW 2
 * X. Victor Gao and Yifan Yang
 * bit2.c : implementation of bit2
 */

#include <bit2.h>

struct Bit2_T {
    int width;
    int height;
    Bit_T myBit;
};

#define T Bit2_T
/*
 * Bit2_new
 * Parameters - width and height of the 2D bit-vector
 *              both are nonnegtive integers
 * Return Values - a pointer to 2D bit-vector
 *                 all bit are initially set to be zero
 * Checked runtime error - width or height to be negative
 */
extern T Bit2_new(int width, int height)
{
        /* revised Fri
        assert(width > 0 && height > 0);
        */
        assert(width >= 0 && height >= 0);
        T myBit2;
        myBit2 = malloc(sizeof(*myBit2));
        myBit2->width = width;
        myBit2->height = height;
        myBit2->myBit = Bit_new( width * height );

        return myBit2;
}

/*
 * Bit2_free
 * Parameter - a double pointer to 2D bit-vector
 * Return value - void
 * Checked runtime error - passed pointer or its dereference is null
 */
extern void Bit2_free(T *bit2)
{
        assert(bit2 && *bit2);
        Bit_free(&((*bit2)->myBit));
        free(*bit2);
}

/*
 * Bit2_width, Bit2_height
 * Parameter - a pointer to 2D bit-vector
 * Return value - width/height of the 2D bit-vector
 * Checked runtime error - passed parameter is a null pointer 
 */
extern int Bit2_width(T bit2)
{
        assert (bit2);
        return bit2->width;
}

extern int Bit2_height(T bit2)
{
        assert (bit2);
        return bit2->height;
}

/*
 * Bit2_count
 * Parameter - a pointer to 2D bit-vector
 * Return value - number of ones in the 2D bit-vector
 * Checked runtime error - passed parameter is a null pointer
 */
extern int Bit2_count(T bit2)
{
        assert (bit2);
        return Bit_count(bit2->myBit);
}

/*
 * Bit2_get : returns bit at position (col, row)
 *            and tests whether (col, row) is the 2D bit-vector
 * Parameters - a pointer to 2D bit-vector
 *              column index and row index
 * Return value - return one if bit value at (col, row) is in one
 *                otherwise return zero
 * Checked runtime error - passed 2D bit-vector pointer is null
 *                         either column index or row index is out ofm bound
 */
extern int Bit2_get(T bit2, int col, int row)
{
        assert(bit2);
        assert ( col >= 0 && col < bit2 -> width);
        assert ( row >= 0 && row < bit2 -> height);
        return Bit_get(bit2->myBit, row * bit2->width + col);
}

/*
 * Bit2_put : set value at given (col, row) to be bit (1 or 0)
 * Parameters - a pointer to 2D bit-vector
 *              column index and row index
 *              bit value to be set (1 or 0)
 * Return value - return the previous value at that position
 * Checked runtime error - passed 2D bit-vector pointer is null
 *                         either column index or row index is out ofm bound
 *                         value to be set is neither 1 nor 0  
 */
extern int Bit2_put(T bit2, int col, int row, int bit)
{
        assert(bit2);
        assert ( col >= 0 && col < bit2 -> width);
        assert ( row >= 0 && row < bit2 -> height);
        assert (bit == 1 || bit == 0);
        return Bit_put(bit2->myBit, row * bit2->width + col, bit);
}


/*
 * Bit2_map_row_major : calls function apply for each bit in the
 *                      2D bit-vector in the row-major-order
 * Bit2_map_col_major : does the smae thing but in column-major-order
 * Parameters - column and row indices (col, row)
 *              function pointer
 *              application-specific pointer
 * Return value - void
 * Checked Runtime Error - index out of bound
 *                         passed array pointer is NULL             
 */
extern void  Bit2_map_row_major(T bit2,
                void apply(int col, int row, int bit, void *cl),
                void *cl)
{
        assert(bit2);
        for (int j = 0; j < bit2->height; j++)
                for (int i = 0; i < bit2->width; i++)
                        apply(i, j, Bit2_get(bit2, i, j), cl);
        return;
}

extern void  Bit2_map_col_major(T bit2,
                void apply(int col, int row, int bit, void *cl),
                void *cl)
{
        assert(bit2);

        for (int i = 0; i < bit2->width; i++)
                for (int j = 0; j < bit2->height; j++)
                        apply(i, j, Bit2_get(bit2, i, j), cl);
        return;
}


#undef T
