#ifndef USER_H
#define USER_H

void working(short size);
void clear_brackets(struct Cursor cr, short size);
void print_brackets(struct Cursor cr, short size);
short process_input(short *** sud, short size, struct Cursor * curs, short ** dots, char c);
void print_sudoku_with_cursor(short ** sud, short size, struct Cursor cr);
#endif