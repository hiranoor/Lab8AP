#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <ctime>
#include "matrix.h"
#include "vector.h"

using namespace ::std;

#define SIZE 5  // Size by SIZE matrices

#define num_thrd 32
int* matrix11;
int* matrix21;
int* matrix31;
int* vector11;
int* vectorR1;




int main()
{
	//pthread_t* thread;  // pointer to a group of threads
	pthread_t thread[num_thrd];
	pthread_t thread2[num_thrd];
	long i;

	//matrix11 = new int[SIZE * SIZE];
	//matrix21 = new int[SIZE * SIZE];
	//matrix31 = new int[SIZE * SIZE];
	//vector11 = new int[SIZE * 1];
	//vectorR1 = new int[SIZE * 1];

	init_matrix(matrix11);
	init_matrix(matrix21);
	init_matrix(matrix31);
	init_vector(vector11);
	init_vector(vectorR1);
	

	//threads for vector multiplication
	
	clock_t tic1 = clock();
	for (i = 1; i < num_thrd; i++)
	{


	if (pthread_create(&thread2[i], NULL, Vmultiply, (void *)i) != 0)

	{
	perror("Can't create thread");
	pthread_exit(NULL);
	//exit(-1);
	}
	}
	clock_t toc1 = clock();
	double time1 = (double)((toc1 - tic1) / CLOCKS_PER_SEC);
	printf("Time for parallel vector mul: %f seconds\n", (double)(toc1 - tic1) / CLOCKS_PER_SEC);

	Vmultiply(0);


	//main thead waiting for other thread to complete
	for (int p = 1; p < num_thrd; p++){
	pthread_join(thread2[p], NULL);
	}

	//pthread_exit(NULL);
	
	getchar();
	return 0;

}
