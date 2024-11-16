#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#define TIME_DELTA 10000 // в миллисекундах

void working(short size);
int next_element(short * i, short * j, short size);
int prev_element(short * i, short * j, short size);
void process_dots(short *** sud, short ** dots, short size, struct Cursor * cr);
typedef int (*move) (short *, short *, short);
void choose_number(short *** sud, short size, struct Cursor cr, move * operation, char c);

#endif