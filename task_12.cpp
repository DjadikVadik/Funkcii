
// 12.	Функция рисует красивый цветной игральный кубик.
//      В качестве параметров передаются случайные цвет, координаты и значение кубика.

#include <iostream>
#include <Windows.h>
using namespace std;

void Kubik(int tochki, int color = 15, int x = 0, int y = 0) {
	HANDLE h = GetStdHandle(-11);

	COORD cursor;
	cursor.X = x;
	cursor.Y = y;
	SetConsoleCursorPosition(h, cursor);
	SetConsoleTextAttribute(h, color * 16);

	char arr[5][9];

	for (size_t i = 0; i < 5; i++) 
		for (size_t j = 0; j < 9; j++) 
		  arr[i][j] = ' ';

	switch (tochki) {

	case 1: arr[2][4] = '@';
		break;
	case 2: arr[2][2] = '@';
		arr[2][6] = '@';
		break;
	case 3: arr[1][2] = '@';
		arr[2][4] = '@';
		arr[3][6] = '@';
		break;
	case 4: arr[1][2] = '@';
		arr[1][6] = '@';
		arr[3][2] = '@';
		arr[3][6] = '@';
		break;
	case 5: arr[1][2] = '@';
		arr[1][6] = '@';
		arr[2][4] = '@';
		arr[3][2] = '@';
		arr[3][6] = '@';
		break;
	case 6: arr[1][2] = '@';
		arr[1][6] = '@';
		arr[2][2] = '@';
		arr[2][6] = '@';
		arr[3][2] = '@';
		arr[3][6] = '@';
		break;
	}

	for (size_t i = 0; i < 5; i++) {
		cursor.X = x;
		cursor.Y = y + i;
		SetConsoleCursorPosition(h, cursor);
		for (size_t j = 0; j < 9; j++) {
			cout << arr[i][j];
		}
	}
	SetConsoleTextAttribute(h, 15);
}

int main() {

	Kubik(5, 15, 10, 3);
}