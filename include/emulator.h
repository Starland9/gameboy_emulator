#ifndef EMULATOR_H
#define EMULATOR_H

#include <string>
#include "cpu.h"

class Emulator
{

private:
    Cpu cpu;

public:
    Emulator(/* args */);
    ~Emulator();

    void loadROM(const std::string &romPath);
    void run();

};

Emulator::Emulator(/* args */)
{
}

Emulator::~Emulator()
{
}


#endif // !EMULATOR_H