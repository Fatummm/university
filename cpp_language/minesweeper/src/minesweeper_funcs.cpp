#include "minesweeper_funcs.h"
#include "terminal_config.cpp"


std::string set_color(Color foreground);

std::ostream& operator << (std::ostream& out, const Item& item) {
    if (item.opened && item.type == BOMB) {
        out << set_color(RED) << '*' << set_color();
    }
    else if (item.opened && item.bombs_nearby == 0) {
        out << ' ';
    }
    else if (item.opened) {
        out << item.bombs_nearby;
    }
    else if (item.marked) {
        out << set_color(MAGENTA) << '?' << set_color();
    }
    return out;
}
// 16%
class Field {
private:
    std::vector<std::vector<Item>> data;
    size_t rows, columns;
    void Generate
public:


};

