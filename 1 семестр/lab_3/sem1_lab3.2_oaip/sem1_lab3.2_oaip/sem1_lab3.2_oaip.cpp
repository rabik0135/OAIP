#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	double x, y, h, k, s, a, b, n, r, y_x;
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
		case '1':									//Значения переменных предложенные в условии задания
			a = 0.1;
			cout << "a=0.1" << endl;
			b = 1;
			cout << "b=1" << endl;
			h = 0.1;
			cout << "h=0.1" << endl;
			n = 50;
			cout << "n=50 \n" <<endl;
			flag = true;
		break;
		
		case'2':								    //Ввод значений переменных с клавиатуры
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
			
			cout << "Введите число n: ";
			while (!(cin >> n))
			{
				cout << "Ошибка. Введите данные заново." << endl;
				cin.clear();
				cin.ignore();
			}
			cout << endl;
			flag = true;
		break;
		
		default:													//Защита от случайного нажатия
			flag = false;
		break;
		}
	}while (flag == false);

	for (x=a; x <=b; x+=h)											//Цикл для вычисления значений функций с пошаговым увеличением числа x  
	{
		cout << "x= " << x <<"\t";
		s = r = pow(x, 3) / 3;										//Начальное значение функции S при данном x
		y = ((1 + pow(x, 2)) / 2)*atan(x) - x / 2;					//Значение функции y при данном x
		
		for (k = 2; k <=n; k++)										//Цикл для рассчета алгебраической суммы с реккурентным уравнением
		{
			r = -r * ((2 * (k - 1) - 1)*(x*x)) / (2 * k + 1);		//Реккурентная формула
			s += r;													//Алгебраическая сумма(функция S)									
		}
	
	y_x = abs(y - s);												//Модуль разности 
	cout << "S= " << s <<"\t";										//Вывод значений
	cout << "Y= " << y << "\t";
	cout << "|Y-S|= " << y_x << "\t";
	cout << endl;
	}
}