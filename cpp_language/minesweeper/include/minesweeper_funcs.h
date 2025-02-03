#pragma once

#include <iostream>
#include <vector>
// * - bomb
// ? - miracle
// [ ] - selected
// 1-8 - how many bombs are nearby
// 
enum Type {
    NOTBOMB, BOMB
};

struct Item {
    Type type = NOTBOMB;
    bool opened = false;
    bool marked = false;
    unsigned bombs_nearby = 0;
    Item(Type t, bool o, bool m, unsigned b): type(t), opened(o), marked(m), bombs_nearby(b) {}
    Item() {}
};

enum Difficulty {
    EASY, NORMAL, HARD, EXTREME
};

class Field {
private:
    std::vector<std::vector<Item>> data;
    size_t rows = 0, columns = 0;
    void Generate(Difficulty);
public:
    size_t cursorx = 0, cursory = 2;
    bool opened = true;
    Field(size_t, size_t, Difficulty);
    size_t GetRows() const;
    size_t GetColumns() const;

    Item GetAt(size_t row, size_t column) const;
    void Open();
    void Close();
    void OpenAt(size_t i, size_t j);
    void MarkAt(size_t i, size_t j);
    

};

enum Command {
    EXIT, UP, DOWN, LEFT, RIGHT, MARK, OPEN, SPECIAL, NOTHING
};

void Execute(Command cm, Field& f);
Command Process(char c);
std::ostream& operator << (std::ostream& out, const Item& item);
std::ostream& operator << (std::ostream& out, const Field& f);