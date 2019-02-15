#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int size = 15;
//const int width = 15;

clock_t start, end;
double time_elapsed;

int main()
{
	start = clock();

	int *triangle = (int *)malloc(size * size * sizeof(int));

	int other_triangle[size][size] = 
	{
	{75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{95, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{17, 47, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{18, 35, 87, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{20, 4, 82, 47, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{19, 1, 23, 75, 3, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{88, 2, 77, 73, 7, 63, 67, 0, 0, 0, 0, 0, 0, 0, 0},
	{99, 65, 4, 28, 6, 16, 70, 92, 0, 0, 0, 0, 0, 0, 0},
	{41, 41, 26, 56, 83, 40, 80, 70, 33, 0, 0, 0, 0, 0, 0},
	{41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 0, 0, 0, 0, 0},
	{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 0, 0, 0, 0},
	{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 0, 0, 0},
	{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 0, 0},
	{63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 0},
	{4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}
	};
	
	
	int col, row;
	
	for(col=0;col<size;col++){
		for(row=0;row<size;row++){
			*(triangle + col*size + row) = other_triangle[col][row];
		}
	}
	
	printf("\n");
	
	for(col=0;col<size;col++){
		for(row=0;row<size;row++){
			printf("%d ", *(triangle + col*size + row));
		}
		printf("\n");
	}
	
	//triangle[height 0-15][width 0-15]
	
	/*
	for(i=size-2; i>-1; i--) {
		for(j=0; j<size; j++) {
			if((triangle[i][j] > 0 && triangle[i+1][j] > 0) || (triangle[i+1][j+1] > 0 && triangle[i][j] > 0)) {
				if(triangle[i][j] + triangle[i+1][j] > triangle[i][j] + triangle[i+1][j+1]) {
					triangle[i][j] = triangle[i][j] + triangle[i+1][j];
				} else {
					triangle[i][j] = triangle[i][j] + triangle[i+1][j+1];
				}
			}
		}
	}
	*/
	
	//printf("Euler 18 answer: %d\n", triangle[0][0]);
	
	end = clock();
	time_elapsed = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("Program time: %f secs\n", time_elapsed);
	free(triangle);
	return 0;
}