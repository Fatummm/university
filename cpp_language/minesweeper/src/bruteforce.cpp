#include "bruteforce.h"


bool MarkBombs(Field& f) {
    bool good = false;
    for (size_t i = 0; i != f.GetRows(); ++i) {
        for (size_t j = 0; j !=f.GetColumns(); ++j) {
            if (f.GetAt(i, j).opened == true && f.GetAt(i, j).bombs_nearby != 0) {
                unsigned hidden = 0;
                unsigned marked = 0;
                for (size_t x = (i == 0) ? 0: i - 1; x != ((i + 1 == f.GetRows()) ? i + 1: i + 2); ++x) {
                    for (size_t y = (j == 0) ? 0: j - 1; y != ((j + 1 == f.GetColumns()) ? j + 1: j + 2); ++y) {
                        hidden += (f.GetAt(x, y).opened == false);
                        marked += (f.GetAt(x, y).marked == true);
                    }
                }
                if (hidden == f.GetAt(i, j).bombs_nearby && marked != hidden) {
                    good = true;
                    for (size_t x = (i == 0) ? 0: i - 1; x != ((i + 1 == f.GetRows()) ? i + 1: i + 2); ++x) {
                        for (size_t y = (j == 0) ? 0: j - 1; y != ((j + 1 == f.GetColumns()) ? j + 1: j + 2); ++y) {
                            if (f.GetAt(x, y).marked == false && f.GetAt(x, y).opened == false) {
                                f.MarkAt(x, y);
                            }
                        }
                    }
                }
            }
        }
    }
    return good;
}

bool OpenCells(Field& f) {
    bool good = false;
    for (size_t i = 0; i != f.GetRows(); ++i) {
        for (size_t j = 0; j !=f.GetColumns(); ++j) {
            if (f.GetAt(i, j).opened == true && f.GetAt(i, j).bombs_nearby != 0) {
                unsigned marked = 0;
                unsigned hidden = 0;
                for (size_t x = (i == 0) ? 0: i - 1; x != ((i + 1 == f.GetRows()) ? i + 1: i + 2); ++x) {
                    for (size_t y = (j == 0) ? 0: j - 1; y != ((j + 1 == f.GetColumns()) ? j + 1: j + 2); ++y) {
                        marked += (f.GetAt(x, y).marked == true);
                        hidden += (f.GetAt(x, y).marked == false && f.GetAt(x, y).opened == false);
                    }
                }
                if (marked == f.GetAt(i, j).bombs_nearby && hidden != 0) {
                    good = true;
                    for (size_t x = (i == 0) ? 0: i - 1; x != ((i + 1 == f.GetRows()) ? i + 1: i + 2); ++x) {
                        for (size_t y = (j == 0) ? 0: j - 1; y != ((j + 1 == f.GetColumns()) ? j + 1: j + 2); ++y) {
                            if (f.GetAt(x, y).marked == false && f.GetAt(x, y).opened == false) {
                                f.OpenAt(x, y);
                            }
                        }
                    }
                }
            }
        }
    }
    return good;
}

bool OpenRandom(Field& f) {
    for (size_t i = 0; i != f.GetRows(); ++i) {
        for (size_t j = 0; j != f.GetColumns(); ++j) {
            if (f.GetAt(i, j).opened == false && f.GetAt(i, j).marked == false && rand() % 5 == 0) {
                f.OpenAt(i, j);
                return f.GetAt(i, j).type != BOMB;
            }
        }
    }
    return false;
}

void Solve(Field& f) {
    usleep(TIME_DELTA);
    f.OpenAt(f.GetRows() / 2, f.GetColumns() / 2);

    bool something_changed = true;
    bool game = true;
    while (game) {
        something_changed = true;
        while (something_changed) {
            std::cout << "\007";
            something_changed = MarkBombs(f) + OpenCells(f);
            std::cout << set_cursor(f.GetRows() + f.comments.size() + 2, 0);
            //usleep(TIME_DELTA);
            usleep(TIME_DELTA);
        }
        game = OpenRandom(f) && (f.BombsLeft() != 0);
        std::cout << set_cursor(f.GetRows() + f.comments.size() + 2, 0);
        usleep(TIME_DELTA); 
    }
}
