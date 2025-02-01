#include "terminal_config.h"

std::string set_color(Color foreground) {
    std::stringstream s;
    s << "\033[";
    if (!foreground){
        s << "0"; // reset colors if no params
    }
    if (foreground) {
        s << 29 + foreground;
    }
    s << "m";
    return s.str();
}

std::string set_cursor(unsigned int row, unsigned int column) {
    std::stringstream s;
    s << "\033[" << row << ";" << column << 'H';
    return s.str();
}

std::string clear_terminal() {
    return "\033[2J";
}

char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}

void set_brackets(unsigned int x, unsigned int y, Color foreground) {
    std::cout << set_color(foreground);
    if (y != 0) std::cout << set_cursor(x, y - 1) << '[';
    std::cout << set_cursor(x, y + 1) << ']' << set_color();
}