use std::env;

fn main()
{
    match env::args().nth(1)
    {
      Some(sentence) =>
      {
        let words: Vec<&str> = sentence
            .split(' ')
            .collect();

        let words_containing_t: Vec<&str> = words
            .into_iter()
            .filter(|x| x.contains("t"))
            .collect();
        println!("{:?}", words_containing_t);
      }
      None => {}
    }
}