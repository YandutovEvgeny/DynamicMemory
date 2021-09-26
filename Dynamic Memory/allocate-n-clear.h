#pragma once
#include"stdafx.h"
//Создание & удаление двумерного массива:
int** allocate(const unsigned int rows, const unsigned int cols);
void clear(int** arr, const unsigned int rows);