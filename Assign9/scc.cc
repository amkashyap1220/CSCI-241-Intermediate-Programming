//*****************************************************************************
//
//  scc.cpp
//  CSCI 241 Assignment 9
//  Created by name (z-ID)
//
//*****************************************************************************

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <sstream>
#include "sml.h"

using namespace std;

/**
 * 
 * Symbol table entry.
 *
 ********************************************************************/
struct table_entry
{
    int symbol;
    char type;        // 'C' constant, 'L' Simple line number, 'V' variable
    int location;     // Simplesim address (00 to MEMSIZE-1)
};

/**
 * 
 * Simple compiler.
 *
 ********************************************************************/
class scc
{
public:

    // Data members
    static const int MEMORY_SIZE = 100;
    static const int SYMBOL_TABLE_SIZE = 1000;

    // Member functions
    scc();
    void first_pass();
    void second_pass();
    void print_program() const;

private:

    // Data members
    int memory[MEMORY_SIZE];
    
    int data[MEMORY_SIZE];
    int ndata = 0;

    table_entry symbol_table[SYMBOL_TABLE_SIZE];
    
    int flags[MEMORY_SIZE];

    int next_instruction_addr = 0;
    int next_const_or_var_addr = MEMORY_SIZE - 1;
    int next_symbol_table_idx = 0;

    // Member functions
    void data_check() const;
    void memory_check() const;
    void handle_input(istringstream&);
    void handle_data(istringstream&);
    void handle_end();
    int get_symbol_location(const string&);
    int search_symbol_table(int, char) const;
};

int main()
{
    scc compiler;

    compiler.first_pass();

    compiler.second_pass();

    compiler.print_program();

    return 0;
}

/**
 * Initializes memory and flags array.
 *
 ********************************************************************/
scc::scc()
{
    // Initalize memory and flags arrays.
    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        memory[i] = 7777;
        flags[i] = -1;
    }
}

/**
 * Performs first pass of compilation.
 *
 ********************************************************************/
void scc::first_pass()
{
    string buffer1, buffer2, command;

    int line_number;

    while (getline(cin, buffer1))
    {
        // Save copy of buffer for use in handling let instruction.
        buffer2 = buffer1;
        istringstream ss(buffer1);

        // Read line number.
        ss >> line_number;

        // Add line number to symbol table
        symbol_table[next_symbol_table_idx].symbol = line_number;
        symbol_table[next_symbol_table_idx].type = 'L';
        symbol_table[next_symbol_table_idx].location = next_instruction_addr;
        next_symbol_table_idx++;

        // Extract the command from this Simple statement.
        ss >> command;

        // Process the command.
        if (command == "input")
        {
            handle_input(ss);
        }
        else if (command == "data")
        {
            handle_data(ss);
        }
        else if (command == "let")
        {

        }
        else if (command == "if")
        {

        }
        else if (command == "goto")
        {

        }
        else if (command == "print")
        {

        }
        else if (command == "end")
        {
            handle_end();
        }
        else // if (command == "rem")
        {
            // Nothing to do for this instruction.
        }
    }
}

/**
 * Generates code for an "input" instruction.
 *
 * @param ss Input string stream from which to read.
 *
 ********************************************************************/
void scc::handle_input(istringstream& ss)
{
    string token;

    ss >> token;

    int location = get_symbol_location(token);

    memory_check();
    memory[next_instruction_addr] = READ * 100 + location;
    next_instruction_addr++;
}

/**
 * Generates code for a "data" instruction.
 *
 * @param ss Input string stream from which to read.
 *
 ********************************************************************/
void scc::handle_data(istringstream& ss)
{
    string token;

    ss >> token;

    data_check();
    data[ndata] = stoi(token);
    ndata++;
}

/**
 * Generates code for an "end" instruction.
 *
 ********************************************************************/
void scc::handle_end()
{
    memory_check();
    memory[next_instruction_addr] = HALT * 100;
    next_instruction_addr++;
}

/**
 * Checks whether there is room in the data array to add another data
 * item.
 *
 ********************************************************************/
void scc::data_check() const
{
    if (ndata >= MEMORY_SIZE)
    {
        cout << "*** ERROR: too many data lines ***\n";
        exit(1);
    }
}

/**
 * Checks whether there is room in the memory array to add another
 * instruction.
 *
 ********************************************************************/
void scc::memory_check() const
{
    if (next_instruction_addr >= MEMORY_SIZE || next_instruction_addr >
        next_const_or_var_addr)
    {
        cout << "*** ERROR: ran out Simplesim memory ***\n";
        exit(1);
    }
}

/**
 * Gets the location of a constant or variable, adding it to the 
 * symbol table and memory if necessary.
 *
 * @param token The symbol to locate.
 *
 * @return The symbol's location.
 *
 ********************************************************************/
int scc::get_symbol_location(const string& token)
{
    int location, symbol;
    char type;

    if (islower(token[0]))
    {
        // This is a variable.
        symbol = token[0];
        type = 'V';
    }
    else
    {
        // This is an integer constant.
        symbol = stoi(token);
        type = 'C';
    }

    int index = search_symbol_table(symbol, type);
    if (index == -1)
    {
        // Symbol is not in symbol table.
        // Add this symbol to the symbol table.
        location = next_const_or_var_addr;

        symbol_table[next_symbol_table_idx].symbol = symbol;
        symbol_table[next_symbol_table_idx].type = type;
        symbol_table[next_symbol_table_idx].location = location;
        next_symbol_table_idx++;
        
        // Allocate memory for this constant or variable.
        memory_check();
        if (type == 'V')
            memory[next_const_or_var_addr] = 0;
        else
            memory[next_const_or_var_addr] = symbol;

        next_const_or_var_addr--;
    }
    else
    {
        // Symbol is in symbol table at index.
        location = symbol_table[index].location;
    }

    return location;
}

/**
 * Searches the symbol table for a symbol.
 *
 * @param symbol The symbol for which to search the symbol table.
 * @param type The type of the symbol ('C', 'L', or 'V')
 *
 * @return The index of the item found or -1 if the search fails.
 *
 * @note Uses the linear search algorithm.
 *
 ********************************************************************/
int scc::search_symbol_table(int symbol, char type) const
{
    for (int i = 0; i < next_symbol_table_idx; i++)
    {
        if (symbol == symbol_table[i].symbol && type == symbol_table[i].type)
            return i;
    }

    return -1;
}

/**
 * Performs second pass of compilation.
 *
 ********************************************************************/
void scc::second_pass()
{
}

/**
 * Prints memory and data for the compiled SML program.
 *
 ********************************************************************/
void scc::print_program() const
{
    cout << setfill('0') << internal << showpos;

    // Print entire memory array.
    for (int i = 0; i < MEMORY_SIZE; i++)
        cout << setw(5) << memory[i] << endl;

    // Print "end of instructions" sentinel value.
    cout << -99999 << endl;

    cout << setfill(' ') << noshowpos;
    
    // Print data values.
    for (int i = 0; i < ndata; i++)
        cout << data[i] << endl;
}