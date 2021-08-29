#include "quadric.h"

int quad_solver(double a, double b, double c, double *x1, double *x2) {
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL);
    assert(x2 != NULL);

    if (!iszero(a)) {

        if (iszero(c) && !iszero(b)) {
            *x1 = -b / (2 * a);
            *x2 = 0;
            return Two;

        }
        double D = b * b - 4 * a * c;

        if (iszero(D)) {
            *x1 = -b / (2 * a);
            return One;

        }
        if (D < 0) {
            return Zero;

        }
        *x1 = (-b + sqrt(D)) / (2 * a);
        *x2 = (-b - sqrt(D)) / (2 * a);
        return Two;

    }
    return non_quad_solver(b, c, x1);

}

int non_quad_solver(double b, double c, double *x1) {
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL);

    if (!iszero(b)) {
        *x1 = -c / b;
        return One;

    }
    else if (!iszero(c)) {
        return Zero;

    }
    return Infinity;

}

void printx(int status, double x1, double x2) {
    switch(status) {
        case Infinity:
            printf("All numbers is solutions\n");
            break;

        case Zero:
            printf("Zero solutions\n");
            break;

        case One:
            printf("x= %.2f\n", x1);
            break;

        case Two:
            printf("x1= %.2f x2= %.2f\n", x1, x2);
            break;

        case Incorrect_input:
            printf("Input error\n");
            break;

        default:
            printf("Unknown failure\n");
            break;

    };

}

bool reader(double *a, double *b, double *c) {
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    char trash[Standart_array_size - 1] = {};

    int res = scanf("%lf %lf %lf", a, b, c);

    scanf("%*[^\n]");
    scanf("%*c");

    return (res >= 3);

}

void test_from_file() {
    FILE   *fp = fopen("test.txt", "r");
    char   str_test[Standart_array_size] = {};
    char   str_ans[Standart_array_size] = {};
    int    cor_test = 0,
           incor_test = 0;

    if (fp == NULL){
        printf("Error while reading file\n");

    } else {
        while (!feof (fp)) {
            fgets(str_test, Standart_array_size - 1, fp);
            fgets(str_ans, Standart_array_size - 1, fp);

            if (single_line_test(cor_test + incor_test + 1, str_test, str_ans)) {
                cor_test++;

            } else {
                incor_test++;

            }
            fgets(str_test, 2, fp);

        }
        printf("Number of correct tests - %d\n%s %d\n", cor_test, "Number of incorrect tests -", incor_test);

    }
    fclose(fp);
}

bool single_line_test(int num, char *test, char *test_answers) {
    assert(test != NULL);
    assert(test_answers != NULL);

    int    status = 0,   status_ans = 0,
           test_res = 0, test_answ_res = 0;
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN,
           ans1 = NAN, ans2 = NAN;
    bool succesful_test = true;

    test_res = sscanf(test, "%lf %lf %lf", &a, &b, &c);
    test_answ_res = sscanf(test_answers, "%d %lf %lf", &status_ans, &ans1, &ans2);

    if (test_answ_res == 0) {
        printf("%s %d %s\n", "test", num, "incorrect\n");
        return false;

    }
    if (test_res != 3) {
        status = Incorrect_input;

    } else {
        status = quad_solver(a, b, c, &x1, &x2);

    }
    if (status != status_ans) {
        printf("%s %d %s\n", "In test", num, "wrong number of roots");
        succesful_test = false;

    } else {
        switch(status) {
            case One:
                if (!iszero(x1 - ans1)) {

                    printf("%s %d %s\n", "In test", num, "1 root and it is incorrect");
                    succesful_test = false;
                }
                break;

            case Two:
                if ((roots_check(x1, x2, ans1, ans2)) == 0) {
                    printf("%s %d %s\n", "In test", num, "2 roots and both is correct");
                    succesful_test = false;

                } else if ((roots_check(x1, x2, ans1, ans2)) == 1) {
                    printf("%s %d %s\n", "In test", num, "2 roots and only one is correct");
                    succesful_test = false;

                }
                break;

            case Infinity:
            case Incorrect_input:
            case Zero:
                break;

            default:
                succesful_test = false;
                printf("Unknown error\n");
                break;

        }
    }
    if (!succesful_test) {
        if (status_ans == Incorrect_input) {
            printf("%s %s\n", "Input:", test);

        } else {
            printf("Input: ");
            equation_former(a, b, c);

        }
        printf("Expected input: ");
        printx(status_ans, ans1, ans2);
        printf("Received input: ");
        printx(status, x1, x2);
        printf("\n");
        return false;

    }
    printf("%s %d %s\n", "test", num, "is successful");
    return true;

}

void equation_former(double a, double b, double c) {
    char main_str[Standart_array_size] = {},
         alt_str[Standart_array_size] = {};

    if (!iszero(a)) {
        snprintf(main_str, Standart_array_size - 1, "%.2f %s", a, "* x^2");

    }
    if (!iszero(b)) {
        snprintf(alt_str, Standart_array_size - 1, "%.2f %s", b, "* x");

        if (main_str[0] != '\0') {
            snprintf(main_str, Standart_array_size - 1, "%s %s %s", main_str, "+", alt_str);

        } else {
            strncpy_s(main_str, alt_str, Standart_array_size - 1);

        }
    }
    if (!iszero(c)) {
        snprintf(alt_str, Standart_array_size - 1, "%.2f", c);

        if (main_str[0] != '\0') {
            snprintf(main_str, Standart_array_size - 1, "%s %s %s", main_str, "+", alt_str);

        } else {
            snprintf(main_str, Standart_array_size - 1, "%lf",c);

        }
    }
    if (main_str[0] != '\0') {
        snprintf(main_str, Standart_array_size - 1, "%s %s", main_str, "= 0");

    } else {
        snprintf(main_str, Standart_array_size - 1, "%s", "0 = 0");

    }
    printf("%s \n", main_str);

}

int roots_check(double x1, double x2, double ans1, double ans2) {
    assert(isfinite(x1));
    assert(isfinite(x2));
    assert(isfinite(ans1));
    assert(isfinite(ans2));

    int count = 0;

    if (iszero_not_strict(x1 - ans1) || iszero_not_strict(x1 - ans2)) {
        count++;

    }
    if (iszero_not_strict(x2 - ans1) || iszero_not_strict(x2 - ans2)) {
        count++;

    }
    return count;

}

bool iszero(double val){
    return(fabs(val) < Epsilon);

}

bool iszero_not_strict(double val){
    return(fabs(val) < ansEpsilon);

}
