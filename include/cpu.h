#ifndef CPU_H
#define CPU_H


#include <cstdint>
#include "memory.h"
#include "registers.h"




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

    case 0x02: // LD (BC), A
        memory.write(reg.BC(), reg.A);
        cycles += 8; // 8 cycles par instruction
        break;

    case 0x03: // INC BC
        reg.incBC();
        cycles += 8; // 8 cycles par instruction
        break;

    case 0x04: // INC B
        reg.B ++;
        reg.F = (reg.B == 0) ? 0x80 : 0; // Met à jour le registre F
        reg.F |= 0x20;
        reg.F |= (reg.B & 0x10) ? 0x40 : 0;
        cycles += 4; // 4 cycles par instruction
        break;
    
    default:
        break;
    }
}


#endif // !CPU_H