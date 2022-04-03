mod database;

use crate::database::database::do_something;

fn main() {
    let result = do_something();
    match result {
        Ok(_) => {
            println!("Hello World");
        }
        Err(_) => {
            println!("Error!");
        }
    }
}
