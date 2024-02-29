// use std::env;


fn list_of_plastic(plastic: &str) -> Option<&str>
{
    let list_plastics: [&str; 7] = ["Polyethylene Terephthalate", "High-Density Polyethylene", "Polyvinyl Chloride", "Low-Density Polyethylene", "Polypropylene", "Polystyrene", "Polycarbonate"];
    if list_plastics.contains(&plastic)
    {
        return Some(&plastic);
    }
    else
    {
        return None;
    }
}