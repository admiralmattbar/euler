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

int main(int argc, char *argv[])
{
	start = clock();
	const int size = getLines(f, argv[1]);
	
	f = fopen(argv[1], "r");
	int col, row;
	
	int triangle[size][size];
	for(col=0; col<size; col++){
		for(row=0; row<size; row++){
			fscanf(f, "%i", &triangle[col][row]);
		}
	}
	
	printf("Checking triangle: ");
	printf("\n");
	
	int linelength;
	
	for(col=0;col<size;col++){
		linelength = 0;
		for(row=0;row<size;row++){
			/*if(triangle[col][row] != 0) */printf("%d ", triangle[col][row]);
			linelength++;
		}
		printf("EndLine: %d\n", linelength);
	}
	
	printf("Last item on triangle: %d\n", triangle[size][size]);

	fclose(f);
	
		
	for(col=size-2; col>-1; col--) {
		for(row=0; row<size; row++) {
			if((triangle[col][row] > 0 && triangle[col+1][row] > 0) || (triangle[col+1][row+1] > 0 && triangle[col][row] > 0)) {
				if(triangle[col][row] + triangle[col+1][row] > triangle[col][row] + triangle[col+1][row+1]) {
					triangle[col][row] = triangle[col][row] + triangle[col+1][row];
				} else {
					triangle[col][row] = triangle[col][row] + triangle[col+1][row+1];
				}
			}
		}
	}
	
	printf("\n");
	
	printf("Answer: %d\n", triangle[0][0]);
	printf("Size of triangle: %d\n", size);
	
	end = clock();
	time_elapsed = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("Program time: %f secs\n", time_elapsed);
	
	return 0;
}