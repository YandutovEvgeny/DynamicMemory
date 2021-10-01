#pragma once
#include"stdafx.h"
//Создание и удаление двумерного массива:
template <typename T>
T** allocate(unsigned int rows, unsigned int cols);
template <typename T>
void clear(T** arr, const unsigned int rows);