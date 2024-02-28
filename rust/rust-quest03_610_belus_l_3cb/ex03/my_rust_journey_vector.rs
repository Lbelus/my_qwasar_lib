fn status_and_push(vector: &mut Vec::<i32>)
{
    println!("{}", vector.len());
    if let Some(last) = vector.last()
    {   
        if *last == 1
        {
            vector.push(0);
        }
        else
        {
            vector.push(1);
        }
    }
}


fn main()
{
    let mut vector = Vec::<i32>::new();

    vector.push(0);
    vector.push(1);
    status_and_push(&mut vector);
    println!("{:?}", vector);
    vector.rotate_left(1);
    status_and_push(&mut vector);
    println!("{:?}", vector);
}