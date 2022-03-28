
//   9.	Написать функцию, показывающую на экран минимум и максимум
//      (значение и индекс) среди элементов передаваемого ей массива.

#include<iostream>
using namespace std;


void MaxMin(int arr[], const int X) {

	int min = arr[0];
	int max = arr[0];
	int max_i, min_i;

	for (int i = 0; i < X; i++) {
		if (arr[i] > max) {
			max = arr[i];
			max_i = i;
		}
		if (arr[i] < min) {
			min = arr[i];
			min_i = i;
		}
	}

	cout << "Максимальный элимент массива = " << max << " и имеет индекс : " << max_i << "\n";
	cout << "Мминимальный элимент массива = " << min << " и имеет индекс : " << min_i << "\n";
}




int main()
{
	system("chcp 1251 > 0");


	int mass[25];

	for (int i = 0; i < 25; i++)
		mass[i] = rand() % 50;

	MaxMin(mass, 25);

}