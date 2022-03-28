
//  8.	Написать функцию, определяющую среднее арифметическое элементов передаваемого ей массива.

#include<iostream>
using namespace std;

template <class T1>
double  Srednee(T1 arr[], const int SIZE) {
	
	double sum = 0;
	for (int i = 0; i < SIZE; i++)
		sum += arr[i];
	double srednee = sum / SIZE;

	return srednee;
}

int main()
{
	system("chcp 1251 > 0");
	int mass[5]{ 12,16,65,73,3 };
	double srednee = Srednee(mass, 5);

	cout << "Среднее арифметическое элементов массива = " << srednee << "\n";
}