
//   3.	Написать функцию Rectangle, которая выводит на экран прямоугольник. Функция принимает 
//      такие параметры: ширина, высота, символ рамки, символ заливки, цвет рамки, цвет заливки, 
//      координаты верхнего левого угла по X и Y. У функции должны быть параметры по умолчанию.

#include <iostream>
#include <Windows.h>
using namespace std;


void Rectangle(int height, int width, char simvol1, char simvol2, int color1 = 12, int color2 = 14, int y = 2, int x = 5) {

    HANDLE h = GetStdHandle(-11);
    COORD cursor;
    cursor.Y = y;
    cursor.X = x;
    SetConsoleCursorPosition(h, cursor);
   
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || i == 0 || j == width - 1 || i == height - 1) {
                SetConsoleTextAttribute(h, color1);
                cout << simvol1 << " ";
            }
            else {
                SetConsoleTextAttribute(h, color2);
                cout << simvol2 << " ";
            }
        }
        cursor.Y = y + 1 + i;
        cursor.X = x;
        SetConsoleCursorPosition(h, cursor);
    }
            
    
        cout << "\n";
    SetConsoleTextAttribute(h, 15);
}

int main()
{
    Rectangle(15, 20, '#', '*');
}