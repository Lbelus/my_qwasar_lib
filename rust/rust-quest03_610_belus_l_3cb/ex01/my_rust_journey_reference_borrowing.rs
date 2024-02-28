fn my_formatting_and_printing_function(volcano_str: &str)
{
    let mut result = String::from("=>");
    result.push_str(volcano_str);
    result.push_str("<=");
    println!("{}", result);
}

fn main()
{
    let array = ["Kilauea", "Maunaloa", "Maunakea", "Hualalai", "Kohala", "Leahi", "Oahu", "Haleakala"];

    for volcano in array.iter()
    {
        my_formatting_and_printing_function(&volcano);
    }
    println!("{:?}", array);
}