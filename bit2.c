#include <bit2.h>


struct Bit2_T {
    int width;
    int height;
    Bit_T myBit;
};

#define T Bit2_T

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

extern void Bit2_free(T *bit2)
{
        assert(bit2 && *bit2);
        Bit_free(&((*bit2)->myBit));
        free(*bit2);
}

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

extern int Bit2_count(T bit2)
{
        assert (bit2);
        return Bit_count(bit2->myBit);
}

extern int Bit2_get(T bit2, int col, int row)
{
        return Bit_get(bit2->myBit, row * bit2->width + col);
}

extern int Bit2_put(T bit2, int col, int row, int bit)
{
        assert ( col >= 0 && col < bit2 -> width);
        assert ( row >= 0 && row < bit2 -> height);
        assert (bit == 1 || bit == 0);
        return Bit_put(bit2->myBit, row * bit2->width + col, bit);
}

extern void  Bit2_map_row_major(T bit2,
                void apply(int col, int row, int bit, void *cl),
                void *cl)
{
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