#include "../include/all_sudoku_files.h"
#include "../include/bruteforce.h"




// главная функция
void working(short size) {
    short ** sd = generate_sudoku(size);
    short ** dots = encrypt_sudoku(&sd, size);
    struct Cursor curs; curs.row = 0; curs.column = 0;
    printf("\033[0;0H\033[J");
    print_sudoku(sd, size);
    set_cursor_start();
    process_dots(&sd, dots, size, &curs);
    set_console_color(WHITE);
    set_cursor_end(size);
    free_sudoku(&sd, size, 0);
    free_sudoku(&dots, size, 1);
}

// переходим к следующему элементу
int next_element(short * i, short * j, short size) {
    if (*j + 1 == size && *i + 1 == size) return 0;
    else if (*j + 1 == size) {
        (*i)++; *j = 0;
    }
    else (*j)++;
    return 1;
}

// переход к предыдущему элементу
int prev_element(short * i, short * j, short size) {
    if (*i == 0 && *j == 0) return 0;
    else if (*j == 0) {
        (*i)--; *j = size - 1;
    }
    else (*j)--;
    return 1;
}
// обработка точек
void process_dots(short *** sud, short ** dots, short size, struct Cursor * cr) {
    move oper = &next_element;
    short i = 0, j = 0;
    int truee = 1;
    while (truee) {
        set_cursor_start();
        if (*(*(dots + i) + j) == 1) {
            cr->column = j;
            cr->row = i;
            char x = (*(*(*sud + i) + j) == '.') ? '1' : *(*(*sud + i) + j);
            choose_number(sud, size, *cr, &oper, x);
        }
        truee = oper(&i, &j, size);
        set_cursor_end(size);
        printf(" ");
    }
}

// выборка числа
void choose_number(short *** sud, short size, struct Cursor cr, move * operation, char c) {
    char ch = c;
    while (!check_for_good_column(*sud, size, cr.column, ch) ||
    !check_for_good_row(*sud, size, cr.row, ch) ||
    !check_for_good_square(*sud, size, cr.row, cr.column, ch)) {
        set_console_color(RED);
        insert_number(sud, cr, size, ch);
        usleep(TIME_DELTA);
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
    usleep(TIME_DELTA);
}

