use std::env;

fn main()
{
    for element in env::args().skip(1)
    {
        println!("{}", element.len());
    }
}