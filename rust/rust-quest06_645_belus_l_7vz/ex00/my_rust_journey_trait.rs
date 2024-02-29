struct Horse { name: String }
struct Sheep {
    name: String,
    sheared:bool    
}

trait Animal {
    fn new(name: String) -> Self;
    fn name(&self) -> &String;
    fn noise(&self) -> String;

    fn talk(&self) {
        println!("{} says {}", self.name(), self.noise());
    }
}

impl Horse {
    fn gallop(&mut self) {
        println!("{} is galloping", self.name());
    }
}



impl Animal for Horse {
    fn new(name: String) -> Horse {
        Horse { name: name }
    }

    fn name(&self) -> &String {
        &self.name
    }

    fn noise(&self) -> String {
        "whinny".to_string()
    }

    fn talk(&self) {
        println!("{} pauses briefly... {}", self.name(), self.noise());
    }
}


impl Sheep {
    fn shear(&mut self) {
        self.sheared = true;
        println!("{} is getting a haircut", self.name());
    }
}


impl Animal for Sheep {
    fn new(name: String) -> Sheep {
        Sheep { 
            name: name,
            sheared: false
            }
    }

    fn name(&self) -> &String {
        &self.name
    }

    fn noise(&self) -> String {
        if self.sheared {
            "brrrrrrr".to_string()
        } else {
            "meuuuh".to_string()
        }
        
    }



    fn talk(&self) {
        println!("{} pauses briefly... {}", self.name(), self.noise());
    }
}


// fn main() {
//     let mut tucker: Horse = Horse::new("Tucker".to_string());

//     tucker.talk();
//     tucker.gallop();
//     tucker.talk();

//     let mut merino: Sheep = Sheep::new("Merino".to_string());

//     merino.talk();
//     merino.shear();
//     merino.talk();
// }