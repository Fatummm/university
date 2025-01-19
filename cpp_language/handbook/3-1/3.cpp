#include <iostream>
#include <list>
#include <string>

void MakeTrain() {
    std::list<int> trains;
    std::string command;
    int number;
    while (std::cin >> command) {
        std::cin >> number;
        if (command == "+left") trains.push_front(number);
        else if (command == "+right") trains.push_back(number);
        else if (command == "-left") {
            if ((size_t)number >= trains.size()) trains.clear();
            else {
                auto it = trains.begin();
                std::advance(it, number);
                trains.erase(trains.begin(), it);
            }
        }
        else {
            if ((size_t)number >= trains.size()) trains.clear();
            else {
                auto it = trains.end();
                std::advance(it, -number);
                trains.erase(it, trains.end());
            }
        }
    }
    for (auto elem: trains) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

// int main() {
//     MakeTrain();
// }