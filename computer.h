#ifndef COMPUTER_H
#define COMPUTER_H
#include "program.h"

class Computer {
private:
    double clockRateGHz; // Clock rate in GHz
    double cpiArith;     // CPI of arithmetic instructions
    double cpiStore;     // CPI of store instructions
    double cpiLoad;      // CPI of load instructions
    double cpiBranch;    // CPI of branch instructions

public:
    // Constructor to initialize the computer's specifications
    Computer(double clockRate, double cpiArith, double cpiStore, double cpiLoad, double cpiBranch)
        : clockRateGHz(clockRate), cpiArith(cpiArith), cpiStore(cpiStore), cpiLoad(cpiLoad), cpiBranch(cpiBranch) {}

    // Member function to calculate the global CPI
    double calculateGlobalCPI();

    // Member function to print the computer's stats
    void printStats();

    // Member function to calculate the execution time of a Program in seconds
    double calculateExecutionTime(Program);
    
    double calculateMIPS(void);
};

#endif // COMPUTER_H
