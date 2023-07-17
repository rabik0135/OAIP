#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

double recurcion(double n, double res) 
{
	if (n < 1)
		return sqrt(res);    
	res = n + sqrt(res);    
	return recurcion(n - 1, res);
}

double without_recurcion(int n)
{
	double r,x,y;

	r = sqrt(n);
	x = n;

	for (int i = 1; i < x; i++)
	{
		r = sqrt((n - 1) + r);
		n--;
	}
	
	y = r;
	return y;
}


int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	double y;
	double res = 0;
	char sw;
	bool flag = false;
	bool povtor = true;
	
	while(povtor==true)
	{
		cout << "Число n: ";
		while (!(cin >> n))
		{
			cout << "Введено некорректное значение. Введите значение заново." << endl;
			cout << endl;
			cin.clear();
			cin.ignore();
			cout<<"Число n: "<<endl;
		
		}
		cout << endl;

		cout << "Выберите тип выводимой функции:" << endl;
		cout << "1) С рекурсией" << endl;
		cout << "2) Без рекурсии" << endl;
		cout << "3) Сравнить обе функции" << endl;
		cout << endl;
		

		do
		{
			sw = _getch();
			switch (sw)
			{
			case'1':
			{
				flag = true;
				y = recurcion(n, res);
				cout << "Итоговое значение: " << y << endl;
				break;
			}

			case '2':
			{
				flag = true;
				y = without_recurcion(n);
				cout << "Итоговое значение: " << y << endl;
				break;
			}

			case '3':
			{
				flag = true;
				y = recurcion(n, res);
				cout << "Итоговое значение по функции с рекурсией: \t" << y << endl;
				y = 0;
				y = without_recurcion(n);
				cout << "Итоговое значение по функции без рекурсии: \t" << y << endl;
				break;
			}

			default:
			{
				flag = false;
				break;
			}
			}
		} while (flag == false);

		cout << endl; cout << endl;
		cout << "Провести вычисления заново?" << endl;
		cout << "1)Да \n2)Нет \n";

		flag = false;
		
		do
		{
			sw = _getch();
			switch (sw)
			{

			case '1':
			{
				flag = true;
				povtor = true;
				cout << endl;
				break;
			}

			case '2':
			{
				flag = true;
				povtor = false;
				break ;
			}

			default:
			{
				flag = false;
				break;
			}

			} 

		} while (flag == false);
	}
}