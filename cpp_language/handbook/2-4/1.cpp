#include <iostream>
#include <string>

int main() {
    std::string password;
    std::cin >> password;
    std::string bolsh = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string smol = "abcdefghijklmnopqrstuvwxyz";
    std::string cifri = "0123456789";
    int big = 0, small = 0, digits = 0, special = 0, good = 1;
    for (size_t i = 0; i != password.size(); ++i) {
        if ((int)bolsh.find(password[i]) != -1) big++;
        else if ((int)smol.find(password[i]) != -1) small++;
        else if ((int)cifri.find(password[i]) != -1) digits++;
        else special++;
        if (!(33 <= password[i] && password[i] <= 126)) good = 0;
    }
    if (good && (big + small + digits + special >= 3) && (password.size() >= 4 && password.size() <= 14)) std::cout << "YES";
    else std::cout << "NO";
}