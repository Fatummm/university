#include <stdexcept>
#include <optional>
#include <map>
#include <vector>

template <typename Key1, typename Key2, typename Value>
class BiMap {
private:
    std::vector<Value> values;
    std::map<Key1, size_t> data1;
    std::map<Key2, size_t> data2;

public:
    // Вставить значение, указав один или оба ключа.
    // Генерирует исключение std::invalid_argument("some text") в случае,
    // если оба ключа пусты, либо один из ключей уже имеется в хранилище.
    void Insert(const std::optional<Key1>& key1, const std::optional<Key2>& key2, const Value& value) {
        if (key1.has_value() && key2.has_value()) {
            if (data1.find(key1.value()) == data1.end() && data2.find(key2.value()) == data2.end()) {
                data1.insert({key1.value(), values.size()});
                data2.insert({key2.value(), values.size()});
                values.push_back(value);
            }
            else throw std::invalid_argument("Some text");
        }
        else if (key1.has_value()) {
            if (data1.find(key1.value()) == data1.end()) {
                data1.insert({key1.value(), values.size()});
                values.push_back(value);
            }
            else throw std::invalid_argument("Some text");
        }
        else if (key2.has_value()) {
            if (data2.find(key2.value()) == data2.end()) {
                data2.insert({key2.value(), values.size()});
                values.push_back(value);
            }
            else throw std::invalid_argument("Some text");
        }
        else throw std::invalid_argument("Some text");
    }
    // Получить значение по ключу первого типа.
    // Генерирует исключение std::out_of_range("some text")
    // в случае отсутствия ключа (как и функция at в std::map).
    Value& GetByPrimaryKey(const Key1& key) {
        try {
            return values[data1.at(key)];
        } catch (...) {throw std::out_of_range("some text");}
    }
    const Value& GetByPrimaryKey(const Key1& key) const {
        try {
            return values[data1.at(key)];
        } catch (...) {throw std::out_of_range("some text");}
    }

    // Аналогичная функция для ключа второго типа.
    Value& GetBySecondaryKey(const Key2& key) {
        try {
            return values[data2.at(key)];
        } catch (...) {throw std::out_of_range("some text");}
    }
    const Value& GetBySecondaryKey(const Key2& key) const {
        try {
            return values[data2.at(key)];
        } catch (...) {throw std::out_of_range("some text");}
    }
};