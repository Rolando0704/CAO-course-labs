#include "registers.h"
#include <iostream>
using namespace std;

Registers::Registers() {
    // Initialize all registers to 0.
    for (int i = 0; i < 32; ++i) {
        regs[i] = 0;
    }
    PC = 0; // Initialize program counter to 0.
}

void Registers::setRegister(int regNum, int value) {
    if (regNum >= 0 && regNum < 32 && regNum != 0) {
        regs[regNum] = value;
    }
}

int Registers::getRegister(int regNum) {
    if (regNum == 0) {
        return 0; // Register $0 always returns 0.
    } else if (regNum >= 0 && regNum < 32) {
        return regs[regNum];
    } else {
        return 0; // Out of bounds access returns 0.
    }
}

void Registers::setPC(int value) {
    PC = value;
}

int Registers::getPC() {
    return PC;
}

void Registers::print() {
    cout << "Registers state:" << endl;
    for (int i = 0; i < 32; ++i) {
        cout << "R" << i << ": " << regs[i] << endl;
    }
    cout << "Program Counter: " << PC << endl;
}
