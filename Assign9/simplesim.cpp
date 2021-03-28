/**********************************************************
 * CSCI 241         Assignment 4     Spring 2021
 * @author Alexander Kashyap
 * @file simplesim.cpp
 * @version 1.0
 * Section: 1
 * Date Due: 2/11/2021
 * Z-id: z1926618  
 **********************************************************/
#include <iostream>
#include <iomanip>

// Including headers files for sml operation codes and class definition
#include "sml.h"
#include "simplesim.h"

using namespace std;

/**
 * Constructor for simplesim class
 * fills memory with 7777
 */
simplesim::simplesim()
{
    // Initializing the memory
    for (int i = 0; i < 100; i++) 
    {
        memory[i] = 7777;
    }
}

/**
 * reads an SML program from standard input and attempts to load it into the Simplesim's memory
 * @return value indicating whether or not the program was successfully 
 * loaded (true if so, false if the load process abnormally terminated).
 */
bool simplesim::load_program()
{
    // Read in instuctions from standard input until end of instuction code (-99999) or memory is full
    int count = 0;
    int instruction;
    while (cin >> instruction && instruction != -99999) 
    {
        // Invalid instuction check
        if (not_valid_word(instruction))
        {
            cout << "*** ABEND: pgm load: invalid word ***" << endl;
            return false;
        }
        // Too many instructions check
        if (count >= 100)
        {
            cout << "*** ABEND: pgm load: pgm too large ***" << endl;
            return false;
        }
        // Filling memory and incrementing the counter
        memory[count] = instruction;
        count++;
    }

    // Program was loaded with no error
    return true;
}

/**
 * Function that checks if a passed int is within a range
 * @return true if outside the range, false if inside
 */
bool simplesim::not_valid_word(int word) const
{
    return (word < -9999 || word > 9999);
}

/**
 * execute the simplesim program thats currently in memory
 */
void simplesim::execute_program()
{
    // Initializing variables
    bool done = false; // done - loop over and complete instuctions until done
    bool branched = false; // branched - boolean that checks if the current inctruction was a branch
    instruction_counter = 0; // instruction_counter - current instuction we are on
    while (!done)
    {
        
        // Testing the instuction counter is within range
        if (instruction_counter >= 100)
        {
            cout << "*** ABEND: addressability error ***" << endl;
            return;
        }

        // Fetching instructions
        instruction_register = memory[instruction_counter];
        operation_code = instruction_register / 100;
        operand = instruction_register % 100;

        // Instruction execute
        switch (operation_code)
        {
            // Input/Output Operations
            case READ:
                int num; 
                cin >> num;
                if (not_valid_word(num)) 
                {
                    cout << "*** ABEND: illegal input ***" << endl;
                    return;    
                }
                cout << "READ: " << showpos << setfill('0') << setw(5) << internal << num << endl;
                memory[operand] = num;
                break;
            case WRITE:
                cout << showpos << setfill('0') << setw(5) << internal << memory[operand] << endl;
                break;
            // Store/Load Operations
            case LOAD:
                accumulator = memory[operand];
                break;
            case STORE:
                memory[operand] = accumulator;
                break;
            // Arithmetic Operations (must check over/under flows)
            case ADD:
                if (overunder(accumulator + memory[operand]))
                {
                    return;
                }
                accumulator += memory[operand];
                break;
            case SUBTRACT:
                if (overunder(accumulator - memory[operand]))
                {
                    return;
                }
                accumulator -= memory[operand];
                break;
            case MULTIPLY:
                if (overunder(accumulator * memory[operand]))
                {
                    return;
                }
                accumulator *= memory[operand];
                break;
            case DIVIDE:
                // Special division by 0 case
                if (memory[operand] == 0)
                {
                    cout << "*** ABEND: attempted division by 0 ***" << endl;
                    return;
                }
                if (overunder(accumulator / memory[operand]))
                {
                    return;
                }
                accumulator /= memory[operand];
                break;
            // Transfer Control Operations
            case BRANCH:
                branched = true;
                instruction_counter = operand;
                break;
            case BRANCHZERO:
                if (accumulator == 0)
                {
                    branched = true;
                    instruction_counter = operand;
                }
                break;
            case BRANCHNEG:
                if (accumulator < 0)
                {
                    branched = true;
                    instruction_counter = operand;
                }
                break;
            case HALT:
                // Finished
                done = true;
                cout << "*** Simplesim execution terminated ***" << endl;
                break;
            // More cases
            default:
                // Error message and return
                cout << "*** ABEND: invalid opcode ***" << endl;
                return;
        }

        // As long as we are not branching and not done, continue to the next instruction        
        if (!branched && !done)
        {
            instruction_counter++;
        }

        // Reset branched for next instruction
        branched = false;
        
    }
}

/**
 * checks if a passed num is within range -9999 to 9999 for over and underflow
 * @return true if out of range, false if in range
 */
bool simplesim::overunder(int num) const
{
    if (num < -9999) 
    {
        cout << "*** ABEND: underflow ***" << endl;
        return true;
    }
    else if (num > 9999)
    {
        cout << "*** ABEND: overflow ***" << endl;
        return true;
    }
    return false;
}
/**
 * dumps the contents of the Simplesim's registers and memory
 */
void simplesim::dump() const
{
    // Print the registers
    cout << setfill(' ');
    cout << "\nREGISTERS:\n";
    cout << setw(24) << left << "accumulator: " << showpos << setw(5) << setfill('0') << internal << accumulator << endl << setfill(' ');
    cout << setw(24) << left << "instruction_counter: " << noshowpos << setw(2) << setfill('0') << right << instruction_counter << endl << setfill(' ');
    cout << setw(24) << left << "instruction_register: " << showpos << setw(5) << setfill('0') << internal << instruction_register << endl << setfill(' ');
    cout << setw(24) << left << "operation_code: " << noshowpos << setw(2) << setfill('0') << right << operation_code << endl << setfill(' ');
    cout << setw(24) << left << "operand: " << setw(2) << setfill('0') << right << operand << endl << setfill(' ');

    // Printing the memory

    // first set of numbers on top
    cout << "\nMEMORY:\n   ";
    for (int i = 0; i < 9; i++)
    {
        cout << right << setw(5) << i << " ";
    }
    cout << right << setw(5) << 9;

    // Memory
    cout << endl << right << " 0 ";
    for (int i = 0; i < 100; i++) 
    {
        cout << showpos << setw(5) << setfill('0') << internal << memory[i];
        if ((i + 1) % 10 == 0 && i != 99)
        {
            cout << endl << noshowpos << (i + 1) << " ";
        }
        else if (i != 99)
        {
            cout << " ";
        }
    }
    cout << endl;
}   

// GO TO NOTES FOR OUTPUT FORMATTING 
// setw(), endl, left, right, internal, showpos / noshowpos, setfill('0')
// 1. labels on registers (which are strings) - width 24 left
// 2. four didgit signed number with leading zeros (accumulator, instruction register, memory elements) - width 5, fill char 0, internal justification, showpos
// 3. twi digit unsigned register (instuction counter, operation code, operand) - width 2, right justified, fill 0
// 4. row and colomn headers - setw(6), fill char space, no sign