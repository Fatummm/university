#include <stdio.h>

long long get_pow(long long a, long long b) {
    long long n = 1;
    for (long long i = 0; i != b; ++i) {
        n *= a;
    }
    return n;
}

int main() {
    long long a, b;
    scanf("%d %d", &a, &b);
    long long first_a = a % get_pow(2, 8);
    long long second_a = a % get_pow(2, 16) / get_pow(2, 8);
    long long third_a = a % get_pow(2, 24) / get_pow(2, 16);
    long long fourth_a = a % get_pow(2, 32) / get_pow(2, 24);

    long long first_b = b % get_pow(2, 8);
    long long second_b = b % get_pow(2, 16) / get_pow(2, 8);
    long long third_b = b % get_pow(2, 24) / get_pow(2, 16);
    long long fourth_b = b % get_pow(2, 32) / get_pow(2, 24);
    first_a *= first_b; if (first_a > 255) first_a = 255;
    second_a *= second_b; if (second_a > 255) second_a = 255;
    third_a *= third_b; if (third_a > 255) third_a = 255;
    fourth_a *= fourth_b; if (fourth_a > 255) fourth_a = 255;
    printf("%ld", first_a + second_a * get_pow(2, 8) + third_a * get_pow(2, 16) + fourth_a * get_pow(2, 24));
}