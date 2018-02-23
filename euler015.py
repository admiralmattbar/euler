

'''
Project Euler 015

Starting in the top left corner of a 2×2 grid, 
and only being able to move to the right and down, 
there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?

I will use the combinatrix equation.
'''

import math

#Use Math module to make formula.
def formula(num):
	return math.factorial(num*2)/math.pow(math.factorial(num), 2)

#Print formula with dimension size of square grid
print formula(20)