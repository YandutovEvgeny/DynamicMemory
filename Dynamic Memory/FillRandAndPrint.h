#pragma once
#include"stdafx.h"
//Заполнение массивов & вывод на экран:
template <typename T>
void FillRand(T arr[], const unsigned int n, int minRand = 0, int maxRand = 100);
template <typename T>
void FillRand(T** arr, const unsigned int rows, const unsigned int cols, int minRand = 0, int maxRand = 100);
inline void FillRand(double** arr, const unsigned int rows, const unsigned int cols);
inline void FillRand(float** arr, const unsigned int rows, const unsigned int cols);
template <typename T>
void Print(T arr[], const unsigned int n);
template <typename T>
void Print(T** arr, const unsigned int rows, const unsigned int cols);