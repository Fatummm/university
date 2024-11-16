#include "../include/all_sudoku_files.h"
#include "../include/user.h"

// главная функция
void working(short size) {
    short ** sd = generate_sudoku(size);
    short ** dots = encrypt_sudoku(&sd, size);
    struct Cursor curs; curs.row = 0; curs.column = 0;
    int not_escape = 1;
    printf("\033[J");
    print_sudoku_with_cursor(sd, size, curs);
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
        char c = get_char_from_input();
        not_escape = process_input(&sd, size, &curs, dots, c);
        printf("\033[0;0H");
        print_sudoku(sd, size);
    }
    free_sudoku(&dots, size, 1);
    free_sudoku(&sd, size, 0);
}

void print_sudoku(short ** sudoku, short size, struct Cursor cr) {
    for (short i = 0; i != size; ++i) {
        short sq = get_sqrt(size);
        if (i % sq == 0 && i != 0) {
            for (int it = 0; it != sq; ++it) {
                for (int x = 0; x != sq; ++x) {
                    printf("--");
                }
                if (it + 1 != sq) printf("-+");
            }
            printf("\n");
        }
        for (short j = 0; j!= size; ++j) {
            short sq = get_sqrt(size);
            if (j != 0 && cr.column == j - 1 && i == cr.row) {
                
            }
            if (j % sq == 0 && j != 0) printf(" |");
            if ('0' <= *(*(sudoku + i) + j) <= '9') printf("%2c", *(*(sudoku + i) + j));
            else printf(".");
        }
        printf("\n");
    }
}


// обработка введённого символа
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

// очистка квадратных скобок
void clear_brackets(struct Cursor cr, short size) {
    short sq = get_sqrt(size);
    printf("\033[%d;%dH ", cr.row / sq + cr.row + 1, 2 * (cr.column / sq + cr.column) + 1);
    printf("\033[%d;%dH ", cr.row / sq + cr.row + 1, 2 * (cr.column / sq + cr.column) + 2 + 1);
}

// установка квадратных скобок
void print_brackets(struct Cursor cr, short size) {
    short sq = get_sqrt(size);
    set_console_color(CYAN);
    printf("\033[%d;%dH[", cr.row / sq + cr.row + 1, 2 * (cr.column / sq + cr.column) + 1);
    printf("\033[%d;%dH]", cr.row / sq + cr.row + 1, 2 * (cr.column / sq + cr.column) + 2 + 1);
    set_console_color(WHITE);
}

