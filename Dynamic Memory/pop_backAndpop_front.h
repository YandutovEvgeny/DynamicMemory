#pragma once
#include"stdafx.h"
template <typename T>
T* pop_back(T arr[], int& n);
template <typename T>
T* pop_front(T arr[], int& n);
template <typename T>
T** pop_row_back(T**& arr, unsigned int& rows, unsigned int& cols);
template <typename T>
T** pop_row_front(T**& arr, unsigned int& rows, unsigned int& cols);
template <typename T>
void pop_col_back(T**& arr, unsigned int& rows, unsigned int& cols);
template <typename T>
void pop_col_front(T**& arr, unsigned int& rows, unsigned int& cols);