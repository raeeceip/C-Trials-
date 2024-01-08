#ifndef STACK
#define STACK

#include <iostream>
#include <vector>
using namespace std;

// Defining types for the vm
typedef int32_t i32;

class StackVM
{
    // Creating registers to store information
    i32 pc = 100; // program counter
    i32 sp = 0;   // stack pointer
    std::vector<i32> memory;
    i32 typ = 0;
    i32 dat = 0;
    i32 running = 1; // check if vm is stil running

    // creating a private set of functions for stackVm class
    i32 getType(i32 instruction);
    i32 getData(i32 instruction);

    // a CPU basically uses these three functions in a loop, to run and execute commands in a computer
    void fetch();       // gets next command from memory
    void decode();      // decodes the command
    void execute();     // executes the command
    void doPrimitive(); // helper function for the vm

    // public functions
    StackVM() void run() void loadProgram(std::vector<i32> prog);
};