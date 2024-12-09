#include <stdio.h>

int IsPalindrome(char * s, int ln) {
    if (ln <= 1) return 1;
    return (s[0] == s[ln - 1]) && IsPalindrome(s + 1, ln - 2);
}

int main() {
    printf("%d", IsPalindrome("12321", 5));
}