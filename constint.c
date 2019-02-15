//Stupid c thing

#include <stdio.h>

int main(){
	int i;
	
	printf("Enter a low number\n");
	scanf("%d", &i);
	
	const int x = i;

	int hi[x];

	for(int j=0; j<i; j++){
		hi[j] = 0;
	}
	
	for(int j=0; j<i; j++){
		printf("%d", hi[j]);
	}
	printf("\n");

	return 0;
}