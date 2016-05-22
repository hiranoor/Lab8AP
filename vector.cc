#include "vector.h"

#include <iostream>
#include <stdio.h>
#include <ctime>
#define num_thrd 32
#define SIZE 5
int vectorR[SIZE];
int* matrix1;
int* vector1;
int *vect;
void init_vector(int * vect)
{
vect = new int[SIZE];
	for (int i = 0; i < SIZE * 1; i++){

		//matrix[i] = rand() % 10;
		vect[i] = 1;

	}
}


void *Vmultiply(void* slice){



	int r4 = SIZE;
	int c4 = SIZE;
	int it = 0;

	long s = (long)slice;   // retrive the slice info
	int from = (int)(s * SIZE) / num_thrd; // note that this 'slicing' works fine
	int to = (int)((s + 1) * SIZE) / num_thrd; // even if SIZE is not divisible by num_thrd
	int i, j, k;
	int sum = 0;

	//result matrix
	for (int j = 0; j < SIZE; j++){
		vectorR[j] = 0;
	}
	int counter = 0;
	for (i = from; i < to; i++)
	{


		for (int i = 0; i < SIZE*SIZE; i = i + SIZE){ 		// instead of 9 use the matrix.rows
			for (int j = 0; j < SIZE; j++){		//instead of 3 use martrix.columns 
				sum += (matrix1[(i)+j] * vect[j]);
			}
			vectorR[it] = sum;

			sum = 0;
			it++;
		}
	}

	return 0;
}
