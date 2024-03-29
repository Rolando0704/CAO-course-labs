#include "program.h"
#include <iostream>


// Member function to print the program's stats
void Program::printStats() const {
    std::cout << "Program Instructions:" << std::endl;
    std::cout << "Arithmetic Instructions: " << numArith << std::endl;
    std::cout << "Store Instructions: " << numStore << std::endl;
    std::cout << "Load Instructions: " << numLoad << std::endl;
    std::cout << "Branch Instructions: " << numBranch << std::endl;
    std::cout << "Total Instructions: " << numTotal << std::endl;
}
