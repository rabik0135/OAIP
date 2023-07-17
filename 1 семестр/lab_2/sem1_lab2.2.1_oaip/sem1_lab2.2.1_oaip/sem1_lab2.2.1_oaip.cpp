#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	
	double x, y, z, c, d, f_x, t_1, t_2, t_3, t_4, p_1, p_2, p_3;
	double e = exp(1.0);
	char t_f;
	bool flag;
	
	cout << "Введите число c: ";											//Ввод значений переменных и проверка на ввод неисловых данных
	while (!(cin >> c))
	{
		cout << "Ошибка. Введите данные заново." << endl;
		cin.clear();
		cin.ignore();
	}

	cout << "Введите число d: ";
	while (!(cin >> d))
	{
		cout << "Ошибка. Введите данные заново." << endl;
		cin.clear();
		cin.ignore();
	}

	cout << "Введите число z: ";
	while (!(cin >> z))
	{
		cout << "Ошибка. Введите данные заново." << endl;
		cin.clear();
		cin.ignore();
	}

	if (z < 1)
		x = pow(z, 2) + 1;							//Значение переменной x в зависимости от z
	else
		x = z - 1;

	cout << "Функции: " << endl;					//Список функций
	cout << "1) 2x" << endl;
	cout << "2) x^2" << endl;
	cout << "3) х/3" << endl;
	cout << "Номер желаемой функции: " << endl;		//Выбор желаемой функции
	
	do												//Выбор функции и защита от нажатия случайной клавиши
	{
		t_f = _getch();
		switch (t_f)
		{
			case '1':
				cout << "1" << endl;
				f_x = 2 * x;
				cout << "Результат вычислялся при условии, что ф(х)=2х" << endl;
				flag = true;
			break;
			case '2':
				cout << "2" << endl;
				f_x = pow(x, 2);
				cout << "Результат вычислялся при условии, что ф(х)=х^2" << endl;
				flag = true;
			break;
			case '3':
				cout << "3" << endl;
				f_x = x / 3;
				cout << "Результат вычислялся при условии, что ф(х)=х/3" << endl;
				flag = true;
			break;
			default:
				cout << "Неправильно введены значения." << endl;
				flag = false;
		}
	}while (flag == false);
	
	if (x == 0)																//Невозможно деление на 0
	
		cout << "Невозможно решить пример. Введены некорректные данные. ";
	
	else
	{
		t_1 = pow(sin(x), 3);		//Промежуточное выражение
		t_2 = pow(e, t_1);
		p_1 = d * f_x*t_2;			//Действие основного выражения
		t_3 = log(x + 1);
		p_2 = c * t_3;
		p_3 = p_1 + p_2;
		t_4 = sqrt(x);
		y = p_3 / t_4;

		cout << "Результат: " << y << endl;
	}
}


