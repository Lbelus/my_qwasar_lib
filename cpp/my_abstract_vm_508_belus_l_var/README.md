# Welcome to My Abstract Vm
***

An abstract machine implementation that uses a stack to compute simple arithmetic expressions.

Uses C++17 or later version.


## Task

My_Abstract_VM is designed to simulate a simple abstract machine that can evaluate and execute a series of instructions from either the standard input or from a file. The challenge lies in creating a robust system that can interpret a series of commands, handle different types of operands, and manage stack operations with appropriate error handling.

It aims at teaching you polymorphism through the usage of dynamic casting; although the current solution relies heavily on static casting, template implementation, std::function and function pointers;

## Description

The solution involves creating a lexer to parse and tokenize the input received, a BNF was created from the given instructions to handle the language structure

```
    BNF notation : 
        <program> ::= {<line>} [";;"]
        <line> ::= <instruction> "#" | <comment> "#" | "#"
        <instruction> ::= <keyword> [<value>]
        <keyword> ::= "push" | "pop" | "dump" | "assert" | "add" | "sub" | "div" | "mod" | "print" | "exit"
        <value> ::= <value_type> "(" <number> ")"
        <value_type> ::= "int8" | "int16" | "int32" | "float" | "double"
        <number> ::= {<digit>} ["." {<digit>}]
        <digit> ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
        <comment> ::= ";" {<any_character_except_newline_or_semicolon>} [";"]
```
Through a series of classes, the program tokenize the receive data into meaningfull and curated tokens; 

 - MAIN: Centralize every headers;
 - LANG_PARAM: #define all the relevants values describing or helping the language;
 - LEXER: The Lexer class is responsible for parsing and tokenizing instructions from either standard input or a file. It receives input through the parseLine method and breaks it down into individual tokens using the tokenize method. After tokenizing, the distributeTokens method categorizes tokens into appropriate groups such as keywords, types, and digits. Tokens are further processed and stored as instructions that can be passed on for execution. The class also provides diagnostic capabilities to inspect categorized tokens and clear internal states;
 - PARSER: Perfom a sanity checks, verify that sentences are formulated in a correct manner and check for relevant token; 
 - EXECUTOR: perfom the execution of the instructions, relies on function pointers and if and else cascade;
 - ERROR MANAGEMENT: Errors are managed though the creation of our own exception type by subclassing the standard std::exception class and overriding the what() method. While in VM Mode, the VM must keep running even when the program running on it encounter an issue;
 - STACK: 
    - The MyStack class is a custom stack implementation that utilizes the C++ Standard Library's std::variant to handle multiple types of data (int8_t, int16_t, int32_t, float, double);
    - It provides methods to push and pop values to and from the stack, with additional arithmetic operations like addition, subtraction, multiplication, division, and modulo. The MyStack class is a type-safe stack implementation;
    - It relies on templated functions, the class provides a mechanism to dynamically convert strings to their corresponding std::variant types;
    - The stack offers methods for standard operations like push and pop, but with added type-specific functionality through std::visit and lambdas;
    - A dispatch map pattern has been created to determine the correct type conversion function to invoke based on the provided type string.

Next steps on the roadmap ; 

Dynamic cast polymorphism - Low level implementation - Performance benchmark between the 3 solutions;  

## Installation
Insert inside the terminal :

1.
```bash
make
```
2.
```bash
make fclean
```

or

1.
```bash
make debug
```
2.
```bash
make debugc
```

## Usage
TODO - How does it work?
```
./my_abstract_vm <optional_file.avm>
```
or 
```
./debug <optional_file.avm>
```
### The Core Team
* [Lorris BELUS](//github.com/Lbelus) - Developer


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
