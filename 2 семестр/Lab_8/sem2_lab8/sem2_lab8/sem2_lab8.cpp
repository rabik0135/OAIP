#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

double Func(double);
double Method(double(*f)(double), double, double, int);
double Check(double);

int main()
{
	setlocale(LC_ALL, "rus");
	double a=0, b=0, x, eps, h, I1, I2, pogr;
	int n=0, n1;
	char select_var, select_sposob;
	bool flag_var, flag_sposob;

	cout << "Вычисляемая функция: x^3+10x^2" << endl;
	cout << endl;
	cout << "Значения переменных" << endl;
	cout << "1) Тестовые значения" << endl;
	cout << "2) Ввод с клавиатуры" << endl;
	cout << endl;

	do {
		select_var = _getch();
		switch (select_var)
		{
		case '1':
		{
			a = -8; b = 2;
			cout << "a=" << a << "\nb=" << b << endl;
			flag_var = true;
			break;
		}
		case '2':
		{
			cout << "Введите а:";
			Check(a);
			cout << "\nВведите b:";
			Check(b);
			cout << endl;
			flag_var = true;
			break;
		}
		default:
		{
			flag_var = false;
		}
		}
	} while (flag_var != true);

	cout << endl;
	cout << "Выберите способ вычисления интеграла: " << endl;
	cout << "1) По заданному количеству разбиений" << endl;
	cout << "2) По заданной точности" << endl;
	cout << endl;
	do {
		select_sposob = _getch();
		switch (select_sposob)
		{
		case '1':
		{
			cout << "Введите число разбиений" << endl;
			cout << "n=";
			cin >> n;
			
			I1 = Method(Func, a, b, n);
			cout << "Значение интеграла по количеству разбиений: " << I1 << endl;
			flag_sposob = true;
			break;
		}
		case '2':
		{
			eps = 0.0000001;
			cout << "eps= " << eps << endl;
			n1 = 2;
			I1 = Method(Func, a, b, n1);
			do
			{
				n1 *= 2;
				I2 = Method(Func, a, b, n1);
				pogr = fabs(I2 - I1);
				I1 = I2;
			} while (pogr > eps);
			cout << I1;
			flag_sposob = true;
			break;
		}
		default:
			flag_sposob = false;
		break;
		}
	} while (flag_sposob != true);
}
double Func(double x)
{
	return pow(x, 3) + 10 * pow(x, 2);
}

double Method(double(*f)(double x), double a, double b, int n)
{
	double s = 0, h, x;
	h = (b - a) / n;
	x = a;

	for (int i = 1; i <= n; i++)
	{
		s += f(x) + 4 * f(x + h / 2) + f(x + h);
		x += h;
	}

	return s * h / 6;
}

double Check(double x)
{
	while (!(cin >> x))
	{
		cout << "Ошибка. Введите данные заново" << endl;
		cin.clear();
		cin.ignore();
	}
	return x;
}