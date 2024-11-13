#include <stdio.h>
#ifndef CALC_10_H
#define CALC_10_H

int Calculator()
{
    double a, b, res;
    char operation;
    scanf("%lf %c %lf", &a, &operation, &b);
    switch (operation) {
    case '+': {
        res = a + b;
        break;
        }
    case '-': {
        res = a - b;
        break;
        }
    case '*': {
        res = a * b;
        break;
        }
    case '/': {
        if (b == 0) {
            printf("Error DivizionByZero");
        }
        res = a / b;
        }
    }
    if (res) {
        printf("The result is: %lf\n", res);
        return 1;
    } else {
        return 0;
    }
}
#endif