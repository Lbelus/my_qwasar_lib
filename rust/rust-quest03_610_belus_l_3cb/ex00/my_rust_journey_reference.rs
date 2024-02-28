fn my_initialize(nbr: &mut i16)
{
    *nbr = 0;
}

fn main()
{
    let mut nbr:i16 = 40;

    println!("{}", nbr);
    my_initialize(&mut nbr);
    println!("{}", nbr);
}