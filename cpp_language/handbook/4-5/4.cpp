#include <iostream>
#include <string>

class LoggerGuard {
private:
    std::string msg;
    std::ostream& out_stream;
public:
    LoggerGuard(const std::string& message, std::ostream& out = std::cout): msg(message), out_stream(out) {}

    ~LoggerGuard() {
        out_stream << msg << '\n';
    }
};

int SomeFunction() {return 1;}

int SomeOtherFunction() {return 1;}
int FinalFunction() {
    throw std::invalid_argument("Some text");
    return 1;
}

int Function() {
    LoggerGuard logger("Function completed");

    int value = 1;
    try {
        value = SomeFunction();
        if (value == 0) {
            return value;
        }

        value = SomeOtherFunction();
        if (value == 0) {
            return value;
        }

        value = FinalFunction();  // might throw an exception
    } catch (...) {
        throw;  // throws the exception further.
    }

    return value;
}

int main() {
    Function();
}