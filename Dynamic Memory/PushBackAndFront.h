#pragma once
#include"stdafx.h"
template <typename T>
T* push_back(T arr[], int& n, int r_value);
template <typename T>
T* push_front(T arr[], int& n, int l_value);
template <typename T>
T** push_row_back(T**& arr, unsigned int& rows, unsigned int& cols);
template <typename T>
T** push_row_front(T**& arr, unsigned int& rows, unsigned int& cols);
template <typename T>
void push_col_back(T**& arr, unsigned int& rows, unsigned int& cols);
template <typename T>
void push_col_front(T**& arr, unsigned int& rows, unsigned int& cols);