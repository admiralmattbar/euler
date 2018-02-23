/*
Project Euler 015

Starting in the top left corner of a 2×2 grid, 
and only being able to move to the right and down, 
there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?

SOLUTION: There's a math equation for this.

((2n)!)/(n!)**2

*/

#include <iostream>
#include <cmath>
#include <cstdint>
#include <climits>

using namespace std;

long size;

/*
struct uint256_t
{
    std::uint64_t bits[4];
};
*/


unsigned long long factorialReduced(long num)
{
	unsigned long long numerator = 1, denominator = 1;
	
	int i;
	for (i = num+1; i <= (2*num); i++){
		numerator *= i;
	}
	int j;
	for(j = 2; j <= num; j++) {
		denominator *= j;
	}
	
	return numerator/denominator;
}



int main(void)
{
	size = 20;
	
	cout << factorialReduced(size) << endl;
	cout << ULLONG_MAX << endl;
	
	
	
	//cout << "There are: " << rout_num << " routes on a "<< size << " x " << size << "grid." << endl;
	return 0;
}