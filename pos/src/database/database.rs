extern crate redis;
use redis::Commands;
use serde::{Deserialize, Serialize};

#[derive(Serialize, Deserialize)]
pub struct Entity {
    pub x: i32,
}

impl redis::FromRedisValue for Entity {
    fn from_redis_value(v: &redis::Value) -> redis::RedisResult<Self> {
        let v: i32 = redis::from_redis_value(v)?;
        Ok(Entity { x: v })
    }
}

//the trait bound `redis::Iter<'_, Entity>: FromRedisValue` is not satisfied: the trait `FromRedisValue` is not implemented for `redis::Iter<'_, Entity>`
impl redis::ToRedisArgs for Entity {
    fn write_redis_args<W>(&self, out: &mut W)
    where
        W: ?Sized + redis::RedisWrite,
    {
        let encoded = bincode::serialize(&self).unwrap();
        out.write_arg(&encoded);
    }
}

pub struct DatabaseConnection {
    pub _connection: redis::Connection,
}

impl DatabaseConnection {
    pub fn new() -> DatabaseConnection {
        let client = redis::Client::open("redis://127.0.0.1/").unwrap();
        let con = client.get_connection().unwrap();
        DatabaseConnection { _connection: con }
    }
    pub fn get<T>(&mut self, name: &str) -> redis::RedisResult<Option<T>>
    where
        T: redis::FromRedisValue,
    {
        self._connection.get(name)
    }
    pub fn insert(&mut self, name: &str, value: Entity) -> redis::RedisResult<()> {
        self._connection.set(name, value)
    }
    pub fn size(&mut self) -> usize {
        redis::cmd("dbsize").query(&mut self._connection).unwrap()
    }
    pub fn print_keys(&mut self) -> Result<(), ()> {
        Ok(())
        //redis::cmd("KEYS").arg("*").execute(&mut self._connection)
    }
}

pub fn do_something() -> redis::RedisResult<()> {
    let client = redis::Client::open("redis://127.0.0.1/")?;
    let mut connection = client.get_connection()?;
    let _: () = connection.set("my_key", 42)?;
    let value: i64 = connection.get("my_key")?;

    println!("{}", value);

    Ok(())
}
