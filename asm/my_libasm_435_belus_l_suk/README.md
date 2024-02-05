# Welcome to My Libasm
***

## Task

The problem is to implement a library in assembly language, which is a low-level programming language designed for a specific type of processor. The challenge lies in the fact that assembly language is low-level, meaning you have to write more code to perform the same operation than in a higher-level language. For this project, we are using NASM 64.

## Description

The project involves writing several commonly used functions in assembly language. These functions include strlen, strchr, memset, memcpy, strcmp, memmove, strncmp, strcasecmp, index, read, and write. Each of these functions will have a corresponding function in the library with a prefix of my_, for example my_strlen for the strlen function.

## Installation

To install the project, you will need to compile the assembly code using the NASM assembler and then link the object files using gcc. The provided Makefile automates this process.

Navigate to the project directory:
```bash
cd my_libasm
```

Build the project using the Makefile:
```bash
make
```



## Usage

To use the library, you will need to include the header file in your C code and then link the object file when compiling your code. Here is an example of how to use the my_strlen function:
```c
#include <my_libasm.h>

int main()
{
    char *str = "Hello, world";
    int length = _my_strlen(str);
    printf("Length: %d\n", length);
    return 0;
}

The Makefile provided in the repository contains several targets that help with the build and clean process:

    - make: This is the default target and builds the entire project.
    - clean: This target removes all the object files.
    - fclean: This target removes all the object files and the executable.
    - debug: This target builds the project with debugging information.
    - debugc: This target removes all the object files, the executable, and the debug file.
    - To use the Makefile, run the following command:

```

### The Core Team
* [Lorris BELUS](//github.com/Lbelus) - Developer


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt="Qwasar SV -- Software Engineering School's Logo" src="https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png" width="20px" /></span>
