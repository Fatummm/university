#include <stdio.h>

int sm_digits(int n) {
    if (n == 0) return 0;
    return n % 10 + sm_digits(n / 10);
}

int main() {
    printf("%d", sm_digits(53));
}