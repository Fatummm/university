#include <stdio.h>

void reversed_recursion(int n, int last) {
    if (n == 0) return;
    if (n % 2 != last) printf("%d", n % 2);
    reversed_recursion(n / 2, (n % 2 == last) ? -1 : n % 2);
}

void recursion(int n, int last) {
    if (n == 0) return;
    recursion(n / 2, (n % 2 == last) ? -1 : n % 2);
    if (n % 2 != last) printf("%d", n % 2);
}

int main() {
    int n; scanf("%d", &n);
    recursion(n, -1);
    printf("\n");
    reversed_recursion(n, -1);
}