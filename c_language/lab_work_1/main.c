//#define BRUTEFORCE_SOLUTION


#ifndef BRUTEFORCE_SOLUTION
#include "src/user_plays.c"
#else
#include "src/bruteforce.c"
#endif


typedef unsigned sudoku_size;
int main() {
    srand(time(NULL));
    system("cls");
    printf("Enter the size of a sudoku: ");
    sudoku_size sz;
    scanf("%d", &sz);
    working(sz);
}
