
//  16.	Написать функцию Module для расчёта остатка от деления двух чисел. 
//      Предусмотреть перегрузки для типов (int, double, float). Не использовать 
//      стандартные функции! (оператор %  можно использовать).

#include <iostream>
using namespace std;


int Module(int a, int b) {
	int module = a % b;
	return module;
}

double Module(double a, double b) {
	double module;
	if (a < b && a > 0 && b > 0) module = a;
	else {
		int mnogitel = a / b;
		module = a - (b * mnogitel);
	}
	return module;
}

float Module(float a, float b) {
	float module;
	if (a < b && a > 0 && b > 0) module = a;
	else {
		int mnogitel = a / b;
		module = a - (b * mnogitel);
	}
	return module;
}



int main()
{
	system("chcp 1251 >nul");


	double x = Module(-18.5,4.2);
	cout << "Остаток от деления = " << x << "\n";
}
