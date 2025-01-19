#include <stack>
#include <iostream>

int main() {
    bool flag = true;
    std::stack<char> st;
    char c;
    while (std::cin >> c) {
        if (c == '{' || c == '[' || c == '(') st.push(c);
        else {
            if (st.empty()) flag = false;
            else if (c == '}' && st.top() != '{') flag = false;
            else if (c == ']' && st.top() != '[') flag = false;
            else if (c == ')' && st.top() != '(') flag = false;
            else st.pop();
        }
    }
    if (!st.empty() || !flag) std::cout << "NO" << std::endl;
    else std::cout << "YES" << std::endl;
}