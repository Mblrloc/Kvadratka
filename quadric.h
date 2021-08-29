#ifndef QUADRIC_H_INCLUDED
#define QUADRIC_H_INCLUDED

#include <cstring>
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "TXLib.h"

/*!
 Решает квадратное уравнение.
\param[out] *x1 Первый корень в уравнении
\param[out] *x2 Второй корень в уравнении
\param[in] a, b, c Параметры соответствующии к-там "a", "b", "c" в квадратном уравнении
\return Кол-во корней в квадратном уравнении
*/
int quad_solver(double a, double b, double c, double *x1, double *x2);

/*!
 Решает уравнение со степенью < 2.
\param[out] *x1 Первый корень в уравнении
\param[out] *x2 Второй корень в уравнении
\param[in]   b, c Параметры соответствующии к-там "b", "c" в квадратном уравнении
\return Кол-во корней в квадратном уравнении
*/
int non_quad_solver(double b, double c, double *x1);

/*!
 Выводит на экран ответ на уравнение исходя из кол-ва корней.
\param[in] status Кол-во корней
\param[in] x1 Первый корень
\param[in] x2 Второй корень
*/
void printx(int status, double x1, double x2);

/*!
 Читает данные с консоли.
\param[out] a, b, c Параметры соответствующии к-там "a", "b", "c" в квадратном уравнении
\return true - если ввод был успешным и все параметры уравнения были успешно считаны, false - если нет.
*/
bool reader(double *a, double *b, double *c);

/*!
 Запускает тестовую систему, читает файл с тестами, прогоняя его в цикле, каждый новый тест прогоняет через функцию single_line_test().
 После всех тестов выводит кол-во успешных и неуспешных тестов.
*/
void test_from_file();

/*!
 Проводит проверку одного теста, в случае неуспешного теста выводит: описание ошибки,
 стартовые условия, требуемый результат и ошибочный результат, который вывела программа.
\param[in] num Номер теста
\param[in] test Строка с условиями теста
\param[in] test_answers Строка с ответами на тест
\return true - если тест успешный, false - если нет
*/
bool single_line_test(int num, char test[], char test_answers[]);

/*!
 Проверяет сколько среди пары x1, x2 и ans1, ans2 одинаковых элементов.
\param[in] x1, x2 значения первой пары
\param[in] a1, a2 значения второй пары
\return Кол-во совпавших значений
*/
int roots_check(double x1, double x2, double a1, double a2);

/*!
 Формирует условие квадратного уравнения
\param[in] a, b, c Параметры соответствующии к-там "a", "b", "c" в квадратном уравнении
\return строка вида a * x^2 + b * x + c = 0 или строка схожего вида, соответсвующая входным условиям
*/
void equation_former(double a, double b, double c);

/*!
Проверка для double, является ли он нулем.
\param[in] val сравниваемое значение
*/
bool iszero(double val);

/*!
Проверка для double, является ли он нулем, не такая строгая как iszero(), для тестов.
\param[in] val сравниваемое значение
*/
bool iszero_not_strict(double val);

/// Набор кол-ва возможных корней в уравнении и константа для массивов
enum State {
    Incorrect_input = -2,       ///< Ввод данных некоректен, уравнение не существует воовсе.
    Infinity = -1,              ///< В уравнении бесконечное кол-во корней
    Zero = 0,                   ///< В уравнении 0 корней
    One = 1,                    ///< В уравнении 1 корень
    Two = 2,                    ///< В уравнении 2 корня
    Standart_array_size = 128   ///< Стандартный размер массива
};

const double Epsilon = 1e-8;           ///< Константа для сравнивая double
const double ansEpsilon = 0.05;        ///< Константа для сравнивая результатов теста.

#endif // QUADRIC_H_INCLUDED

