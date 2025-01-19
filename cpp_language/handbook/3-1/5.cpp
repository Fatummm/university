#include <iostream>
#include <list>
#include <string>

void InsertFromBuffer(std::list<std::string>& file, 
std::list<std::string>& buffer, 
std::list<std::string>::iterator& position) {

    for (auto it = buffer.begin(); it != buffer.end(); ++it) {
        file.insert(position, *it);
    }
    // std::list<std::string>::iterator it = buffer.begin();
    // while (it != buffer.end()) {
    //     position = file.insert(position, *it);
    //     it++;
    // }
}

int main() {
    std::list<std::string> file;
    std::string line;
    while (std::getline(std::cin, line)) {
        file.push_back(line);
        if (line == "") break;
    }
    std::string command;
    std::list<std::string> buffer;
    std::list<std::string>::iterator cursor = file.begin(), start;
    bool shift = false;
    int shifted = 0;
    while (std::getline(std::cin, command)) {
        if (command == "") break;
        if (command == "Shift") {
            shift = true;
            start = cursor;
        }
        else if (command == "Ctrl+X") {
            if ((!shift && *cursor != "") || (shift && shifted == 0)) {
                shift = false;
                shifted = 0;
                buffer.clear();
                buffer.push_back(*cursor);
                cursor = file.erase(cursor);
            }
            else if (shift) {
                buffer.clear();
                if (shifted > 0) {
                    auto cur = cursor;
                    buffer.splice(buffer.begin(), file, start, cursor);
                    cursor = cur;
                }
                else {
                    auto cur = start;
                    buffer.splice(buffer.begin(), file, cursor, start);
                    cursor = cur;
                }
                shifted = 0;
                shift = false;
            }
        }
        else if (command == "Ctrl+V") {
            if (shifted > 0) cursor = file.erase(start, cursor);
            else if (shifted < 0) cursor = file.erase(cursor, start);
            InsertFromBuffer(file, buffer, cursor);
            //file.splice(cursor, buffer);
            shifted = 0;
            shift = false;
            
        }
        else if (command == "Down") {
            if (shift) shifted++;
            if (++cursor == file.end()) --cursor;
        }
        else if (command == "Up") {
            if (shift) shifted--;
            if (cursor != file.begin()) --cursor;
        }
    }
    // std::cout << file.size() << std::endl;
    for (cursor = file.begin(); cursor != file.end(); ++cursor) {
        std::cout << *cursor << std::endl;
    }
    // std::cout << "Buffer\n";
    // for (auto it = buffer.begin(); it != buffer.end(); ++it) {
    //     std::cout << *it << '\n';
    // }
    
}