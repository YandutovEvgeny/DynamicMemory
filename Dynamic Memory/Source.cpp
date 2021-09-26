#include"stdafx.h"
#include"allocate-n-clear.h"
#include"Fill-n-Print.h"
#include"Prototypes for MDA.h"
#include"Prototypes for ODA.h"
#include"Realizations for MDA.h"
#include"Realizations for ODA.h"

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
	
	cout << "Добавление строки в конец массива: " << endl;
	arr = push_row_back(arr, rows, cols);
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
	Print(arr, rows, cols);

	/*for (int i = 0; i < rows; i++)
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