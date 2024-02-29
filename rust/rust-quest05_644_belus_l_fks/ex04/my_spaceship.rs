const DIRECTIONS:usize = 4;

struct Radar {
    coordinate_x:i32,
    coordinate_y:i32
}

impl Radar {
    fn update(&mut self, thruster_x_update: i32, thruster_y_update: i32 ) {
        self.coordinate_x += thruster_x_update;
        self.coordinate_y += thruster_y_update;
    }
}

struct Gyroscopes<'a> {
    needle:i32,
    compass: [&'a str; DIRECTIONS]
}

struct Engine {
    thruster_x: [i8; DIRECTIONS],
    thruster_y: [i8; DIRECTIONS]
}

struct Radio
{
    call:String
}

impl Radio {
    fn new(x:i32, y:i32, bearing: String) -> String
    {
        format!("{{x: {}, y: {}, direction: '{}'}}",x, y, bearing)
    }
    
    fn update(&mut self, x: i32, y: i32, bearing: &str) {
        self.call = format!("{{x: {}, y: {}, direction: '{}'}}", x, y, bearing);
    }
}

struct Instrument<'a> {
    radar:Radar,
    gyroscopes:Gyroscopes<'a>,
    engine:Engine,
    radio:Radio
}

impl Instrument<'_> {
    fn new() -> Instrument<'static> {
        let instrument = Instrument {
            radar: Radar {
                coordinate_x: 0,
                coordinate_y: 0
            },
            gyroscopes: Gyroscopes {
                needle: 0,
                compass: ["up","right","down","left"]
            },
            engine: Engine {
                thruster_x: [0, 1, 0, -1],
                thruster_y: [-1, 0, 1, 0]
            },
            radio: Radio {
                call: Radio::new(0, 0, String::from("North")),
            }
        };
        instrument
    }

    fn adjust_gyroscope(&mut self)
    {
        if self.gyroscopes.needle > DIRECTIONS as i32 - 1 {
            self.gyroscopes.needle = 0;
        } else if self.gyroscopes.needle < 0 {
            self.gyroscopes.needle = DIRECTIONS as i32 - 1;
        }
    }

    fn move_ship(&mut self, order : & String)
    {
        for ch in order.chars()
        {
            match ch {
                'R' => self.gyroscopes.needle += 1,
                'L' => self.gyroscopes.needle -= 1,
                'A' => self.radar.update(
                    self.engine.thruster_x[self.gyroscopes.needle as usize] as i32, 
                    self.engine.thruster_y[self.gyroscopes.needle as usize] as i32),
                _ => panic!("Unknown order. ABORT!")
            }
            self.adjust_gyroscope();
        }
            self.radio.update(
            self.radar.coordinate_x,
            self.radar.coordinate_y,
            self.gyroscopes.compass[self.gyroscopes.needle as usize]
            );
    }
}

fn my_spaceship(order: & String) ->String {

    let mut instrument = Instrument::new();
    instrument.move_ship(&order);
    instrument.radio.call
}