#ifndef EMULATOR_H
#define EMULATOR_H

#include <string>
#include "cpu.h"
#include "memory.h"

class Emulator
{

private:
    Cpu cpu;
    Memory memory;

public:
    Emulator(/* args */);
    ~Emulator();

    void loadROM(const std::string &romPath);
    void run();

};

Emulator::Emulator(/* args */) : cpu(memory)
{
}

Emulator::~Emulator()
{
}


#endif // !EMULATOR_H