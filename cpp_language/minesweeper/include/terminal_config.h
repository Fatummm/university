#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>

enum Color {
    NONE = 0,
    BLACK, RED, GREEN,
    YELLOW, BLUE, MAGENTA,
    CYAN, WHITE
};

std::string set_color(Color foreground = NONE);
std::string set_cursor(unsigned int row, unsigned int column);
std::string clear_terminal();
char getch();
void set_brackets(unsigned int x, unsigned int y, Color foreground = NONE);
