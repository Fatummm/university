#include <stdio.h>

void prin(int n) {
    if (n == 1) printf("%d ", n);
    else {
        prin(n - 1);
        printf("%d ", n);
    }
}

int main() {
    prin(4);
}