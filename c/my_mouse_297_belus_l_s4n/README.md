# Welcome to My Mouse
***

## Task
TODO - What is the problem? And where is the challenge?

## Description
 
 A grid is a form of implicit graph. meaning we can detect a node's neighbours based on its location.


To solve it we must convert the grid to another format : an adjacency list/matrix.
```
     Empty grid:

     ┌─────┬─────┐
     │     │     │  STEP 1: Labels ths cells in grid with numbers :
     │  0  │  1  │      n = number rows * numbers column
     ├─────┼─────┤      0 to n
     │     │     │
     │  2  │  3  │
     ├─────┼─────┤
     │     │     │
     │  4  │  5  │
     └─────┴─────┘

     Adjacency list: 

        0->[1, 2]
        1->[0, 3]
        2->[0, 3, 4]
        3->[1, 2, 5]
        4->[2, 5]
        5->[4, 3]



     Adjacency matrix:

            0     1     2     3     4     5
        ┌─────┬─────┬─────┬─────┬─────┬─────┐
        │     │     │     │     │     │     │
     0  │     │  1  │  1  │     │     │     │
        ├─────┼─────┼─────┼─────┼─────┼─────┤
        │     │     │     │     │     │     │
     1  │  1  │     │     │ 1   │     │     │
        ├─────┼─────┼─────┼─────┼─────┼─────┤
        │     │     │     │     │     │     │
     2  │  1  │     │     │ 1   │ 1   │     │
        ├─────┼─────┼─────┼─────┼─────┼─────┤
        │     │     │     │     │     │     │
     3  │     │ 1   │ 1   │     │     │  1  │
        ├─────┼─────┼─────┼─────┼─────┼─────┤
        │     │     │     │     │     │     │
     4  │     │     │ 1   │     │     │  1  │
        ├─────┼─────┼─────┼─────┼─────┼─────┤
        │     │     │     │     │     │     │
     5  │     │     │     │  1  │ 1   │     │
        └─────┴─────┴─────┴─────┴─────┴─────┘

     
```
## Installation
TODO - How to install your project? npm install? make? make re?

## Usage
TODO - How does it work?
```
./my_project argument1 argument2
```

### The Core Team
* [Lorris BELUS](//github.com/Lbelus) - Developer


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
