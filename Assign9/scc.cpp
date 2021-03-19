#include "sml.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>

using namespace std;

//#define SYMBOL_TABLE_SIZE 1000

struct table_entry
{
    int symbol;
    char type; // 'C' constant, 'L' Simple line number, 'V' variable
    int location; // Simplesim address (00 to MEMSIZE-1)
};

class scc
{
public: 
    static const int MEM_SIZE = 100;
    static const int SYMBOL_TABLE_SIZE = 1000;

    scc();
    void first_pass();
    void second_pass();
    void print_program() const;
private:
    int memory[MEM_SIZE];
    int data[MEM_SIZE];
    int ndata = 0;

    table_entry symbol_table[SYMBOL_TABLE_SIZE];
    int flags[MEM_SIZE];

    int next_instruction_addr = 0;
    int next_const_or_var_addr = MEM_SIZE -1;
    int next_symbol_table_idx = 0;
};

int main(int argc, char *argv[])
{
    scc compiler;

    compiler.first_pass();
    compiler.second_pass();
    compiler.print_program();

}

scc::scc()
{
    // Initalize memory and flags arrays
    for (int i = 0; i < MEM_SIZE; i++)
    {
        memory[i] = 7777;
        flags[i] = -1;
    }
}

void scc::first_pass()
{
    string buffer1, buffer2, line_number, command;

    while (getline(cin, buffer1))
    {
        buffer2 = buffer1;         // buffer2 used for 'let'
        istringstream ss(buffer1);
        
        ss >> line_number;
        
        // ... code to add line_number to symbol table, type 'L' ...
        
        ss >> command;
        
        if (command == "input")
        {
            // ... code to process 'input' command ...
        }
        else if (command == "data")
        {
            // ... code to process 'data' command ...
        }
        else if (command == "let")
        {
            // ... code to process 'let' command ...
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
        else if (command == "rem")
        {
            // ... code to process 'rem' command ...
        }
    }
}

void scc::second_pass()
{

}

void scc::print_program() const
{
    // Print memory array followed by the data array
    for (int i = 0; i < MEM_SIZE; i++)
    {
        cout << setw(4) << setfill('0') << memory[i] << endl;
    } 
    cout << -99999 << endl;
    for (int i = 0; i < ndata; i++)
    {
        cout << data[i] << endl;
    } 
}