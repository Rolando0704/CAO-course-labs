#ifndef REGISTERS_H
#define REGISTERS_H

class Registers {
private:
    int regs[32]; // Array to hold the values of the registers.
    int PC; // Variable to hold the value of the program counter.

public:
    Registers(); // Constructor.
    void setRegister(int regNum, int value);
    int getRegister(int regNum);
    void setPC(int value);
    int getPC();
    void print();
};

#endif // REGISTERS_H
