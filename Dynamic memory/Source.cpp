#include<iostream>
using namespace std;

void FillRand  (int arr[], const int n);
template<typename T>void Print     (T arr[],       int n);
template<typename T>T* Push_back   (T arr[],      int& n , T value);
template<typename T>T* Push_front  (T arr[],      int& n , T value);
template<typename T>T* insert      (T arr[],      int& n , T value ,int index);
template<typename T>T* pop_back    (T arr[],      int& n);
template<typename T>T* pop_front   (T arr[],      int& n);
template<typename T>T* erase       (T arr[],      int& n ,          int index);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);

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
	arr = insert(arr, n, value, index);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Введите индекс удаляемого элемента"; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
template<typename T>void FillRand(T** arr, const int ROWS,const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
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
template<typename T>T* Push_back(T arr[], int& n, T value)
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
template<typename T>T* Push_front(T arr[], int& n, T value)
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
template<typename T>T* insert(T arr[], int& n, T value, int index)
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
template<typename T>T* pop_back(T arr[], int& n)
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
template<typename T>T* pop_front(T arr[], int& n)
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
template<typename T>T* erase(T arr[], int& n, int index)
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
