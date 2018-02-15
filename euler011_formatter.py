'''
Format the grid for Project Euler 11 to get an array in c++

Requires the following:
-Removing 0s from front of numbers
-Adding commas between numbers
-Adding curly brackets

Final formatting should look like a 2D C++ array
'''

#Get the grid from a file (pasted from website)
file_in = open("euler011_raw.txt", "r")

#Store grid in raw string form
grid_raw = file_in.read()

#Convert grid to a list for modification and iteration
grid_list = list(grid_raw)

#Use line breaks to find end of lines
line_length = grid_list.index('\n')

#Iterate through the list and add }s
grid_size = len(grid_list)
for i in range(line_length,grid_size,line_length+2):
	grid_list.insert(i, "},")

#Iterate through the list and add {s
grid_size = len(grid_list)
for i in range(line_length,grid_size,line_length+3):
	grid_list.insert(i+2, "{")

#Add the brackets for the end and beginning
grid_list.append("}}")
grid_list.insert(0,"{{");

#Store list as a string in new variable
grid_string = ''.join(grid_list)

#Use replace() to remove the 0s in the tens place, and add commas
grid_fixed = grid_string.replace("{0", "{").replace(" 0"," ").replace(" ", ", ")

#Print to console for testing
print grid_fixed

#Print the properly formatted string to a new file
file_out = open("euler011_formatted.txt", "w")
file_out.write(grid_fixed)
file_out.close()
