#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <functional>
using namespace std;
class BloomFilter
{
private:
  static const int SIZE = 1000; // Size of bit array
  bitset<SIZE> bitArray;
  vector<hash<string>> hashFunctions;

public:
  BloomFilter(int numHashes = 3)
  {
    // Initialize multiple hash functions (using std::hash with different seeds)
    for (int i = 0; i < numHashes; ++i)
    {
      hashFunctions.push_back(hash<string>());
    }
  }

  void add(const string &item)
  {
    for (size_t i = 0; i < hashFunctions.size(); ++i)
    {
      size_t hash = hashFunctions[i](item + to_string(i)) % SIZE;
      bitArray.set(hash);
    }
  }

  bool check(const string &item) const
  {
    for (size_t i = 0; i < hashFunctions.size(); ++i)
    {
      size_t hash = hashFunctions[i](item + to_string(i)) % SIZE;
      if (!bitArray.test(hash))
      {
        return false;
      }
    }
    return true;
  }
};

// 🔧 Example usage
int main()
{
  BloomFilter bf;

  bf.add("apple");
  bf.add("banana");

  cout << std::boolalpha;
  cout << "apple: " << bf.check("apple") << "\n";   // true
  cout << "banana: " << bf.check("banana") << "\n"; // true
  cout << "cherry: " << bf.check("cherry") << "\n"; // false (probably)

  return 0;
}
