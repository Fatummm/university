#include <string>
#include <iostream>

class Serializer {
private:

public:
    virtual void BeginArray() = 0;
    virtual void AddArrayItem(const std::string &) = 0;
    virtual void EndArray() = 0;

    virtual ~Serializer() {}
};

class JsonSerializer: public Serializer {
private:
    bool started;
public:
    JsonSerializer(): started(false) {}
    void BeginArray() override {
        std::cout << '[';
        started = false;
    }

    void EndArray() override {
        std::cout << ']';
        started = true;
    }

    void AddArrayItem(const std::string& s) override {
        if (started) std::cout << ',';
        std::cout << '"' << s << '"';
        started = true; 
    }
};

int main() {
    JsonSerializer js;
    js.BeginArray();
    js.BeginArray();
    js.EndArray();
    js.EndArray();
}