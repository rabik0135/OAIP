#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	double x, y, z, max, min, t_1, t_2, t_3, m;

	cout << "Введите x: ";
	while (!(cin >> x))										//Ввод значений переменных и проверка на ввод нечисловых данных
	{
		cout << "Ошибка. Введите данные заново." << endl;
		cin.clear();					
		cin.ignore();					
	}
	
	cout << "Введите y: ";
	while (!(cin >> y))					
	{
		cout << "Ошибка.Введите данные заново." << endl;
		cin.clear();					
		cin.ignore();					
	}
	
	cout << "Введите z: ";
	while (!(cin >> z))					
	{
		cout << "Ошибка. Введите данные заново." << endl;
		cin.clear();					
		cin.ignore();					
	}

	//1) Выбор найбольшего числа из чисел x и y
	if (x > y)
	{
		max = x;
	}
	else 
	{
		max = y;
	}
	t_1 = max;
	cout << "t_1: " << t_1 << endl;

	//2) Выбор найбольшего числа из чисел y и z
	if (y>z)
	{
		max = y;
	}
	else
	{
		max = z;
	}
	t_2 = max;
	cout << "t_2: " << t_2 << endl;


	//3) Выбор найбольшего числа из первых двух выражений
	if (t_1 > t_2)
	{
		max = t_1;
	}
	else
	{
		max = t_2;
	}
	cout << "max: " << max << endl;
	
	//4) Выбор минимального числа из всех трех переменных
	if ((x<y || x==y) and (x<z || x==z))
	{
		min = x;
	}
	if ((y < x || y==x) and (y < z || y==z))
	{
		min = y;
	}
	if ((z<x || z==x) and (z<y || z==y))
	{
		min = z;
	}
	cout << "min: " << min << endl << endl;

	if (min==0)
	{
		cout << "Невозможно деление на 0. Невозможно решить пример." << endl;
	}
	else
	{
		m = max / min;
		cout << "Результат: " << m << endl;
	}
}
