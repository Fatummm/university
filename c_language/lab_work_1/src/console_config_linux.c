#include "sudoku.c"

#ifndef CONSOLE_H
#define CONSOLE_H

// структурка для задания цвета
enum Color {
    RED, BLUE, GREEN, CYAN, WHITE
};

// структурка для курсора, а точнее - для каретки
struct Cursor {
    short row, column;
};

void set_cursor(struct Cursor cr, short size);
void set_cursor_end(short size);
void set_cursor_start();
void set_console_color(enum Color clr);
void insert_number(short *** sud, struct Cursor cr, short size, char c);

// установка цвета печати в консоли
void set_console_color(enum Color clr) {
    
    switch (clr) {
        case (WHITE): {
            printf("\033[0;37m"); break;
        }
        case (RED): {
            printf("\033[0;31m"); break;
        }
        case (BLUE): {
            printf("\033[0;34m"); break;
        }
        case (GREEN): {
            printf("\033[0;32m"); break;
        }
        case (CYAN): {
            printf("\033[0;36m"); break;
        }
    }
}

// установка курсора в конец таблицы, чтобы не мешал
void set_cursor_end(short size) { // Ставит курсор в конец судоку
    short sq = sqrt(size);
    printf("\033[%d;%dH", size + sq - 1 + 3, 0);
}

// установка курсора на начало консоли, чтобы можно было правильно печатать
void set_cursor_start() {
    printf("\033[%d;%dH", 0, 0);
}

// вставка числа на определённу позицию курсора
void insert_number(short *** sud, struct Cursor cr, short size, char c) {
    short sq = sqrt(size);
    printf("\033[%d;%dH", cr.row / sq + cr.row, 2 * (cr.column / sq + cr.column) + 1);
    *(*(*sud + cr.row) + cr.column) = c;
    printf("%c", c);
}

#endif
