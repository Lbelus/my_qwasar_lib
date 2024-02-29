use std::env;
use std::panic;

fn is_it_a_good_ide(ide: &str)
{
    match ide
    {
        "google doc" => panic!("Caught a panic!"),
        "vscode" | "cloud9" | "docode" | "emacs" | "nano" => println!("Good"),
        "vim" | "atom" =>  println!("Not good"),
        _ =>  println!("Not on the list")
    }
}
