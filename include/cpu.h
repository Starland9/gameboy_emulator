#ifndef CPU_H
#define CPU_H


#include <cstdint>
#include "memory.h"


struct Registers
{
    uint8_t A, F; // Accumulator and flags
    uint8_t B, C;
    uint8_t D, E;
    uint8_t H, L;
    uint16_t SP; // Stack pointer
    uint16_t PC; // Program counter
};



class Cpu
{
private:
    Registers reg;
    int cycles;
    Memory memory;

public:
    Cpu(Memory &memory);
    ~Cpu();

    void executeOpcode(uint8_t opcode);
};

Cpu::Cpu(Memory &memory) : memory(memory)
{
}

Cpu::~Cpu()
{
}

void Cpu::executeOpcode(uint8_t opcode)
{
    switch (opcode)
    {
    case 0x00: // NOP
        cycles += 4; // 4 cycles par instruction
        break;

    case 0x01: // LD BC, d16
        reg.C = memory.read(reg.PC++); // On lit le premier octet
        reg.B = memory.read(reg.PC++); // On lit le deuxième octet
        cycles += 12; // 12 cycles par instruction
        break;

    
    default:
        break;
    }
}


#endif // !CPU_H