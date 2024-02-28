fn concat_string(str1: & String,str2: & String) -> String
{
    let mut result = String::from(str1);
    result.push_str(str2);
    result
}

fn main()
{
    let hello       = String::from("Hello");
    let world       = String::from("world");
    let space       = String::from(" ");
    let exclamation = String::from("!");

    let mut temporary = concat_string(&hello, &space);
    temporary = concat_string(&temporary, &world);

    println!("{}", concat_string(&temporary, &exclamation));
}