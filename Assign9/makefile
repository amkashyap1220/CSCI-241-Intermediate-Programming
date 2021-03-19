#
# PROGRAM:    Assignment 9
# PROGRAMMER: your name
# LOGON ID:   your z-id
# DATE DUE:   due date of program
#
    
# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11
        
# Rule to link object code files to create executable file
all: scc simplesim

scc: scc.o inpost.o mystack.o
	$(CXX) $(CXXFLAGS) -o scc $^

simplesim: simplesim_main.o simplesim.o
	$(CXX) $(CXXFLAGS) -o simplesim $^

# Rules to compile source code file to object code
scc.o: scc.cpp sml.h inpost.h
inpost.o: inpost.cpp inpost.h mystack.h
mystack.o: mystack.cpp mystack.h
simplesim_main.o: simplesim_main.cpp simplesim.h
simplesim.o: simplesim.cpp simplesim.h sml.h
   
# Pseudo-target to remove object code and executable files
clean:
	rm -f scc simplesim *.o
