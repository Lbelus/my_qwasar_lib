# Welcome to My Ftp
***

## Task


Create a FTP server.

File Transfer Protocol (FTP) is a standard Internet protocol for transmitting files between computers on the Internet over TCP/IP connections. FTP is a client-server protocol where a client will ask for a file, and a local or remote server will provide it.

You will have to follow the protocol (RFC959)

The network communication will be achieved with TCP sockets.

Server will start with the port and the path of where file can be access:

Usage : ./server port path
port is the port number on which the server socket is listening.

path is the path to the home directory for the "Anonymous" user.

The server MUST be able to handle several clients at the same time by using a
thread.

I think using a thread pool is cool. :-)

Your server must also have those features:

An authentication with an "Anonymous" account and an empty password
Data transfer MUST use "active" or "passive" mode as explained in the protocol.


## Description


The task is to reproduce a FTP SERVER  to transmit files over a TCP/IP connections. 

The Client asks for a file and the Server provices it, the server should be able to handle multiple users at once through the usage of multithreading.

The users needs to be able to roam through the directories independently from one another.

Active and passive mode to tranfer the file is available; 
- active Mode will have the server connect to client; 
- passive Mode will let the user connect to server; 

The Project has several main components 
- LEXER/PARSER
- Server FTP
- Client 




```
my_ftp FTP Server Project
|
|-- 1.0 Project Initialization
|   |-- 1.1 Define project scope based on provided requirements ✓
|
|-- 2.0 Core Server Development
|   |-- 2.1 Basic Server Setup✓
|   |   |-- 2.1.1 Implement command-line argument parsing for port and path ✓
|   |   |-- 2.1.2 Initialize TCP socket and understand the concept of bind(0) ✓
|   |   |-- 2.1.3 Handle socket binding to the specified port and listening ✓
|   |-- 2.2 Multi-client Handling
|   |   |-- 2.2.1 Accept incoming client connections ✓
|   |   |-- 2.2.2 Design and implement a thread pool for handling multiple clients ✓
|   |-- 2.3 FTP Command Handling
|   |   |-- 2.3.1 Develop a command parser to detect FTP commands ✓
|   |   |-- 2.3.2 Implement the "USER" and "PASS" commands for "Anonymous" authentication
|   |   |-- 2.3.3 Set up data transfer commands using active and passive modes
|   |-- 2.4 File and Directory Management
|   |   |-- 2.4.1 Determine the home directory for the "Anonymous" user ? 
|   |   |-- 2.4.2 Implement file retrieval and listing commands ✓
|
|-- 3.0 Protocol Adherence and Enhancement
|   |-- 3.1 Study and understand the FTP protocol (RFC959) ✓
|   |-- 3.2 Implement any additional FTP commands as per protocol 
|   |-- 3.3 Ensure data transfer adheres to active and passive modes ✓
|
|-- 4.0 Testing and Debugging
|   |-- 4.1 Unit Testing
|   |   |-- 4.1.1 Test individual FTP command handlers
|   |   |-- 4.1.2 Test thread pool functionality and multi-client handling
|   |-- 4.2 Integration and Protocol Testing
|   |   |-- 4.2.1 Test overall server functionality using FTP clients
|   |   |-- 4.2.2 Validate server behavior against the FTP protocol (RFC959)
|
|-- 5.0 Documentation and Cleanup
|   |-- 5.1 Comment the codebase for clarity
|   |-- 5.2 Write a brief README or user manual
|   |-- 5.3 Address any known issues, limitations, or potential improvements
|
|-- 6.0 Compilation and Delivery
    |-- 6.1 Compile the server for the target platform(s)
    |-- 6.2 Package the server, documentation, and any required dependencies
    |-- 6.3 Deliver or release to intended users or stakeholders
```

two-week timeframe schedule:

Days 1-2:
- Project Initialization, Environment Setup ✓
- Preliminary Research on FTP and RFC959 ✓
Days 3-5:
- Basic Server Setup (TCP socket initialization, command-line parsing) ✓
- Multi-client Handling with Thread Pool ✓
Days 6-8:
- Implement FTP Command Handling (USER, PASS, LIST, RETR, etc.) ✓
- Implement Active and Passive Modes ✓
Days 9-10:
- File and Directory Management ✓
- Additional FTP Commands and Features ✓
Days 11-12:
- Thorough Testing (Unit, Integration, Protocol Adherence)
Days 13:
- Documentation, Code Cleanup, Addressing Known Issues 75%✓
Day 14:
- Compilation, Packaging, and Delivery ✓

```

                                            -------------
                                            |/---------\|
                                            ||   User  ||    --------
                                            ||Interface|<--->| User |
                                            |\----^----/|    --------
                  ----------                |     |     |
                  |/------\|  FTP Commands  |/----V----\|
                  ||Server|<---------------->|   User  ||
                  ||  PI  ||   FTP Replies  ||    PI   ||
                  |\--^---/|                |\----^----/|
                  |   |    |                |     |     |
      --------    |/--V---\|      Data      |/----V----\|    --------
      | File |<--->|Server|<---------------->|  User   |<--->| File |
      |System|    || DTP  ||   Connection   ||   DTP   ||    |System|
      --------    |\------/|                |\---------/|    --------
                  ----------                -------------

                  Server-FTP                   USER-FTP
```

project BNF : 
```
*SP = space
*CRLF Carriage Return Line Feed

            USER <SP> <username> <CRLF>
            PASS <SP> <password> <CRLF>
            ACCT <SP> <account-information> <CRLF>
            CWD  <SP> <pathname> <CRLF>
            CDUP <CRLF>
            SMNT <SP> <pathname> <CRLF>
            QUIT <CRLF>
            REIN <CRLF>

            PORT <SP> <host-port> <CRLF>
            PASV <CRLF>
            TYPE <SP> <type-code> <CRLF>
            STRU <SP> <structure-code> <CRLF>
            MODE <SP> <mode-code> <CRLF>

            RETR <SP> <pathname> <CRLF>
            STOR <SP> <pathname> <CRLF>
            STOU <CRLF>
            APPE <SP> <pathname> <CRLF>
            ALLO <SP> <decimal-integer>
                [<SP> R <SP> <decimal-integer>] <CRLF>
            REST <SP> <marker> <CRLF>
            RNFR <SP> <pathname> <CRLF>
            RNTO <SP> <pathname> <CRLF>
            ABOR <CRLF>
            DELE <SP> <pathname> <CRLF>
            RMD  <SP> <pathname> <CRLF>
            MKD  <SP> <pathname> <CRLF>
            PWD  <CRLF>
            LIST [<SP> <pathname>] <CRLF>
            NLST [<SP> <pathname>] <CRLF>
            SITE <SP> <string> <CRLF>
            SYST <CRLF>
            STAT [<SP> <pathname>] <CRLF>
            HELP [<SP> <string>] <CRLF>
            NOOP <CRLF>

            <username> ::= <string>
            <password> ::= <string>
            <account-information> ::= <string>
            <string> ::= <char> | <char><string>
            <char> ::= any of the 128 ASCII characters except <CR> and
            <LF>
            <marker> ::= <pr-string>
            <pr-string> ::= <pr-char> | <pr-char><pr-string>
            <pr-char> ::= printable characters, any
                          ASCII code 33 through 126
            <byte-size> ::= <number>
            <host-port> ::= <host-number>,<port-number>
            <host-number> ::= <number>,<number>,<number>,<number>
            <port-number> ::= <number>,<number>
            <number> ::= any decimal integer 1 through 255
            <form-code> ::= N | T | C
            <type-code> ::= A [<sp> <form-code>]
                          | E [<sp> <form-code>]
                          | I
                          | L <sp> <byte-size>
            <structure-code> ::= F | R | P
            <mode-code> ::= S | B | C
            <pathname> ::= <string>
            <decimal-integer> ::= any decimal integer
```

## Installation

Insert inside the terminal :
to build the Server; 

From the main directory : 
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

From the clientFTP directory :

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

The Following CMD are available 


Every command existing on the bnf will receive an answer from the server, but only USER, PASS, CWD, PWD, LIST, PASV, PORT and RETR have been implemented; 

USER will only anwer to "anonymous"
NO password is required 


```
Usage: ./my_ftp port path
example: ./my_ftp 8080 .

Go to client and launch the program 

usage ./my_client_ftp port
example: ./my_client_ftp 8080 

CMD list : 

USER anonymous
PASS <password>
CWD <dir> or <..>
PWD
LIST
PASV
PORT <port-number>
RETR <filename or filepath>

```

### The Core Team
* [Lorris BELUS](//github.com/Lbelus) - Developer


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
