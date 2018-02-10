#include "uarray2.h"


int main(int argc, char *argv[])
{
        (void) argv;
        (void) argc;
        UArray2_T myarray = UArray2_new (1, 4 , 1);

        UArray2_free(&myarray);

}