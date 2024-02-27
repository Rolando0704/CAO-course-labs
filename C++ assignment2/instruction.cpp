
#include "instruction.h"
#include <iostream>

using namespace std;

// AddInstruction implementation
AddInstruction::AddInstruction(int rs, int rt, int rd) : rs(rs), rt(rt), rd(rd) {}

void AddInstruction::execute(Registers *registers) const {
    registers->setRegister(registers->getRegister(rs) + registers->getRegister(rt), rd);
}

void AddInstruction::disassemble() const {
    cout << "ADD R" << rd << ", R" << rs << ", R" << rt << endl;
}

// SubInstruction implementation
SubInstruction::SubInstruction(int rs, int rt, int rd) : rs(rs), rt(rt), rd(rd) {}

void SubInstruction::execute(Registers *registers) const {
    registers->setRegister(registers->getRegister(rs) - registers->getRegister(rt), rd);
}

void SubInstruction::disassemble() const {
    cout << "SUB R" << rd << ", R" << rs << ", R" << rt << endl;
}

// OriInstruction implementation
OriInstruction::OriInstruction(int rs, int rt, int immediate) : rs(rs), rt(rt), immediate(immediate) {}

void OriInstruction::execute(Registers *registers) const {
    registers->setRegister(registers->getRegister(rs) | immediate, rt);
}

void OriInstruction::disassemble() const {
    cout << "ORI R" << rt << ", R" << rs << ", #" << immediate << endl;
}

// BrneInstruction implementation
BrneInstruction::BrneInstruction(int rs, int rt, int offset) : rs(rs), rt(rt), offset(offset) {}

void BrneInstruction::execute(Registers *registers) const {
    if (registers->getRegister(rs) != registers->getRegister(rt)) {
        registers->setPC(registers->getPC() + offset);
    }
}

void BrneInstruction::disassemble() const {
    cout << "BRNE R" << rs << ", R" << rt << ", PC+" << offset << endl;
}
