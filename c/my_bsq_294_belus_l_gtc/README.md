# Welcome to My Bsq
***

## Task

The objectif is to find the largest possible square inside a map that contains obstacles. 

The challenge was to understand and use Dynamic programming. 

## Description

```
1.get map with size transform it into a matrix : map matrix
2.create a dynamic programming matrix : dp matrix

3.if value at coordonate(x,y) on map matrix != obstacle -> check on dp matrix :
return value of
if index/jndex and > 0 : top[index-1][jndex] else return 0 
if index/jndex and > 0 : left[index][jndex -1] else return 0
if index/jndex and > 0 : top_left[index -1][jndex-1] else return 0

4.update value dp matrix on coord -> dp[index][jndex] = 1 + min(top,left,topleft)
5.if dp[index][jndex] > max size
update max size and save right coord
```
```
exemple:

grid to check :
- x are obstacles
 ┌──┬──┬──┬──┬──┐
 | .│ .│ x│ x│ x│
 ├──┼──┼──┼──┼──┤
 │ x│ .│ .│ .│ .│
 ├──┼──┼──┼──┼──┤
 │ x│ .│ x│ .│ .│
 ├──┼──┼──┼──┼──┤
 │ x│ .│ x│ x│ x│
 └──┴──┴──┴──┴──┘

check process on the two first iteration
- L = left, T = top, TL= top_left;
- R = updated value;
 ┌──┬──┬──┬──┬──┐
 │ L│ L│ L│ L│ L│
 ├──┼──┼──┼──┼──┤
 │  │  │  │  │  │
 ├──┼──┼──┼──┼──┤
 │  │  │  │  │  │
 ├──┼──┼──┼──┼──┤
 │  │  │  │  │  │
 └──┴──┴──┴──┴──┘
    │  │
    │  │
    │  │
    ▼  ▼
 ┌──┬──┬──┬──┬──┐
 │TL│ T│  │  │  │
 ├──┼──┼──┼──┼──┤
 │ L│ R│  │  │  │
 ├──┼──┼──┼──┼──┤
 │  │  │  │  │  │
 ├──┼──┼──┼──┼──┤
 │  │  │  │  │  │
 └──┴──┴──┴──┴──┘


DP matrix on completion :

 ┌──┬──┬──┬──┬──┐
 │ 1│ 1│ 0│ 0│ 0│
 ├──┼──┼──┼──┼──┤
 │ 0│ 1│ 1│ 1│ 1│
 ├──┼──┼──┼──┼──┤
 │ 0│ 1│ 0│ 1│ 2│
 ├──┼──┼──┼──┼──┤
 │ 0│ 1│ 0│ 0│ 0│
 └──┴──┴──┴──┴──┘
```

## Installation

 Type in ``make`` inside the terminal to compile.

## Usage

type in the terminal
```
./my_bsq [map_file]
```

### The Core Team
* [Lorris BELUS](//github.com/Lbelus) - Developer


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
