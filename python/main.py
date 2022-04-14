import dataclasses
import pickle
import redis
import typing


@dataclasses.dataclass
class Entity:
    x: int


class DatabaseConnection:
    def __init__(self):
        self._connection = redis.StrictRedis(host="localhost", port=6379)

    def insert(self, key: str, value: typing.Any):
        """Insert custom structure by converting to a byte array"""

        self._connection.set(key, pickle.dumps(value))

    def get(self, value: str) -> Entity:
        """Render the byte array as an Entity structure"""

        return pickle.loads(self._connection.get(value))


D = DatabaseConnection()
D.insert("Hello", Entity(x=10))
print(D.get("Hello"))
