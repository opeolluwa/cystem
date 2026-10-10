use std::str::FromStr;

pub struct Options {
    pub dirs: Vec<String>,
    pub app_name: Option<String>,
    pub use_cmake: Option<bool>,
    pub cmake_version: Option<String>,
    pub add_readme: Option<bool>,
}

fn parse_input<T: FromStr>(prompt: &str) -> Result<T, std::io::Error> {
    println!("{prompt}");

    let mut value = String::new();

    std::io::stdin().read_line(&mut value)?;
    let value = value.parse::<T>().map_err(|_| {
        std::io::Error::new(std::io::ErrorKind::Other, "failed to parse input into type")
    })?;

    Ok(value)
}

fn main() {
    println!("Hello, world!");
    let age = parse_input::<u8>("What is your age");
}
