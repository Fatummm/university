#include <iostream>
#include <list>
#include <string>

int main() {
    std::list<std::string> file;
    std::string line;
    while (std::getline(std::cin, line)) {
        file.push_back(line);
        if (line == "") break;
    }
    std::string command;
    std::string buffer = "";
    std::list<std::string>::iterator cursor = file.begin();
    while (std::getline(std::cin, command)) {
        if (command == "") break;
        if (command == "Ctrl+X" && *cursor != "") {
            auto cur = cursor;
            cursor++;
            buffer = *cur;
            file.erase(cur);
        }
        else if (command == "Ctrl+V" && buffer != "") {
            file.insert(cursor, buffer);
        }
        else if (command == "Down") {
            if (++cursor == file.end()) --cursor;
        }
        else if (command == "Up") {
            if (cursor != file.begin()) --cursor;
        }
    }
    for (cursor = file.begin(); cursor != file.end(); ++cursor) {
        std::cout << *cursor << std::endl;
    }
    
}