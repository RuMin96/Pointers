#include<iostream>
using namespace std;

void Sort(int arr[i]);

void main()
{
	setlocale(LC_ALL, "");
	int n = 10;
	double division;
	double* arr = new double[n];
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
	   division = arr[i] / 2;
		cout << division <<"\t";
	}
}