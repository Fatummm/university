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
    return "\033[1J";
}

void set_brackets(unsigned int x, unsigned int y, Color foreground) {
    std::cout << set_color(foreground);
    if (y != 1) std::cout << set_cursor(x, y - 1) << '[';
    std::cout << set_cursor(x, y + 1) << ']' << set_color();
}

void remove_brackets(unsigned int x, unsigned int y) {
    if (y != 0) std::cout << set_cursor(x, y - 1) << ' ';
    std::cout << set_cursor(x, y + 1) << ' ';
}

int newgetch() { // not working: ¹ (251), num lock (-144), caps lock (-20), windows key (-91), kontext menu key (-93)
    struct termios term;
    tcgetattr(0, &term);
    while(true) {
        term.c_lflag &= ~(ICANON|ECHO); // turn off line buffering and echoing
        tcsetattr(0, TCSANOW, &term);
        int nbbytes;
        ioctl(0, FIONREAD, &nbbytes); // 0 is STDIN
        while(!nbbytes) {
            sleep(0.01);
            fflush(stdout);
            ioctl(0, FIONREAD, &nbbytes); // 0 is STDIN
        }
        int key = (int)getchar();
        term.c_lflag |= (ICANON|ECHO); // turn on line buffering and echoing
        tcsetattr(0, TCSANOW, &term);
        return key;
        
    }
}