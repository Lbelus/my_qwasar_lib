use std::env;

fn main()
{
  for argument in env::args().skip(1)
  {
      println!("{}", argument);
  }
}