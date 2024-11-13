#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include "sudoku.c"
#include "console_config.c"

#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#define TIME_DELTA 20 // в миллисекундах

void working(short size);
void sudoku_solver(short *** sud, short size, short ** dots);
int next_element(short * i, short * j, short size);
int prev_element(short * i, short * j, short size);
void process_dots(short *** sud, short ** dots, short size, struct Cursor * cr);
typedef int (*move) (short *, short *, short);
void choose_number(short *** sud, short size, struct Cursor cr, move * operation, char c);



void working(short size) {
    short ** sd = generate_sudoku(size);
    short ** dots = encrypt_sudoku(&sd, size);
    struct Cursor curs; curs.row = 0; curs.column = 0;
    system("cls");
    print_sudoku(sd, size);
    set_cursor_start();
    process_dots(&sd, dots, size, &curs);
    set_console_color(WHITE);
    set_cursor_end(size);
    free_sudoku(&sd, size, 0);
    free_sudoku(&dots, size, 1);
}

int next_element(short * i, short * j, short size) {
    if (*j + 1 == size && *i + 1 == size) return 0;
    else if (*j + 1 == size) {
        (*i)++; *j = 0;
    }
    else (*j)++;
    return 1;
}

int prev_element(short * i, short * j, short size) {
    if (*i == 0 && *j == 0) return 0;
    else if (*j == 0) {
        (*i)--; *j = size - 1;
    }
    else (*j)--;
    return 1;
}

void process_dots(short *** sud, short ** dots, short size, struct Cursor * cr) {
    move oper = &next_element;
    short i = 0, j = 0;
    int true = 1;
    while (true) {
        set_cursor_start();
        if (*(*(dots + i) + j) == 1) {
            cr->column = j;
            cr->row = i;
            char x = (*(*(*sud + i) + j) == '.') ? '1' : *(*(*sud + i) + j);
            choose_number(sud, size, *cr, &oper, x);
        }
        true = oper(&i, &j, size);
        set_cursor_end(size);
        printf(" ");
    }
}

void choose_number(short *** sud, short size, struct Cursor cr, move * operation, char c) {
    char ch = c;
    while (!check_for_good_column(*sud, size, cr.column, ch) ||
    !check_for_good_row(*sud, size, cr.row, ch) ||
    !check_for_good_square(*sud, size, cr.row, cr.column, ch)) {
        set_console_color(RED);
        insert_number(sud, cr, size, ch);
        Sleep(TIME_DELTA);
        set_console_color(WHITE);
        if (ch == '0' + size) {
            insert_number(sud, cr, size, '.');
            *operation = &prev_element;
            return;
        }
        ch++;
    }
    set_console_color(GREEN);
    insert_number(sud, cr, size, ch);
    *operation = &next_element;
    set_console_color(WHITE);
    Sleep(TIME_DELTA);
}

#endif