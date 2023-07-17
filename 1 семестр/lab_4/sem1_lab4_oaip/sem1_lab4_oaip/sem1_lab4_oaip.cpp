#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

typedef double(*TypeFun)(double);							//Декларация указателя на переменную     double-тип указателя; (*TypeFun)-имя указателя; (double)-список параметров
//double n;

double y(double x)											//Y(x)			//double-тип возвращаемого результата; Y-имя функции; (double x)-параметры функции
{																			//Тело функции
	double y=((1 + pow(x, 2)) / 2)*atan(x) - x / 2;
	return y;																//Возвращение результата
}		
double s(double x)											//S(x)
{
	double s, r, n=50;
	s = r = pow(x, 3) / 3;
	for (int k = 2; k <= n; k++)
	{
		r = -r * ((2 * (k - 1) - 1)*(x*x)) / (2 * k + 1);
		s += r;
	}
	return s;
}

double y_x(double x)										//|S-Y|
{
	double y_x = abs(y(x) - s(x));
	return y_x;
}			

void Output(double x, TypeFun y, TypeFun s, TypeFun y_x)	//Вывод		//Функция типа void не возвращает никаких значений	//Typefun-указатель на область памяти, где лежит заданная функция
{
	cout << "x=" << x << "\t";
	cout << "S=" << s(x) << "\t";
	cout << "Y=" << y(x) << "\t";
	cout << "|Y-S|=" << y_x(x) << "\t";
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	double a, b, h;
	char sw;
	bool flag;

	cout << "Варианты используемых значений:" << endl;
	cout << "1) Тестовые значения" << endl;
	cout << "2) Ввод с клавиатуры \n" << endl;

	do
	{
		sw = _getch();
		switch (sw)
		{
		case '1':
			a = 0.1;
			cout << "a=0.1" << endl;
			b = 1;
			cout << "b=1" << endl;
			h = 0.1;
			cout << "h=0.1" << endl;
			//n = 50;
			//cout << "n=50 \n" << endl;
			flag = true;
			break;
		case'2':
			cout << "Введите число a: ";
			while (!(cin >> a))
			{
				cout << "Ошибка. Введите данные заново." << endl;
				cin.clear();
				cin.ignore();
			}
			cout << "Введите число b: ";
			while (!(cin >> b))
			{
				cout << "Ошибка. Введите данные заново." << endl;
				cin.clear();
				cin.ignore();
			}
			cout << "Введите число h: ";
			while (!(cin >> h))
			{
				cout << "Ошибка. Введите данные заново." << endl;
				cin.clear();
				cin.ignore();
			}
			/*cout << "Введите число n: ";
			while (!(cin >> n))
			{
				cout << "Ошибка. Введите данные заново." << endl;
				cin.clear();
				cin.ignore();
			}*/
			cout << endl;
			flag = true;
		break;
		default:
			flag = false;
		break;
		}
	} 
	while (flag == false);

	for (double x = a; x <= b; x += h)
	{
		Output(x, s, y, y_x);
	}
}


