#include "config/all_sudoku_files.h"

typedef unsigned sudoku_size;


//#define BRUTEFORCE_SOLUTION

#ifndef BRUTEFORCE_SOLUTION
#include "config/user_plays.c"
#else
#include "config/bruteforce.c"
#endif

int main() {
    srand(time(NULL));
    system("cls");
    printf("Enter the size of a sudoku: ");
    sudoku_size sz;
    scanf("%d", &sz);
    working(sz);
}
