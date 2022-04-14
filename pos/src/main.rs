mod database;

//use crate::database::database::DatabaseConnection;
use crate::database::database::Entity;
use redis::Commands;

fn main() {
    let client = redis::Client::open("redis://127.0.0.1/").unwrap();
    let mut connection = client.get_connection().unwrap();
    match connection.set::<&str, Entity, ()>("Hello", Entity { x: 100 }) {
        Ok(_) => {
            println!("Hello:");
        }
        Err(err) => {
            println!("{}", err);
        }
    }
    let size: u64 = redis::cmd("dbsize").query(&mut connection).unwrap();
    println!("{}", size);

    //let mut database_given = DatabaseConnection::new();
    //match database_given.insert("Hello World This", Entity { x: 100 }) {
    //Ok(_) => {
    //println!("Success");
    //}
    //Err(err) => {
    //println!("{:?}", err)
    //}
    //}
    //match database_given.get::<Entity>("Hello World This") {
    //Ok(result) => { println!("{:?}", result.unwrap().x); }
    ////Ok(value) => { println!("herro: {}", value.unwrap().x); }
    //Err(err) => { println!("nope: {}", err); }
    //}
}
