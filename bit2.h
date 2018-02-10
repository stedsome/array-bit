/*
 * COMP 40 HW 2
 *
 * X. Victor Gao and Yifan Yang
 *
 * bit2.h : interface of bit2
 */

#include "bit.h"
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "except.h"

#ifndef BIT2_INCLUDED
#define BIT2_INCLUDED

#define T Bit2_T
typedef struct T *T;


extern T     Bit2_new    (int width, int height);
extern void  Bit2_free   (T *bit2);
extern int   Bit2_width  (T bit2);
extern int   Bit2_height (T bit2);
extern int   Bit2_count  (T bit2);

extern int   Bit2_get  (T bit2, int col, int row);
extern int   Bit2_put  (T bit2, int col, int row, int bit);

extern void  Bit2_map_row_major(T bit2,
                void apply(int col, int row, int bit, void *cl),
                void *cl);

extern void  Bit2_map_col_major(T bit2,
                void apply(int col, int row, int bit, void *cl),
                void *cl);
#undef T
#endif
