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

    /**
     * @brief Constructeur de la mémoire vive.
     *
     * Initialise tous les octets de la mémoire vive à 0.
     */
Memory::Memory(/* args */)
{
    data.fill(0); // Initialise tous les octets de la màmoire à 0
}

Memory::~Memory()
{
}
    /**
     * @brief Lit l'octet stock  dans la mémoire vive à l'adresse donnée.
     * @param address l'adresse de l'octet  lire
     * @return l'octet stock  à l'adresse
     */
 uint8_t Memory::read(uint16_t address) const
{
    return data[address]; // Lecture de l'octet
}

/**
 * @brief Ecrit un octet dans la mémoire vive à l'adresse donnée.
 * @param address L'adresse où l'octet doit être écrit.
 * @param value L'octet à écrire dans la mémoire.
 */
 void Memory::write(uint16_t address, uint8_t value)
{
    data[address] = value; // Ecriture de l'octet
}

#endif // !MEMORY_H