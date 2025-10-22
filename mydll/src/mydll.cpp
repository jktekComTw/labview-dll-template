#include "mydll.h"
#include <iostream>
#include <string>

// C functions implementation
extern "C" {
    MYDLL_API int Add(int a, int b) {
        return a + b;
    }
    
    MYDLL_API int Multiply(int a, int b) {
        return a * b;
    }
    
    MYDLL_API void SayHello(const char* name) {
        std::cout << "Hello, " << name << "!" << std::endl;
    }
    
    MYDLL_API double CalculateAverage(const double* numbers, int count) {
        if (count <= 0 || numbers == nullptr) {
            return 0.0;
        }
        
        double sum = 0.0;
        for (int i = 0; i < count; i++) {
            sum += numbers[i];
        }
        return sum / count;
    }
}

// C++ class implementation
Calculator::Calculator() : memory(0.0) {
    std::cout << "Calculator created" << std::endl;
}

Calculator::~Calculator() {
    std::cout << "Calculator destroyed" << std::endl;
}

double Calculator::add(double a, double b) {
    return a + b;
}

double Calculator::subtract(double a, double b) {
    return a - b;
}

void Calculator::setMemory(double value) {
    memory = value;
}

double Calculator::getMemory() const {
    return memory;
}