#
# PROGRAM:    Assignment 12
# PROGRAMMER: Alexander KAshyap
# LOGON ID:   z1926618
# DATE DUE:   4/22/21
#

# Compiler variables
CXXFLAGS = -Wall -Werror -std=c++11
# Rule to link object code files to create executable file
all: assign12

assign12: assign12.o rectangle.o shape.o triangle.o circle.o
	g++ $(CXXFLAGS) -o assign12 $^
rectangle: assign12.o rectangle.o shape.o
	g++ $(CXXFLAGS) -o rectangle $^

# Rules to compile source code files to object code
assign12.o: assign12.cpp circle.h shape.h rectangle.h triangle.h
shape.o: shape.cpp shape.h
circle.o: circle.cpp circle.h
rectangle.o: rectangle.cpp rectangle.h
trianle.o: triangle.cpp triangle.h

# Pseudo-target to remove object code and executable files
clean:
	rm -f assign12 rectangle *.o