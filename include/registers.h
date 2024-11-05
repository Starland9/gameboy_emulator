#ifndef REGISTERS_H
#define REGISTERS_H


#include <cstdint>

class Registers
{
private:

public:
    Registers(/* args */);
    ~Registers();

    uint8_t A, F; // Accumulator and flags
    uint8_t B, C;
    uint8_t D, E;
    uint8_t H, L;
    uint16_t SP; // Stack pointer
    uint16_t PC; // Program counter


    /**
     * @brief Returns the combined value of registers B and C.
     * @return A 16-bit unsigned integer where the upper byte is B and the lower byte is C.
     */
    uint16_t BC() const
    {
        return (uint16_t)(B << 8) | C;
    }

    /**
     * @brief Returns the combined value of registers D and E.
     * @return A 16-bit unsigned integer where the upper byte is D and the lower byte is E.
     */
    uint16_t DE() const
    {
        return (uint16_t)(D << 8) | E;
    }

    /**
     * @brief Returns the combined value of registers H and L.
     * @return A 16-bit unsigned integer where the upper byte is H and the lower byte is L.
     */
    uint16_t HL() const
    {
        return (uint16_t)(H << 8) | L;
    }


    void incRegs(uint8_t &reg1, uint8_t &reg2)
    {
        reg2++;
        if (reg2 == 0)
        {
            reg1++;
        }
    }

    void incBC()
    {
       incRegs(B, C);
    }
    
    void incDE()
    {
       incRegs(D, E);
    }

    void incHL()
    {
       incRegs(H, L);
    }

};


#endif // !REGISTERS_H