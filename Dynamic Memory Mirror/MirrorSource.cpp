#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void FillRand(int arr[], const unsigned int n);
void Print(int arr[], const unsigned int n);

int* push_back(int arr[], int& n, int value);

void main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавочное значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	delete[] arr;
}

void FillRand(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
int* push_back(int arr[], int& n, int value)
{
	///////////////////////////////////////////////////////////////////////////
	///////////////////////   Добавление элемента в массив   //////////////////
	///////////////////////////////////////////////////////////////////////////
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}