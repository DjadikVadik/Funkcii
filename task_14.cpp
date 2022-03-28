
//  14.	Написать игру «Крестики - нолики», реализовать 3 уровня сложности.Режим: 
//      человек – компьютер.Для реализации построить многофайловый проект.

#include <iostream>
#include <Windows.h>
using namespace std;

const int col = 3, row = 3;
char arr[row][col];

void initial() {
	for (int i = 0; i < row * col; i++)
		arr[0][i] = ' ';
}

void level_1() {

	bool game = true;

	while (game) {

		int x = rand() % 9;
		if (arr[0][x] == ' ') {
			arr[0][x] = 'O';
			game = false;
		}
	}
}

void level_2() {

	if (arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == ' ') arr[0][2] = 'O';
	else if (arr[0][3] == 'X' && arr[0][4] == 'X' && arr[0][5] == ' ') arr[0][5] = 'O';
	else if (arr[0][6] == 'X' && arr[0][7] == 'X' && arr[0][8] == ' ') arr[0][8] = 'O';

	else if (arr[0][1] == 'X' && arr[0][2] == 'X' && arr[0][0] == ' ') arr[0][0] = 'O';
	else if (arr[0][4] == 'X' && arr[0][5] == 'X' && arr[0][3] == ' ') arr[0][3] = 'O';
	else if (arr[0][7] == 'X' && arr[0][8] == 'X' && arr[0][6] == ' ') arr[0][6] = 'O';

	else {
		bool game = true;

		while (game) {

			int x = rand() % 9;
			if (arr[0][x] == ' ') {
				arr[0][x] = 'O';
				game = false;
			}
		}
	}
}

void level_3() {

	if (arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == ' ') arr[0][2] = 'O';
	else if (arr[0][3] == 'X' && arr[0][4] == 'X' && arr[0][5] == ' ') arr[0][5] = 'O';
	else if (arr[0][6] == 'X' && arr[0][7] == 'X' && arr[0][8] == ' ') arr[0][8] = 'O';
											
	else if (arr[0][1] == 'X' && arr[0][2] == 'X' && arr[0][0] == ' ') arr[0][0] = 'O';
	else if (arr[0][4] == 'X' && arr[0][5] == 'X' && arr[0][3] == ' ') arr[0][3] = 'O';
	else if (arr[0][7] == 'X' && arr[0][8] == 'X' && arr[0][6] == ' ') arr[0][6] = 'O';
												  
	else if (arr[0][0] == 'X' && arr[0][3] == 'X' && arr[0][6] == ' ') arr[0][6] = 'O';
	else if (arr[0][1] == 'X' && arr[0][4] == 'X' && arr[0][7] == ' ') arr[0][7] = 'O';
	else if (arr[0][2] == 'X' && arr[0][5] == 'X' && arr[0][8] == ' ') arr[0][8] = 'O';
												
	else if (arr[0][3] == 'X' && arr[0][6] == 'X' && arr[0][0] == ' ') arr[0][0] = 'O';
	else if (arr[0][4] == 'X' && arr[0][7] == 'X' && arr[0][1] == ' ') arr[0][1] = 'O';
	else if (arr[0][5] == 'X' && arr[0][8] == 'X' && arr[0][2] == ' ') arr[0][2] = 'O';
												 
	else if (arr[0][0] == 'X' && arr[0][4] == 'X' && arr[0][8] == ' ') arr[0][8] = 'O';
	else if (arr[0][4] == 'X' && arr[0][8] == 'X' && arr[0][0] == ' ') arr[0][0] = 'O';
	else if (arr[0][2] == 'X' && arr[0][4] == 'X' && arr[0][6] == ' ') arr[0][6] = 'O';
	else if (arr[0][6] == 'X' && arr[0][4] == 'X' && arr[0][2] == ' ') arr[0][2] = 'O';

	else {
		bool game = true;

		while (game) {

			int x = rand() % 9;
			if (arr[0][x] == ' ') {
				arr[0][x] = 'O';
				game = false;
			}
		}
	}
}

void show() {

	cout << " " << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << "            1 | 2 | 3\n";
	cout << "-----------          -----------\n";
	cout << " " << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << "            4 | 5 | 6\n";
	cout << "-----------          -----------\n";
	cout << " " << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << "            7 | 8 | 9\n\n";
}

void proverka(bool& gameOver) {



	if ((arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == 'X') ||
		(arr[0][3] == 'X' && arr[0][4] == 'X' && arr[0][5] == 'X') ||
		(arr[0][6] == 'X' && arr[0][7] == 'X' && arr[0][8] == 'X') ||
		(arr[0][0] == 'X' && arr[0][4] == 'X' && arr[0][8] == 'X') ||
		(arr[0][2] == 'X' && arr[0][4] == 'X' && arr[0][6] == 'X') ||
		(arr[0][0] == 'X' && arr[0][3] == 'X' && arr[0][6] == 'X') ||
		(arr[0][1] == 'X' && arr[0][4] == 'X' && arr[0][7] == 'X') ||
		(arr[0][2] == 'X' && arr[0][5] == 'X' && arr[0][8] == 'X')) {

		gameOver = true;
		cout << "Игрок победил!!!\n\n";
	}

	else if ((arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] == 'O') ||
		(arr[0][3] == 'O' && arr[0][4] == 'O' && arr[0][5] == 'O') ||
		(arr[0][6] == 'O' && arr[0][7] == 'O' && arr[0][8] == 'O') ||
		(arr[0][0] == 'O' && arr[0][4] == 'O' && arr[0][8] == 'O') ||
		(arr[0][2] == 'O' && arr[0][4] == 'O' && arr[0][6] == 'O') ||
		(arr[0][0] == 'O' && arr[0][3] == 'O' && arr[0][6] == 'O') ||
		(arr[0][1] == 'O' && arr[0][4] == 'O' && arr[0][7] == 'O') ||
		(arr[0][2] == 'O' && arr[0][5] == 'O' && arr[0][8] == 'O')) {

		gameOver = true;
		cout << "Компьютер победил!!!\n\n";
	}

	else {

		bool empty = false;

		for (int i = 0; i < row * col; i++)
			if (arr[0][i] == ' ') empty = true;

		if (!empty) {
			gameOver = true;
			cout << "Ничья!!!\n\n";
		}
	}
}


int main() {

	system("chcp 1251 > 0");
	srand(time(0));
	bool gameOver = false;

	initial();
	cout << "Введите уровень сложности: 1,2,3 (где 1 - самый легкий и 3 - самый сложный)\n";
	int level;
	cin >> level;

	do {
		system("cls");
		cout << "Введите номер ячейки в которую поставить 'X' номера указаны справа!!!\n\n";
		show();
		proverka(gameOver);
		if (gameOver) break;
		int num;
		cin >> num;
		arr[0][num - 1] = 'X';
		system("cls");
		cout << "Введите номер ячейки в которую поставить 'X' номера указаны справа!!!\n\n";
		show();
		proverka(gameOver);
		if (gameOver) break;
		if (level == 1) level_1();
		else if (level == 2) level_2();
		else if (level == 3) level_3();
	} while (true);
}