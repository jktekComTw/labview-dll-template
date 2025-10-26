# MyDLL - LabVIEW DLL Template

A template project for creating Windows DLLs that can be used with LabVIEW and other applications. This project demonstrates how to create both C and C++ functions in a DLL using MinGW64.

## Project Location

**Current Working Directory:** `z:\lab\workspace_window\labview-dll-template\mydll`

## Project Structure

```
mydll/
├── build/                  # Compiled binaries (DLL, test executables)
├── include/
│   └── mydll.h            # Header file with function declarations
├── src/
│   └── mydll.cpp          # Implementation of DLL functions
├── test/
│   └── main.cpp           # Test program to verify DLL functionality
└── .vscode/
    ├── tasks.json         # Build tasks configuration
    └── settings.json      # VS Code settings
```

## VS Code Configuration

The `.vscode` folder contains configuration files for optimal development experience:

### settings.json

Configures VS Code editor and terminal settings:

```json
{
    "terminal.integrated.profiles.windows": {
        "MSYS2 Bash": {
            "path": "C:\\msys64\\usr\\bin\\bash.exe",
            "args": ["--login", "-i"],
            "env": {
                "MSYSTEM": "MINGW64",
                "CHERE_INVOKING": "1"
            }
        }
    },
    "terminal.integrated.defaultProfile.windows": "MSYS2 Bash",
    "terminal.integrated.automationProfile.windows": {
        "path": "C:\\msys64\\usr\\bin\\bash.exe",
        "args": ["--login", "-i"]
    },
    "files.associations": {
        "*.h": "cpp",
        "*.cpp": "cpp"
    }
}
```

**Key Settings:**
- **Terminal Profile**: Sets MSYS2 Bash as default terminal with MinGW64 environment
- **File Associations**: Treats `.h` files as C++ for better IntelliSense
- **Environment Variables**: Configures MSYSTEM for proper MinGW64 toolchain access

### c_cpp_properties.json

Configures C/C++ IntelliSense and code completion:

```json
{
    "configurations": [
        {
            "name": "MinGW64",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [],
            "compilerPath": "C:/msys64/mingw64/bin/g++.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "windows-gcc-x64"
        }
    ],
    "version": 4
}
```

**Configuration Details:**
- **Compiler Path**: Points to MinGW64 G++ compiler
- **Include Paths**: Scans entire workspace for header files
- **Standards**: Uses C17 and C++17 standards
- **IntelliSense Mode**: Windows GCC x64 for proper syntax highlighting and completion

### tasks.json

Defines build and test tasks accessible via Ctrl+Shift+P → "Tasks: Run Task":

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Build DLL",
            "type": "shell",
            "command": "mkdir -p build && /mingw64/bin/g++ -shared -o build/mydll.dll src/mydll.cpp -Iinclude -DMYDLL_EXPORTS -Wl,--out-implib,build/libmydll.a",
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": ["$gcc"]
        },
        {
            "label": "Build Test",
            "command": "/mingw64/bin/g++ test/main.cpp -o build/test.exe -Iinclude -Lbuild -lmydll",
            "dependsOn": ["Build DLL"]
        },
        {
            "label": "Run Test",
            "command": "./build/test.exe",
            "dependsOn": ["Build Test"]
        }
    ]
}
```

**Available Tasks:**
1. **Build DLL** (Ctrl+Shift+B): Compiles the shared library
2. **Build Test**: Compiles test executable (depends on Build DLL)
3. **Run Test**: Executes test program (depends on Build Test)

**Task Features:**
- **Problem Matchers**: Parses GCC output for errors/warnings
- **Dependencies**: Automatic task chaining (Run Test → Build Test → Build DLL)
- **Shell Environment**: Uses MSYS2 Bash with MinGW64 environment
- **Working Directory**: Uses VS Code workspace folder

### Recommended VS Code Extensions

For optimal C/C++ development experience:

1. **C/C++** (`ms-vscode.cpptools`)
   - IntelliSense, debugging, code browsing

2. **C/C++ Extension Pack** (`ms-vscode.cpptools-extension-pack`)
   - Includes C/C++, CMake Tools, and other useful extensions

3. **GitLens** (`eamodio.gitlens`)
   - Git integration and history visualization

4. **Error Lens** (`usernamehw.errorlens`)
   - Inline error and warning display

### Setting Up VS Code for This Project

1. **Open Project**:
   ```
   File → Open Folder → Select mydll folder
   ```

2. **Install Recommended Extensions**:
   - VS Code should prompt to install recommended extensions
   - Or install manually from Extensions panel (Ctrl+Shift+X)

3. **Verify Configuration**:
   - Open terminal (Ctrl+`) - should default to MSYS2 Bash
   - Check C++ IntelliSense by opening `src/mydll.cpp`
   - Test build with Ctrl+Shift+B

4. **Debugging Setup** (Optional):
   Add `.vscode/launch.json` for debugging:
   ```json
   {
       "version": "0.2.0",
       "configurations": [
           {
               "name": "Debug Test",
               "type": "cppdbg",
               "request": "launch",
               "program": "${workspaceFolder}/build/test.exe",
               "cwd": "${workspaceFolder}",
               "environment": [
                   {"name": "PATH", "value": "${workspaceFolder}/build;${env:PATH}"}
               ],
               "externalConsole": false,
               "MIMode": "gdb",
               "miDebuggerPath": "C:/msys64/mingw64/bin/gdb.exe",
               "preLaunchTask": "Build Test"
           }
       ]
   }
   ```

## Features

This DLL template includes:

### C Functions (extern "C")
- `Add(int a, int b)` - Simple addition
- `Multiply(int a, int b)` - Simple multiplication
- `SayHello(const char* name)` - String handling example
- `CalculateAverage(const double* numbers, int count)` - Array processing

### C++ Class
- `Calculator` class with:
  - `add(double a, double b)` - Addition
  - `subtract(double a, double b)` - Subtraction
  - `setMemory(double value)` - Memory storage
  - `getMemory()` - Memory retrieval

## Prerequisites

### Installing MinGW64

MinGW64 (Minimalist GNU for Windows 64-bit) provides the GCC compiler and GNU toolchain for Windows.

#### Method 1: Using MSYS2 (Recommended)

1. **Download MSYS2**
   - Visit: https://www.msys2.org/
   - Download the installer (e.g., `msys2-x86_64-latest.exe`)
   - Install to `C:\msys64` (default location)

2. **Update MSYS2**
   - Open MSYS2 MSYS terminal (from Start menu)
   - Run the following commands:
     ```bash
     pacman -Syu
     ```
   - Close the terminal when prompted
   - Reopen MSYS2 MSYS terminal and run again:
     ```bash
     pacman -Syu
     ```

3. **Install MinGW64 GNU Toolchain**
   
   Open **MSYS2 MinGW64** terminal (not MSYS terminal) and run:
   
   ```bash
   # Install the complete toolchain
   pacman -S mingw-w64-x86_64-toolchain
   ```
   
   Or install individual packages:
   
   ```bash
   # Core compiler and tools
   pacman -S mingw-w64-x86_64-gcc
   pacman -S mingw-w64-x86_64-g++
   pacman -S mingw-w64-x86_64-gdb
   pacman -S mingw-w64-x86_64-make
   
   # Additional useful tools
   pacman -S mingw-w64-x86_64-cmake
   pacman -S mingw-w64-x86_64-pkg-config
   ```

4. **Verify Installation**
   
   In MSYS2 MinGW64 terminal:
   ```bash
   # Check GCC version
   gcc --version
   g++ --version
   
   # Check tool locations
   which gcc
   which g++
   ```
   
   Tools will be installed in: `C:\msys64\mingw64\bin\`

5. **Add to Windows PATH (Optional)**
   
   To use MinGW64 tools from Windows Command Prompt or PowerShell:
   - Open System Properties → Advanced → Environment Variables
   - Add to PATH: `C:\msys64\mingw64\bin`
   - Verify by opening new cmd/PowerShell and running: `gcc --version`

#### Method 2: Standalone MinGW-w64

1. **Download from WinLibs**
   - Visit: https://winlibs.com/
   - Download latest GCC release (e.g., GCC 13.x.x with MSVCRT runtime)
   - Extract to `C:\mingw64` or your preferred location

2. **Add to PATH**
   - Add `C:\mingw64\bin` to Windows PATH environment variable

3. **Verify**
   ```cmd
   gcc --version
   g++ --version
   ```

### GNU Toolchain Components in mingw64/bin

The GNU toolchain includes these essential tools:

| Tool | Description |
|------|-------------|
| `gcc.exe` | GNU C Compiler |
| `g++.exe` | GNU C++ Compiler |
| `gdb.exe` | GNU Debugger |
| `ar.exe` | Archive utility (creates static libraries) |
| `ld.exe` | GNU Linker |
| `as.exe` | GNU Assembler |
| `nm.exe` | Lists symbols from object files |
| `objdump.exe` | Displays object file information |
| `strip.exe` | Removes symbols from binaries |
| `ranlib.exe` | Generates index for archives |
| `dlltool.exe` | Creates files needed to build/use DLLs |
| `windres.exe` | Windows resource compiler |
| `make.exe` | Build automation tool |

## Building the Project

### Using VS Code Tasks

This project includes pre-configured VS Code tasks:

1. **Build DLL** (Ctrl+Shift+B)
   - Compiles the DLL to `build/mydll.dll`
   - Creates import library `build/libmydll.a`

2. **Build Test**
   - Compiles the test program
   - Links against the DLL

3. **Run Test**
   - Builds and executes the test program

### Manual Build Commands

From MSYS2 MinGW64 terminal in project directory:

```bash
# Create build directory
mkdir -p build

# Build the DLL
/mingw64/bin/g++ -shared -o build/mydll.dll src/mydll.cpp -Iinclude -DMYDLL_EXPORTS -Wl,--out-implib,build/libmydll.a

# Build the test program
/mingw64/bin/g++ test/main.cpp -o build/test.exe -Iinclude -Lbuild -lmydll

# Run the test
./build/test.exe
```

### Build Options Explained

- `-shared` - Create a shared library (DLL)
- `-o build/mydll.dll` - Output file name
- `-Iinclude` - Include directory for headers
- `-DMYDLL_EXPORTS` - Define macro for DLL export
- `-Wl,--out-implib,build/libmydll.a` - Create import library
- `-Lbuild` - Library search path
- `-lmydll` - Link against mydll library

## Using the DLL

### From C/C++ Applications

1. Include the header: `#include "mydll.h"`
2. Link against `libmydll.a` during compilation
3. Ensure `mydll.dll` is in the same directory as your executable or in PATH

### From LabVIEW

1. Use **Call Library Function Node**
2. Select `mydll.dll`
3. Configure function parameters according to the header file
4. Use C function declarations (those with `extern "C"`)

**Important for LabVIEW:**
- Use only C functions (with `extern "C"`), not C++ classes
- Match data types carefully (int → I32, double → DBL, etc.)
- For string parameters, use "C String Pointer"
- For arrays, pass pointer + count parameters

## Troubleshooting

### DLL Not Found Error
- Ensure `mydll.dll` is in the same directory as your executable
- Or add the DLL directory to Windows PATH
- Or copy DLL to `C:\Windows\System32` (not recommended)

### Missing Dependencies
Check DLL dependencies:
```bash
objdump -p build/mydll.dll | grep "DLL Name"
```

### Build Errors
- Verify MinGW64 is properly installed: `g++ --version`
- Check that MSYSTEM environment variable is set to MINGW64
- Ensure paths don't contain spaces or special characters

## Environment Configuration

This project uses MSYS2 MinGW64 with:
- **MSYSTEM**: MINGW64
- **Shell**: `C:\msys64\usr\bin\bash.exe`
- **Compiler**: `/mingw64/bin/g++`

## License

This is a template project. Modify and use as needed for your projects.

## Contributing

This is a template. Feel free to extend it with additional functionality:
- Add more mathematical functions
- Implement signal processing algorithms
- Add file I/O operations
- Create data structures for LabVIEW integration
