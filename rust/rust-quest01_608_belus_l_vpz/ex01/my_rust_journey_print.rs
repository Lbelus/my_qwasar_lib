// Name (Jeannie)
// Tuple ((1, 2))
// Number with leading Zero (009)

fn main()
{
    let age  = 40;
    let name = "Jeannie";
    let tuple = (1, 2);
    let number_with_leading_zero = 9;

    let age  = format!("Age ({})", age);
    let name = format!("Name ({})", name);
    let tuple  = format!("Tuple ({:?})", tuple);
    let number_with_leading_zero = format!("Number with leading Zero ({:03})", number_with_leading_zero);

    println!("{}", age);
    println!("{}", name);
    println!("{}", tuple);
    println!("{}", number_with_leading_zero);
}