#include "minesweeper_funcs.h"


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
        out << std::endl;
    }
    out << "Bombs left: " << f.BombsLeft() << std::endl;
    for (size_t i = 0; i != f.comments.size(); ++i) {
        out << f.comments.at(i) << std::endl;
    }
    return out;
}

Item Field::GetAt(size_t row, size_t column) const {
    return data.at(row).at(column);
}

Field::Field(size_t r, size_t c, size_t bombs): rows(r), columns(c), unmarked_bombs(bombs) {
    Generate(bombs);
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
        not_over = false;
        Loss();
    }
}

void Field::Generate(size_t bombs) {
    srand(time(NULL));
    std::vector<std::string> s;
    s.push_back("W, A, S, D - moving");
    s.push_back("F - mark");
    s.push_back("Enter - open cell");
    //SetInstructions(s);
    comments.resize(s.size());
    std::copy(s.begin(), s.end(), comments.begin());
    // count the difficulty and amount of bombs via percentage
    int bombs_left = bombs;
    // resize
    data.resize(rows);
    for (size_t i = 0; i != rows; ++i) data.at(i).resize(columns);

    // filling the field with bombs
    while (bombs_left > 0) {
        for (size_t i = 0; i != rows; ++i) {
            for (size_t j = 0; j != columns; ++j) {
                if (rand() % rows*columns == 0 && bombs_left != 0 && data.at(i).at(i).type != BOMB) {
                    --bombs_left;
                    // current Item - bomb
                    Item item(BOMB, false, false, 0);
                    data.at(i).at(j) = item;
                }
            }
        }
    }
    
    // counting bombs_nearby
    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != columns; ++j) {
            if (data.at(i).at(j).type == BOMB) continue;
            else data.at(i).at(j) = Item(NOTBOMB, false, false, 0);
            for (size_t x = ((i == 0) ? 0: i - 1); x != std::min(i + 2, rows); ++x) {
                for (size_t y = ((j == 0) ? 0: j - 1); y != std::min(j + 2, columns); ++y) {
                    data.at(i).at(j).bombs_nearby += (data.at(x).at(y).type == BOMB);
                }
            }
        }
    }
}

void Field::MarkAt(size_t i, size_t j) {
    if (data.at(i).at(j).marked == true) {
        data.at(i).at(j).marked = false;
        unmarked_bombs += (data.at(i).at(j).type == BOMB);
        if (data.at(i).at(j).type == BOMB) std::cout << clear_terminal() << set_cursor(0, 0) <<
        *this << set_cursor(rows + 1,0) << "Bombs left: " << unmarked_bombs << std::endl;
        }
    else {
        data.at(i).at(j).marked = true;
        unmarked_bombs -= (data.at(i).at(j).type == BOMB);
        if (data.at(i).at(j).type == BOMB) std::cout << clear_terminal() << set_cursor(0, 0) <<
        *this << set_cursor(rows + 1,0) << "Bombs left: " << unmarked_bombs << std::endl;
    }
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
        case 10: {
            return OPEN; break;
        }
        case 'F': case 'f': {
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
    if (cm == LEFT && f.cursory > 2) {
        remove_brackets(f.cursorx, f.cursory);
        f.cursory -= 2;
        set_brackets(f.cursorx, f.cursory, MAGENTA);
        }
    else if (cm == RIGHT && f.cursory / 2 < f.GetColumns()) {
        remove_brackets(f.cursorx, f.cursory);
        f.cursory += 2;
        set_brackets(f.cursorx, f.cursory, MAGENTA);
        }
    else if (cm == UP && f.cursorx > 1) {
        remove_brackets(f.cursorx, f.cursory);
        --f.cursorx;
        set_brackets(f.cursorx, f.cursory, MAGENTA);
        }
    else if (cm == DOWN && f.cursorx < f.GetRows()) {
        remove_brackets(f.cursorx, f.cursory);
        ++f.cursorx;
        set_brackets(f.cursorx, f.cursory, MAGENTA);
        }
    else if (cm == MARK) {
        f.MarkAt(f.cursorx - 1, f.cursory / 2 - 1);
        std::cout << "\007" << set_cursor(f.cursorx, f.cursory) << f.GetAt(f.cursorx - 1, f.cursory / 2 - 1);
    }
    else if (cm == SPECIAL) {
        if (f.opened) f.Close();
        else f.Open();
        std::cout << clear_terminal() << set_cursor(0, 0) << f;
        set_brackets(f.cursorx, f.cursory, MAGENTA);
    }
    else if (cm == OPEN) {
        f.OpenAt(f.cursorx - 1, f.cursory / 2 - 1);
    }
    if (f.BombsLeft() == 0) {
        f.Victory();
        f.not_over = false;
    }
}
/*
void Victory();
void Loss();
void SetInstructions(std::vector<std::string> v = {});
void DeleteInstructions();
*/
void Field::Victory() {
    //comments.clear();
    comments.push_back("Congratulations! You have won!");
    std::cout << clear_terminal() << set_cursor(0, 0) << *this;
}

size_t const Field::BombsLeft() const {
    return unmarked_bombs;
}

void Field::Loss() {
    //comments.clear();
    comments.push_back("What a misery! You have lost!");
    std::cout << clear_terminal() << set_cursor(0, 0) << *this;
}
