#pragma once
#include"stdafx.h"
//�������� � �������� ���������� �������:
template <typename T>
T** allocate(unsigned int rows, unsigned int cols);
template <typename T>
void clear(T** arr, const unsigned int rows);