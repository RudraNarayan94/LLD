import math
import mmh3  # MurmurHash
from bitarray import bitarray

class BloomFilter:
    def __init__(self, size: int, hash_count: int):
        self.size = size
        self.hash_count = hash_count
        self.bit_array = bitarray(size)
        self.bit_array.setall(0)

    def add(self, item: str):
        for i in range(self.hash_count):
            index = mmh3.hash(item, i) % self.size
            self.bit_array[index] = 1

    def check(self, item: str) -> bool:
        for i in range(self.hash_count):
            index = mmh3.hash(item, i) % self.size
            if self.bit_array[index] == 0:
                return False
        return True

# Example usage
bf = BloomFilter(size=5000, hash_count=7)
bf.add("apple")
bf.add("banana")

print(bf.check("apple"))   # True
print(bf.check("banana"))  # True
print(bf.check("cherry"))  # False (probably)
