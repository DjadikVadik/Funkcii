
//   2.	Написать функцию Line, которую можно будет вызвать так:  Line(20, '@', 12, true);
//      и при этом горизонтальная нарисуется линия, состоящая из 20 «собачек» красного цвета. 
//      Если передать в последнем параметре false – линия станет вертикальной.


#include <iostream>
#include <Windows.h>
using namespace std;


void Line(int kolichestvo, char simvol, int color, bool line) {

    HANDLE h = GetStdHandle(-11);
    SetConsoleTextAttribute(h, color);
    if (line)
        for (int i = 0; i < kolichestvo; i++)
            cout << simvol;
    else  for (int i = 0; i < kolichestvo; i++)
        cout << simvol << "\n";
    SetConsoleTextAttribute(h, 15);
}

int main()
{
    Line(15, 'A', 12, false);
}