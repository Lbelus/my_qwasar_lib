# Welcome to my_sqlite
***

## Task
The task is to create a class called MySqliteRequest that behaves like a request on a real SQLite database. The class should have methods for select, where, join, order, insert, values, update, set, and delete. Additionally, a run method should be implemented to execute the query. A Command Line Interface (CLI) should also be created for the MySqlite class that accepts SQL-like queries

## Description

**My_sqlite** is a Ruby-based implementation of a simple database system that relies on an **inverted index** for efficient data retrieval. The code follows a **command design pattern**, providing methods for various database operations. It includes classes **MySqliteGetter** and **MySqliteSetter**, each serving specific purposes to handle data retrieval and manipulation.
At its core **my_sqlite** allows to perfom **CRUD** operations efficiently. 

The **MySqliteGetter** class is responsible for fetching data from the database based on user queries.
The **MySqliteSetter** module contains methods for modifying the database. It enables users to perform INSERT, UPDATE, DELETE, JOIN and ORDER operations on the database.

The **MySqliteRequest** class extends both **MySqliteGetter** and **MySqliteSetter**, combining their functionalities to execute complete database queries. It allows users to interact with the my_sqlite database system through SQL-like queries and perform complex operations on the data.

The **InvertedIndex** class is also part of the my_sqlite implementation. It handles data storage and retrieval, using an inverted index structure to optimize searching for values across the dataset. The inverted index is a dictionary-like data structure that maps values to a list of associated IDs. This approach allows for efficient searches and reduces the need for full-table scans.

To use the project, run the my_sqlite_cli.rb file with Ruby. You will be presented with a prompt to enter queries in SQL-like format. The queries can include SELECT, INSERT, UPDATE, DELETE, and JOIN statements. The FROM and WHERE clauses are also supported. Only one WHERE condition and one JOIN condition are allowed per query.

## Installation
#### Clone the repository:

```bash

git clone git@github.com:Lbelus/my_sqlite.git
```
#### install the gem 
To install the gem localy and run it from any directory

from 
```
/my_gem_box/my_sqlite/
```
run
```
gem build my_sqlite.gemspec
gem install ./my_sqlite-0.0.0.gem
```
Then type ``my_sqlite`` from anywhere in the dir to run my_sqlite.

#### run the gem server

To run the gem server and install from "local" server
```
gem install geminabox
gem install puma
gem install rake
```

from 
```
/my_sqlite/geminabox
```
run 
```
rackup
```
access it from local http://localhost:9292


#### Test my_sqlite

to run automated test on my_sqlite
```
gem install rake
```
from
``` 
/my_gem_box_my_sqlite/
```
run
```
rake
```
## Usage

To use the CLI for the MySqlite class, run the my_sqlite_cli.rb file with Ruby:

```bash
    ruby my_sqlite_cli.rb
```
You will be presented with a prompt to enter queries in SQL-like format. For example:

```sql
    my_sqlite_cli> SELECT * FROM nba_player_data.csv WHERE birth_state='Indiana';
```
The queries can include SELECT, INSERT, UPDATE, DELETE, and JOIN statements. The FROM and WHERE clauses are also supported. Only one WHERE condition and one JOIN condition are allowed per query.

The Ctrl-C or QUIT commands can be used to exit the CLI.


### The Core Team
* [Lorris BELUS](//github.com/Lbelus) - Developer
* [Igor Mirsalikhov](https://www.linkedin.com/in/igor-mirsalikhov/) - Research Assistant at Florida Polytechnic University


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt="Qwasar SV -- Software Engineering School's Logo" src="https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png" width="20px" /></span>