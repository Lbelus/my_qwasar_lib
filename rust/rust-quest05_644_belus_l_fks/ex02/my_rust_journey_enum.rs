enum Action {
    Timer(u32),
    Weather(String),
    Music(String)
}

fn dispatch(action: Action) {
    match action
    {
        Action::Timer(value) => println!("AI -- Timer requested {}", value),
        Action::Weather(text) => println!("AI -- Weather for this city {} requested", text),
        Action::Music(text) => println!("AI -- Play following song requested {}", text)
    }
}

fn main() {
    dispatch(Action::Timer(32));
    dispatch(Action::Music("Fly -- Ludovico Einaudi".to_string()));
    dispatch(Action::Weather("Sedona - Arizona".to_string()));
} 