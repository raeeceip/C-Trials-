#include "stack-vm.h"

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

/*
Reference : Phillip Bohun

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

i32 StackVM::getData(i32 instruction)
{
    i32 data = 0x3fffffff;
    data = data & instruction;
    return data;
}

void StackVM::fetch()
{
    pc++;
}

void StackVM::decode()
{
    typ = getType(memory[pc]);
    dat = getData(memory[pc]);
}

void StackVM::execute()
{
    if (typ == 0 || typ == 2)
    {
        sp++;
        memory[sp] = dat;
    }
    else
    {
        doPrimitive();
    }
}
void StackVM::doPrimitive()
{
    // designing instructions for primitive functions
    switch (dat)
    {
    case 0: //  halt
        std::cout << "halt" << std::endl;
        running = 0;
        break;
    case 1: // add
        std::cout << "add " << memory[sp - 1] << " " << memory[sp] << std::endl;
        memory[sp - 1] = memory[sp - 1] + memory[sp];
        sp--;
        /*
        we essentially add two things from the stack together, and since when we add them we have to remove them from the stack and place the result back into it, we have to remove one from he current stack space, Does that make sense Chiso?
        */
        break;
    }
}

void StackVM::run()
{
    pc -= 1;
    while (running == 1)
    {
        fetch();
        decode();
        execute();
        std::cout << "top of stack" << memory[sp] << std::endl;
    }
}
void StackVM::loadProgram(std::vector<i32> prog)
{
    for (i32 i = 0; i < prog.size(); i++)
    {
        memory[pc + i] = prog[i];
    }
}