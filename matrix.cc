
#include "matrix.h"

#include <iostream>
#include <stdio.h>
#include <ctime>
#define SIZE 5

int *mat;
void init_matrix(int * mat)
{
mat = new int[SIZE* SIZE];
	for (int i = 0; i < SIZE*SIZE; i++){

		//matrix[i] = rand() % 10;
		mat[i] = 1;

	}
}