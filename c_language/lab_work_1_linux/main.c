//#define BRUTEFORCE_SOLUTION


#ifndef BRUTEFORCE_SOLUTION
#include "src/user_plays.c"
#else
#include "src/bruteforce.c"
#endif


typedef unsigned sudoku_size;
int main() {
    srand(time(NULL));
    sudoku_size sz;
    printf("\033[%d;%dH\033[JEnter the size of a sudoku: ", 0, 0);
    scanf("%d", &sz);
    printf("\033[%d;%dH\033[J", 0, 0);  
    working(sz);
}
