fn main() 
{
    let squre = "square";
    let mut x = 0;
    let mut y = 0;
    
    x += 1;
    println!("X should be equal to 1 -- {}", x);
    x += 1;
    x += 1;
    x += 1;
    y += 10;
    println!("I have a {} of coordinates X({}) - Y({})", squre, x, y);
}