struct Rectangle {
    height: u32,
    width: u32
}

impl Rectangle {
    fn new(width:u32, height:u32) -> Rectangle
    {
        Rectangle {width:width, height: height }
    }

    fn area(&self) -> u64
    {
        (self.width * self.height).into()
    }

    fn can_hold(&self, other_rectangle:&Rectangle) -> bool
    {
        if self.area() > other_rectangle.area()
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

// fn main()
// {
//     let rect1 = Rectangle::new(30, 50);
//     let rect2 = Rectangle::new(10, 40);
//     let rect3 = Rectangle::new(60, 45);

//     println!("Rectangle 1 {} - {}", rect1.height, rect1.width);
//     println!("Rectangle 1 area {}", rect1.area());

//     println!("Can Rectangle #1 hold Rectangle #2? {}", rect1.can_hold(&rect2));
//     println!("Can Rectangle #1 hold Rectangle #3? {}", rect1.can_hold(&rect3));
// }