#include "computer.h"
#include "program.h"
#include <iostream>

// Calculate the global CPI based on specific CPIs for different instruction types
double Computer::calculateGlobalCPI() {
    // Assuming equal distribution of instruction types for simplification
    // You may need to adjust the calculation based on actual distribution if provided
    double totalCPI = (cpiArith + cpiStore + cpiLoad + cpiBranch) / 4;
    return totalCPI;
}

// Print the computer's specifications including clock rate and CPIs
void Computer::printStats() {
    std::cout << "Computer Specifications:" << std::endl;
    std::cout << "Clock Rate: " << clockRateGHz << " GHz" << std::endl;
    std::cout << "CPI (Arithmetic): " << cpiArith << std::endl;
    std::cout << "CPI (Store): " << cpiStore << std::endl;
    std::cout << "CPI (Load): " << cpiLoad << std::endl;
    std::cout << "CPI (Branch): " << cpiBranch << std::endl;
    std::cout << "Global CPI: " << calculateGlobalCPI() << std::endl;
}


// Implementation of the calculateExecutionTime member function
double Computer::calculateExecutionTime(Program program) {
    // Total execution time calculation based on instruction counts
    double totalTime = (program.numArith * cpiArith +
                       program.numStore * cpiStore +
                       program.numLoad * cpiLoad +
                       program.numBranch * cpiBranch)/ (clockRateGHz * 1e9);

    return totalTime;

}

// Implementation of the calculateglobalMIPS member function
double Computer::calculateglobalMIPS() {
    // Global MIPS calculation based on instruction counts
    double globalMIPS = (clockRateGHz * 1e3)/ Computer::calculateGlobalCPI();

    return globalMIPS;

}


// Implementation of the calculateMIPS member function
double Computer::calculateMIPS(Program program) {
    // Global MIPS calculation based on instruction counts
    double MIPS = ((program.numTotal) / Computer::calculateExecutionTime(Program program))/ 1e6;

    return MIPS;

}
