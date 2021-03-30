#
# PROGRAM:    Assignment 10
# PROGRAMMER: your name
# LOGON ID:   your z-id
# DATE DUE:   due date of program
#
    
# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11
        
# Rule to link object code files to create executable file
assign10: assign10.o
	$(CXX) $(CXXFLAGS) -o assign10 $^

# Rules to compile source code file to object code
assign10.o: assign10.cpp mylist.h
   
# Pseudo-target to remove object code and executable files
clean:
	rm -f assign10 *.o
