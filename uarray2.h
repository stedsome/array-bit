/*
 * COMP 40 HW 2
 *
 * X. Victor Gao and Yifan Yang
 *
 * uarray2.h : interface of uarray2
 */


#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "except.h"
#include "uarray.h"

struct UArray2_T {
	int width;
	int height;
	int size;
	UArray_T myArray;
};

#ifndef UARRAY2_INCLUDED
#define UARRAY2_INCLUDED
#define T UArray2_T

typedef struct T *T;

extern T     UArray2_new (int width, int height, int size);
extern void  UArray2_free (T *uarray2);
extern int   UArray2_width  (T uarray2);
extern int   UArray2_height (T uarray2);
extern int   UArray2_size   (T uarray2);

extern void *UArray2_at  (T uarray2, int col, int row);

extern void UArray2_map_row_major  (T uarray2,
		void apply (int i, int j, T uarray2, void *elem, void *cl),
		void *cl);
extern void UArray2_map_col_major  (T uarray2,
		void apply (int i, int j, T uarray2, void *elem, void *cl),
		void *cl);	

#undef T
#endif