# Welcome to My String Rust
***

## Task

Create a MyString struct. It will behave exactly like the std::string::String struct.
Usage of std::string::String is not allowed.

There are two types of strings in Rust: String and &str.

A String is stored as a vector of bytes (Vec``<u8>``), but guaranteed to always be a valid UTF-8 sequence. String is heap allocated, growable and not null terminated.``</u8>``

&str is a slice (&[``u8``]) that always points to a valid UTF-8 sequence, and can be used to view into a String, just like &[T] is a view into Vec``<t>``.

## Description

The project was realised with the help of the following traits :

- PartialEq (or Eq) trait:

impl PartialEq for Book {
    fn eq(&self, other: &Self) -> bool {}
}

- Copy trait:

let s = String::new();
let copy = s.clone();

and the Add trait.


## Installation

No installation

## Usage

compile with 
```bash
rustc ex00/my_string_rust.rs
```

### The Core Team
* [Lorris BELUS](//github.com/Lbelus) - Developer


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
