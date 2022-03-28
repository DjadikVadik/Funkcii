
//    1.	Написать функцию SetCursor, которая устанавливает координаты и цвет текста. 
//          Функция принимает три аргумента: координата по X, координата по Y, номер цвета.

#include <iostream>
#include <Windows.h>
using namespace std;


void SetCursor(int y, int x, int color) {

    HANDLE h = GetStdHandle(-11);
    COORD cursor;
    cursor.Y = y;
    cursor.X = x;
    SetConsoleTextAttribute(h, color);
    SetConsoleCursorPosition(h, cursor);
}

int main()
{
    SetCursor(2, 2, 12);

    cout << "Program working" << "\n";
}