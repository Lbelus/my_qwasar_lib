# Welcome to My Zsh
***

## Task

The task is to create a UNIX command interpreter in C that can read, parse, and execute commands entered by the user. The interpreter should display a prompt in the format "[what_you_want]>". The interpreter should be able to execute basic command lines using execve and handle the PATH and environment variables. Additionally, built-in commands like echo, cd, setenv, unsetenv, env, exit, pwd, and which should be implemented.

## Description
To solve this challenge, I created a UNIX command interpreter in C. The interpreter uses a loop that reads commands from standard input, parses the command into a program and arguments, and executes the command using execve. The interpreter displays a prompt in the format "[what_you_want]>" and waits for a command line to be entered.

The parser is a simple split on spaces, and only basic command lines are expected to be executed. The executables should be those found in the PATH environment variable. If the executable cannot be found, an error message is displayed, and the prompt is displayed again.

The built-in commands echo, cd, setenv, unsetenv, env, exit, pwd, and which are implemented using their respective system calls and functions.

To install the project, simply clone the repository and compile the my_zsh.c file using the command ```make```

To use the interpreter, run the my_zsh executable in the terminal. You will be presented with a prompt in the format "[what_you_want]>". Enter commands and press enter to execute them. The interpreter will display the output of the executed command and wait for another command line to be entered.

### Architecture overview / flowchart

```
                               ┌─────────┐
                               │  START  │
                               └─────────┘
                                    │
                                    │
                                    ▼
                            ┌────────────────┐
  ┌────────────────────────►│  User input ?  │◄────────────────────────────────────────────────────┐
  │                         └───────┬────────┘                                                     │
  │                                 │                                                              │
  │                                 ▼                                                              │
  │                        ┌──────────────────┐      ┌────────────────────────────┐                │
  │                        │ Parse user input ├──┬──►│  Command does not exists   ├─────┐          │
  │                        └────────┬─────────┘  │   └────────────────────────────┘     │          │
  │                                 │            │                                      │          │
  │                                 │            │   ┌────────────────────────────┐     │  ┌───────┴───────┐
  │                                 │            ├──►│     /bin/ does not exists  ├─────┼─►│     perror()  │
  │                                 │            │   └────────────────────────────┘     │  └───────────────┘
  │                                 │            │                                      │
  │                                 │            │   ┌────────────────────────────┐     │
  │                                 │            └──►│    command is invalid      ├─────┘
  │                                 │                └────────────────────────────┘
  │                                 │
  │           ┌─────────────────────┼─────────────────────────┬─────────────────┐
  │           │                     │                         │                 │
  │           │                     │                         │                 │
  │           ▼                     ▼                         ▼                 ▼
  │ ┌────────────────┐    ┌───────────────────┐    ┌───────────────────┐    ┌──────┐
  │ │  exec builtin  │    │     exec /bin/    │    │   Exec local bin  │    │ Quit │
  │ └────────┬───────┘    └─────────┬─────────┘    └──────────┬────────┘    └──┬───┘
  │          ▼                      ▼                         ▼                │
  └────────────────────────────────────────────────────────────                ▼
                                                                            ┌──────┐
                                                                            │ END  │
                                                                            └──────┘
```


## Installation
Clone the repository:

```
git clone https://github.com/QwasarSV/my_zsh_299_belus_l_xaq.git
```

Compile the my_zsh.c file:
```
make
```
To clean the binaries:
```
make clean 
or
make fclean
```

## Usage
To use the UNIX command interpreter, run the my_zsh executable in the terminal:
```
./my_zsh
```
You will be presented with a prompt in the format "[what_you_want]>". Enter commands and press enter to execute them. The interpreter will display the output of the executed command and wait for another command line to be entered : 
- The built-in commands echo, cd, setenv, unsetenv, env, exit, pwd, can be used;
- You can use any command from /bin/;
- You can run any program;

Enter commands at the prompt. For example:
```
GTN - my_zsh $>echo "hello"
hello
GTN - my_zsh $>ls -l
...
GTN - my_zsh $>pwd
/Users/gtn/
GTN - my_zsh $>cd /tmp
GTN - my_zsh $>pwd
/tmp/
GTN - my_zsh $>./my_segfault_program
Segfault
GTN - my_zsh $>cd -
/Users/gtn/
GTN - my_zsh $>exit
```
### The Core Team
* [Lorris BELUS](//github.com/Lbelus) - Developer


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
