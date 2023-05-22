#include<iostream>
using namespace std;

int**  Allocate                        (               const  int  ROWS  , const int COLS);
template<typename T>void FillRand      (T**  arr,      const  int  ROWS  , const int COLS);
template<typename T>void Print         (T**  arr,      const  int  ROWS  , const int COLS);
template<typename T>void Clear         (T**  arr,      const  int  ROWS) ;
template<typename T>T**  Double_arrays (T**  arr,      const  int  ROWS  , const int COLS);
template<typename T>T**  Push_row_back (T** &arr_dual,        int& ROWS  , const int COLS);
template<typename T>T**  Push_row_front(T** &arr_dual,        int& ROWS  , const int COLS);
template<typename T>void Insert_row    (T** &arr_dual,        int& ROWS  , const int COLS,int const index);
template<typename T>T**  Pop_row_back  (T** &arr_dual,        int& ROWS  , const int COLS);
template<typename T>void Pop_row_front (T** &arr_dual,        int& ROWS  , const int COLS);
template<typename T>T**  Push_col_back (T** &arr_dual, const  int  ROWS  ,       int&COLS);




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
template<typename T>void FillRand(T** arr, const int ROWS, const int COLS)
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
template<typename T>void Print(T** arr, const int rows, const int cols)
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
template<typename T>void Clear(T** arr, const int ROWS)
{
	for (int i = 0; i < ROWS; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
template<typename T>T** Push_row_back(T** &arr, int &ROWS, const int COLS)
{
	T** buffer = Allocate(++ROWS,COLS);
	for (int i = 0; i < ROWS-1; i++) buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[ROWS-1] = new int[COLS] {};
	return arr;
}
template<typename T>T** Double_arrays(T** arr_dual, const int ROWS, const int COLS)
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
template<typename T>T** Push_row_front(T**& arr, int& ROWS, const int COLS)
{
	T** buffer = Allocate(++ROWS, COLS);
	for (int i = 0; i < ROWS - 1; i++) buffer[i+1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = new int [COLS] {};
	return arr;
}
template<typename T> void Insert_row(T**& arr, int& ROWS, const int COLS, int const index)
{
	T** buffer = Allocate(++ROWS, COLS);
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
template<typename T>T ** Pop_row_back(T**& arr, int& ROWS, const int COLS)
{
	T** buffer = Allocate(--ROWS, COLS);
	for (int i = 0; i < ROWS; i++) buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[ROWS] = new int[COLS] {};
	return arr;
}
template<typename T>void Pop_row_front(T** & arr, int& ROWS, const int COLS)
{
	T** buffer = Allocate(--ROWS, COLS);
	for (int i = 0; i < ROWS; i++) buffer[i] = arr[i+1];
	delete[] arr;
	arr = buffer;
}
template<typename T>T** Push_col_back(T**& arr, const int ROWS, int& COLS)
{
	T** buffer = Allocate(ROWS, ++COLS);
	for (int i = 0; i < COLS - 1; i++) buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[COLS-1] = new int[ROWS] {};
	return arr;
}




