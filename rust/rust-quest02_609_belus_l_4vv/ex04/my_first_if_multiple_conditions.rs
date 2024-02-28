fn main()
{
  let a:u8 = 10;
  let b:u8 = 9;
  let c:u8 = 11;
  let d:u8 = 10;
  let y:u8 = 9;
  let z:u8 = 11;

  if a > b && a < c && a == d {
    println!("a is bigger than b AND smaller than c AND equal to d");
  }
  if z > a || y > a {
    println!("z OR y are bigger than a");
  }
}