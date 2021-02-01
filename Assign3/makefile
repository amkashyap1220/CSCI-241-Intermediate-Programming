#
# PROGRAM:    Assignment 3
# PROGRAMMER: your name
# LOGON ID:   your z-ID
# DATE DUE:   9/17/2020
#

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

# Rules to link object code files to create executable file
all: quick_sort merge_sort

quick_sort: quick_sort.o
	$(CXX) $(CXXFLAGS) -o quick_sort $^

merge_sort: merge_sort.o
	$(CXX) $(CXXFLAGS) -o merge_sort $^

# Rules to compile source code files to object code
quick_sort.o: quick_sort.cpp
merge_sort.o: merge_sort.cpp

# Pseudo-target to remove object code and executable files
clean:
	rm -f quick_sort merge_sort *.o
