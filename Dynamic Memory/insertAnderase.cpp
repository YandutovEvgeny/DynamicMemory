#include"insertAnderase.h"
template <typename T>
T* insert(T arr[], int& n, int insert_value, int insert_index)
{
	if (insert_index >= n)return arr;
	T* buffer = new T[n + 1];
	for (int i = 0; i < insert_index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = insert_index + 1; i < n + 1; i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete[] arr;
	arr = buffer;
	arr[insert_index] = insert_value;
	n++;
	return arr;
}
template <typename T>
T* erase(T arr[], int& n, int pop_index)
{
	if (pop_index >= n)return arr;
	T* buffer = new T[--n];
	for (int i = 0; i < pop_index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = pop_index; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
template <typename T>
T** insert_row(T**& arr, unsigned int& rows, unsigned int& cols, unsigned int insert_index)
{
	if (insert_index >= rows)return arr;
	T** buffer = new T * [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = insert_index + 1; i < rows + 1; i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete[] arr;
	arr = buffer;
	arr[insert_index] = new T[cols] {};
	rows++;
	return arr;
}
template <typename T>
T** erase_row(T**& arr, unsigned int& rows, unsigned int& cols, unsigned int pop_index)
{
	if (pop_index >= rows)return arr;
	T** buffer = new T * [--rows]{};
	for (int i = 0; i < pop_index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = pop_index; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
template <typename T>
void insert_col(T**& arr, unsigned int& rows, unsigned int& cols, unsigned int insert_index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < insert_index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = insert_index + 1; j < cols + 1; j++)
		{
			buffer[j] = arr[i][j - 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template <typename T>
void erase_col(T**& arr, unsigned int& rows, unsigned int& cols, unsigned int pop_index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < pop_index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = pop_index; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;
}