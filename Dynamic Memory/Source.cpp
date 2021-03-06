#include<iostream>
using std::cout;
using std::cin;
using std::endl;
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

//Заполнение массивов & вывод на экран:
void FillRand(int arr[], const unsigned int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const unsigned int rows, const unsigned int cols, int minRand = 0, int maxRand = 100);
void Print(int arr[], const unsigned int n);
void Print(int** arr, const unsigned int rows, const unsigned int cols);

//Создание и удаление двумерного массива:
int** allocate(const unsigned int rows, const unsigned int cols);
void clear(int** arr, const unsigned int rows);

//Основные функции для одномерного массива:
int* push_back(int arr[], int& n, int r_value);
int* push_front(int arr[], int& n, int l_value);
int* insert(int arr[], int& n, int insert_value, int insert_index);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int pop_index);

//Основные функции для двумерного массива:
int** push_row_back(int** arr, unsigned int& rows, const unsigned int cols);
int** push_row_front(int** arr, unsigned int& rows, const unsigned int cols);
int** insert_row(int** arr, unsigned int& rows, const unsigned int cols, unsigned int insert_index);
int** pop_row_back(int** arr, unsigned int& rows, const unsigned int cols);
int** pop_row_front(int** arr, unsigned int& rows, const unsigned int cols);
int** erase_row(int** arr, unsigned int& rows, const unsigned int cols, unsigned int pop_index);

void push_col_back(int** arr, const unsigned int rows, unsigned int& cols);
void push_col_front(int** arr, const unsigned int rows, unsigned int& cols);
void insert_col(int** arr, const unsigned int rows, unsigned int& cols, unsigned int insert_index);
void pop_col_back(int** arr, const unsigned int rows, unsigned int& cols);
void pop_col_front(int** arr, const unsigned int rows, unsigned int& cols);
void erase_col(int** arr, const unsigned int rows, unsigned int& cols, unsigned int pop_index);

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
	cout << "Вывод исходного массива: " << endl;
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	
	/*cout << "Добавление строки в конец массива: " << endl;
	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 200, 300);
	Print(arr, rows, cols);
	
	cout << "Добавление строки в начало массива: " << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	int insert_index;
	cout << "Введите индекс ряда массива в который хотите добавить строку: "; cin >> insert_index;
	arr = insert_row(arr, rows, cols, insert_index);
	Print(arr, rows, cols);

	cout << "Удаление строки с конца массива: " << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаление строки с начала массива: " << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	int pop_index;
	cout << "Введите индекс ряда массива из которого хотите удалить строку: "; cin >> pop_index;
	arr = erase_row(arr, rows, cols, pop_index);
	Print(arr, rows, cols);*/

	cout << "Добавление столбца в конец массива: " << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	
	cout << "Добавление столбца в начало массива: " << endl;
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	unsigned int insert_index;
	cout << "Введите индекс по которому хотите вставить столбец в массив: "; cin >> insert_index;
	insert_col(arr, rows, cols, insert_index);
	Print(arr, rows, cols);

	cout << "Удаление столбца в конце массива: " << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаление столбца в начале массива: " << endl;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	unsigned int pop_index;
	cout << "Введите индекс по которому хотите удалить столбец из массива: "; cin >> pop_index;
	erase_col(arr, rows, cols, pop_index);
	Print(arr, rows, cols);

	/*//Заполнение "случайными" числами столбца в конце массива:
	for (int i = 0; i < rows; i++)
	{
		arr[i][cols - 1] = rand() % 1000;
	}
	Print(arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(arr + i) + j) << "\t";
		}
		cout << endl;
	}*/
	clear(arr, rows);
#endif // DYNAMIC_MEMORY_2
}
//Для одномерных массивов:
void FillRand(int arr[], const unsigned int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
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
	if (insert_index >= n)return arr;
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
	if (pop_index >= n)return arr;
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
//Для двумерных массивов:
void FillRand(int** arr, const unsigned int rows, const unsigned int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
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
	if (insert_index >= rows)return arr;
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
	if (pop_index >= rows)return arr;
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
void push_col_back(int** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) Создаём буфферную строку, размером на 1 элемент больше:
		int* buffer = new int [cols + 1]{};
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
void push_col_front(int** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void insert_col(int** arr, const unsigned int rows, unsigned int& cols, unsigned int insert_index)
{
	if (insert_index >= rows)cout << "Индекс больше массива!\n";
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < insert_index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = insert_index + 1; j < cols + 1; j++)
		{
			buffer[j] = arr[i][j-1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void pop_col_back(int** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < cols-1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;
}
void pop_col_front(int** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;
}
void erase_col(int** arr, const unsigned int rows, unsigned int& cols, unsigned int pop_index)
{
	if (pop_index >= rows)cout << "Индекс больше массива!\n";
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols-1];
		for (int j = 0; j < pop_index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for(int j = pop_index; j < cols-1; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;
}