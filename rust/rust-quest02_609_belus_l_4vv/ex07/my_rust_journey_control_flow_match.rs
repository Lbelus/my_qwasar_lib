use std::env;

/*
if argument is "hello" it will print "world"
if argument is "john" or "jenny" or "michael" it will print "name"
if argument is "northern" it will print "light"
if argument is "grogu" it will print "This is the way.
"
else it will print "unknown"
*/
fn main()
{
    match env::args().nth(1).as_deref()
    {
        Some("hello") => println!("world"),
        Some("john") | Some("jenny") | Some("michael") => println!("name"),
        Some("northern") => println!("light"),
        Some("grogu") => println!("This is the way."),
        Some("") => println!("one argument"),
        None => println!("one argument"),
        _ => println!("unknown")
    }
}
