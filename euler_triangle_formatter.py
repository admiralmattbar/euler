from array import *
import sys

'''
Format the grid for Project Euler 18 to get an array in c

Requires the following:
-Removing 0s from front of numbers
-Adding commas between numbers
-Adding curly brackets

Final formatting should look like a 2D C array with 0s inserted 
for blanks in the triangle.
'''

if len(sys.argv) != 3:
	print("This program takes the arguments for the input file, then the name of the output file. You do not have the proper amount of arguments.")
	sys.exit()
	
#Get the data for the triangle
file_in = open(sys.argv[1], "r")

#Store as a string
triangle_raw = file_in.read()

#Remove 0s at the beginning of numbers and add commas
triangle_no_zeroes = triangle_raw.replace(" 0", " ").replace("\n0", "\n")

triangle_split = triangle_no_zeroes.splitlines()

#Count the number of lines of the triangle in the file. Add one for last line.
count = triangle_no_zeroes.count('\n') + 1

add_zeroes_per_line = count-1

for i in range(0, len(triangle_split), 1):
	for j in range(0, add_zeroes_per_line, 1):
		triangle_split[i] += ' 0'
	triangle_split[i] += '\n'
	add_zeroes_per_line -= 1

triangle_final = ''.join(triangle_split)

print("Number of layers: " + str(count))

#Print the properly formatted string to a new file
file_out = open(sys.argv[2], "w")
file_out.write(triangle_final)
file_out.close()