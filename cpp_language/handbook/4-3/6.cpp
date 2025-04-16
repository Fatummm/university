#include <iostream>
#include <chrono>

// TimerGuard(std::string message = "", std::ostream& out = std::cout);

class TimerGuard {
private:
    std::chrono::high_resolution_clock::time_point start;
    std::ostream& output;
    std::string msg;
public:
    TimerGuard(std::string message = "", std::ostream& out = std::cout): output(out), msg(message) {
        start = std::chrono::high_resolution_clock::now();
    }

    ~TimerGuard() {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> df = std::chrono::high_resolution_clock::now() - start;
        output << msg << ' ' << df.count() << '\n';
    }
};

int main() {

}