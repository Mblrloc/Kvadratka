#include "quadric.h"

/*!
¬водит результаты квадратного уравнени€, основыва€сь на введенных к-тах.
*/
int main() {
    printf("Please input a, b, c of your quadratic equation\n");

    int    status = 0;
    double a = NAN, b = NAN, c = NAN,
           x1 = NAN, x2 = NAN;
    bool   repeat = true;

    while (repeat) {
        repeat = !reader (&a, &b, &c);

        if (!repeat) {
            status = quad_solver(a, b, c, &x1, &x2);
            printx(status, x1, x2);

        } else {
            printf("Incorrect input\n");

        }
    }
    return 0;

}
