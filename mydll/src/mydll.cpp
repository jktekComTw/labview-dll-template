#include "mydll.h"
#include <stdio.h>

// ============ Simple C functions ============
int Add(int a, int b) {
    return a + b;
}

int Multiply(int a, int b) {
    return a * b;
}

void SayHello(const char* name) {
    printf("Hello, %s!\n", name);
}

double CalculateAverage(const double* numbers, int count) {
    if (count <= 0) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return sum / count;
}

// ============ Calculator Class Implementation ============
Calculator::Calculator() : memory(0.0) {
    // Constructor implementation
}

Calculator::~Calculator() {
    // Destructor implementation
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

// ============ C Wrapper Functions for Calculator ============
void* Calculator_Create() {
    return new Calculator();
}

void Calculator_Destroy(void* handle) {
    if (handle) {
        delete static_cast<Calculator*>(handle);
    }
}

double Calculator_Add(void* handle, double a, double b) {
    if (!handle) return 0.0;
    return static_cast<Calculator*>(handle)->add(a, b);
}

double Calculator_Subtract(void* handle, double a, double b) {
    if (!handle) return 0.0;
    return static_cast<Calculator*>(handle)->subtract(a, b);
}

void Calculator_SetMemory(void* handle, double value) {
    if (handle) {
        static_cast<Calculator*>(handle)->setMemory(value);
    }
}

double Calculator_GetMemory(void* handle) {
    if (!handle) return 0.0;
    return static_cast<Calculator*>(handle)->getMemory();
}