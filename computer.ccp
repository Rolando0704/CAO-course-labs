#include "computer.h"
#include <iostream>

// Calculate the global CPI based on specific CPIs for different instruction types
double Computer::calculateGlobalCPI() const {
    // Assuming equal distribution of instruction types for simplification
    // You may need to adjust the calculation based on actual distribution if provided
    double totalCPI = (cpiArith + cpiStore + cpiLoad + cpiBranch) / 4;
    return totalCPI;
}

// Print the computer's specifications including clock rate and CPIs
void Computer::printStats() const {
    std::cout << "Computer Specifications:" << std::endl;
    std::cout << "Clock Rate: " << clockRateGHz << " GHz" << std::endl;
    std::cout << "CPI (Arithmetic): " << cpiArith << std::endl;
    std::cout << "CPI (Store): " << cpiStore << std::endl;
    std::cout << "CPI (Load): " << cpiLoad << std::endl;
    std::cout << "CPI (Branch): " << cpiBranch << std::endl;
    std::cout << "Global CPI: " << calculateGlobalCPI() << std::endl;
}
