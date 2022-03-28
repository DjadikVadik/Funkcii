
//  6.	Написать функцию, которая получает в качестве параметров 2 
//      целых числа и возвращает сумму чисел из диапазона между ними.

#include<iostream>
using namespace std;

int SumDiapazona(int a, int b) {

	int sum = 0;
	if (a > b) swap(a, b);
	for (int i = a; i <= b; i++)
		sum += i;

	return sum;
}

int main()
{
	system("chcp 1251 > 0");
	int a = 5, b = 11;

	int sum = SumDiapazona(a, b);

	cout << "Сумма чисел диапазона = " << sum << "\n";
}