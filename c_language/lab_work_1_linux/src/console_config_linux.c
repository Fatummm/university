#include "sudoku.c"
#include <math.h>
#ifndef CONSOLE_H
#define CONSOLE_H
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
 
void term_setup(struct termios *old) {
    int r = tcgetattr(STDOUT_FILENO, old); // Сохраняем настройки терминала
    assert(r != -1);
 
    struct termios new = *old;
    new.c_lflag &= ~ICANON; // Неканонический режим
    new.c_lflag &= ~ECHO; // Без эхо
    new.c_cc[VMIN] = 1; // Чтение посимвольно
    new.c_cc[VTIME] = 0; // И без таймаута
 
    r = tcsetattr(STDOUT_FILENO, TCSANOW, &new); // Устанавливаем свои настройки
    assert(r != -1);
}
 
void term_restore(struct termios *old) {
    tcsetattr(STDOUT_FILENO, TCSADRAIN, old); // Восстанавливаем настройки терминала
}
 
char get_char_from_input() {
    struct termios old;
    term_setup(&old);
 
    bool ret;
    char c;
    while (1) {
        ssize_t r = read(0, &c, 1);
        
        break;
    }
    term_restore(&old);
    return c;
}


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
    short sq = get_sqrt(size);
    printf("\033[%d;%dH", size + sq - 1 + 3 + 1, 0);
}

// установка курсора на начало консоли, чтобы можно было правильно печатать
void set_cursor_start() {
    printf("\033[%d;%dH", 1, 1);
}

// вставка числа на определённу позицию курсора
void insert_number(short *** sud, struct Cursor cr, short size, char c) {
    short sq = get_sqrt(size);
    printf("\033[%d;%dH", cr.row / sq + cr.row + 1, 2 * (cr.column / sq + cr.column) + 1 + 1);
    *(*(*sud + cr.row) + cr.column) = c;
    printf("%c", c);
}

#endif
