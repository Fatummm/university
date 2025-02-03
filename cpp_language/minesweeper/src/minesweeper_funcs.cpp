#include "minesweeper_funcs.h"
#include "terminal_config.h"

std::ostream& operator << (std::ostream& out, const Item& item) {
    if (item.opened && item.type == BOMB) {
        out << set_color(RED) << '*' << set_color();
    }
    else if (item.opened && item.bombs_nearby == 0) {
        out << ' ';
    }
    else if (item.opened) {
        out << set_color(CYAN) << item.bombs_nearby << set_color();
    }
    else if (item.marked) {
        out << set_color(MAGENTA) << '?' << set_color();
    }
    else {
        out << '?';
    }
    return out;
}

std::ostream& operator << (std::ostream& out, const Field& f) {
    for (size_t i = 0; i != f.GetRows(); ++i) {
        for (size_t j = 0; j != f.GetColumns(); ++j) {
            //if (j != 0) out << ' ';
            out << ' ' << f.GetAt(i, j);
        }
        out << '\n';
    }
    return out;
}

Item Field::GetAt(size_t row, size_t column) const {
    return data.at(row).at(column);
}

Field::Field(size_t r, size_t c, Difficulty d): rows(r), columns(c) {
    Generate(d);
}

size_t Field::GetColumns() const {
    return columns;
}

size_t Field::GetRows() const {
    return rows;
}

void Field::OpenAt(size_t i, size_t j) {
    if (data.at(i).at(j).type == NOTBOMB) {
        if (data.at(i).at(j).opened) return;
        data.at(i).at(j).opened = true;
        std::cout << set_cursor(i + 1, (j + 1) * 2) << data.at(i).at(j);
        if (data.at(i).at(j).bombs_nearby != 0) return;
        //size_t x = i - 1, y = j;
        //while (x >= 0)
        if (i != 0) OpenAt(i - 1, j);
        if (i + 1 < rows) OpenAt(i + 1, j);
        if (j != 0) OpenAt(i, j - 1);
        if (j + 1 < columns) OpenAt(i, j + 1);
    }
    else {
        data.at(i).at(j).opened = true;
        std::cout << set_cursor(i + 1, (j + 1) * 2) << data.at(i).at(j);
    }
}

void Field::Generate(Difficulty dif) {
    srand(time(NULL));
    // count the difficulty and amount of bombs via percentage
    unsigned percentage = 10 + 6 * dif;
    unsigned bombs_left = rows * columns * percentage / 100;

    // resize
    data.resize(rows);
    for (size_t i = 0; i != rows; ++i) data.at(i).resize(columns);

    // filling the field with bombs
    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != columns; ++j) {
            if (rand() % 100 < percentage && bombs_left-- != 0) {
                // current Item - bomb
                Item item(BOMB, true, false, 0);
                data.at(i).at(j) = item;
            }
        }
    }
    // counting bombs_nearby
    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != columns; ++j) {
            if (data.at(i).at(j).type == BOMB) continue;
            else data.at(i).at(j) = Item(NOTBOMB, true, false, 0);
            for (size_t x = ((i == 0) ? 0: i - 1); x != std::min(i + 2, rows); ++x) {
                for (size_t y = ((j == 0) ? 0: j - 1); y != std::min(j + 2, columns); ++y) {
                    data.at(i).at(j).bombs_nearby += (data.at(x).at(y).type == BOMB);
                }
            }
        }
    }
}

void Field::MarkAt(size_t i, size_t j) {
    if (data.at(i).at(j).marked == true) data.at(i).at(j).marked = false;
    else data.at(i).at(j).marked = true;
}

void Field::Open() {
    opened = true;
    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != columns; ++j) {
            data.at(i).at(j).opened = true;
        }
    }
}

void Field::Close() {
    opened = false;
    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != columns; ++j) {
            data.at(i).at(j).opened = false;
        }
    }
}

Command Process(char c) {
    switch (c) {
        case 'W': case 'w': {
            return UP; break;
        }
        case 'D': case 'd': {
            return RIGHT; break;
        }
        case 'S': case 's': {
            return DOWN; break;
        }
        case 'A': case 'a': {
            return LEFT; break;
        }
        case ' ': {
            return OPEN; break;
        }
        case 10: {
            return MARK; break;
        }
        case 27: {
            return EXIT; break;
        }
        case '0': {
            return SPECIAL; break;
        }
        default: return NOTHING;
    }
}

void Execute(Command cm, Field& f) {
    if (cm == LEFT && f.cursory > 2) f.cursory -= 2;
    else if (cm == RIGHT && f.cursory / 2 < f.GetColumns()) f.cursory += 2;
    else if (cm == UP && f.cursorx > 1) --f.cursorx;
    else if (cm == DOWN && f.cursorx < f.GetRows()) ++f.cursorx;
    else if (cm == MARK) {
        f.MarkAt(f.cursorx - 1, f.cursory / 2 - 1);
        std::cout << "\007" << set_cursor(f.cursorx, f.cursory) << f.GetAt(f.cursorx - 1, f.cursory / 2 - 1);
    }
    else if (cm == SPECIAL) {
        if (f.opened) f.Close();
        else f.Open();
        std::cout << clear_terminal() << f;
    }
    else if (cm == OPEN) {
        f.OpenAt(f.cursorx - 1, f.cursory / 2 - 1);
    }
}

