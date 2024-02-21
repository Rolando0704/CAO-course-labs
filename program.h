#ifndef PROGRAM_H
#define PROGRAM_H

class Program {


public:

    int numArith;    // Number of arithmetic instructions
    int numStore;    // Number of store instructions
    int numLoad;     // Number of load instructions
    int numBranch;   // Number of branch instructions
    int numTotal;    // Total number of instructions


    // Constructor to initialize the program's instructions
    Program(int arith, int store, int load, int branch)
        : numArith(arith), numStore(store), numLoad(load), numBranch(branch) {
            numTotal = arith + store + load + branch;
        }

    //overloaded constructor:
    Program(int total, double arith, double store, double load)
        : numTotal(total), numArith(arith * total), numStore(store * total), numLoad(load * total) {
            numBranch = total * (1 - (arith + store + load));
        }

    // Member function to print the program's stats
    void printStats() const;
};

#endif // PROGRAM_H
