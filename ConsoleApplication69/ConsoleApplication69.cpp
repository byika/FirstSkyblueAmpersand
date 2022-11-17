#include <iostream>
#include <ctime> 
using namespace std;


void AllocateMemory();
void FillArray();
void UserFillArray();
void RandomFillArray();
void ShowArray();
void FreeMemory();
void AddElementToTheEndOfArray();
void AddElementToTheMiddleOfArray();
void RemoveAddElementToTheMiddleOfArray();
void RemoveAddElementToTheStartOfArray();

void AllocateMemory(int*& ar, int& count)
{
    cout << "Please, enter count of elements: ";
    cin >> count; // просим пользователя ввести количество элементов
    // нормализация количества элеметов массива
    if (count < 5) count = 5;
    if (count > 10000) count = 10000;
    // пример создания одномерного динамического массива 

    ar = new int[count];
}

void FillArray(int* ar, int count)
{
    for (int i = 0; i < count; i++)
    {
        ar[i] = 100;
    }
}

void RandomFillArray(int* ar, int count)
{
    srand(time(NULL));
    for (int i = 0; i < count; i++)
    {
        ar[i] = 1 + rand() % 100;
    }   
}

void UserFillArray(int* ar, int count)
{
    int num;
    for (int i = 0; i < count; i++)
    {
        cout << "Введите число: ";
        cin >> num;
        ar[i] = num;
    }
}

void ShowArray(int* ar, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << ar[i] << ", ";
    }
    cout << "\n";
}

void AddElementToTheEndOfArray(int*& ar, int& count, int number)
{
    int* temp = new int[count + 1];
    for (int i = 0; i < count; i++) temp[i] = ar[i];
    temp[count] = number;
    delete[] ar;
    ar = temp;
    count++;
}

void RemoveAddElementToTheEndOfArray(int*& ar, int& count)
{
    int* temp = new int[count - 1];
    for (int i = 0; i < count - 1; i++) temp[i] = ar[i];
    delete[] ar;
    ar = temp;
    count--;
}

void AddElementToTheMiddleOfArray(int*& ar, int& count, int number, int pos) {
    int* temp = new int[count + 2];

    for (int i = 0; i < pos; i++) {
        temp[i] = ar[i];
    }
    temp[pos] = number;
    for (int i = pos; i < count; i++) {
        temp[i + 1] = ar[i];
    }
    delete[] ar;
    ar = temp;    
    count++;
}

void RemoveAddElementToTheMiddleOfArray(int*& ar, int& count, int pos) {
    int* temp = new int[count];

    for (int i = 0; i < count - 1; i++) {
        if (i >= pos) {
            temp[i] = ar[i + 1];
        }
        else {
            temp[i] = ar[i];
        }
    } 
    delete[] ar;
    ar = temp;
    count--;
}

void RemoveAddElementToTheStartOfArray(int*& ar, int& count) {
    int* temp = new int[count - 1];

    for (int i = 0; i < count - 1; i++) {
        temp[i] = ar[i + 1];
    }
    delete[] ar;
    ar = temp;
    count--;
}

void FreeMemory(int* ar)
{
    delete[] ar;
}

int main()
{
    int count = 0;
    int* ar = nullptr;

    AllocateMemory(ar, count);
    FillArray(ar, count);
    ShowArray(ar, count);


    AddElementToTheEndOfArray(ar, count, 234);
    ShowArray(ar, count);
    AddElementToTheMiddleOfArray(ar, count, 1234, 5);
    ShowArray(ar, count);
    RemoveAddElementToTheMiddleOfArray(ar, count, 5);
    ShowArray(ar, count);
    RemoveAddElementToTheStartOfArray(ar, count);
    ShowArray(ar, count);
    FreeMemory(ar);
}