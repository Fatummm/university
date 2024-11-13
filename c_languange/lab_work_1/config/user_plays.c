#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include "sudoku.c"
#include "console_config.c"


#ifndef USER
#define USER


void clear_brackets(struct Cursor cr, short size);
void print_brackets(struct Cursor cr, short size);
short process_input(short *** sud, short size, struct Cursor * curs, short ** dots, char c);


void working_user(short size) {
    short ** sd = generate_sudoku(size);
    short ** dots = encrypt_sudoku(&sd, size);
    struct Cursor curs; curs.row = 0; curs.column = 0;
    int not_escape = 1;
    system("cls");
    print_sudoku(sd, size);
    set_console_color(CYAN);
    printf("ESCAPE"); 
    set_console_color(WHITE);
    printf(" - to quit\n");
    set_console_color(CYAN);
    printf("BACKSPACE"); 
    set_console_color(WHITE);
    printf(" - to remove your number\n");
    set_console_color(CYAN);
    printf("ENTER"); 
    set_console_color(WHITE);
    printf(" - to check sudoku\n");

    while (not_escape) {
        set_cursor_start();
        print_brackets(curs, size);
        set_cursor_end(size);
        char c = getch();
        not_escape = process_input(&sd, size, &curs, dots, c);
    }
    free_sudoku(&dots, size, 1);
    free_sudoku(&sd, size, 0);
}


short process_input(short *** sud, short size, struct Cursor * curs, short ** dots, char c) {
    printf("                                                               ");
    switch (c) {
        case 'w': case 'W':{
            if ((*curs).row > 0) {
                clear_brackets(*curs, size);
                (*curs).row--;
                }
            break;
        }
        case 'a': case 'A':{
            if (curs->column > 0) {
                clear_brackets(*curs, size);
                curs->column--;
                }
            break;
        }
        case 's': case 'S':{
            if (curs->row + 1 != size) {
                clear_brackets(*curs, size);
                curs->row++;
                }
            break;
        }
        case 'd': case 'D':{
            if (curs->column + 1 != size) {
                clear_brackets(*curs, size);
                curs->column++;
                }
            break;
        }
        case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': {
            if (*(*(dots + curs->row) + curs->column) != 1) break;
            if (size < c - '0') break;
            if (check_for_good_column(*sud, size, curs->column, c) && 
                check_for_good_row(*sud, size, curs->row, c) && 
                check_for_good_square(*sud, size, curs->row, curs->column, c)) {
                set_console_color(GREEN);
                insert_number(sud, *curs, size, c);
                if (check_for_success(*sud, size)) {
                    set_cursor_end(size);
                    printf("Sudoku solved!!! Congrats!\n");
                    set_console_color(WHITE);
                    return 0;
                }
            }
            else {
                set_console_color(RED);
                insert_number(sud, *curs, size, c);
            }
            set_console_color(WHITE);
            break;
        }
        case 27: {
            return 0;
            break;
        }
        case 8: {
            if (*(*(dots + curs->row) + curs->column) != 1) break;
            insert_number(sud, *curs, size, '.');
            break;
        }
        case 13: {
            set_cursor_end(size);
            if (check_for_success(*sud, size)) {
                printf("Sudoku solved Wrong!!\n");
            }
            else printf("There are some spaces that need to be filled...\n");
            set_cursor_end(size);
        }

    }
    return 1;
}


void clear_brackets(struct Cursor cr, short size) {
    HANDLE handle;
    COORD coordinates;
    short sq = sqrt(size);
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = 2 * (cr.column / sq + cr.column) ; // Иксы по горизонтали
    coordinates.Y = cr.row / sq + cr.row; // игреки по вертикали
    SetConsoleCursorPosition ( handle , coordinates );
    printf(" ");
    coordinates.X += 2;
    SetConsoleCursorPosition ( handle , coordinates );
    printf(" ");
}



void print_brackets(struct Cursor cr, short size) {
    HANDLE handle;
    COORD coordinates;
    short sq = sqrt(size);
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = 2 * (cr.column / sq + cr.column) ; // Иксы по горизонтали
    coordinates.Y = cr.row / sq + cr.row; // игреки по вертикали
    SetConsoleCursorPosition ( handle , coordinates );
    set_console_color(CYAN);
    printf("[");
    coordinates.X += 2;
    SetConsoleCursorPosition ( handle , coordinates );
    printf("]");
    set_console_color(WHITE);
}

#endif