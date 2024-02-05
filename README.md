# my_qwasar_lib
Repository holding my qwasar master projects 

Project in order of creation:
|language  | Project name|
| -------- | ----------- |
| cpp |  my_ftp   [view](https://github.com/Lbelus/my_qwasar_lib/tree/main/cpp/my_ftp_509_belus_l_cwo)|
| cpp |  my_abstract_vm    [view](https://github.com/Lbelus/my_qwasar_lib/tree/main/cpp/my_abstract_vm_508_belus_l_var)|
| c |  my_malloc    [view](https://github.com/Lbelus/my_qwasar_lib/tree/main/c/my_malloc_436_belus_l_m1a)|
| asm |  my_libasm  [view](https://github.com/Lbelus/my_qwasar_lib/tree/main/asm/my_libasm_435_belus_l_suk)|
| c |  my_curl    [view](https://github.com/Lbelus/my_qwasar_lib/tree/main/c/my_curl_368_belus_l_zr1)|
| ruby |  my_sqlite/my_ruby_lib   [view](https://github.com/Lbelus/my_qwasar_lib/tree/main/ruby/my_ruby_lib)|
| ruby |  bootcamp   [view](https://github.com/Lbelus/my_qwasar_lib/tree/main/ruby/bootcamp)|
| c |  my_zsh    [view](https://github.com/Lbelus/my_qwasar_lib/tree/main/c/my_zsh_402_belus_l_u1y)|
| c |  my_mouse    [view](https://github.com/Lbelus/my_qwasar_lib/tree/main/c/my_mouse_297_belus_l_s4n)|
| c |  my_bc    [view](https://github.com/Lbelus/my_qwasar_lib/tree/main/c/my_bc_296_belus_l_ynf)|
| c |  my_bsq    [view](https://github.com/Lbelus/my_qwasar_lib/tree/main/c/my_bsq_294_belus_l_gtc)|
| c |  my_blockchain    [view](https://github.com/Lbelus/my_qwasar_lib/tree/main/c/my_blockchain_173_belus_l_nmq)|
| c |  my_readline    [view](https://github.com/Lbelus/my_qwasar_lib/tree/main/c/my_readline_172_belus_l_6f-)|
| c |  my_tar    [view](https://github.com/Lbelus/my_qwasar_lib/tree/main/c/my_tar_166_belus_l_egy)|
| c |  my_ls    [view](https://github.com/Lbelus/my_qwasar_lib/tree/main/c/my_ls_163_belus_l_vff)|
| c |  my_printf    [view](https://github.com/Lbelus/my_qwasar_lib/tree/main/c/my_printf_70028_vfhfqu)|
| c |  extra    [view](https://github.com/Lbelus/my_qwasar_lib/tree/main/c/extra)|
| python |  extra    [view](https://github.com/Lbelus/my_qwasar_lib/tree/main/python)|



# Project #1: Malloc

#### Description : 

A custom implementation of memory management allocation functions (malloc, calloc, realloc, free and malloc_usable_size) from stdlib. 

The project aim to :
- Replace those functions at runtime on any program;
- Reduce overhead by storing only the pages adresses inside a tree;
- A 256 bit bitmap is used to keep track of every allocation;

A more comprehensive readme is available at the project URL;

#### Why ? 

- Understand Memory allocation and management;
- Creating a lib in C;
- Do a LD_PRELOAD trick;

#### Technologies Used: 
C, asm (nasm64), Makefile

#### Usage:
```c
#include <main_header.h>

int main(void)
{
    char *ptr = malloc(10);
    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    strcpy(ptr, "Hello");
    printf("%s\n", ptr);
    free(ptr);
    return 0;
}
```

#### Installation:
From the project root dir

```bash
make
```

```bash
LD_PRELOAD=./libmymalloc.so ls
```
```bash
unset LD_PRELOAD
```

```bash
make fclean
```



/!\ make debug do not produce a usable binary/!\

#### Project URL:
https://github.com/Lbelus/my_qwasar_lib/tree/main/c/my_malloc_436_belus_l_m1a


# Project #2: my_ftp

## Description

An implementation of a FTP server following a strict BNF through a custom LEXER/PARSER. 
The users needs to be able to roam through the directories independently from one another and retreive files.

Active and passive mode to tranfer the file is available: 
- Active Mode will have the server connect to client; 
- Passive Mode will let the user connect to server; 

The Project has three main components:
- LEXER/PARSER;
- Server FTP;
- Client FTP;

#### Why ? 
- Understand the limitation arround socket;
- Learn how to use mulithreading;
- learn how to handle multiple client at once;

#### Technologies Used: 
CPP, C, asm (nasm64), Makefile

#### Installation:
From the main directory : 
```bash
make
```
From the clientFTP directory :

```bash
make
```
run the server then the client


### usage
The Following CMD are available 

Every command existing on the bnf will receive an answer from the server, but only USER, PASS, CWD, PWD, LIST, PASV, PORT and RETR have been implemented;


#### Project URL:
https://github.com/Lbelus/my_qwasar_lib/tree/main/cpp/my_ftp_509_belus_l_cwo


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt="Qwasar SV -- Software Engineering School's Logo" src="https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png" width="20px" /></span>