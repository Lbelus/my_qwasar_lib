use std::env;
use std::io;
use rand::Rng;
use std::io::Write;

fn parse_int(next_argument: &String) -> u32
{
    match next_argument.parse::<u32>() {
        Ok(parsed) => parsed,
        Err(_) => panic!("Invalid value")
    }
}

fn generate_secret_code() -> String
{
    let mut secret_code = String::new();
    for _ in 0..4 {
        let tmp = rand::thread_rng().gen_range(0..=9);
        secret_code.push_str(&tmp.to_string());
    }
    secret_code
}

fn find_pos(string: &String, input_char: char) -> Option<usize> {
    for (index, ch) in string.chars().enumerate() {
        if input_char == ch {
            return Some(index);
        }
    }
    None
}

fn validity_check(input:&str) -> bool
{
    if input.len() > 4
    {
        return false;
    }
    for ch in input.chars() {
        if !ch.is_digit(10) 
        {
            return false;
        }
    }
    return true;
}

fn check_user_input(secret_code: &str, input: &str) -> bool {
    if secret_code == input
    {
        return true;
    }

    let mut correct_placed = 0;
    let mut incorrect_placed = 0;

    let mut input_chars: [char; 4] = Default::default(); // default trait, apply default value according to type
    let mut password_chars: [char; 4] = Default::default();

    for (index, ch) in input.chars().enumerate() {
        input_chars[index] = ch;
    }
    for (index, ch) in secret_code.chars().enumerate() {
        password_chars[index] = ch;
    }

    for index in 0..4 {
        if input_chars[index] == password_chars[index] {
            correct_placed += 1;
            password_chars[index] = '\0';
        }
    }

    for index in 0..4 {
        if input_chars[index] != password_chars[index] && password_chars.contains(&input_chars[index]) {
            incorrect_placed += 1;
            let pos = find_pos(&secret_code.to_string(), input_chars[index]);
            password_chars[pos.unwrap()] = '\0';
        }
    }

    println!("Well placed pieces: {}\nMisplaced pieces: {}", correct_placed, incorrect_placed);

    return false;
}

fn main() {
    let mut args = env::args().peekable();
    let mut attempt:u32 = 10;
    let mut secret_code = generate_secret_code();

    while let Some(argument) = args.next() {
        if argument == "-t" {
            match args.peek() {
                Some(next_argument) => attempt = parse_int(next_argument),
                None => println!("Found -t but no argument follows it."),
            }
        }
        else if argument == "-c" {
            match args.peek() {
                Some(next_argument) => 
                    secret_code = String::from(next_argument),
                None => println!("Found -c but no argument follows it."),
            }
        }
    }

    println!("Will you find the secret code?");
    println!("secret code: {}", secret_code);
    let mut round = 0;
    while round < attempt {
        print!("---\nRound {}\n>", round);
        io::stdout().flush().unwrap();
        let mut user_input = String::new();
        io::stdin()
            .read_line(&mut user_input)
            .expect("Failed to read line");
        let user_input = user_input.trim();
        if user_input == 0
        {
            break;
        }
        if !validity_check(user_input)
        {
            println!("Wrong input!");
            continue;
        }
        if user_input.eq("exit") {
            println!("Exiting...");
            break; 
        } else {
            if check_user_input(&secret_code, user_input) {
                println!("Congrats! You did it!");
                break;
            }
        }
        println!("You entered: {}", user_input);
        round += 1;
    }
}