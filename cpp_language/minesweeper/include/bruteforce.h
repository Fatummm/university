#pragma once

#include "minesweeper_funcs.h"
#include "terminal_config.h"

#define TIME_DELTA 1000000

void Solve(Field& f);
bool MarkBombs(Field& f);
bool OpenCells(Field& f);
bool OpenRandom(Field& f);