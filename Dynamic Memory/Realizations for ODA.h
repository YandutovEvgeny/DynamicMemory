#pragma once
#include"stdafx.h"
//��� ���������� ��������:
void FillRand(int arr[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
int* push_back(int arr[], int& n, int r_value)
{
	//���������� ��������� � ������

	//1) ������ �������� ������ ������� �������:
	int* buffer = new int[n + 1];
	//2) �������� �������� ������ � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������:
	delete[] arr;
	//4) ��������� �������� ������ ����� (��������) ��������, �� ���� ������� ������:
	arr = buffer;
	//5) ������ ����� ���� ���� �������� ����� �������� �������� � ����� �������
	arr[n] = r_value;
	//6) ����� ���������� �������� � ������, ���������� ��� ��������� ������������� 
	//�� 1:
	n++;
	return arr;
}
int* push_front(int arr[], int& n, int l_value)
{
	int* buffer = new int[n + 1];
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
int* insert(int arr[], int& n, int insert_value, int insert_index)
{
	int* buffer = new int[n + 1];
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
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
int* erase(int arr[], int& n, int pop_index)
{
	int* buffer = new int[--n];
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