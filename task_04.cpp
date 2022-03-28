
//   1.	Написать функцию, которая возвращает куб переданного числа.

#include <iostream>
#include <Windows.h>
using namespace std;

template <class T>
T vKube(T number) {
    T a = number * number * number;
    return a;
}

int main()
{
    double a = vKube(3.14);
    cout << a << "\n";
}