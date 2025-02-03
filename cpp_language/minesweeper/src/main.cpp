#include <iostream>
#include "terminal_config.h"
#include "minesweeper_funcs.h"

int main() {    
    Field f(30, 30, EASY);
    std::cout << clear_terminal() << set_cursor(0, 0);
    std::cout << f;
    char c;
    set_brackets(f.cursorx, f.cursory, MAGENTA);
    std::cout << set_cursor(30 + 1, 0);
    int nn = 0;
    while (true) {
        c = newgetch();
        remove_brackets(f.cursorx, f.cursory);
        Command com = Process(c);
        Execute(com, f);
        if (com == SPECIAL) {
            if (nn++ % 2 == 0) f.Close();
            else f.Open();
            std::cout << clear_terminal();
            std::cout << set_cursor(0, 0) << f;
        }
        
        set_brackets(f.cursorx, f.cursory, MAGENTA);
        std::cout << set_cursor(30 + 1, 0);
        
    }
}