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
    char type;    // 'C' constant, 'L' Simple line number, 'V' variable
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
    int next_const_or_var_addr = MEM_SIZE - 1;
    int next_symbol_table_idx = 0;

    void memory_check() const;
    void data_check() const;
    void handle_end();
    void handle_input(istringstream &ss);
    int get_symbol_location(const string &token);
    int search_symbol_table(int, char) const;
    void handle_data(istringstream &ss);
    void handle_let(istringstream &ss, const string& buffer);
    void stack_space_check(int location) const;
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

void scc::stack_space_check(int location) const
{
    if (location < next_instruction_addr)
    {
        cout << "*** ERROR: insufficient stack space ***\n";
        exit(1);
    }
}

void scc::first_pass()
{
    string buffer1, buffer2, line_number, command;

    while (getline(cin, buffer1))
    {
        buffer2 = buffer1; // buffer2 used for 'let'
        istringstream ss(buffer1);

        ss >> line_number;

        // ... code to add line_number to symbol table, type 'L' ...
        symbol_table[next_symbol_table_idx].symbol = stoi(line_number);
        symbol_table[next_symbol_table_idx].type = 'L';
        symbol_table[next_symbol_table_idx].location = next_instruction_addr;
        next_symbol_table_idx++;

        // Extract the command
        ss >> command;

        if (command == "input")
        {
            // ... code to process 'input' command ...
            handle_input(ss);
        }
        else if (command == "data")
        {
            handle_data(ss);
        }
        else if (command == "let")
        {
            // ... code to process 'let' command ...

            handle_let(istringstream &ss, const string &buffer1);
        }
        else if (command == "if")
        {
            // this and let are the only two more than 1 sml lines

            // 60 if x > 10 goto 120

            string lop, relop, rop, unused;
            int lop_location, rop_location, linen, branch_location;

            // Read left operand into lop
            // Get location for the symbol lop (lop location) (I HAVE A FUNCTUION FOR THIS)

            // Read relational operator into relop

            // REad right operand into rop
            // Get location for the symbol rop (rop_location)

            // read the 'goto' into unused and ignore it

            // read line number into linen

            // Search the symbol table for that line number. A failed search will require the generation of partial branch instructions until second pass
            int index = search_symbol_table(linen, 'L');

            // Test relop and generate the appropriate complete or partial instructions for this relational operator
            if (relop == ">")
            {
                // Generate Load
                memory_check();
                memory[next_instruction_addr] = LOAD * 100 + rop_location;
                next_instruction_addr++;

                // Generate Subract
                memory_check();
                memory[next_instruction_addr] = SUBTRACT * 100 + lop_location;
                next_instruction_addr++;

                // Generate BRANCHNEG
                memory_check();
                if (index == -1)
                {
                    memory[next_instruction_addr] = BRANCHNEG * 100;
                    flags[next_instruction_addr] = linen;
                }
                else
                {
                    memory[next_instruction_addr] = BRANCHNEG * 100 + symbol_table[index].location;
                }
                next_instruction_addr++;
            }
            else if (relop == "<")
            {
                    // LECTURE 20; THERE SHOULD BE A branch logic for if_goto.docx
            }


        }
        else if (command == "goto")
        {
        }
        else if (command == "print")
        {
        }
        else if (command == "end")
        {
            // ... code to process 'end' command ...
            handle_end();
        }
        else if (command == "rem")
        {
        }
    }
}

void scc::handle_let(istringstream &ss, const string& buffer)
{
    // 85 let x (y + 10) * (z - 3)

    string lvar; // variabvle on left of statement
    int lvar_location, location;
    string token, postfix;

    // Read the variable on the left side of the '=' into lvar
    // Get the location of the symbol lvar (lvar_location)

    // Locate the '=' in buffer. Infix string starts after that

    // call your convert funciton, passing it the infix string, to get the postfix string to process

    istringstream ss(postfix);
    int next_stack_idx = 0;
    while (ss >> token)
    {
        if (islower(token[0]) || isdigit(token[0]))
        {
            // This is an operand (variable or constant)

            // Get the location of token from the symbol table (location)
            int location = get_symbol_location(token);

            memory_check();
            memory[next_instruction_addr] = LOAD * 100 + location;
            next_instruction_addr++;

            memory_check();
            memory[next_instruction_addr] = STORE * 100;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr;
            next_stack_idx++;
        }
        else if (token == "+")
        {
            memory_check();
            memory[next_instruction_addr] = LOAD * 100;     // omit address
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;

            memory_check();
            memory[next_instruction_addr] = ADD * 100;      // for addition, omit address
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;

            memory_check();
            memory[next_instruction_addr] = STORE * 100;    // omit address
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_stack_idx++;
            next_instruction_addr++;
        }
        else if (token == "*")
        {
            memory_check();
            memory[next_instruction_addr] = LOAD * 100;     // omit address
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;

            memory_check();
            memory[next_instruction_addr] = MULTIPLY * 100;      // for addition, omit address
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;

            memory_check();
            memory[next_instruction_addr] = STORE * 100;    // omit address
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_stack_idx++;
            next_instruction_addr++;
        }
        else if (token == "-")
        {
            memory_check();
            memory[next_instruction_addr] = LOAD * 100;        // omit address
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;
            
            memory_check();
            memory[next_instruction_addr] = STORE * 100;       // omit address
            flags[next_instruction_addr] = -2;
            next_instruction_addr++;
            
            memory_check();
            memory[next_instruction_addr] = LOAD * 100;        // omit address
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;
            
            memory_check();
            memory[next_instruction_addr] = SUBTRACT * 100;    // for subtraction, omit address
            flags[next_instruction_addr] = -2;
            next_instruction_addr++;
            
            memory_check();
            memory[next_instruction_addr] = STORE * 100;       // omit address
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_stack_idx++;
            next_instruction_addr++;
        }
        else // if (token == "/")
        {
             memory_check();
            memory[next_instruction_addr] = LOAD * 100;        // omit address
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;
            
            memory_check();
            memory[next_instruction_addr] = STORE * 100;       // omit address
            flags[next_instruction_addr] = -2;
            next_instruction_addr++;
            
            memory_check();
            memory[next_instruction_addr] = LOAD * 100;        // omit address
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;
            
            memory_check();
            memory[next_instruction_addr] = DIVIDE * 100;    // for subtraction, omit address
            flags[next_instruction_addr] = -2;
            next_instruction_addr++;
            
            memory_check();
            memory[next_instruction_addr] = STORE * 100;       // omit address
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_stack_idx++;
            next_instruction_addr++;
        }
    }

    // Pop the final result off the stack

    memory_check();
    memory[next_instruction_addr] = LOAD * 100;
    flags[next_instruction_addr] = -3;
    next_instruction_addr++;

    memory_check();
    memory[next_instruction_addr] = STORE * 100 + lvar_location;
}
void scc::handle_data(istringstream &ss)
{
    string token;

    ss >> token;

    data_check();
    data[ndata] = stoi(token);
    ndata++;
}
void scc::memory_check() const
{
    if (next_instruction_addr >= MEM_SIZE || next_instruction_addr > next_const_or_var_addr)
    {
        cout << "*** ERROR: ran out of Simplesim memory ***\n";
        exit(1);
    }
}

void scc::data_check() const
{
    if (ndata >= MEM_SIZE)
    {
        cout << "*** ERROR: too many data lines ***\n";
        exit(1);
    }
}

void scc::handle_input(istringstream &ss)
{
    string token;

    ss >> token;

    int location = get_symbol_location(token);

    memory_check();
    memory[next_instruction_addr] = READ * 100 + location;
    next_instruction_addr++;
}

int scc::get_symbol_location(const string &token)
{
    int location, symbol;
    char type;

    if (islower(token[0]))
    {
        // This is a variable
        symbol = token[0];
        type = 'V';
    }
    else
    {
        // This is an integer const
        symbol = stoi(token);
        type = 'C';
    }

    int index = search_symbol_table(symbol, type);
    if (index == -1)
    {
        // Symbol is not in the table
        // Add this symbol to the symbol table and to memory
        location = next_const_or_var_addr;

        symbol_table[next_symbol_table_idx].symbol = symbol;
        symbol_table[next_symbol_table_idx].type = type;
        symbol_table[next_symbol_table_idx].location = location;

        next_symbol_table_idx++;

        //Allovate memory for this constant or variable
        memory_check();
        if (type == 'V')
        {
            memory[next_const_or_var_addr] = 0;
        }
        else
        {
            memory[next_const_or_var_addr] = symbol;
        }
        next_const_or_var_addr--;
    }
    else
    {
        // Symnol is in the table at index 
        location = symbol_table[index].location;
    }
    return location;
}

int scc::search_symbol_table(int symbol, char type) const
{
    for (int i = 0; i < next_symbol_table_idx; i++)
    {
        if (symbol_table[i].symbol == symbol && symbol_table[i].type == type)
        {
            return i;
        }
    }
    return -1;
}

void scc::handle_end()
{
    memory_check();
    memory[next_instruction_addr] = HALT * 100;
    next_instruction_addr++;
}

void scc::second_pass()
{
    int index;
    int stack_start = next_const_or_var_addr - 1;

    for (int i = 0; i < next_const_or_var_addr; i++)
    {
        if (flags[i] != -1) // incomplet instruction ?
        {
            if (flags[i] > 0) // goto
            {
                // Search symbol table for line number flags[i]
                // add that line number's lovation from the symbol table the instruciton
                // memory[i] += ...
            }
            else if (flags[i] == -2) // incomplete right op reg
            {
                // add location of temp storage to instuction
                memory[i] += next_const_or_var_addr;
            }
            else if (flags[i] < -2) // incomplete stack reference
            {
                // compute stack idx

                int idx = -3 - flags[i];
               // location fo that stack elemet = stack start - idx;
               // stack_space_check(location);

                // check to see if location referenced by stack index is within the bounds of the space available for te stack
                // add location to instruction 
            }
        }
    }
}

void scc::print_program() const
{
    // Print memory array followed by the data array
    cout << setfill('0') << internal << showpos;
    for (int i = 0; i < MEM_SIZE; i++)
    {
        cout << setw(5) << memory[i] << endl;
    }
    cout << -99999 << endl;

    cout << setfill(' ') << noshowpos;
    for (int i = 0; i < ndata; i++)
    {
        cout << data[i] << endl;
    }
}