extern crate redis;
use redis::Commands;

pub struct DatabaseConnection {
    pub _connection: redis::Connection,
}

impl DatabaseConnection {
    pub fn new() -> DatabaseConnection {
        let client  = redis::Client::open("redis://127.0.0.1/").unwrap();
        let con = client.get_connection().unwrap();
        DatabaseConnection{ _connection: con }
    }
}

pub fn do_something() -> redis::RedisResult<()> {
    let client  = redis::Client::open("redis://127.0.0.1/")?;
    let mut connection = client.get_connection()?;
    let _: () = connection.set("my_key", 42)?;
    let value: i64 = connection.get("my_key")?;

    println!("{}", value);

    Ok(())
}
