#pragma once
#include"stdafx.h"
//Основные функции для одномерного массива:
int* push_back(int arr[], int& n, int r_value);
int* push_front(int arr[], int& n, int l_value);
int* insert(int arr[], int& n, int insert_value, int insert_index);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int pop_index);