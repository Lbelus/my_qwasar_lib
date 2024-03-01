use std::ops::Add;
use std::fmt;

struct MyStringRust {
    chars: Vec<u8>,
}

trait Len {
    fn len(&self) -> usize;
}

impl Len for MyStringRust {
    fn len(&self) -> usize {
        self.chars.len()
    }
}

trait ToMyStringRust {
    fn to_my_string_rust(&self) -> MyStringRust;
}

impl ToMyStringRust for &str {
    fn to_my_string_rust(&self) -> MyStringRust
    {
        MyStringRust {
            chars: self.as_bytes().to_vec(),
        }
    }
}

trait Clone {
    fn clone(&self) -> Self;
}

impl Clone for MyStringRust {
    fn clone(&self) -> MyStringRust {
        MyStringRust {
            chars: self.chars.clone(),
        }
    }
}

impl PartialEq for MyStringRust {
    fn eq(&self, other: &Self) -> bool {
        self.chars == other.chars
    }
}

impl Add for MyStringRust {
    type Output = MyStringRust;

    fn add(self, other: Self) -> MyStringRust {
        let mut new_chars = self.chars.clone();
        new_chars.extend_from_slice(&other.chars);
        MyStringRust { chars: new_chars }
    }
}


impl fmt::Display for MyStringRust { // https://doc.rust-lang.org/std/fmt/trait.Display.html#tymethod.fmt
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let string_slice = std::str::from_utf8(&self.chars) 
            .map_err(|_| fmt::Error)?;
        write!(f, "{}", string_slice)
    }
}

impl MyStringRust {
    fn new() -> MyStringRust {
        MyStringRust {
            chars: Vec::new(), 
            }
    }

    fn from(slice: &str) -> MyStringRust {
        MyStringRust {
            chars: slice.as_bytes().to_vec(),
        }
    }



    fn push_str(&mut self, slice: &str) {
        self.chars.extend_from_slice(slice.as_bytes());
    }
}





// fn main() {
//     {
//         println!("## CONSTRUCTOR TEST");

//         println!("default constructor: ");
//         let s1 = MyStringRust::new();

//         println!("{}", s1.len() == 0);

//         println!("&str from constructor: ");
//         let s2 = MyStringRust::from("Trait PartialEq");

//         println!("s2 'hello' = {}?", s2);

//         println!("Trait PartialEq: ");
//         println!("{}", s2 == "Trait PartialEq".to_my_string_rust());

//         let mut s3 = MyStringRust::new();

//         println!("push_str(): ");
//         s3.push_str("push_str");
//         println!("{}", s3 == "push_str".to_my_string_rust());

//         println!("Copy string: ");
//         let s4 = s2.clone();

//         println!("{}", s4 == s2);
//     }


//     {
//         println!("## SIZE");

//         let u = "qwasar creating stars".to_my_string_rust();

//         println!("size: ");
//         println!("{}", u.len() == 21);
//     }

//     {
//         println!("## OPERATOR+");

//         let u = "qwasar ".to_my_string_rust();
//         let v = "creating stars".to_my_string_rust();
//         let w = u + v;

//         println!("operator+: ");
//         println!("{}", w == "qwasar creating stars".to_my_string_rust());
//     }
// }