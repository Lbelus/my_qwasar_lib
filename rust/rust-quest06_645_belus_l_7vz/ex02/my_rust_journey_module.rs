mod restaurant {
    pub struct Server {
        name: String,
    }
    impl Server {
        pub fn new(name: String) -> Server {
            Server { name: name }
        }
    }

    pub struct Group {
        name: String,
        nbr_person: u16
    }

    impl Group {
        pub fn new(name: String, nbr_person:u16) -> Group {
            Group { 
                name: name,
                nbr_person: nbr_person
            }
        }
    }

    pub mod hosting {
        pub fn add_to_waitlist(group: &super::Group) {
            println!("{} is waiting for a table with {} seats", group.name, group.nbr_person);
        }
        pub fn seat_at_table(group: &super::Group) {
            println!("{} seat at a table", group.name);
        }
    }


    pub mod serving {
        pub fn take_order(server: &super::Server, group: &super::Group) {
            println!("{} takes the order of {}", server.name, group.name)
        }
        pub fn serve_order(server: &super::Server, group: &super::Group) {
            println!("{} serves {}", server.name, group.name);
        }
        pub fn take_paiement(server: &super::Server, group: &super::Group) {
            println!("{} takes paiement for {}", server.name, group.name);
        }
    }

}


// Peterson Family is waiting for a table with 12 seats
// John takes the order of Peterson Family
// Jenny & Michael is waiting for a table with 2 seats
// Peterson Family seat at a table
// Richarson household is waiting for a table with 4 seats
// Richarson household seat at a table
// Jenny & Michael seat at a table
// Larry takes the order of Jenny & Michael
// Larry serves Peterson Family
// Larry serves Jenny & Michael
// Larry takes the order of Richarson household
// Larry serves Richarson household
// John takes paiement for Jenny & Michael
// Larry takes paiement for Peterson Family
// John takes paiement for Richarson household

// fn main() {
//     let server_1 = restaurant::Server::new("John".to_string());
//     let server_2 = restaurant::Server::new("Larry".to_string());

//     let group_1 = restaurant::Group::new("Peterson Family".to_string(), 12);
//     let group_2 = restaurant::Group::new("Jenny & Michael".to_string(), 2);
//     let group_3 = restaurant::Group::new("Richarson household".to_string(), 4);

//     restaurant::hosting::add_to_waitlist(&group_1);
//     restaurant::serving::take_order(&server_1, &group_1);
//     restaurant::hosting::add_to_waitlist(&group_2);
//     restaurant::hosting::seat_at_table(&group_1);
//     restaurant::hosting::add_to_waitlist(&group_3);
//     restaurant::hosting::seat_at_table(&group_3);

//     restaurant::hosting::seat_at_table(&group_2);
//     restaurant::serving::take_order(&server_2, &group_2);

//     restaurant::serving::serve_order(&server_2, &group_1);
//     restaurant::serving::serve_order(&server_2, &group_2);

//     restaurant::serving::take_order(&server_2, &group_3);
//     restaurant::serving::serve_order(&server_2, &group_3);
//     restaurant::serving::take_paiement(&server_1, &group_2);
//     restaurant::serving::take_paiement(&server_2, &group_1);
//     restaurant::serving::take_paiement(&server_1, &group_3);
// }