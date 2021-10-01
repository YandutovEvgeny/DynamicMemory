#include"stdafx.h"
#include"FillRandAndPrint.h"
#include"FillRandAndPrint.cpp"
#include"allocateAndclear.h"
#include"allocateAndclear.cpp"
#include"push_backAndpush_front.h"
#include"push_backAndpush_front.cpp"
#include"pop_backAndpop_front.h"
#include"pop_backAndpop_front.cpp"
#include"insertAnderase.h"
#include"insertAnderase.cpp"

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
	double** arr = allocate<double>(rows, cols);
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