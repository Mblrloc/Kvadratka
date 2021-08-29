#ifndef QUADRIC_H_INCLUDED
#define QUADRIC_H_INCLUDED

#include <cstring>
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "TXLib.h"

/*!
 ������ ���������� ���������.
\param[out] *x1 ������ ������ � ���������
\param[out] *x2 ������ ������ � ���������
\param[in] a, b, c ��������� ��������������� �-��� "a", "b", "c" � ���������� ���������
\return ���-�� ������ � ���������� ���������
*/
int quad_solver(double a, double b, double c, double *x1, double *x2);

/*!
 ������ ��������� �� �������� < 2.
\param[out] *x1 ������ ������ � ���������
\param[out] *x2 ������ ������ � ���������
\param[in]   b, c ��������� ��������������� �-��� "b", "c" � ���������� ���������
\return ���-�� ������ � ���������� ���������
*/
int non_quad_solver(double b, double c, double *x1);

/*!
 ������� �� ����� ����� �� ��������� ������ �� ���-�� ������.
\param[in] status ���-�� ������
\param[in] x1 ������ ������
\param[in] x2 ������ ������
*/
void printx(int status, double x1, double x2);

/*!
 ������ ������ � �������.
\param[out] a, b, c ��������� ��������������� �-��� "a", "b", "c" � ���������� ���������
\return true - ���� ���� ��� �������� � ��� ��������� ��������� ���� ������� �������, false - ���� ���.
*/
bool reader(double *a, double *b, double *c);

/*!
 ��������� �������� �������, ������ ���� � �������, �������� ��� � �����, ������ ����� ���� ��������� ����� ������� single_line_test().
 ����� ���� ������ ������� ���-�� �������� � ���������� ������.
*/
void test_from_file();

/*!
 �������� �������� ������ �����, � ������ ����������� ����� �������: �������� ������,
 ��������� �������, ��������� ��������� � ��������� ���������, ������� ������ ���������.
\param[in] num ����� �����
\param[in] test ������ � ��������� �����
\param[in] test_answers ������ � �������� �� ����
\return true - ���� ���� ��������, false - ���� ���
*/
bool single_line_test(int num, char test[], char test_answers[]);

/*!
 ��������� ������� ����� ���� x1, x2 � ans1, ans2 ���������� ���������.
\param[in] x1, x2 �������� ������ ����
\param[in] a1, a2 �������� ������ ����
\return ���-�� ��������� ��������
*/
int roots_check(double x1, double x2, double a1, double a2);

/*!
 ��������� ������� ����������� ���������
\param[in] a, b, c ��������� ��������������� �-��� "a", "b", "c" � ���������� ���������
\return ������ ���� a * x^2 + b * x + c = 0 ��� ������ ������� ����, �������������� ������� ��������
*/
void equation_former(double a, double b, double c);

/*!
�������� ��� double, �������� �� �� �����.
\param[in] val ������������ ��������
*/
bool iszero(double val);

/*!
�������� ��� double, �������� �� �� �����, �� ����� ������� ��� iszero(), ��� ������.
\param[in] val ������������ ��������
*/
bool iszero_not_strict(double val);

/// ����� ���-�� ��������� ������ � ��������� � ��������� ��� ��������
enum State {
    Incorrect_input = -2,       ///< ���� ������ ����������, ��������� �� ���������� ������.
    Infinity = -1,              ///< � ��������� ����������� ���-�� ������
    Zero = 0,                   ///< � ��������� 0 ������
    One = 1,                    ///< � ��������� 1 ������
    Two = 2,                    ///< � ��������� 2 �����
    Standart_array_size = 128   ///< ����������� ������ �������
};

const double Epsilon = 1e-8;           ///< ��������� ��� ��������� double
const double ansEpsilon = 0.05;        ///< ��������� ��� ��������� ����������� �����.

#endif // QUADRIC_H_INCLUDED

