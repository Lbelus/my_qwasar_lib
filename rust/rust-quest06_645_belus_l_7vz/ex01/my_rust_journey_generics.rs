use std::fmt::Debug;

struct MyBox<T> {
    element: T,
}

impl<T> MyBox<T> where T: Debug
{
    fn new(value: T) -> MyBox<T>
    {
        MyBox {element: value}
    }
    fn print(&self) {
        println!("My box contains {:?}", self.element)
    }
}


// Input: 
// Output: My box contains "secret"
// My box contains 32
// My box contains 3.14


// fn main() {
//     let my_box1 = MyBox::<String>::new("secret".to_string());

//     my_box1.print();

//     let my_box2 = MyBox::<i32>::new(32);

//     my_box2.print();

//     let my_box3 = MyBox::<f32>::new(3.14);

//     my_box3.print();
// }