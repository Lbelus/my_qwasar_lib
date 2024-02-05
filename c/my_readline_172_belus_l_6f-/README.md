# Welcome to My Readline
***

## Task

objective is to recode readline function following specifics specs. 

- one global variable for the size
- one global variable for the buffer;

it has to read a file line by line. 

## Description

12/14/2022:
Having two set of functions (one to fill the buffer, one to set the position) does not work.
You have only one fd to work with and you cannot set a tmp_fd, so positioning the fd to the desired value is not possible. 

Problem is not keeping track of the FD position but keeping track of what is being sent as a result 
and then read the fd and refresh the buffer if the cursor is going further than the fd position. 

it leads to three case scenario :
    if buff contains more than a line length == What to returns, full line length (unlikely) or line sliced to buff_size
        ==> dumb question : can you have an "infinite" line ? impossible you need to stream the data;  
    if buff contains less than a line length;
        ==> once the line has been read do you "rewrite"/concatenante the buff from the cursor to the next chunck size.
    if buff contains a line length;


fn read_to_pos() rendered useless; 

Q1 : Can I have 2 buffer ? NO
Q2 : Can I constantly refresh the buffer to replace each byte that has been previously read  ? 
    - On a 512 bytes buffer, a '/n' is on the 10th byte;
    - 1st line with 10 bytes is returned to user; 
    - I will read 10 new bytes to replace the one in the buffer that has been "consumed";
    - start again until EOF;

16/12/2022:

various test has been performed, circular buffer seems to be the solution.
need to make a working prototype with a size read of 1; and work from there to have a it a read size of n;

19/12/2022:

good progress but three cases are currently problematic : 
    -tail cannot be greater than head
    -getting the initale size and the logic behing it
    -new line are skipped on some occasions


20/12/2022:
Several tries and recoding, circular buffer generate logic issue due to the fact that you cannot use global variable to save the positions of read and write;
Found an almost working solution without having to save position but buffer will sporadically store garbage values;

21/12/2022:
Meeting with CTO and students;
Complimentary specs : buffer has not a fixed size, meaning you can resize it following the programs need; 

22/12/2022:
Readline works.


Program organisation :

```

workflow here : it's been erased for the third time




```


## Installation

to compile insert `` gcc -o my_readline my_readline.c"``

## Usage

to call for the program and a file name 

```
./my_readline [file01]
```

### The Core Team
* [Lorris BELUS](//github.com/Lbelus) - Developer


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt="Qwasar SV -- Software Engineering School's Logo" src="https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png" width="20px" /></span>
