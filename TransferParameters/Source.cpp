#include<iostream>
using namespace std;
/*
----------------------------------
1.by value;
2.by pointer;
3.by reference;
----------------------------------
*/

void Exchange(int a, int b);

void main()
{
	setlocale(LC_ALL, "");
	int a = 2, b = 3;
	cout << a << "\t" << b << endl;
	Exchange(a, b);
	cout<<a<<"\t"<<b<<endl;
}
void Exchange(int a, int b)
{
	int buffer = a;
	a = b;
	b = buffer;
}
