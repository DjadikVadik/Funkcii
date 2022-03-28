
//  1.	Написать функцию, которая принимает две даты(т.е.функция принимает шесть параметров) 
//      и вычисляет разность в днях между этими датами.Для решения этой задачи необходимо также 
//      написать функцию, которая определяет, является ли год високосным.

#include <iostream>
using namespace std;


void kolichestvoDney(int day1, int month1, int year1, int day2, int month2, int year2) {
	int months[13]{ 0,31,0,31,30,31,30,31,31,30,31,30,31 };
	int sum = 0;

	if (month1 == month2 && year1 == year2) sum = day2 - day1;

	else {
		sum = months[month1] - day1;
		do {
			month1++;
			if (month1 == 13) {
				month1 = 1;
				year1++;
			}
			if (year1 % 4 == 0) months[2] = 29;
			else months[2] = 28;
			sum += months[month1];
		} while (month1 != month2 && year1 != year2);

		sum = sum - months[month1] + day2;
	}
	cout << "\nРазность между этими датами состовляет: " << sum << " дней\n";
}

int main()
{
	system("chcp 1251 >nul");

	cout << "Введите первую дату - день (2 цифры): ";
	int day1;
	cin >> day1;
	cout << "Введите первую дату - месяц (2 цифры): ";
	int month1;
	cin >> month1;
	cout << "Введите первую дату - год (4 цифры): ";
	int year1;
	cin >> year1;

	cout << "Введите вторую дату - день (2 цифры): ";
	int day2;
	cin >> day2;
	cout << "Введите вторую дату - месяц (2 цифры): ";
	int month2;
	cin >> month2;
	cout << "Введите вторую дату - год (4 цифры): ";
	int year2;
	cin >> year2;

	kolichestvoDney(day1, month1, year1, day2, month2, year2);
}
