# Welcome to My Cpp Redis Client
***

## Task

The task is to develop my_redis_cli, a Command-Line Interface (CLI) application in C++ that interfaces with a Redis server.

This project aimed at developping knowledge on:

- The RESP protocole;
- Network Programming;
- Building a lib and install it localy with PKG support;
- Cmake;

## Description

The project is composed of two elements:

- A C++ API of hiredis built as a lib;
- A CLI ported from C to C++;


The redis client lib is called in the CLI that created a derived class from my_redis::RedisClient class. 
The derived class modify the original class to allow the transfert of ownership of the redisContext which hold a socket.
The user input is passed through a readline, a custom cpp getopt and function ptr map to run each commands.

🚨
The project relies on Docker and the provided environement to run the built-in test. If you plan to run these tests, please respect the given procedure in ``Installation``. It goes as well to simplify the project building and compiling.
🚨

Here is the commands supported by the CLI and redis client API in a BNF format:

### KEY/VALUES
```md
<command> ::= <set-command> | <get-command> | <keys-command> | <type-command> | <del-command> | <unlink-command> | <expire-command> | <rename-command>

<set-command> ::= "SET" <SP> <key> <SP> <value> <CRLF>
<get-command> ::= "GET" <SP> <key> <CRLF>
<keys-command> ::= "KEYS" <SP> <pattern> <CRLF>
<type-command> ::= "TYPE" <SP> <key> <CRLF>
<del-command> ::= "DEL" <SP> <key> <CRLF>
<unlink-command> ::= "UNLINK" <SP> <key> <CRLF>
<expire-command> ::= "EXPIRE" <SP> <key> <SP> <seconds> <CRLF>
<rename-command> ::= "RENAME" <SP> <old_key> <SP> <new_key> <CRLF>
```

### LISTS

```md
<list-command> ::= <lpush-command> | <rpush-command> | <lpop-command> | <rpop-command> | <llen-command> | <lrem-command> | <lindex-command> | <lset-command>

<lpush-command> ::= "LPUSH" <SP> <key> <SP> <value> <CRLF>
<rpush-command> ::= "RPUSH" <SP> <key> <SP> <value> <CRLF>
<lpop-command> ::= "LPOP" <SP> <key> <CRLF>
<rpop-command> ::= "RPOP" <SP> <key> <CRLF>
<llen-command> ::= "LLEN" <SP> <key> <CRLF>
<lrem-command> ::= "LREM" <SP> <key> <SP> <count> <SP> <element> <CRLF>
<lindex-command> ::= "LINDEX" <SP> <key> <SP> <index> <CRLF>
<lset-command> ::= "LSET" <SP> <key> <SP> <index> <SP> <value> <CRLF>
```

### HASHES

```md
<hash-command> ::= <hget-command> | <hexists-command> | <hmset-command> | <hdel-command> | <hset-command> | <hvals-command> | <hgetall-command> | <hkeys-command> | <hlen-command>

<hget-command> ::= "HGET" <SP> <key> <SP> <field> <CRLF>
<hexists-command> ::= "HEXISTS" <SP> <key> <SP> <field> <CRLF>
<hmset-command> ::= "HMSET" <SP> <key> <SP> <field-value-pairs> <CRLF>
<hdel-command> ::= "HDEL" <SP> <key> <SP> <field> <CRLF>
<hset-command> ::= "HSET" <SP> <key> <SP> <field> <SP> <value> <CRLF>
<hvals-command> ::= "HVALS" <SP> <key> <CRLF>
<hgetall-command> ::= "HGETALL" <SP> <key> <CRLF>
<hkeys-command> ::= "HKEYS" <SP> <key> <CRLF>
<hlen-command> ::= "HLEN" <SP> <key> <CRLF>

<field-value-pairs> ::= <field> <SP> <value> {<SP> <field> <SP> <value>}
```

### Commons
```md
<utility-command> ::= <echo-command> | <ping-command> | <flushall-command> | <info-command>

<echo-command> ::= "ECHO" <SP> <message> <CRLF>
<ping-command> ::= "PING" <CRLF>
<flushall-command> ::= "FLUSHALL" <CRLF>
<info-command> ::= "INFO" <SP> <section> <CRLF> | "INFO" <CRLF>
```

## Installation

### Step 1. setup the Environment.
Using docker.

- Create a docker network:
```bash
docker network create mynetwork
```

- Pull redis image: 
```bash
docker pull redis
```

```bash
docker run --name myredis --network mynetwork -d redis
```
From the ``project root`` dir.
- Build the image:
```bash
docker build -t img_redis_client .
```

- Then run the container:
```bash
docker run -it --network mynetwork -v /my/local/dir:/workspace --name cont_redis_client img_redis_client /bin/bash
```

### Step 2. Build the API and run tests with GoogleTest.

From the ``/redis_client_api/`` dir.

- Generate the build system:

```bash
cmake -S . -B build -DENABLE_GTEST=ON
```

- Build the executable and the tests:
```bash
cmake --build build
```

🚨 Test are hardcoded to run on "tcp://myredis:6379" 🚨

- Run the tests:
```bash
cd build && ctest
```

- Run the test without google test and check the output:
```bash
./rediPack
```

- Install the lib:
```bash
make install
```


### Step 3. Build the CLI and run some manual tests.
From the ``/redis_cli/`` dir.

- Generate the build system:

```bash
cmake -S . -B build -DENABLE_GTEST=OFF
```

- Compile:
```bash
cd build && make
```


## Usage

From the ``/redis_cli/build`` dir.

- Run the program:
```bash
./redisCli tcp://myredis:6379
```

For any commands, please refer to the BNF in the description.


### The Core Team
* [Lorris BELUS](//github.com/Lbelus) - Developer


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt="Qwasar SV -- Software Engineering School's Logo" src="https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png" width="20px" /></span>
