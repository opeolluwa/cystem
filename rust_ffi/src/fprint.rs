#[unsafe(no_mangle)]
pub extern "C" fn print_new_line(s: &str) {
    println!(s);
}
