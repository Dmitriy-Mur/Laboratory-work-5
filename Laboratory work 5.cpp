#include <iostream>
using namespace std;
const int A = 20;
int arr_one[A];
const int B = 5;
const int C = A / B;
int arr_two[B][C];

void array_one()
{
    srand(time(0));
    cout << "Исходный одномерный массив:\n";
    for (int i = 0; i < A; i++)
    {
        arr_one[i] = (rand() % 100 - 50);
        cout << arr_one[i] << " ";
    }
    cout << "\n";
}

void array_two(int a[])
{
    int index = 0;
    cout << "Восстановленный двумерный массив:\n";
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < C; j++) 
        {
            arr_two[j][i] = a[index];
            cout << arr_two[j][i] << "\t";
            index++;
        }
        cout << "\n";
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    array_one();
    array_two(arr_one);
}