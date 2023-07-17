#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

double Function(double);
double Method(double, double, double);

int main()
{
	setlocale(LC_ALL, "rus");
	
	int nom = 0;
	double  x, y, h;
	double	a , b, eps;
	bool flag = true;
	char sw;
	
	cout << "Исходное уравнение: x^3+10x^2-50" << endl;
	cout << "1)Тестовые значения" << endl;
	cout << "2)Ввести с клавиатуры" << endl;

	do
	{
		sw = _getch();
		switch (sw)
		{

		case '1':
		{
			a = -12; b = 5; eps = 0.00001;
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
			cout << "\neps=";
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
	}while (flag == false);

	double 	x0 = a, x1 = b;
	cout << "a=" << a << "\nb=" << b << "\neps=" << eps << endl;

	cout << endl;
	for (x = a; x < b; x += h)
	{	
		h = eps * 10;
		if (Function(x)*Function(x + h) < 0)
		{
			nom++;
			y = Method(x, x + h, eps);
			cout<<nom<<"-ый корень"<< "=" << y << endl;
		}
	}
}

double Function(double x)
{
	return pow(x, 3) + 10 * pow(x, 2) - 50;
}

double Method(double x0, double x1, double eps)
{
	double y0, y1, x2, de;
	y0 = Function(x0); y1 = Function(x1);
	do 
	{
		x2 = x1 - y1 * (x1 - x0) / (y1 - y0);
		de = fabs(x1 - x2);
		x0 = x1;	x1 = x2;	y0 = y1;	y1 = Function(x2);
	} while (de > eps);
	return x2;
}