
//  13.	Написать функцию для округления заданного числа 
//      до указанного количества знаков после запятой.

#include <iostream>
using namespace std;

double Okruglit(double chislo, int znak) {

	int x = chislo * (pow(10, (znak + 1)));
	int x1 = x % 10;
	double chislo1;
	if (x1 > 4) chislo1 = (x / 10 + 1) / pow(10, znak);
	else chislo1 = (x / 10) / pow(10, znak);
	return chislo1;
}



int main()
{
	system("chcp 1251 >nul");


	double x = 12.3456;
	cout << "число до преобразования = " << x << "\n";

	x = Okruglit(x, 3);
	cout << "число после преобразования = " << x << "\n";
}
