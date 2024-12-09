#include <iostream>
#include <crtdbg.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    const int SIZE = 10;
    short* arr = new short[SIZE];

    for (int i = 0; i < SIZE; i++) 
    {
        short temp;
        cout << "Введите число от -32,768 до 32,767: ";
        cin >> temp;
        arr[i] = temp;
    }

    for (int i = 0; i < SIZE; i++) 
    {
        cout << i + 1 << " Элемент массива равен: " << arr[i] << endl;
    }
 
    cout << "Адрес начала массива равен: " << arr << endl;

    for (int i = 1; i < SIZE; i++) 
    {
        cout << "Расстояние от начала массива: " << (i + 1) * sizeof(short)<< " байта" << endl;
    }

    delete[] arr;
}
