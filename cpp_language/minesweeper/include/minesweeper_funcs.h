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
    Type type;
    bool opened;
    bool marked;
    unsigned bombs_nearby;
    Item(Type t, bool o, bool m, unsigned b): type(t), opened(o), marked(m), bombs_nearby(b) {}
};

class Field {
private:

public:

};
std::ostream& operator << (std::ostream& out, const Item& item);
