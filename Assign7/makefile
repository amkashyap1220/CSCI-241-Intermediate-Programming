#
# PROGRAM:    Assignment 7
# PROGRAMMER: alexander kashyap
# LOGON ID:   z1926618
# DATE DUE:   3/11/21
#
    
# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11
        
# Rule to link object code files to create executable file
all: inpost

inpost: main.o inpost.o mystack.o
	$(CXX) $(CXXFLAGS) -o inpost $^

stack_test: stack_test.o mystack.o
	$(CXX) $(CXXFLAGS) -o stack_test $^

# Rules to compile source code file to object code
main.o: main.cpp inpost.h
inpost.o: inpost.cpp inpost.h mystack.h
mystack.o: mystack.cpp mystack.h
stack_test.o: stack_test.cpp
   
# Pseudo-target to remove object code and executable files
clean:
	rm -f inpost stack_test *.o

clean_test:
	rm -f stack_test stack_test.o
