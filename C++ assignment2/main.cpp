
#include "registers.h"
#include "instruction.h"
#include <iostream>
#include <vector>

// Function to append instructions to the program
void appendInstruction(std::vector<Instruction*>& instructions, Instruction* instr) {
    instructions.push_back(instr);
}

int main() {
    Registers cpuRegisters;

    // Instructions vector
    std::vector<Instruction*> instructions;

    // Append MIPS instructions to the instructions vector
    appendInstruction(instructions, new OriInstruction(0, 1, 12)); // ori $s1, $0, 12
    appendInstruction(instructions, new OriInstruction(0, 2, 4));  // ori $s2, $0, 4
    appendInstruction(instructions, new OriInstruction(0, 3, 1));  // ori $s3, $0, 1


    // Print initial register state
    cpuRegisters.print();

    // Execute the first three instructions and print register state
    for (int i = 0; i < 3; ++i) {
        instructions[i]->execute(&cpuRegisters);
        instructions[i]->disassemble();
        cpuRegisters.print();
    }

// Append loop instructions to the instructions vector
appendInstruction(instructions, new AddInstruction(4, 1, 4));  // add $s4, $s4, $s1
appendInstruction(instructions, new SubInstruction(2, 3, 2));  // sub $s2, $s2, $s3
appendInstruction(instructions, new BrneInstruction(2, 0, -3)); // brne $s2, $0, loop start

// Set the program counter to the start of the loop, which is the fifth instruction
//cpuRegisters.setPC(4);

// Execute the loop using BrneInstruction
while (true) {
    instructions[3]->execute(&cpuRegisters); // add $s4, $s4, $s1
    instructions[3]->disassemble();
    cpuRegisters.print();

    instructions[4]->execute(&cpuRegisters); // sub $s2, $s2, $s3
    instructions[4]->disassemble();
    cpuRegisters.print();

    instructions[5]->execute(&cpuRegisters); // brne $s2, $0, loop start
    instructions[5]->disassemble();
    cpuRegisters.print();

    if (cpuRegisters.getPC() != 3) { // If PC is not pointing to the loop start, break
        break;
    }
}
    // Print initial register state
    cpuRegisters.print();

    return 0;
}


/*
#include "registers.h"
#include "instruction.h"
#include <iostream>
#include <vector>

// Function to append instructions to the program
void appendInstruction(std::vector<Instruction*>& instructions, Instruction* instr) {
    instructions.push_back(instr);
}

int main() {
    Registers cpuRegisters;

    // Instructions vector
    std::vector<Instruction*> instructions;

    // Append MIPS instructions to the instructions vector
    appendInstruction(instructions, new OriInstruction(0, 17, 12)); // ori $s1, $0, 12
    appendInstruction(instructions, new OriInstruction(0, 18, 4));  // ori $s2, $0, 4
    appendInstruction(instructions, new OriInstruction(0, 19, 1));  // ori $s3, $0, 1

    // Print initial register state
    cpuRegisters.print();

    // Execute the first three instructions and print register state
    for (int i = 0; i < 3; ++i) {
        instructions[i]->execute(&cpuRegisters);
        instructions[i]->disassemble();
        cpuRegisters.print();
    }

    // Append loop instructions to the instructions vector
    appendInstruction(instructions, new AddInstruction(20, 17, 20)); // add $s4, $s4, $s1
    appendInstruction(instructions, new SubInstruction(18, 19, 18)); // sub $s2, $s2, $s3

    // Simulate the loop by executing the last two instructions repeatedly
    for (int loopCounter = 0; cpuRegisters.getRegister(18) != cpuRegisters.getRegister(0); ++loopCounter) {
        instructions[3]->execute(&cpuRegisters); // add $s4, $s4, $s1
        instructions[3]->disassemble();
        cpuRegisters.print();

        instructions[4]->execute(&cpuRegisters); // sub $s2, $s2, $s3
        instructions[4]->disassemble();
        cpuRegisters.print();

        // Check for the branch condition
        if (cpuRegisters.getRegister(18) != cpuRegisters.getRegister(0)) {
            // Adjust PC for the loop, in this simulation, we do not actually use PC, so no change
        } else {
            break; // Exit the loop if $s2 is equal to $0
        }
    }

    // Clean up instructions
    for (size_t i = 0; i < instructions.size(); ++i) {
        delete instructions[i];
    }

    return 0;
}
*/
