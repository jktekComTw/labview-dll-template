#ifndef MYDLL_H
#define MYDLL_H

// Export/Import macro
#ifdef MYDLL_EXPORTS
    #define MYDLL_API __declspec(dllexport)
#else
    #define MYDLL_API __declspec(dllimport)
#endif

// Use extern "C" to prevent name mangling (makes it easier to use from other languages)

extern "C" {
    // Simple math functions
    MYDLL_API int Add(int a, int b);
    MYDLL_API int Multiply(int a, int b);
    
    // String function
    MYDLL_API void SayHello(const char* name);
    
    // More complex function
    MYDLL_API double CalculateAverage(const double* numbers, int count);

    // ========= ADD THESE WRAPPER FUNCTIONS =========
    // Calculator class C wrappers (for LabVIEW)
    MYDLL_API void* Calculator_Create();
    MYDLL_API void Calculator_Destroy(void* handle);
    MYDLL_API double Calculator_Add(void* handle, double a, double b);
    MYDLL_API double Calculator_Subtract(void* handle, double a, double b);
    MYDLL_API void Calculator_SetMemory(void* handle, double value);
    MYDLL_API double Calculator_GetMemory(void* handle);
}

// C++ class example (without extern "C")
class MYDLL_API Calculator {
public:
    Calculator();
    ~Calculator();
    
    double add(double a, double b);
    double subtract(double a, double b);
    void setMemory(double value);
    double getMemory() const;
    
private:
    double memory;
};

#endif // MYDLL_H