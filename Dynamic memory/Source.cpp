#include<iostream>
using namespace std;

template<typename T>T** Allocate(const  int  ROWS, const int COLS);
template<typename T>void Clear(T** arr, const  int  ROWS);

void FillRand  (int arr[], const int n);
void FillRand  (double arr[], const int n);
void FillRand  (char arr[], const int n);

void FillRand(int** arr_dual, const  int  ROWS, const int COLS);
void FillRand(double** arr_dual, const  int  ROWS, const int COLS);
void FillRand(char** arr_dual, const  int  ROWS, const int COLS);

template<typename T>void Print     (T arr[],      const int n);
template<typename T>void Print_dual(T** arr, const  int  ROWS, const int COLS);

template<typename T>T* Push_back   (T* arr,      int& n , T value);
template<typename T>T* Push_front  (T* arr,      int& n , T value);
template<typename T>T* insert      (T* arr,      int& n , T value ,int index);

template<typename T>T* pop_back    (T* arr,      int& n);
template<typename T>T* pop_front   (T* arr,      int& n);
template<typename T>T* erase       (T* arr,      int& n ,          int index);
template<typename T>T** Double_arrays(T** arr, const  int  ROWS, const int COLS);

template<typename T>T** Push_row_back (T** arr_dual, int& rows, const int COLS);
template<typename T>T** Push_row_front (T** arr_dual, int& rows, const int COLS);
template<typename T>void Push_col_back(T**& arr_dual, const  int  ROWS, int& cols);
template<typename T>T** Insert_row (T** arr_dual, int& rows, const int COLS, const int index);
template<typename T>T** Pop_row_back(T**& arr_dual, int& rows, const int COLS);
template<typename T>T** Pop_row_front(T** arr_dual, int& rows, const int COLS);
template<typename T>void Pop_col_back(T**& arr_dual, const int ROWS, int& cols);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение:"; cin >> value;
	arr = Push_back(arr, n, value);
	Print(arr, n);
	
	cout << "Введите добавляемое значение:"; cin >> value;
	arr = Push_front(arr, n, value);
	Print(arr, n);
	
	int index;
	cout << "Введите добавляемое значение:"; cin >> value;
	cout << "Введите индекс добавляемого элемента"; cin >> index;
	arr = insert(arr, n,value, index);
	Print(arr, n);
	
	arr = pop_back(arr, n);
	Print(arr, n);
	
	arr = pop_front(arr, n);
	Print(arr, n);
	
	cout << "Введите индекс удаляемого элемента"; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);


	int rows, cols;
	cout << "Введите количество строк"; cin >> rows;
	cout << "Введите количество элементов"; cin >> cols;
	int** arr_dual = Allocate<int>(rows, cols);

	FillRand(arr_dual, rows, cols);
	Print_dual(arr_dual, rows, cols);
	cout << endl;

	Push_row_back(arr_dual, rows, cols);
	Print_dual(arr_dual, rows, cols);
	cout << endl;

	Push_row_front(arr_dual, rows, cols);
	Print_dual(arr_dual, rows, cols);
	cout << endl;

	cout << "Введите индекс"; cin >> index;
	Insert_row(arr_dual, rows, cols, index);
	Print_dual(arr_dual, rows, cols);
	cout << endl;

	Pop_row_back(arr_dual, rows, cols);
	Print_dual(arr_dual, rows, cols);
	cout << endl;

	Pop_row_front(arr_dual, rows, cols);
	Print_dual(arr_dual, rows, cols);
	cout << endl;

	Push_col_back(arr_dual, rows, cols);
	Print_dual(arr_dual, rows, cols);
	cout << endl;

	Pop_col_back(arr_dual, rows, cols);
	Print_dual(arr_dual, rows, cols);
	cout << endl;


	Clear(arr_dual, rows);

	delete[] arr;
}
template<typename T>T** Allocate(const int ROWS, const int COLS)
{
	T** arr = new T* [ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		arr[i] = new T[COLS];
	}
	return arr;
}
template<typename T>void Clear(T** arr, const int ROWS)
{
	for (int i = 0; i < ROWS; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 10000;
		arr[i] /= 100;
	}
}
void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand();
	}
}
void FillRand(int** arr, const int ROWS,const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void FillRand(double** arr, const int ROWS,const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 10000;
			arr[i][j] /= 100;
		}
	}
}
void FillRand(char** arr, const int ROWS,const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand();
		}
	}
}
template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>void Print_dual(T** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
template<typename T>T* Push_back(T* arr, int& n, T value)
{
	//Cоздаем буферный массив нужного размера(на 1 элемент больше)
	T* buffer = new T[n + 1];
	//Копируем  все значения из исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//Удаляем исходный массив:
	delete[] arr;
	//Подменяем адрес исходного массива адресом нового массива:
	arr = buffer;
	buffer = nullptr;
	//В массив arr можно добавить значение:
	arr[n] = value;
	n++;
	return arr;
}
template<typename T>T* Push_front(T* arr, int& n, T value)
{
	T* buffer = new T [n + 1];
	buffer[0] = value;

	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
	n++;
	return arr;
}
template<typename T>T* insert(T* arr, int& n, T value, int index)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index;i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
template<typename T>T* pop_back(T* arr, int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n-1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
	n--;
	return arr;

}
template<typename T>T* pop_front(T* arr, int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
	n--;
	return arr;
}
template<typename T>T* erase(T* arr, int& n, int index)
{
	T* buffer = new T[--n];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
template<typename T>T** Push_row_back(T** arr, int& rows, const int COLS)
{
	return Push_back(arr, rows, new T[COLS]{});
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
template<typename T>T** Push_row_front(T** arr, int& rows, const int COLS)
{
	T** buffer = new T*[++rows, COLS];
	for (int i = 0; i < rows - 1; i++) buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = new T [COLS] {};
	return arr;
}
template<typename T> T** Insert_row(T** arr, int& rows, const int COLS, int const index)
{
	T** buffer =new T*[++rows, COLS];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < rows - 1; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = new int[COLS] {};
	return arr;
}
template<typename T>T** Pop_row_back(T**& arr, int& rows, const int COLS)
{
	delete[] arr[rows - 1];
	T** buffer = new T * [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T>T** Pop_row_front(T** arr, int& rows, const int COLS)
{

	T** buffer = new T*[--rows, COLS];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
	return arr;
}
template<typename T>void Push_col_back(T**& arr, const int ROWS, int& cols)
{
	for (int i = 0; i < ROWS; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void Pop_col_back(T**& arr, const int ROWS, int& cols)
{
	cols--;
	for (int i = 0; i < ROWS; i++)
	{
		T* buffer = new T [cols] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
}
