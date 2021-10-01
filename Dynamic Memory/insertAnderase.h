#pragma once
#include"stdafx.h"
template <typename T>
T* insert(T arr[], int& n, int insert_value, int insert_index);
template <typename T>
T* erase(T arr[], int& n, int pop_index);
template <typename T>
T** insert_row(T**& arr, unsigned int& rows, unsigned int& cols, unsigned int insert_index);
template <typename T>
T** erase_row(T**& arr, unsigned int& rows, unsigned int& cols, unsigned int pop_index);
template <typename T>
void insert_col(T**& arr, unsigned int& rows, unsigned int& cols, unsigned int insert_index);
template <typename T>
void erase_col(T**& arr, unsigned int& rows, unsigned int& cols, unsigned int pop_index);