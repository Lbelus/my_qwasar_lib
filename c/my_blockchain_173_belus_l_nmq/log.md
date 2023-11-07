## Blockchain build
- Create new Block;
- Add transaction to block;
- Hash a Block;
- Return last block on chain;

 ## Block structure

- Index;
- Timestamp;
- Transactions: {sender, recipient, amount};
- Proof;
- Previous Hash;

## Add transaction to Block

Add transaction to list, return index of block to wich the transaction will added to.

## Create new blocks

Genesis block:

    -> block with no predecessor (head);
    -> used to seed an instantiated Blockchain;
    -> proof to genesis blocks (result of mining);

Block maximum size is set to kb for x transactions;


## PoW

Solves a problem;
Must be difficult to find but easy to verify (computationally);

#### Exemple

+hashcash principle;


## Blockchain as CLI


Each commmand issued to the makefile call a specific program.

 '*' : all nodes are impacted;
 NID is an integer;
 BID is a string;

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

1:no more resources available on computer;
2:this node already exists;
3:this block already exists;
4:node doesn't exists;
5:block doesn't exists;
6:command not found;


## Mining endpoint

- Calculate Proof of Work
- Reward the miner by adding a transaction
- Forge the new block by adding it to the chain


## Consensus

Implement consensus algorithm by setting rules.
- longest valid chain (authoritative):
    - check if chain is valid;
    - resolve conflict;
    - if valid chain found is longer than current then it is valid;

Q&A;

- Block is supposed to have a fixed size or a multiple of a fixed size;
- Makefile CLI ? one command call for a specific bin ? so no master program;
- add ? mean add don't add directly to blockchain ? blockchain is instanciated until sync 
- sync ? what is the valid consensus ? 
- what kind of data structure is expected   
- no more ressource on computer ? how to check it ? 


## Architecture overview / flowchart

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
  ┌────────►│ Restore from backup │   │ Start new backup │
  │         └──────────┬──────────┘   └──────────┬───────┘
  │                    │                         │
  │                    └────────────┬────────────┘
  │                                 │
  │                                 ▼
  │                         ┌────────────────┐
  │                         │  User input ?  │◄────────────────────────────────────────────────────┐
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
  │ │ Add Block/Node │◄───│ Remove Block/Node │◄───│ Synchronize Chain │    │ Quit │
  │ └────────┬───────┘    └─────────┬─────────┘    └──────────┬────────┘    └──┬───┘
  │          ▼                      ▼                         ▼                │
  └────────────────────────────────────────────────────────────                ▼
                                                                            ┌──────┐
                                                                            │ END  │
                                                                            └──────┘
```

## Milestone/implementation plan

1. Parse command line : DONE (1/5/2023)
    user input goes through readline to be parsed and categorized by getopt. 
    -c args are separated from command such ad "add", "rm",...
2. Node/block related function
    
3. Write backup
4. Read backup