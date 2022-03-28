
// 15.	Написать игру «Пятнашки».

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
using namespace std;

const int STR = 4,
COL = 4;

void Initial(string arr[STR][COL]) {
	for (int i = 0; i < STR * COL - 1;) {
		bool povtor = false;
		string x = to_string(rand() % 15 + 1);
		for (int j = 0; j < i; j++)
			if (arr[0][j] == x) povtor = true;
		if (!povtor) {
			arr[0][i] = x;
			i++;
		}
	}
	arr[0][15] = "  ";
}

void show(string arr[STR][COL]) {
	cout << "_________________________________\n";
	for (int y = 0; y < STR; y++) {
		for (int x = 0; x < COL; x++) {
			cout << arr[y][x] << "\t|";
		}		
		cout << "\n_________________________________\n";
	}
}

void input(string& napravlenie) {

	if (_kbhit()) {

		switch (_getch()) {

		case 75:  // влево
			napravlenie = "LEFT";
			break;
		case 77: // вправо
			napravlenie = "RIGHT";
			break;
		case 80: // вниз
			napravlenie = "DOWN";
			break;
		case 72: // вверх
			napravlenie = "UP";
			break;
		}
	}
}

void Logoka(string arr[STR][COL], string& napravlenie, int& hodov) {

	for (int y = 0; y < STR; y++) {
		for (int x = 0; x < COL; x++) {
			if (arr[y][x] == "  " && napravlenie == "LEFT" && x - 1 >= 0) {
				swap(arr[y][x], arr[y][x - 1]);
				napravlenie = " ";
				hodov++;
			}
			else if (arr[y][x] == "  " && napravlenie == "RIGHT" && x + 1 < COL) {
				swap(arr[y][x], arr[y][x + 1]);
				napravlenie = " ";
				hodov++;
			}
			else if (arr[y][x] == "  " && napravlenie == "DOWN" && y + 1 < STR) {
				swap(arr[y][x], arr[y + 1][x]);
				napravlenie = " ";
				hodov++;
			}
			else if (arr[y][x] == "  " && napravlenie == "UP" && y - 1 >= 0) {
				swap(arr[y][x], arr[y - 1][x]);
				napravlenie = " ";
				hodov++;
			}
		}
	}
}

void logika_zaversheniya(string arr[STR][COL], bool& gameOver) {

	bool sovpadenie = true;
	for (int i = 0; i < STR * COL - 1; i++) {
		if (arr[0][i] != to_string(i + 1))
			sovpadenie = false;
	}
	if (sovpadenie) {
		gameOver = true;
		cout << "\n\nПоздравляем вы выиграли!!!\n";
	}
}

void pologenie_cursora() {
	HANDLE h = GetStdHandle(-11);

	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 100;
	SetConsoleCursorInfo(h, &info);


	COORD cursor;
	cursor.X = 0;
	cursor.Y = 0;
	SetConsoleCursorPosition(h, cursor);
}

void statistica(int hodov) {
	HANDLE h = GetStdHandle(-11);

	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 100;
	SetConsoleCursorInfo(h, &info);

	COORD cursor;
	cursor.X = 37;
	cursor.Y = 4;
	SetConsoleCursorPosition(h, cursor);
	cout << "Совершино ходов - " << hodov << "  ";
}

int main() {

	system("chcp 1251 >0");
	srand(time(0));
	string mass[STR][COL];
	string napravlenie;
	bool gameOver = false;
	int hodov = 0;
	Initial(mass);

	do {
		pologenie_cursora();
		cout << "Управляя стрелочками на калавиатуре перемещайте пустую ячейку\n"
			<< "пока не соберете возростающую последовательность!!!\n\n";
		input(napravlenie);
		Logoka(mass, napravlenie, hodov);
		show(mass);
	    statistica(hodov);
		logika_zaversheniya(mass, gameOver);
	} while (!gameOver);

}