#
# PROGRAM:    Assignment 4
# PROGRAMMER: your name
# LOGON ID:   your z-id
# DATE DUE:   due date of program
#
    
# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11
        
# Rule to link object code files to create executable file
simplesim: main.o simplesim.o
	$(CXX) $(CXXFLAGS) -o simplesim $^

# Rules to compile source code file to object code
main.o: main.cpp simplesim.h
simplesim.o: simplesim.cpp simplesim.h sml.h
   
# Pseudo-target to remove object code and executable files
clean:
	rm -f simplesim *.o
