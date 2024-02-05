# Welcome to My Tar
***

## Task

Tar is a utility is an archive utility that store and regroup multiple files on a single archive. A tar ball can be updated through or appended with new or modified file.

Objectives :
- Reproduce tar with some of its functionnalities;
- To understand and reproduce ``flags`` (``c``,``r``,``t``,``u``,``x``);
- To read and write every files in a modifiable block size (512 bytes);

## Description

### Project organisation :
 The project Scope was larger than previous projects. In consequence, adopting a predictive approach seemed unadapted. 
An iterative approach allowed to understand its scope as the project was being coded. It allowed to deliver a usable product through each milestone.
Each milestones was represented by a flag. 

While the project is finished, its late stage would require a thorough refactoring and/or total recoding. 
The approach, however, produced a complete understanding of the project scope.  

### Next milestones : 

- Improve file and related node selection directly in the LS suite:
    * Modify ls structure to make the decision before a node creation (memory performance improvement)
    * Modify header to allow user input selection (reusable organizational assets);
    * Search for file and folder recursively (functionnalities improvement);

- Pursue the refactoring.
- Regroup functions to increase code weight and accessibility (overall performance improvement).
- Finish implementing recursive directory search and extraction.(functionnalities improvement)


Project structure : 

```
                                                                  ______read archive (-tf)
                                                                 |
                                                                 |______unarchive (-xf)
     user input-----analyse user input----Seek file information--|  
                                                                 |____________________________________archive(-cf)
                                                                 |                                    ^
                                                                 |                                    |
                                                                 |_______________________set FD_______|(-rf)
                                                                 |                                   
                                                                 |                                   
                                                                 |______map archive______set FD_______archive(-uf)
```
## Installation

To compile my_tar :
> insert in terminal ``make my_tar``

To remove my_tar :
> insert in terminal ``make fclean``

## Usage

- The options are : 
    * ``-cf`` to archive
    * ``-rf`` to append
    * ``-uf`` to append new files or new version of already present files
    * ``-tf`` to list all files present within archive
    * ``-xf`` to unarchive files

Insert in terminal:
```
./my_tar [OPTION] [file.tar] [...file] 
```

### The Core Team
* [Lorris BELUS](//github.com/Lbelus) - Developer


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt="Qwasar SV -- Software Engineering School's Logo" src="https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png" width="20px" /></span>
