﻿// FunctionConvertTemperatureValues.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <iomanip>
#include <cmath>

#include "conversions.h"

#ifdef _WIN32
#include <windows.h>
#endif

bool FixFlow()
{
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        fflush(stdin);
        return true;
        //        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else
    {
        return false;
    }
}


template <typename T>
void Input(T& side1, const std::string& message)
{
    do
    {
        std::cout << message << '\n';
        std::cin >> side1;
    } while (FixFlow());
}


void PrintPreliminaryMessage()
{
    std::cout << "Эта программа печатает значения температур в разных шкалах.\n";
}

void InputValues(double& min, double& max, double& interval)
{   
    do
    {
        Input(min, "Введите минимальное значение в °C, больше -273,15 ");
    } while (min < -273.15);
    Input(max, "Введите максимальное значение в °C ");    
    Input(interval, "Введите интервал в °C ");
}



void PrintHeaderTemperature()
{
    // установка ширины поля вывода для операций вывода в поток std::cout
    std::cout.width(15);
    std::cout << "Цельсий";
    std::cout.width(15);
    std::cout << "Фаренгейт";
    std::cout.width(15);
    std::cout << "Кельвин" << '\n';
}

void PrintTableTemperature(double min, double max, double interval)
{
    for (double cel = min; (fabs(cel - max) < std::numeric_limits<double>::epsilon() || cel < max); cel += interval)
    {
        std::cout.width(15);
        std::cout << cel; // цельсии
        std::cout.width(15);
        std::cout << ConvertCelsiusToFahrenheit(cel); // фаренгейты
        std::cout.width(15);
        std::cout << ConvertCelsiusToKelvin(cel) << '\n'; // кельвины
    }
}

void PrintTable(double min, double max, double interval)
{
    PrintHeaderTemperature();
    PrintTableTemperature(min, max, interval);
}


int main()
{
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
    // устанавливается фиксированный формат вывода для чисел с плавающей точки
    std::cout.setf(std::ios::fixed);
    //установка точности вывода чисел с плавающей точкой на 2 знака после запятой
    std::cout.precision(2);
    std::cout << "Упражнение 1\n";
    PrintTable(0, 300, 20);
    
    std::cout << "Упражнение 2\n";
    double min = 0, max = 0, interval = 0;
    PrintPreliminaryMessage();
    InputValues(min, max, interval);
    PrintTable(min, max, interval);

    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
