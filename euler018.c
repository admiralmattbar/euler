#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start, end;
double time_elapsed;

FILE *f;

int getLines(FILE *fn, char filename[])
{
	fn = fopen(filename, "r");
	int lines = 0;
	char c;
	for(c = getc(fn); c != EOF; c = getc(fn)){
		if(c == '\n') lines++;
	}
	
	fclose(fn);
	return lines;
}

int main()
{
	start = clock();
	const int size = getLines(f, "euler018_formatted.txt");
	
	f = fopen("euler018_formatted.txt", "r");
	int col, row;
	
	//Iterate through triangle.
	int triangle[size][size];
	for(col=0; col<size; col++){
		for(row=0; row<size; row++){
			fscanf(f, "%i", &triangle[col][row]);
		}
	}
	
	printf("Checking triangle: ");
	printf("\n");
	
	for(col=0;col<size;col++){
		for(row=0;row<size;row++){
			if(triangle[col][row] != 0) printf("%d ", triangle[col][row]);
		}
		printf("\n");
	}

	fclose(f);
		
	int i, j;
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
	
	
	
	printf("Euler 18 answer: %d\n", triangle[0][0]);
	printf("Size of triangle: %d\n", size);
	
	end = clock();
	time_elapsed = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("Program time: %f secs\n", time_elapsed);

	return 0;
}