# Welcome to My Bc
***

## Task

To reproduce a basic calculator with the following specs : 

- must only contain the operators +, -, *, /, and modulo (percent)
- must only have integer values
- can contain parentheses, but each group must be properly closed
- can contain spaces

Divisions are euclidian keeping only the quotient, while the remainder can be obtained with a modulo operation.


## Description
Parsing the result using a shunting yard algorithm and change infix notation into Reverse Polish Notation
then using simple and easy algorithm to perform the operation following the RPN notation.

SHUNTING YARD STEPS :

STEP 1 : If the incoming symbols is an operand, print it..

STEP 2 : If the incoming symbol is a left parenthesis, push it on the stack.

STEP 3 : If the incoming symbol is a right parenthesis: discard the right parenthesis, pop and print the stack symbols until you see a left parenthesis. Pop the left parenthesis and discard it.

STEP 4 : If the incoming symbol is an operator and the stack is empty or contains a left parenthesis on top, push the incoming operator onto the stack.

STEP 5 : If the incoming symbol is an operator and has either higher precedence than the operator on the top of the stack, or has the same precedence as the operator on the top of the stack and is right associative -- push it on the stack.

STEP 6 : If the incoming symbol is an operator and has either lower precedence than the operator on the top of the stack, or has the same precedence as the operator on the top of the stack and is left associative -- continue to pop the stack until this is not true. Then, push the incoming operator.

STEP 7 : At the end of the expression, pop and print all operators on the stack. (No parentheses should remain.)

## Installation

type ``make`` or ``make my_bc`` inside the terminal to compile 
type ``make fclean`` inside the terminal clean the binaries; 

## Usage
TODO - How does it work?
Format is :
```
 ./my_bc "(a+b)*c"
```
Test the ruby gem.

Type in terminal :
```
cd rb/my_gem_box/my_basic_calc/
rake
```


### The Core Team
* [Lorris BELUS](//github.com/Lbelus) - Developer


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt="Qwasar SV -- Software Engineering School's Logo" src="https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png" width="20px" /></span>
