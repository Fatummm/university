#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, size_t b) {
    return (a > b) ? a: b;
}

int get_digit(char * string, int number) {
    int counter = 1;
    for (int i = 99; i != -1; --i) {
        if (string[i] != '\0' && counter == number) return string[i];
        else if (string[i] != '\0') counter++;
    }
    return 48;
}

int main() {
    int n; scanf("%d", &n);
    char ** strings = (char **) malloc (n * sizeof(char *));
    int mxln = 0;
    for (int i = 0; i != n; ++i) {
        strings[i] = (char *) malloc (100 * sizeof(char));
        for (int j = 0; j != 100; ++j) strings[i][j] = '\0';
        scanf("%s", strings[i]);
        mxln = max(mxln, strlen(strings[i]));
    }
    for (int x = 0; x != mxln; ++x) {
        for (int i = 1; i != n; ++i) {
            for (int j = i; j != 0; --j) {
                if (get_digit(strings[j], x + 1) < get_digit(strings[j - 1], x + 1)) {
                    char * tmp = strings[j];
                    strings[j] = strings[j - 1];
                    strings[j - 1] = tmp;
                }
            }
        }
        printf("Sorting by %d digit:\n", mxln - x - 1);
        for (int i = 0; i != n; ++i) {
            if (i != 0) printf("\n");
            printf("%s", strings[i]);
        }
        printf("\n\n");
    }
    // for (int i = 0; i != n; ++i) {
    //     if (i != 0) printf("\n");
    //     printf("%s", strings[i]);
    // }

    for (int i = 0; i != n; ++i) {
        free(strings[i]);
    }
    free(strings);
}


// int main() {
//     char * s = (char *) malloc (100 * sizeof(char));
//     for (int i = 0; i != 100; ++i) {
//         s[i] = '\0';
//     }
//     scanf("%s", s);
//     printf("%c", s[get_digit(s, 5)]);
// }