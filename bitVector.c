
#include <stdlib.h>
#include "bit2.h"
#include "assert.h"
#include "except.h"

void print(int col, int row, int bit, void *cl)
{
        (void) cl;
        printf("( %d, %d) : %d \n", col, row, bit);
}

int main ( int argc, char * argv[])
{
        (void) argc;
        (void) argv;

        Bit2_T bit;
        bit = Bit2_new(5, 7);
        (void) bit;
        printf("%d \n", Bit2_count(bit));
        for (int i = 0; i < Bit2_width(bit); i++)
        {
                for (int j = 0; j < Bit2_height(bit); j++)
                {
                        if (i != j)
                                Bit2_put(bit, i, j, 1);
                }         
        }
        

        printf("%d \n", Bit2_count(bit));
        printf("Row major printing: \n");
        Bit2_map_row_major(bit, print, NULL);

        printf("column major printing: \n");
        Bit2_map_col_major(bit, print, NULL);
        Bit2_free(&bit);

}