use std::env;

fn main()
{
    match env::args().nth(1)
    {
        Some(argument) =>
        {
            let mut chars = argument.chars();
            while let Some(ch) = chars.next()
            {
                println!("{}", ch);
            }   
        }
        None => {}
    }
}

