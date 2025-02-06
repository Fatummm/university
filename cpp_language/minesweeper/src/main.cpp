#include <iostream>
#include "terminal_config.h"
#include "minesweeper_funcs.h"
#include "bruteforce.h"


void StartMineSweeper() {
    size_t n;
    std::cout << "Enter size of the field: ";
    std::cin >> n;
    size_t bombs;
    std::cout << "Enter amount of bombs: ";

    std::string s;

    std::cin >> bombs;
    Field f(n, n, bombs);


    
    std::cout << "Who will play? [0 - user, 1 - bot]";
    std::cin >> n;
    getline(std::cin, s);
    
    

    if (n == 1) {
        f.comments.clear();
        std::cout << clear_terminal() << set_cursor(0, 0) << f;
        std::cout << set_cursor(f.GetRows() + f.comments.size() + 2, 0);
        Solve(f);
    }
    else {
        std::cout << clear_terminal() << set_cursor(0, 0) << f;
        std::cout << set_cursor(f.GetRows() + f.comments.size() + 2, 0);
        while (f.not_over) {
            Execute(Process(newgetch()), f);
            std::cout << set_cursor(f.GetRows() + f.comments.size() + 2, 0);
        }
    }   

    std::cout << clear_terminal() << set_cursor(0, 0) << f;
    std::cout << set_cursor(f.GetRows() + f.comments.size() + 2, 0);
}

int main() {
    StartMineSweeper();
}
