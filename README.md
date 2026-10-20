# Lab7
Vector Calctulator
commands
help - prints help
        Vector Calculator Help
        "----------------------"
        "Commands:"
        " quit Exit the program."
        " clear Delete all stored vectors."
        " help Display this help message."
        "Vector Assignment:"
        " varname = x y z"
        "Display Vector:"
        " vector name"
        "Addition:"
        " var1 + var2"
        "Subtraction:"
        " var1 - var2"
        "Scalar Multiplication:"
        " var1 * number"
        "Assignment from Expression:"
        " result = var1 + var2"
        " result = var1 - var2"
        " result = var1 * number"
        "Notes:"
        " * Spaces are required around operators."
        " * Maximum of 10 vectors may be stored."
        " * Referenced vectors must exist."
    

quit - closes application
list - lists vectors
load - loads csv file
save - saves current vector list into csv file

This program uses dynamic memory like a array list where when the array 
runs out of space it gets more memory preserving the vectors already in memory. 
Starts at 10 and incriments by 10 every time the memory is filled.
