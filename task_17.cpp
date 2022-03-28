
//  17.	Разбить код лабиринта(из предыдущей темы по двумерным массивам) на функции, на своё усмотрение.

#include<iostream>
#include<windows.h>
using namespace std;

const int X = 80,
Y = 25;
char mass[Y][X];

void initial() {

	system("color F0");


	for (int y = 0; y < Y; y++)          // стены комнаты
		for (int x = 0; x < X; x++) {
			if ((x == 2 && y > 1 && y < Y - 2) ||
				(x == 3 && y > 1 && y < Y - 2) ||
				(x == X - 3 && y > 1 && y < Y - 2) ||
				(x == X - 4 && y > 1 && y < Y - 2))
				mass[y][x] = ' ';
			else
				mass[y][x] = char(219);
		}
	int n = rand() % (Y - 4) + 2;           // выход из абиринта
	mass[n][X - 1] = ' ';
	mass[n][X - 2] = ' ';
}

void labirint(int y = Y / 2, int x = X - 4) {

	mass[y][x] = ' ';
	mass[y][x + 1] = ' ';

	string arr[4];
	int n = 0;

	if (mass[y - 2][x] != ' ' && mass[y - 2][x + 1] != ' ' && y - 2 > 0) {
		arr[n] = "UP";
		n++;
	}
	if (mass[y + 2][x] != ' ' && mass[y + 2][x + 1] != ' ' && y + 2 < Y - 1) {
		arr[n] = "DOWN";
		n++;
	}
	if (mass[y][x - 4] != ' ' && mass[y][x - 3] != ' ' && x - 4 > 1) {
		arr[n] = "LEFT";
		n++;
	}
	if (mass[y][x + 4] != ' ' && mass[y][x + 5] != ' ' && x + 5 < X - 2) {
		arr[n] = "RIGHT";
		n++;
	}

	int x1, y1;
	int k = 5;
	if (n > 0) k = rand() % n;


	if (arr[k] == "UP")
	{
		mass[y - 1][x] = ' ';
		mass[y - 1][x + 1] = ' ';
		mass[y - 2][x] = ' ';
		mass[y - 2][x + 1] = ' ';
		y1 = y - 2;
		x1 = x;
	}

	else if (arr[k] == "DOWN")
	{
		mass[y + 1][x] = ' ';
		mass[y + 1][x + 1] = ' ';
		mass[y + 2][x] = ' ';
		mass[y + 2][x + 1] = ' ';
		y1 = y + 2;
		x1 = x;
	}

	else if (arr[k] == "LEFT")
	{
		mass[y][x - 1] = ' ';
		mass[y][x - 2] = ' ';
		mass[y][x - 3] = ' ';
		mass[y][x - 4] = ' ';
		x1 = x - 4;
		y1 = y;
	}

	else if (arr[k] == "RIGHT")
	{
		mass[y][x + 1] = ' ';
		mass[y][x + 2] = ' ';
		mass[y][x + 3] = ' ';
		mass[y][x + 4] = ' ';
		mass[y][x + 5] = ' ';
		x1 = x + 4;
		y1 = y;
	}

	if (n > 0) labirint(y1, x1);
	if (n > 0) labirint(y, x);
}

void show() {


	HANDLE h = GetStdHandle(-11);

	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
				SetConsoleTextAttribute(h, 9);
				cout << mass[y][x];
		}
		cout << "\n";
	}
}

int main()
{
	srand(time(0));
	initial();
	labirint();
	show();
}