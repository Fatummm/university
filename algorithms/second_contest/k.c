#include <stdio.h>

int min(int a, int b) {
    return (a > b) ? b : a;
}

int max(int a, int b) {
    return (a < b) ? b : a;
}

int f(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return f(20, 20, 20);
    if (a < b && b < c) return f(a, b, c-1) + f(a, b-1, c-1) - f(a, b-1, c);
    return f(a-1, b, c) + f(a-1, b-1, c) + f(a-1, b, c-1) - f(a-1, b-1, c-1);
}

int main() {
    int ans[21][21][21];
    for (int a = 0; a != 21; ++a) {
        for (int b = 0; b != 21; ++b) {
            for (int c = 0; c != 21; ++c) {
                if (a <= 0 || b <= 0 || c <= 0) ans[a][b][c] = 1;
                else if (a < b && b < c) ans[a][b][c] = ans[a][b][c-1] + ans[a][b-1][c-1] - ans[a][b-1][c];
                else ans[a][b][c] = ans[a-1][b][c] + ans[a-1][b-1][c] + ans[a-1][b][c-1] - ans[a-1][b-1][c-1];
            }
        }
    }
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    a = max(0, a); b = max(0, b); c = max(0, c);
    a = min(20, a); b = min(20, b), c = min(20, c);
    if (a == 0 || b == 0 || c == 0) {
        a = 0; b = 0; c = 0;
    }
    if (a == 20 || b == 20 || c == 20) {
        a = 20; b = 20; c = 20;
    }
    printf("%d\n", ans[a][b][c]);
    //printf("%d", f(a, b, c));
}