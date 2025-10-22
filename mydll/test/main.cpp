#include "mydll.h"
#include <iostream>

int main() {
    std::cout << "=== Testing DLL Functions ===" << std::endl << std::endl;
    
    // Test C functions
    std::cout << "Testing C functions:" << std::endl;
    std::cout << "Add(5, 3) = " << Add(5, 3) << std::endl;
    std::cout << "Multiply(4, 7) = " << Multiply(4, 7) << std::endl;
    
    SayHello("World");
    
    double numbers[] = {10.5, 20.3, 30.7, 40.1};
    double avg = CalculateAverage(numbers, 4);
    std::cout << "Average = " << avg << std::endl;
    
    std::cout << std::endl;
    
    // Test C++ class
    std::cout << "Testing C++ class:" << std::endl;
    Calculator calc;
    std::cout << "calc.add(15.5, 4.5) = " << calc.add(15.5, 4.5) << std::endl;
    std::cout << "calc.subtract(20, 7) = " << calc.subtract(20, 7) << std::endl;
    
    calc.setMemory(42.0);
    std::cout << "Memory value: " << calc.getMemory() << std::endl;
    
    std::cout << std::endl << "=== All tests completed ===" << std::endl;
    
    return 0;
}