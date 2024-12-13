#include <stdio.h>

int rem(int prev, int a){
    if (a == 0) return 0;
    rem((a % 2 == prev) ? -1 : a % 2, a / 2);
    if (a % 2 != prev) printf("%d", a % 2);
}

int rem_rev(int prev, int a){
    if (a == 0) return 0;
    if (a % 2 != prev) printf("%d", a % 2);
    rem_rev((a % 2 == prev) ? -1 : a % 2, a / 2);
}

int main(){
    int n;
    scanf("%d", &n);
    int x = rem(-1, n);
    printf("\n");
    int y = rem_rev(-1, n);
    //printf("\n");
    //printf("%d %d", x, y);
}
