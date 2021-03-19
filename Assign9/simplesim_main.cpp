#include "simplesim.h"
#include "sml.h"

int main()
{
    simplesim s;

    if (s.load_program())
        s.execute_program();

    s.dump();

    return 0;
}
