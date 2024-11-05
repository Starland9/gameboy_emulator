#ifndef MEMORY_H
#define MEMORY_H


#include<array>
#include <cstdint>

class Memory
{
private:
    std::array<uint8_t, 0x10000> data; // 64 KB de mémoire


public:
    Memory(/* args */);
    ~Memory();

    uint8_t read(uint16_t address) const;
    void write(uint16_t address, uint8_t value);
};

Memory::Memory(/* args */)
{
    data.fill(0); // Initialise tous les octets de la màmoire à 0
}

Memory::~Memory()
{
}
 uint8_t Memory::read(uint16_t address) const
{
    return data[address]; // Lecture de l'octet
}

 void Memory::write(uint16_t address, uint8_t value)
{
    data[address] = value; // Ecriture de l'octet
}

#endif // !MEMORY_H