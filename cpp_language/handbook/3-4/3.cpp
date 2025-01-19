#include <queue>
#include <iostream>
#include <string>

int main() {
    std::priority_queue<int> q;
    std::string command;
    while (std::cin >> command) {
        if (command == "ADD") {
            int x; std::cin >> x;
            q.push(x);
        }
        else if (command == "EXTRACT") {
            if (q.empty()) std::cout << "CANNOT" << std::endl;
            else {
                std::cout << q.top() << std::endl;
                q.pop();
            }
        }
        else if (command == "CLEAR") {
            while (!q.empty()) q.pop();
        }
    }
}