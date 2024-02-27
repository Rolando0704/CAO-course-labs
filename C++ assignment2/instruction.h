
#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "registers.h"

class Instruction {
public:
    virtual ~Instruction() {}
    virtual void execute(Registers *registers) const = 0;
    virtual void disassemble() const = 0;
};

class AddInstruction : public Instruction {
public:
    AddInstruction(int rs, int rt, int rd);
    void execute(Registers *registers) const override;
    void disassemble() const override;
private:
    int rs, rt, rd;
};

class SubInstruction : public Instruction {
public:
    SubInstruction(int rs, int rt, int rd);
    void execute(Registers *registers) const override;
    void disassemble() const override;
private:
    int rs, rt, rd;
};

class OriInstruction : public Instruction {
public:
    OriInstruction(int rs, int rt, int immediate);
    void execute(Registers *registers) const override;
    void disassemble() const override;
private:
    int rs, rt, immediate;
};

class BrneInstruction : public Instruction {
public:
    BrneInstruction(int rs, int rt, int offset);
    void execute(Registers *registers) const override;
    void disassemble() const override;
private:
    int rs, rt, offset;
};

#endif // INSTRUCTION_H
