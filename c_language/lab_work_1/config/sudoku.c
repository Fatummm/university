#include <stdio.h>
#include <time.h> // Возарващает время в секундах
#include <stdlib.h>
#include <math.h>
#include <conio.h>


#ifndef SUDOKU_H
#define SUDOKU_H



void print_sudoku(short ** sudoku, short size);
short ** generate_sudoku(short size);
void free_sudoku(short *** sud, short size, short parameter);
short ** encrypt_sudoku(short *** sud, short size);
int check_for_good_square(short ** sud, short size, short i, short j, short value);
int check_for_good_row(short **sud, short size, short row, short value);
int check_for_good_column(short ** sud, short size, short column, short value);
short check_for_success(short ** sud, short size);

// 1 - solved/solved wrong, 0 - not solved(dots)
short check_for_success(short ** sud, short size) {
    for (int i = 0; i != size; ++ i) {
        for (int j = 0; j != size; ++j) {
            if (*(*(sud + i) + j) == '.') return 0;
        }
    }
    return 1;
}

// Вывоит судоку, на каждый символ отведено 2 позиции в терминале
void print_sudoku(short ** sudoku, short size) {
    for (short i = 0; i != size; ++i) {
        short sq = sqrt(size);
        if (i % sq == 0 && i != 0) {
            for (short x = 0; x != 2 * (size + sq - 1); ++x) printf("-");
            printf("\n");
        }
        for (short j = 0; j!= size; ++j) {
            short sq = sqrt(size);
            if (j % sq == 0 && j != 0) printf(" |");
            if ('0' <= *(*(sudoku + i) + j) <= '9') printf("%2c", *(*(sudoku + i) + j));
            else printf(".");
        }
        printf("\n");
    }
}

// генерация ГОТОВОГО судоку
short ** generate_sudoku(short size) {
    short ** sud = (short **) malloc(size * sizeof(short *));
    for (short i = 0; i != size; ++i) {
        *(sud + i) = (short *) malloc(size * sizeof(short));
        for (short j = 0; j != size; ++j) {
        }
    }
    short tries;
    short tries_full = 100;
    // цикл while для проверки - если мы не можем подобрать ни одной строчки, пересобираем весь судоку
    while (tries_full >= 100) {
        tries_full = 0;
        // Заполняем судоку нулями
        for (short i = 0; i != size; ++i) {
            for (short j = 0; j != size; ++j) {
                *(*(sud + i) + j) = '0';
            }
        }

        for (short i = 0; i != size; ++i) {
            tries = 100;
            // цикл while для проверки - если не можем подобрать ни одного числа, пересобираем всю строчку
            while (tries >= 100) {
                tries_full++;
                // заполняем строку нулями
                for (short j = 0; j != size; ++j) {
                    *(*(sud + i) + j) = '0';
                }

                tries = 0;
                for (short j = 0; j != size; ++j) {
                    short tmp = rand() % size + 1 + '0';
                    tries = 0;
                    while (check_for_good_square(sud, size, i, j, tmp) == 0 ||
                        check_for_good_column(sud, size, j, tmp) == 0 ||
                        check_for_good_row(sud, size, i, tmp) == 0) {
                        tmp = rand() % size + 1 + '0';
                        tries++;
                        if (tries >= 100) break;
                    }
                    if (tries >= 100) break;
                    tries = 0;
                    *(*(sud + i) + j) = tmp;
                }
                if (tries_full >= 100) break;
            }
        }
    }
    return sud;
}

// освобождение матриц
void free_sudoku(short *** sud, short size, short parameter) {
    for (short i = 0; i != size; ++i) {
        free(*(*sud + i));
    }
    free(*sud);
}

// Зашифровываем судоку - на место некоторых чисел ставим точки
short ** encrypt_sudoku(short *** sud, short size) {
    short ** dots = (short**) malloc (size * sizeof(short *));
    for (short i = 0; i != size; ++i) {
        *(dots + i) = (short *) malloc (size * sizeof(short));
        for (short j = 0; j != size; ++j) {
            if (rand() % 3 == 0) {
                *(*(*sud + i) + j) = '.';
                *(*(dots + i) + j) = 1;
            }
            else *(*(dots + i) + j) = 0;
        }
    }
    return dots;
}

// Далее три функции на проверки - подходит ли число на позицию

int check_for_good_square(short ** sud, short size, short i, short j, short value) {
    short size_smol = sqrt(size);
    short start_i = (i / size_smol) * size_smol;
    short start_j = (j / size_smol) * size_smol;
    for (short x = start_i; x != start_i + size_smol; ++x) {
        for (short y = start_j; y != start_j + size_smol; ++y) {
            if (*(*(sud + x) + y) == value) return 0;
        }
    }
    return 1;
}

int check_for_good_column(short ** sud, short size, short column, short value) {
    for (short x = 0; x != size; ++x) {
        if (*(*(sud + x) + column) == value) return 0;
    }
    return 1;
}

int check_for_good_row(short **sud, short size, short row, short value) {
    for (int y = 0; y != size; ++y) {
        if (*(*(sud + row) + y) == value) return 0;
    }
    return 1;
}

#endif