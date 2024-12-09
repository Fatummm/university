#include <stdio.h>
#include <stdlib.h>


#define ll int
#define ld long double

int main() {
    ll n;
    scanf("%d", &n);
    ll * input = ( ll *) malloc (n * sizeof( ll ));
    ll sm = 0;
    int x;
    for (ll i = 0; i != n; ++i) {
        scanf("%d", &x);
        input[i] = x;
        sm += x;
    }
    ll * results = (ll *) malloc (sm * sizeof(ll));
    ll index = 0;
    for (int i = 0; i != sm; ++i) {
        if (input[index] == 0) index++;
        results[i] = index + 1;
        input[index]--;
    }
    ll m; scanf("%d", &m);
    ll * ans = (ll *) malloc (m * sizeof(ll));
    for (int i = 0; i != m; ++i) {
        scanf("%d", &x);
        ans[i] = results[x - 1];
    }

    for (int i = 0; i != m; ++i) {
        if (i != 0) printf("\n");
        printf("%d", ans[i]);
    }

    free(ans);
    free(input);
    free(results);
}