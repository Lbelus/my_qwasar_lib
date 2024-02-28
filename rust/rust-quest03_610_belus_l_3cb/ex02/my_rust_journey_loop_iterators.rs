fn main()
{
    let int_array = [1, 2, 3, 4, 5];
    let mut int_array_it = int_array.iter();

    loop
    {
        match int_array_it.next()
        {
            Some(element) => println!("{}", element),
            None => break
        }
    }
}