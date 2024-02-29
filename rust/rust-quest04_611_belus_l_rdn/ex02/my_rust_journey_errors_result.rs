// use std::num::ParseIntError;

fn volcano_location(volcano: &str) -> Result<&str, &str>
{
    let hawaii_volcanoes = ["Kilauea", "Maunaloa", "Maunakea", "Hualalai", "Kohala", "Leahi", "Oahu", "Haleakala"];
    let iceland_volcanoes = ["Fagradalsfjall", "Holuhraun", "Eyjafjallajokull", "Hekla", "Krafla", "Eldfell", "Reykjaneshryggur"];
    let usa_volcanoes = ["Lassen Peak", "Long Valley Caldera", "Yellowstone", "Mammoth Mountain", "Pinnacles", "Ubehebe Craters", "Mount Shasta", "Mount St. Helens", "Mount Rainier", "Mount Baker", "Mount Hood"];

    if hawaii_volcanoes.contains(&volcano)
    {
        Ok("Hawaii")
    }
    else if iceland_volcanoes.contains(&volcano) 
    {
        Ok("Iceland")
    }
    else if usa_volcanoes.contains(&volcano)
    {
        Ok("USA")
    }
    else
    {
        Err("Not in database")
    }
}
