#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>

template <typename Key, typename Value>
class KeyValueStorage {
private:
      std::unordered_map<Key, Value> data;

public:
    void Insert(const Key& key, const Value& value) {
        data[key] = value;
    }

    void Remove(const Key& key) {
        data.erase(key);
    }

    bool Find(const Key key, Value* const value = nullptr) const;
};


// Почему-то не работает...

template <typename Key, typename Value>
bool KeyValueStorage<Key, Value>::Find(const Key key, Value* value) const {
    //auto it = std::find(data.begin(), data.end(), key);
    auto it = data.find(key);
    if (it == data.end()) return false;
    std::cout << it->second << '\n';
    auto val = it->second;
    if (value != nullptr)
        *value = val;
    return true;
}



int main() {
    KeyValueStorage<std::string, int> kv;
    kv.Insert("hello", 42);
    kv.Insert("bye", -13);
    int value = 123;
    auto res = kv.Find("wrong", &value);  // должно вернуться false, а value не должен меняться
    std::cout << value << '\n';
    res = kv.Find("bye", &value);  // должно вернуться true, в value должно быть -13
    std::cout << value << '\n';
    res = kv.Find("hello", nullptr);  // должно вернуться true
    std::cout << value << '\n';
    std::cout << "WOW\n";
}
