#
# PROGRAM:    assign5
# PROGRAMMER: your name
# LOGON ID:   your z-id
# DATE DUE:   due date of program
#

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

# Rule to link object code files to create executable file
assign5: main.o account.o bank.o
	$(CXX) $(CXXFLAGS) -o assign5 $^

# Rules to compile source code files to object code
main.o: main.cpp bank.h
account.o: account.cpp account.h
bank.o: bank.cpp bank.h

# The bank class depends on the account class
bank.h: account.h

# Phony target to remove object code and executable files
clean:
	rm -f assign5 *.o
