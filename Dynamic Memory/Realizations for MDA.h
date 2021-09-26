#pragma once
#include"stdafx.h"
//��� ��������� ��������:
void FillRand(int** arr, const unsigned int rows, const unsigned int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int** arr, const unsigned int rows, const unsigned int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
int** allocate(const unsigned int rows, const unsigned int cols)
{
	/////////////////////////////////////////////////////////////////////////////
	//////////////     ���������� ���������� ������������� �������:      ////////
	/////////////////////////////////////////////////////////////////////////////
	//1) ��������� ��������� �� ���������, � ��������� � ���� ����� ������� ����������
	int** arr = new int* [rows];
	//2) ������ ������ ���������� ������������� �������:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
void clear(int** arr, const unsigned int rows)
{
	/////////////////////////////////////////////////////////////////////////////
	////////         �������� ���������� ������������� �������:          ////////
	/////////////////////////////////////////////////////////////////////////////
	//1) ������� ������:
	for (int i = 0; i < rows; i++)
	{
		delete arr[i];
	}
	//2) ������� ������ ����������:
	delete[] arr;
}
int** push_row_back(int** arr, unsigned int& rows, const unsigned int cols)
{
	//1)������ ��������� ������ ����������:
	int** buffer = new int* [rows + 1]{};
	//2)�������� ������ ����� � ��������� ������ ����������
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3)������� �������� ������ ����������:
	delete[] arr;
	//4)��������� �������� ������ ���������:
	arr = buffer;
	//5)��������� � ������ ����� ������:
	arr[rows] = new int[cols] {};
	//6)����������� ���������� �����:
	rows++;
	//7)���������� ����� ������ �� ����� ������:
	return arr;
}
int** push_row_front(int** arr, unsigned int& rows, const unsigned int cols)
{
	int** buffer = new int* [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new int[cols] {};
	rows++;
	return arr;
}
int** insert_row(int** arr, unsigned int& rows, const unsigned int cols, unsigned int insert_index)
{
	int** buffer = new int* [rows + 1]{};
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
	arr[insert_index] = new int[cols] {};
	rows++;
	return arr;
}
int** pop_row_back(int** arr, unsigned int& rows, const unsigned int cols)
{
	int** buffer = new int* [--rows]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
int** pop_row_front(int** arr, unsigned int& rows, const unsigned int cols)
{
	int** buffer = new int* [--rows]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
int** erase_row(int** arr, unsigned int& rows, const unsigned int cols, unsigned int pop_index)
{
	int** buffer = new int* [--rows]{};
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