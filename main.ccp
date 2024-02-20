#include "computer.h"
#include "program.h"
#include <iostream>

int main() {
    // Create a Computer instance with example specifications
    Computer myComputer(3.5, 1.2, 1.3, 1.4, 1.5);

    // Create a Program instance with example instruction counts
    Program myProgram(100, 200, 300, 400);

    // Print the computer's stats
    std::cout << "Computer Stats:" << std::endl;
    myComputer.printStats();

    // Print the program's stats
    std::cout << "\nProgram Stats:" << std::endl;
    myProgram.printStats();

    // Example of additional functionality could be added here
    // such as calculating the execution time of the program on the computer

    return 0;
}
