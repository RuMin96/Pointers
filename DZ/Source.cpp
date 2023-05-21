#include<iostream>
using namespace std;

void FillRand(int** arr, const int ROWS, const int COLS);
int** Allocate(const int ROWS, const int COLS);
void Print(int** arr, const int ROWS, const int COLS);
void Clear(int** arr, const int ROWS);
int** Double_arrays(int** arr, const int ROWS, const int COLS);
int** Push_row_back(int** &arr_dual,int &ROWS, const int COLS);
int** Push_row_front(int** & arr_dual, int& ROWS, const int COLS);
void Insert_row(int**& arr_dual, int& ROWS, const int COLS,int const index);
int** Pop_row_back(int**& arr_dual, int& ROWS, const int COLS);
void Pop_row_front(int**& arr_dual, int& ROWS, const int COLS);
int** Push_col_back(int**& arr_dual, const int ROWS,int& COLS);




void main()
{
	setlocale(LC_ALL, "");
	int ROWS, COLS,index;
	cout << "Введите количество строк"; cin >> ROWS;
	cout << "Введите количество элементов"; cin >> COLS;
	int** arr_dual = Allocate(ROWS, COLS);
	FillRand(arr_dual, ROWS, COLS);
	Print(arr_dual, ROWS, COLS);
	cout << endl;


	Push_row_back(arr_dual, ROWS, COLS);
	Print(arr_dual, ROWS, COLS);
	cout << endl;

	Push_row_front(arr_dual,ROWS, COLS);
	Print(arr_dual, ROWS, COLS);
	cout << endl;

	cout << "Введите индекс"; cin >> index;
	Insert_row(arr_dual,ROWS, COLS,index);
	Print(arr_dual, ROWS, COLS);
	cout << endl;

	Pop_row_back(arr_dual,ROWS, COLS);
	Print(arr_dual, ROWS, COLS);
	cout << endl;

	Pop_row_front(arr_dual, ROWS, COLS);
	Print(arr_dual, ROWS, COLS);
	cout << endl;

	Push_col_back(arr_dual, ROWS, COLS);
	Print(arr_dual, ROWS, COLS);
	cout << endl;





}
void FillRand(int** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
int** Allocate(const int ROWS, const int COLS)
{
	int** arr = new int* [ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		arr[i] = new int[COLS];
	}
	return arr;
}
void Print(int** arr, const int rows, const int cols)
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
void Clear(int** arr, const int ROWS)
{
	for (int i = 0; i < ROWS; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
int** Push_row_back(int** &arr, int &ROWS, const int COLS)
{
	int** buffer = Allocate(++ROWS,COLS);
	for (int i = 0; i < ROWS-1; i++) buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[ROWS-1] = new int[COLS] {};
	return arr;
}
int** Double_arrays(int** arr_dual, const int ROWS, const int COLS)
{
	

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << *(*(arr_dual + i) + j);
		}
		cout << endl;
	}
	return arr_dual;
}
int** Push_row_front(int**& arr, int& ROWS, const int COLS)
{
	int** buffer = Allocate(++ROWS, COLS);
	for (int i = 0; i < ROWS - 1; i++) buffer[i+1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = new int [COLS] {};
	return arr;
}
void Insert_row(int**& arr, int& ROWS, const int COLS, int const index)
{
	int** buffer = Allocate(++ROWS, COLS);
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < ROWS; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = new int[COLS] {};
}
int** Pop_row_back(int**& arr, int& ROWS, const int COLS)
{
	int** buffer = Allocate(--ROWS, COLS);
	for (int i = 0; i < ROWS; i++) buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[ROWS] = new int[COLS] {};
	return arr;
}
void Pop_row_front(int** & arr, int& ROWS, const int COLS)
{
	int** buffer = Allocate(--ROWS, COLS);
	for (int i = 0; i < ROWS; i++) buffer[i] = arr[i+1];
	delete[] arr;
	arr = buffer;
}
int** Push_col_back(int**& arr, const int ROWS, int& COLS)
{
	int** buffer = Allocate(ROWS, ++COLS);
	for (int i = 0; i < COLS - 1; i++) buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[COLS-1] = new int[ROWS] {};
	return arr;
}




