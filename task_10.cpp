
//  10.	Написать функцию, меняющую порядок следования элементов передаваемого ей массива на противоположный.

#include<iostream>
using namespace std;


void Naoborot(int arr[], const int X) {

	for (int i = 0; i < X / 2; i++) {
		swap(arr[i], arr[X - 1 - i]);
	}	
}




int main()
{
	system("chcp 1251 > 0");


	int mass[20];

	for (int i = 0; i < 20; i++)
		mass[i] = rand() % 50;

	for (int i = 0; i < 20; i++)
		cout << mass[i] << "\t";

	cout << "\n\n";

	Naoborot(mass, 20);

	for (int i = 0; i < 20; i++)
		cout << mass[i] << "\t";

	cout << "\n\n";

}