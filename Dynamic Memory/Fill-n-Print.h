#pragma once
#include"stdafx.h"
//Заполнение массивов & вывод на экран:
void FillRand(int arr[], int& n);
void FillRand(int** arr, const unsigned int rows, const unsigned int cols);
void Print(int arr[], int& n);
void Print(int** arr, const unsigned int rows, const unsigned int cols);