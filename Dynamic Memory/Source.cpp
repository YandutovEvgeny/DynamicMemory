#include<iostream>  //Директива языка Си
using std::cout;    //using - Директива языка С++
using std::cin;
using std::endl;
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
#define DATA_TYPE double


//Заполнение массивов & вывод на экран:
template <typename T>void FillRand(T arr[], const unsigned int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const unsigned int n, int minRand = 0, int maxRand = 100);
void FillRand(char arr[], const unsigned int n);
template <typename T>void FillRand(T** arr, const unsigned int rows, const unsigned int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const unsigned int rows, const unsigned int cols, int minRand = 0, int maxRand = 100);
void FillRand(char** arr, const unsigned int rows, const unsigned int cols);
template <typename T>void Print(T arr[], const unsigned int n);
template <typename T>void Print(T** arr, const unsigned int rows, const unsigned int cols);

//Создание и удаление двумерного массива:
template <typename T>T** allocate(unsigned int rows, unsigned int cols);
template <typename T>void clear(T** arr, const unsigned int rows);

//Основные функции для одномерного массива:
template <typename T>T* push_back(T arr[], int& n, int r_value);
template <typename T>T* push_front(T arr[], int& n, int l_value);
template <typename T>T* insert(T arr[], int& n, int insert_value, int insert_index);
template <typename T>T* pop_back(T arr[], int& n);
template <typename T>T* pop_front(T arr[], int& n);
template <typename T>T* erase(T arr[], int& n, int pop_index);

//Основные функции для двумерного массива:
template <typename T>T** push_row_back(T**& arr, unsigned int& rows, unsigned int& cols);
template <typename T>T** push_row_front(T**& arr, unsigned int& rows, unsigned int& cols);
template <typename T>T** insert_row(T**& arr, unsigned int& rows, unsigned int& cols, unsigned int insert_index);
template <typename T>T** pop_row_back(T**& arr, unsigned int& rows, unsigned int& cols);
template <typename T>T** pop_row_front(T**& arr, unsigned int& rows, unsigned int& cols);
template <typename T>T** erase_row(T**& arr, unsigned int& rows, unsigned int& cols, unsigned int pop_index);

template <typename T>void push_col_back(T**& arr, unsigned int& rows, unsigned int& cols);
template <typename T>void push_col_front(T**& arr, unsigned int& rows, unsigned int& cols);
template <typename T>void insert_col(T**& arr, unsigned int& rows, unsigned int& cols, unsigned int insert_index);
template <typename T>void pop_col_back(T**& arr, unsigned int& rows, unsigned int& cols);
template <typename T>void pop_col_front(T**& arr, unsigned int& rows, unsigned int& cols);
template <typename T>void erase_col(T**& arr, unsigned int& rows, unsigned int& cols, unsigned int pop_index);

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
	
	DATA_TYPE** arr = allocate<DATA_TYPE>(rows, cols);
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
template <typename T>
void FillRand(T arr[], const unsigned int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(double arr[], const unsigned int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		arr[i] = double(rand() % (maxRand - minRand) + minRand);
		arr[i] /= 100;
	}
}
void FillRand(char arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = char(rand());
	}
}
template <typename T>
void Print(T arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
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
T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
template <typename T>
T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
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
//Для двумерных массивов:
template <typename T>
void FillRand(T** arr, const unsigned int rows, const unsigned int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}
void FillRand(double** arr, const unsigned int rows, const unsigned int cols, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = double(rand() % (maxRand - minRand) + minRand);
			arr[i][j] /= 100;
		}
	}
}
void FillRand(char** arr, const unsigned int rows, const unsigned int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}
template <typename T>
void Print(T** arr, const unsigned int rows, const unsigned int cols)
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
template <typename T>
T** allocate(unsigned int rows, unsigned int cols)
{
	/////////////////////////////////////////////////////////////////////////////
	//////////////     Объявление двумерного динамического массива:      ////////
	/////////////////////////////////////////////////////////////////////////////
	//1) Объявляем указатель на указатель, и сохраняем в него адрес массива указателей
	T** arr = new T* [rows];
	//2) Создаём строки двумерного динамического массива:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols] {};
	}
	return arr;
}
template <typename T>
void clear(T** arr, const unsigned int rows)
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
template <typename T>
T** push_row_back(T**& arr, unsigned int& rows, unsigned int& cols)
{
	//1)Создаём буфферный массив указателей:
	T** buffer = new T* [rows + 1]{};
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
	arr[rows] = new T*[cols] {};
	//6)Увеличиваем количество строк:
	rows++;
	//7)Возвращаем новый массив на место вызова:
	return arr;
}
template <typename T>
T** push_row_front(T**& arr, unsigned int& rows, unsigned int& cols)
{
	T** buffer = new T* [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new T*[cols] {};
	rows++;
	return arr;
}
template <typename T>
T** insert_row(T**& arr, unsigned int& rows, unsigned int& cols, unsigned int insert_index)
{
	if (insert_index >= rows)return arr;
	T** buffer = new T* [rows + 1]{};
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
	arr[insert_index] = new T*[cols] {};
	rows++;
	return arr;
}
template <typename T>
T** pop_row_back(T**& arr, unsigned int& rows, unsigned int& cols)
{
	T** buffer = new T* [--rows]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
template <typename T>
T** pop_row_front(T**& arr, unsigned int& rows, unsigned int& cols)
{
	T** buffer = new T* [--rows]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
template <typename T>
T** erase_row(T**& arr, unsigned int& rows, unsigned int& cols, unsigned int pop_index)
{
	if (pop_index >= rows)return arr;
	T** buffer = new T* [--rows]{};
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
template <typename T>
void insert_col(T**& arr, unsigned int& rows, unsigned int& cols, unsigned int insert_index)
{
	if (insert_index >= cols)cout << "Индекс больше массива!\n";
	else
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
}
template <typename T>
void pop_col_back(T**& arr, unsigned int& rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols-1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;
}
template <typename T>
void pop_col_front(T**& arr, unsigned int& rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;
}
template <typename T>
void erase_col(T**& arr, unsigned int& rows, unsigned int& cols, unsigned int pop_index)
{
	if (pop_index >= cols)cout << "Индекс больше массива!\n";
	else
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
}