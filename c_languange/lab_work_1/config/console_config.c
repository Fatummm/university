#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include "sudoku.c"

#ifndef CONSOLE_H
#define CONSOLE_H

enum Color {
    RED, BLUE, GREEN, CYAN, WHITE
};

struct Cursor {
    short row, column;
};

void set_cursor(struct Cursor cr, short size);
void set_cursor_end(short size);
void set_cursor_start();
void set_console_color(enum Color clr);
void insert_number(short *** sud, struct Cursor cr, short size, char c);
// RED, BLUE, GREEN, CYAN, YELLOW, WHITE
void set_console_color(enum Color clr) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (clr) {
        case (WHITE): {
            SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); break;
        }
        case (RED): {
            SetConsoleTextAttribute(handle, FOREGROUND_RED); break;
        }
        case (BLUE): {
            SetConsoleTextAttribute(handle, FOREGROUND_BLUE); break;
        }
        case (GREEN): {
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN); break;
        }
        case (CYAN): {
            SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN); break;
        }
    }
}



void set_cursor_end(short size) { // Ставит курсор в конец судоку (потому что заебал)
    short sq = sqrt(size);
    HANDLE handle;
    COORD coordinates;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = 0;
    coordinates.Y = size + sq - 1 + 3;
    SetConsoleCursorPosition ( handle , coordinates );
}

void set_cursor_start() {
    HANDLE handle;
    COORD coordinates;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = 0;
    coordinates.Y = 0;
    SetConsoleCursorPosition(handle, coordinates);
}

void set_cursor(struct Cursor cr, short size) { // меняет положение курсора
    HANDLE handle;
    COORD coordinates;
    short sq = sqrt(size);
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = cr.row ; // Иксы по горизонтали
    coordinates.Y = cr.column; // Игреки по вертикали
    SetConsoleCursorPosition ( handle , coordinates );
}

void insert_number(short *** sud, struct Cursor cr, short size, char c) {
    HANDLE handle;
    COORD coordinates;
    short sq = sqrt(size);
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = 2 * (cr.column / sq + cr.column) + 1; // Иксы по горизонтали
    coordinates.Y = cr.row / sq + cr.row; // игреки по вертикали
    SetConsoleCursorPosition ( handle , coordinates );
    *(*(*sud + cr.row) + cr.column) = c;
    printf("%c", c);
}

#endif