# Welcome to My Blockchain
***

## Task

Task is to prototype a blockchain, creating a cli that can take both simple user input in CLI type program and Echo several order at once. 

## Description

### Blockchain as CLI


Each commmand issued call a specific program.

 '*' : all nodes are impacted;

 - add node nid... :       Add a NID identifier to the blockchain node;
 - rm node nid...  :       Remove node from the blockchain with a NID identifier or '*';
 - add block bid nid... :  Add a BID identified block to nodes identified by NID or '*';
 - rm block bid... :       Remove bid identified block from all nodes where these blocks are present;
 - ls... :                 List all nodes by their identifiers. -l attaches the blocks BID associated with each node;
 - sync... :               Synchronize all of the nodes with each other, upon issuing this command;
 - quit :                  Save and quit blockchain;

Blockchain display prompt :
    - 's' if synchronized;
    - '-' if not synchronized;

```
[s0]>
[-2]>
```
#### Error message

usage error will display following information through STDERR:

1:no more resources available on computer;
2:this node already exists;
3:this block already exists;
4:node doesn't exists;
5:block doesn't exists;
6:command not found;

### Consensus

Implement consensus algorithm by setting rules.
- longest valid chain (authoritative):
    - check if chain is valid;
    - resolve conflict;
    - find the element with the highest frequency (temporary)

### Architecture overview / flowchart

```
                              ┌─────────┐
                              │  START  │
                              └────┬────┘
                                   │
                                   ▼
                          ┌─────────────────┐
                          │ Backup exists ? │
                     ┌────┴─────────────────┴───┐
                     │                          │
                     ▼                          ▼
            ┌─────────────────────┐   ┌──────────────────┐
            │ Restore from backup │   │ Start new backup │
            └──────────┬──────────┘   └──────────┬───────┘
                       │                         │
                       └────────────┬────────────┘
                                    │
                                    ▼
                            ┌────────────────┐
  ┌────────────────────────►│  User input ?  │◄────────────────────────────────────────────────────┐
  │                         └───────┬────────┘                                                     │
  │                                 │                                                              │
  │                                 ▼                                                              │
  │                        ┌──────────────────┐      ┌────────────────────────────┐                │
  │                        │ Parse user input ├──┬──►│ Command does not exists    ├─────┐          │
  │                        └────────┬─────────┘  │   └────────────────────────────┘     │          │
  │                                 │            │                                      │          │
  │                                 │            │   ┌────────────────────────────┐     │  ┌───────┴───────────┐
  │                                 │            ├──►│ Block/Node does not exists ├─────┼─►│ Return error type │
  │                                 │            │   └────────────────────────────┘     │  └───────────────────┘
  │                                 │            │                                      │
  │                                 │            │   ┌────────────────────────────┐     │
  │                                 │            └──►│ Block/Node already exists  ├─────┘
  │                                 │                └────────────────────────────┘
  │                                 │
  │           ┌─────────────────────┼─────────────────────────┬─────────────────┐
  │           │                     │                         │                 │
  │           │                     │                         │                 │
  │           ▼                     ▼                         ▼                 ▼
  │ ┌────────────────┐    ┌───────────────────┐    ┌───────────────────┐    ┌──────┐
  │ │ Add Block/Node │    │ Remove Block/Node │    │ Synchronize Chain │    │ Quit │
  │ └────────┬───────┘    └─────────┬─────────┘    └──────────┬────────┘    └──┬───┘
  │          ▼                      ▼                         ▼                │
  └────────────────────────────────────────────────────────────                ▼
                                                                            ┌──────┐
                                                                            │ END  │
                                                                            └──────┘
```

## Installation
to install project type in terminal "make"
to unsinstall type in terminal make clean

## Usage

launch program by typing ./my_blockchain
and insert following commands :  

or use echo:
```
echo "add node 12\nadd node 15\nadd node 13\nadd block 21 12\nadd block 22 15\nls -l\nsync\nls -l\nquit" | ./my_blockchain | cat -e
```


### The Core Team
* [Lorris BELUS](//github.com/Lbelus) - Developer


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
