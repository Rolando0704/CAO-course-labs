#include "computer.h"
#include "program.h"
#include <iostream>

int main() {
    // Create a Computer instance with example specifications
    Computer myComputer1(1, 2, 2, 3, 4);
    // Create second computer instance
    Computer myComputer2(1.2, 2, 3, 4, 3);
    // Create second computer instance
    Computer myComputer3(2, 2, 2, 4, 6);


    // Create Program A instance with example instruction counts
    Program myProgramA(2000, 100, 100, 50);
    Program myProgramB(2000, 0.10, 0.40, 0.25);
    Program myProgramC(500, 100, 2000, 200);


    // Print the firtst computer's stats
    std::cout << "Computer 1 Stats:" << std::endl;
    myComputer1.printStats();
    std::cout << std::endl;

     // Print the second computer's stats
    std::cout << "Computer 2 Stats:" << std::endl;
    myComputer2.printStats();
    std::cout << std::endl;

    // Print the program's stats
    std::cout << "\nProgram A Stats:" << std::endl;
    myProgramA.printStats();
    std::cout << std::endl;

    std::cout << "\nProgram B Stats:" << std::endl;
    myProgramB.printStats();
    std::cout << std::endl;

    std::cout << "\nProgram C Stats:" << std::endl;
    myProgramC.printStats();
    std::cout << std::endl;

    std::cout << "\n Cpu 1, program A execution time:" << myComputer1.calculateExecutionTime(myProgramA) << " s" << std::endl;
    std::cout << " Cpu 1, program B execution time:" << myComputer1.calculateExecutionTime(myProgramB) << " s" << std::endl;
    std::cout << " Cpu 1, program C execution time:" << myComputer1.calculateExecutionTime(myProgramC) << " s" << std::endl;

    std::cout << "\n Cpu 2, program A execution time:" << myComputer2.calculateExecutionTime(myProgramA) << " s" << std::endl;
    std::cout << " Cpu 2, program B execution time:" << myComputer2.calculateExecutionTime(myProgramB) << " s" << std::endl;
    std::cout << " Cpu 2, program C execution time:" << myComputer2.calculateExecutionTime(myProgramC) << " s" << std::endl;

    std::cout << "\n Cpu 3, program A execution time:" << myComputer3.calculateExecutionTime(myProgramA) << " s" << std::endl;
    std::cout << " Cpu 3, program B execution time:" << myComputer3.calculateExecutionTime(myProgramB) << " s" << std::endl;
    std::cout << " Cpu 3, program C execution time:" << myComputer3.calculateExecutionTime(myProgramC) << " s" << std::endl;


    // Global MIPS per cpu:

    std::cout << "\n Cpu 1, global MIPS:" << myComputer1.calculateglobalMIPS() << std::endl;
    std::cout << " Cpu 2, global MIPS:" << myComputer2.calculateglobalMIPS() << std::endl;
    std::cout << " Cpu 3, global MIPS:" << myComputer3.calculateglobalMIPS() << std::endl;

    std::cout << "\n Cpu 1, program A MIPS:" << myComputer1.calculateMIPS(myProgramA) << std::endl;
    std::cout << " Cpu 1, program B MIPS:" << myComputer1.calculateMIPS(myProgramB) << std::endl;
    std::cout << " Cpu 1, program C MIPS:" << myComputer1.calculateMIPS(myProgramC) << std::endl;

    std::cout << "\n Cpu 2, program A MIPS:" << myComputer2.calculateMIPS(myProgramA) << std::endl;
    std::cout << " Cpu 2, program B MIPS:" << myComputer2.calculateMIPS(myProgramB) << std::endl;
    std::cout << " Cpu 2, program C MIPS:" << myComputer2.calculateMIPS(myProgramC) << std::endl;

    std::cout << "\n Cpu 3, program A MIPS:" << myComputer3.calculateMIPS(myProgramA) << std::endl;
    std::cout << " Cpu 3, program B MIPS:" << myComputer3.calculateMIPS(myProgramB) << std::endl;
    std::cout << " Cpu 3, program C MIPS:" << myComputer3.calculateMIPS(myProgramC) << std::endl;
    // Example of additional functionality could be added here
    // such as calculating the execution time of the program on the computer

    return 0;
}
