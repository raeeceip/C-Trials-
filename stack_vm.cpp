#include 'vm.h'

/*

Instruction format
-----------------
Header : 2 bits
Data : 30 bits

header format
-------------
0 - positive integer
1 - primitive instruction
2 - Negative integer
3 - Undefined

*/
// functions

// reserveing memory
StackVM::StackVM()
{
    memory.reserve(1000000);
}
i32 StackVM::getType(i32 instruction)
{
    i32 type = 0xc0000000;
    type = (type & instruction) >> 30;
    return type;
}