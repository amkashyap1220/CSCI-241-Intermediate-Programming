#ifndef SIMPLESIM_H
#define SIMPLESIM_H

class simplesim
{
private:

    // Private data members
    int memory[100];
    int accumulator = 0;
    int instruction_counter = 0;
    int instruction_register = 0;
    int operation_code = 0;
    int operand = 0; 

    // Private function prototypes
    bool not_valid_word(int word) const;
    bool overunder(int) const;

public:

    // Function Prototypes
    simplesim();
    bool load_program();
    void execute_program();
    void dump() const;

};

#endif