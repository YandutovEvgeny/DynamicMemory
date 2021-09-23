#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int** allocate(const unsigned int rows, const unsigned int cols);
void clear(int** arr, const unsigned int rows);


void FillRand(int arr[], int& n);
void FillRand(int** arr, const unsigned int rows, const unsigned int cols);
void Print(int arr[], int& n);
void Print(int** arr, const unsigned int rows, const unsigned int cols);

int* push_back(int arr[], int& n, int r_value);  
int* push_front(int arr[], int& n, int l_value);
int* insert(int arr[], int& n, int insert_value, int insert_index);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int pop_index);

int** push_row_back(int** arr, unsigned int& rows, const unsigned int cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2


void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int r_value;
	cout << "Введите добавляемое значение в конец массива: "; cin >> r_value;
	arr = push_back(arr, n, r_value);
	Print(arr, n);

	int l_value;
	cout << "Введите добавляемое значение в начало массива: "; cin >> l_value;
	arr = push_front(arr, n, l_value);
	Print(arr, n);

	int insert_value;
	int insert_index;
	cout << "Введите добавлемое значение: "; cin >> insert_value;
	cout << "Введите индекс массива в который хотите вставить значение: "; cin >> insert_index;
	arr = insert(arr, n, insert_value, insert_index);
	Print(arr, n);

	cout << "Удаление последнего элемента в массиве: " << endl;
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "Удаление первого элемента в массиве: " << endl;
	arr = pop_front(arr, n);
	Print(arr, n);

	int pop_index;
	cout << "Введите удаляемый индекс: "; cin >> pop_index;
	arr = erase(arr, n, pop_index);
	Print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	unsigned int rows;
	unsigned int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	int** arr = allocate(rows, cols);
	/////////////////////////////////////////////////////////////////////////////
	////////  Обращение к элементам двумерного динамического массива:    ////////
	/////////////////////////////////////////////////////////////////////////////
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "\n----------------------------------------\n";
	arr = push_row_back(arr, rows, cols);
	

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(arr + i) + j) << "\t";
		}
		cout << endl;
	}
	clear(arr, rows);
	
#endif // DYNAMIC_MEMORY_2
}
int** allocate(const unsigned int rows, const unsigned int cols)
{
	/////////////////////////////////////////////////////////////////////////////
	//////////////     Объявление двумерного динамического массива:      ////////
	/////////////////////////////////////////////////////////////////////////////
	//1) Объявляем указатель на указатель, и сохраняем в него адрес массива указателей
	int** arr = new int* [rows];
	//2) Создаём строки двумерного динамического массива:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
void clear(int** arr, const unsigned int rows)
{
	/////////////////////////////////////////////////////////////////////////////
	////////         Удаление двумерного динамического массива:          ////////
	/////////////////////////////////////////////////////////////////////////////
	//1) Удаляем строки:
	for (int i = 0; i < rows; i++)
	{
		delete arr[i];
	}
	//2) Удаляем массив указателей:
	delete[] arr;
}
void FillRand(int arr[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
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
void Print(int arr[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
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
int* push_back(int arr[], int& n, int r_value)
{
	//Добавление элементов в массив

    //1) Создаём буферный массив нужного размера:
	int* buffer = new int[n + 1];
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
int** push_row_back(int** arr, unsigned int& rows, const unsigned int cols)
{
	//1)Создаём буфферный массив указателей:
	int** buffer = new int* [rows + 1]{};
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
	arr[rows] = new int[cols] {};
	//6)Увеличиваем количество строк:
	rows++;
	//7)Возвращаем новый массив на место вызова:
	return arr;
}