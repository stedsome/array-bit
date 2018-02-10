/*
 * test 
 */
#include "uarray2.h"
#include "bit2.h"

void modify(Bit2_T bit2)
{
  printf("modify\n");
  assert(bit2);
  for (int row = 0; row < Bit2_height(bit2); row++)
    for (int col = 0; col < Bit2_width(bit2); col++)
      if ((col + row) % 2 == 0)
	Bit2_put(bit2, col, row, 1);
  return;
}


void print (int col, int row, int bit, void *cl)
{
  printf("(%d, %d):", col, row);
  printf("%-3d", bit);
  int *i = (int *)cl;
  if (col == *i - 1)
    printf("\n");
  return;
} 

int main(int argc, char *argv[])
{
        (void) argv;
        (void) argc;
        /*
        UArray2_T myarray = UArray2_new (1, 4 , 1);
        UArray2_free(&myarray);
        */
	int w = 0, h = 0;
	printf("enter the width:");
	scanf("%d", &w);
	printf("enter the height:");
	scanf("%d", &h);

	Bit2_T myBit2 = Bit2_new(w, h);
	Bit2_map_row_major(myBit2, print, &w);
	modify(myBit2);
	/*
	Bit2_get(myBit2, 9, 3);
	*/
	Bit2_map_row_major(myBit2, print, &w);
	printf("ones in bit2: %d\n", Bit2_count(myBit2));
	Bit2_free(&myBit2);
        return 0;
}
