    #include <iostream>
    #include <stdexcept>
    #include <vector>
    #include <memory>

    #include "animals.h"

    using Zoo = std::vector<std::shared_ptr<Animal>>;

    Zoo CreateZoo() {
        Zoo zoo;
        std::string word;
        while (std::cin >> word) {
            if (word == "Tiger") {
                zoo.push_back(std::make_shared<Tiger>());
            } else if (word == "Wolf") {
                zoo.push_back(std::make_shared<Wolf>());
            } else if (word == "Fox") {
                zoo.push_back(std::make_shared<Fox>());
            } else
                throw std::runtime_error("Unknown animal!");
        }
        return zoo;
    }

    void Process(const Zoo& zoo) {
        for (const auto& animal : zoo) {
            std::cout << animal->Voice() << "\n";
        }
    }

int main() {
    Zoo z = CreateZoo();
    Process(z);
}