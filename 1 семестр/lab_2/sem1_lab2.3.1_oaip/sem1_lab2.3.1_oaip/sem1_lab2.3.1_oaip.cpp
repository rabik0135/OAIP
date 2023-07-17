#include <iostream>
#include <cmath>
#include <stdio.h>
#include<algorithm>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	double x, y, z, p_1, p_2, t_1, t_2, m;


	cout << "Введите x: ";
	while (!(cin >> x))
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
	t_1 = max(x, y);
	t_2 = max(y, z);
	p_1 = max(t_1,t_2);
	p_2 = min(x, y, z);
	m = p_1 / p_2;


}
