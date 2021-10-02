#include"push_backAndpush_front.h"
template <typename T>
T* push_back(T arr[], int& n, int r_value)
{
	//Добавление элементов в массив

	//1) Создаём буферный массив нужного размера:
	T* buffer = new T[n + 1];
	//2) Копируем исходный массив в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив:
	delete[] arr;
	//4) Подменяем исходный массив новым (буферным) массивом, за счёт подмены адреса:
	arr = buffer;
	//5) Только после всех этих действий можно добавить значение в конец массива
	arr[n] = r_value;
	//6) После добавления элемента в массив, количество его элементов увеличивается 
	//на 1:
	n++;
	return arr;
}
template <typename T>
T* push_front(T arr[], int& n, int l_value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];

	}
	delete[] arr;
	arr = buffer;
	arr[0] = l_value;
	n++;
	return arr;
}
template <typename T>
T** push_row_back(T**& arr, unsigned int& rows, unsigned int& cols)
{
	//1)Создаём буфферный массив указателей:
	T** buffer = new T * [rows + 1]{};
	//2)Копируем адреса строк в буфферный массив указателей
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3)Удаляем исходный массив указателей:
	delete[] arr;
	//4)Подменяем исходный массив буфферным:
	arr = buffer;
	//5)Добавляем в массив новую строку:
	arr[rows] = new T * [cols] {};
	//6)Увеличиваем количество строк:
	rows++;
	//7)Возвращаем новый массив на место вызова:
	return arr;
}
template <typename T>
T** push_row_front(T**& arr, unsigned int& rows, unsigned int& cols)
{
	T** buffer = new T * [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new T * [cols] {};
	rows++;
	return arr;
}
template <typename T>
void push_col_back(T**& arr, unsigned int& rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) Создаём буфферную строку, размером на 1 элемент больше:
		T* buffer = new T[cols + 1]{};
		//2) Копируем исходную строку в буфферную:
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		//3) Удаляем исходную строку
		delete[] arr[i];
		arr[i] = buffer;
	}
	//4) После того, как в каждой строке добавилось по элементу, 
	//количество стобцов увеличилось на 1:
	cols++;
}
template <typename T>
void push_col_front(T**& arr, unsigned int& rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}