
//  11.	Функция рисует красивую цветную игральную карту.В качестве параметров передаются масть и достоинство карты.

#include <iostream>
#include <Windows.h>
using namespace std;

void Karta(string mast, string dostonstvo) {
	HANDLE h = GetStdHandle(-11);
	COORD c;
	
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 31; j++) {
			SetConsoleTextAttribute(h, 15 * 16);
			c.Y = i;
			c.X = j;
			SetConsoleCursorPosition(h, c);
			cout << " ";
		}
		cout << "\n";
	}

	int color;
	if (mast == "chirva" || mast == "bubna") color = 4;
	else color = 0;


	SetConsoleTextAttribute(h, 15 * 16 | color);
	c.Y = 1; 
	c.X = 3; 
	SetConsoleCursorPosition(h, c); 
	cout << dostonstvo;
	mast == "chirva" ? cout << char(3) : mast == "bubna" ? cout << char(4) : mast == "krestya" ? cout << char(5) : cout << char(6);

	c.Y = 23; 
	c.X = 26; 
	SetConsoleCursorPosition(h, c); 
	cout << dostonstvo;
	mast == "chirva" ? cout << char(3) : mast == "bubna" ? cout << char(4) : mast == "krestya" ? cout << char(5) : cout << char(6);

	if (mast == "chirva") {
		SetConsoleTextAttribute(h, color * 16);
		
		for (int y = 10; y < 15; y++) 
			for (int x = 12; x < 19; x++) 
				if ((y == 10 && (x == 13 || x == 14 || x == 16 || x == 17)) ||
					(y == 11 && x > 11 && x < 19) ||
					(y == 12 && x > 12 && x < 18) ||
					(y == 13 && x > 13 && x < 17) ||
					(y == 14 && x == 15)) {

					c.Y = y;
					c.X = x;
					SetConsoleCursorPosition(h, c);
					cout << " ";
				}
	}

	else if (mast == "pika") {
		SetConsoleTextAttribute(h, color * 16);

		for (int y = 10; y < 15; y++) 
			for (int x = 12; x < 19; x++) 
				if ((y == 10 && x == 15) ||
					(y == 11 && x > 13 && x < 17) ||
					(y == 12 && x > 12 && x < 18) ||
					(y == 13 && x > 11 && x < 19) ||
					(y == 14 && x == 15)) {

					c.Y = y;
					c.X = x;
					SetConsoleCursorPosition(h, c);
					cout << " ";
				}
	}

	else if (mast == "bubna") {
		SetConsoleTextAttribute(h, color * 16);

		for (int y = 10; y < 15; y++)
			for (int x = 12; x < 19; x++)
				if ((y == 10 && x == 15) ||
					(y == 11 && x > 13 && x < 17) ||
					(y == 12 && x > 12 && x < 18) ||
					(y == 13 && x > 13 && x < 17) ||
					(y == 14 && x == 15)) {

					c.Y = y;
					c.X = x;
					SetConsoleCursorPosition(h, c);
					cout << " ";
				}
	}

	else if (mast == "krestya") {
		SetConsoleTextAttribute(h, color * 16);

		for (int y = 10; y < 15; y++)
			for (int x = 11; x < 20; x++)
				if ((y == 10 && (x == 15 || x == 14 || x == 16)) ||
					(y == 11 && (x == 11 || x == 15 || x == 19)) ||
					(y == 12 && x > 10 && x < 20) ||
					(y == 13 && (x == 11 || x == 15 || x == 19)) ||
					(y == 14 && (x == 15 || x == 14 || x == 16))) {

					c.Y = y;
					c.X = x;
					SetConsoleCursorPosition(h, c);
					cout << " ";
				}
	}

	c.Y = 27;
	c.X = 0;
	SetConsoleTextAttribute(h, 15);
	SetConsoleCursorPosition(h, c);
	
}

int main() {

	Karta("chirva", "B");
}