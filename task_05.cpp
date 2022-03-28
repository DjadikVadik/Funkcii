
//  5.	Написать функцию, которая проверяет, является ли переданное ей число простым. 
//      Число называется простым, если оно делится без остатка только на себя и на единицу.

#include <iostream>
#include <Windows.h>
using namespace std;

void Prostoe(int number) {

    bool prostoe = true;
    for (int i = 2; i < number; i++) {
        if (number % i == 0) prostoe = false;
    }
    if (!prostoe) cout << "Число не является простым!!!\n";
    else cout << "Число является простым!!!\n";
}

int main()
{
    system("chcp 1251 > 0");
    Prostoe(5);
}