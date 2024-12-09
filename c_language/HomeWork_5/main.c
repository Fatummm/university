#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char c;
} Cell;

void print_matrix(Cell ** matrix, int n, int m) {
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != m; ++j) {
            printf("%2c", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

void destroy_matrix(Cell ** m, int n) {
    for (int i = 0; i != n; ++i) {
        free(*(m + i));
    }
    free(m);
}

int main() {
    srand(time(NULL));
    int n, m;
    printf("Enter two numbers: ");
    scanf("%d %d", &n, &m);
    Cell ** matrix = (Cell **) malloc (n * sizeof(Cell *));
    for (int i = 0; i != n; ++i) {
        *(matrix + i) = (Cell *) malloc (m * sizeof(Cell));
        for (int j = 0; j != m; ++j) {
            (*(*(matrix + i) + j)).c = rand() % 93 + 33;
        }
    }
    print_matrix(matrix, n, m);
    destroy_matrix(matrix, n);
}