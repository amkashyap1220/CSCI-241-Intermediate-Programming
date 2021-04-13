#
# PROGRAM:    Assignment 11
# PROGRAMMER: Alexander KAshyap
# LOGON ID:   z1926618
# DATE DUE:   4/15/21
#

# Compiler variables
#CXXFLAGS = -Wall -Werror -std=c++11
CXXFLAGS = -std=c++11
# Rule to link object code files to create executable file

assign11: assign11.o
	g++ $(CXXFLAGS) -o assign11 assign11.o

# Rules to compile source code files to object code
assign11.o: assign11.cpp bstree.h

# Pseudo-target to remove object code and executable files
clean:
	rm -f assign11 *.o
