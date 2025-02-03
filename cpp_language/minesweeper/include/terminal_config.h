#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <sys/ioctl.h>
#include <termios.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>

enum Color {
    NONE = 0,
    BLACK, RED, GREEN,
    YELLOW, BLUE, MAGENTA,
    CYAN, WHITE
};

std::string set_color(Color foreground = NONE);
std::string set_cursor(unsigned int row, unsigned int column);
std::string clear_terminal();
int newgetch();
void set_brackets(unsigned int x, unsigned int y, Color foreground = NONE);
void remove_brackets(unsigned int x, unsigned int y);
