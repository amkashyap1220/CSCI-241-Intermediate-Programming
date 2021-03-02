#
# PROGRAM:    assign6
# PROGRAMMER: alexander kashyap
# LOGON ID:   z1926618
# DATE DUE:   3/4/21
#

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

# Rule to link object code files to create executable file
assign6: main.o complex.o
	$(CXX) $(CXXFLAGS) -o assign6 $^

# Rules to compile source code files to object code
main.o: main.cpp complex.h
complex.o: complex.cpp complex.h

# Phony target to remove object code and executable files
clean:
	rm -f assign6 *.o
