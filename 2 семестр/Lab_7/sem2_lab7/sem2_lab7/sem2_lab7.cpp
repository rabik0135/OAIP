#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

double Function(double);
double Method(double*, double, int);

int main()
{
	setlocale(LC_ALL, "rus");
	double h, h1, x, *mas_x, *mas_y_t;
	double a, b;
	int n, m, i;
	char sw;
	bool flag = true;

	cout << "Исходная функция: x^3+10*x^2" << endl;
	cout << "1)Тестовые значения" << endl;
	cout << "2)Ввести с клавиатуры" << endl;

	do
	{
		sw = _getch();
		switch (sw)
		{

		case '1':
		{
			a = -8; b = 2; n = 5; m=5;
			flag = true;
			break;
		}

		case '2':
		{
			cout << "a=";
			while (!(cin >> a))
			{
				cout << "Введено недопустимое значение. Введите значение заново." << endl;
				cin.clear();
				cin.ignore();

			}
			cout << "\nb=";
			while (!(cin >> b))
			{
				cout << "Введено недопустимое значение. Введите значение заново." << endl;
				cin.clear();
				cin.ignore();

			}
			cout << "\nm=";
			while (!(cin >> a))
			{
				cout << "Введено недопустимое значение. Введите значение заново." << endl;
				cin.clear();
				cin.ignore();

			}
			cout << "\nn=";
			while (!(cin >> a))
			{
				cout << "Введено недопустимое значение. Введите значение заново." << endl;
				cin.clear();
				cin.ignore();

			}
			flag = true;
			break;
		}

		default:
			flag = false;
			break;
		}
	} while (flag == false);
	
	h = (b - a) / (m - 1);		//нахождение шага для таблицы х
	h1 = (b - a) / (n - 1);		//нахождение шага для таблицы y
	mas_x = new double[m+1];
	mas_y_t = new double[n + 1];
	
	
	cout << "Заданные значения:" << endl;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "m=" << m << endl;
	cout << "n=" << n << endl;
	cout << endl;

	for (x = a, i = 0; i < m; i++){		//формирование узлов
		mas_x[i] = x;
		mas_y_t[i] = Function(x);
		x += h;
	}

	for (x = a, i = 0; i < n; i++, x += h1)		//Нахождение неизвестных значений по методу Лагранжа
	{			
		mas_y_t[i] = Method(mas_x, x, m);
		cout << "x=" << x << "\t f*(x)=" << mas_y_t[i] << endl;
	}
}

double Function(double x)
{
	return pow(x, 3) + 10 * pow(x, 2);
}

double Method(double* x, double xt, int kol)
{
	int i, k;
	double e, p = 0;
	for (k = 0; k < kol; k++)
	{
		e = 1.;
		for (i = 0; i < kol; i++)
		{
			if (i != k) {
				e *= ((xt - x[i]) / (x[k] - x[i]));

			}
			p += e * Function(x[k]);

		}
	}
	return p;
}