#include "registers.h"
#include "instruction.h"
#include <iostream>
#include <vector>

int main() {
    Registers cpuRegisters;
    cpuRegisters.setRegister(1, 10); // R1 = 10
    cpuRegisters.setRegister(2, 20); // R2 = 20

    std::vector<Instruction*> instructions;

    instructions.push_back(new AddInstruction(1, 2, 3)); // R3 = R1 + R2
    instructions.push_back(new SubInstruction(2, 1, 4)); // R4 = R2 - R1
    instructions.push_back(new OriInstruction(1, 5, 0xFF)); // R5 = R1 | 0xFF
    instructions.push_back(new BrneInstruction(1, 2, 4)); // if R1 != R2, PC += 4

    // Execute and disassemble instructions
    for (size_t i = 0; i < instructions.size(); ++i) {
        instructions[i]->execute(&cpuRegisters);
        instructions[i]->disassemble();
        cpuRegisters.print();
    }

    // Clean up instructions
    for (size_t i = 0; i < instructions.size(); ++i) {
        delete instructions[i];
    }

    return 0;
}
