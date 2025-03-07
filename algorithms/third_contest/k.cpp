#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>


double getFirstNumber(std::string& s) {
    double res = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (!('0' <= s[i] && s[i] <= '9')) {
            s.erase(0, i);
            return res;
        }
        res = res * 10 + (s[i] - 48);
        if (i + 1 == s.size()) s.clear();
    }
    
    return res;
}

struct Item {
    char operation = '=';
    double number = -1;
    Item(double n): number(n) {}
    Item(char c): operation(c) {}
};

int solveRPN(std::vector<Item> v) {
    std::vector<double> stack;
    for (int i = 0; i != v.size(); ++i) {
        if (v[i].operation == '=') stack.push_back(v[i].number);
        else {
            double a = stack.back(); stack.pop_back();
            double b = stack.back(); stack.pop_back();
            if (v[i].operation == '+') stack.push_back(a + b);
            else if (v[i].operation == '-') stack.push_back(b - a);
            else if (v[i].operation == '*') stack.push_back(a * b);
            else if (v[i].operation == '/') stack.push_back(b / a);
        }
    }
    return stack.back();
}

int main() {
    std::vector<char> stack;
    std::vector<Item> polish_notation;
    std::string s; std::cin >> s;
    //std::cout.setf(std::ios::fixed, std::ios::floatfield);
    //std::cout << std::fixed;
    std::cout.precision(100);
    std::cout << "Expression:\n" << s << '\n';
    while (!s.empty()) {
        if ('0' <= s[0] && s[0] <= '9') {
            polish_notation.push_back(Item(getFirstNumber(s)));
        }
        else if (s[0] != ')' && s[0] != '(') {
            
            if ((s[0] == '+' || s[0] == '-') && (!stack.empty() && (stack.back() == '*' || stack.back() == '/'))) {
                while (!stack.empty() && (stack.back() != '+' || stack.back() != '-') && stack.back() != '(') {
                    polish_notation.push_back(Item(stack.back())); stack.pop_back();
                }
            }
            else if (((s[0] == '+' || s[0] == '-') && (!stack.empty() && (stack.back() == '+' || stack.back() == '-'))) ||
            (s[0] == '*' || s[0] == '/') && (!stack.empty() && (stack.back() == '*' || stack.back() == '/'))) {
                polish_notation.push_back(Item(stack.back())); stack.pop_back();
            }
            stack.push_back(s[0]);
            s.erase(s.begin());
        }
        else if (s[0] == '(') {
            //std::cout << "SUKAAAA";
            stack.push_back(s[0]);
            s.erase(s.begin());
            //std::cout << *stack.begin();
        }
        else if (s[0] == ')') {
            
            while (!stack.empty() && stack.back() != '(') {
                polish_notation.push_back(Item(stack.back())); stack.pop_back();
            }
            stack.pop_back();
            //std::cout << "NOICE";
            
            s.erase(s.begin());
        }
    }
    while (!stack.empty()) {
        polish_notation.push_back(Item(stack.back()));
        stack.pop_back();
    }
    std::cout << "Reverse Polish Notation:\n";
    for (int i = 0; i != polish_notation.size(); ++i) {
        if (polish_notation[i].number == -1) std::cout << polish_notation[i].operation;
        else std::cout << polish_notation[i].number;//printf("%lf", polish_notation[i].number); //
        std::cout << ' ';
    }
    std::cout << "\nResult:\n";
    std::cout << solveRPN(polish_notation);
}