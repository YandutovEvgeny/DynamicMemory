#pragma once
#include"stdafx.h"
//Основные функции для двумерного массива:
int** push_row_back(int** arr, unsigned int& rows, const unsigned int cols);
int** push_row_front(int** arr, unsigned int& rows, const unsigned int cols);
int** insert_row(int** arr, unsigned int& rows, const unsigned int cols, unsigned int insert_index);
int** pop_row_back(int** arr, unsigned int& rows, const unsigned int cols);
int** pop_row_front(int** arr, unsigned int& rows, const unsigned int cols);
int** erase_row(int** arr, unsigned int& rows, const unsigned int cols, unsigned int pop_index);