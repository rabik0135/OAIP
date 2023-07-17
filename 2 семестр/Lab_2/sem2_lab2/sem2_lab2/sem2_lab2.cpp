#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <ctime>	
using namespace std;

struct Stack
{
	int info;
	Stack *next;
};

//Функция создания или добавления элементов в стек
Stack* input(Stack *b, int a)	
{
	Stack *t = new Stack;
	t->info=a;
	t->next=b;
	return t;
}

//Функция для вывода элементов стека
void view(Stack *b)
{
	Stack *t = b;
	while (t != NULL)
	{
		cout << t->info <<" ";
		t = t->next;
	}
}

//Функция для очистки стека
Stack* delete_stack(Stack *b)
{
	Stack*t;
	while (b != NULL)
	{
		t = b;
		b = b->next;
		delete t;
	}
	return b;
}

//Функция получения информации из вершины с извлечением 
Stack* out_stack(Stack *b, int *out)
{
	Stack* t = b;
	
	*out = b->info;
	b = b->next;
	delete t;
	
	return b;
}

//Функция нахождения максимального элемента в стеке
Stack* Max(Stack *b)
{
	Stack *max = b;
	while (b) 
	{
		if (b->info > max->info)
			max = b;
		if (b->info == max->info)
			max = b;											//???
		b = b->next;	
	}
	return max;
}

//Функция нахождения минимального элемента в стеке
Stack* Min(Stack*b)
{
	Stack* min = b;
	while (b)
	{
		if (b->info < min->info)
			min = b;
		if (b->info == min->info)
			min = b;								//???
		b = b->next;
	}
	return min;
}

//Функция для выполнения задания
Stack* Work(Stack* b)
{
	if (b == NULL)
		return b;
	Stack* max = Max(b);				//Поиск макс мин элементов в стеке
	Stack* min = Min(b);

	if (max == min)						//Проверки на определенные условия 
		return b;

	if (min == max)
		return b;

	if (max->next == min)
		return b;

	if (min->next == max)
		return b;

	b = input(b, 9999);					//Добавление мнимой вершины 
		
	Stack *p=b;							// *t-указатель на следующий элемент *p-указатель на текущий элемент 
	Stack *t = p->next;
		
	int del_numbs = 0;
	while (t != NULL)
	{
		if (t == max)
		{
			Stack* tmp_1 = t->next;			//Дополнительная переменная-следующий элемент после максимального
			while (tmp_1 != min)
			{
				Stack* tmp_2 = tmp_1;		//дополнительная переменная для удаления 
				tmp_1 = tmp_1->next;
				delete tmp_2;
				del_numbs++;
			}
			t->next = min;
			t = b;				//Удаление вершины
			b = b->next;
			delete t;
			cout << "Кол-во удаленных элементов: " << del_numbs << endl;
			return b;
		}

		if (t == min)
		{
			Stack* tmp_1 = t->next;			//Дополнительная переменная-следующий элемент после минимального 
			while (tmp_1 != max)			
			{
				Stack* tmp_2 = tmp_1;		//Дополнительная переменная для удаления 
				tmp_1 = tmp_1->next;
				delete tmp_2;
				del_numbs++;
			}
			t->next = max;		
			t = b;			//Удаление вершины
			b = b->next;
			delete t;
			cout << "Кол-во удаленных элементов: " << del_numbs << endl;
			return b;
		}
		p = t;
		t = t->next;
		}
		
	t = b;			//Удаление вершины
	b = b->next;
	delete t;
	cout << "Кол-во удаленных элементов: " << del_numbs << endl;
	return b;
}

//Функция для выполнения задания используя массив
Stack* mas(Stack *b)
{
	int n = 0, *a, i, m, min, max, numb_of_elements=0;
	Stack *t = b;
	while (t != NULL)
	{
		n++;
		t = t->next;
	}

	a = new int[n];
	for (i = 0; i < n; i++)
		b = out_stack(b, a + i);

	max = a[0]; int pos_max = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			pos_max = i;
		}
	}

	min = a[0]; int pos_min = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
			pos_min = i;
		}
	}


	int pos_now = 0;
	if (pos_min < pos_max)
	{
		for (m = i = 0; i < n; i++)
		{
			pos_now = i;
			if (pos_now != pos_min)
				a[m++] = a[i];

			if (pos_now == pos_min)
			{
				a[m++] = a[i];
				i++; pos_now = i;

				do
				{
					for (int k = i; k < n; k++)
					{
						a[k] = a[k + 1];


					}
					pos_max--; n--; numb_of_elements++;
				} while (pos_now != pos_max);
				a[m++] = a[i];
			}
		}
	}
	if (pos_min > pos_max)
	{
		for (m = i = 0; i < n; i++)
		{
			pos_now = i;
			if (pos_now != pos_max)
				a[m++] = a[i];

			if (pos_now == pos_max)
			{
				a[m++] = a[i];
				i++; pos_now = i;

				do
				{
					for (int k = i; k < n; k++)
					{
						a[k] = a[k + 1];
					}
					pos_min--; n--; numb_of_elements++;
				} while (pos_now != pos_min);
				a[m++] = a[i];
			}
		}
	}

	for (i = 0; i < m; i++)
		b= input(b, a[i]);

	for (i = 0; i < m; i++)
		b= input(b, a[i]);

	for (i = 0; i < m; i++)
		b= out_stack(b, (a + i));

	for (i = 0; i < n; i++)
		b = delete_stack(b);

	for (i = 0; i < m; i++)
		b = input(b, a[i]);
	cout << endl;
	cout << "Количество удаленных элементов: " <<numb_of_elements;
	delete[] a;
	return b;
}

int main()
{
	setlocale(LC_ALL, "rus");

	Stack *begin, *t;
	begin = NULL;
	t=new Stack;
	int a, n, x, out;

	bool menu = true;
	bool flag = false;
	char sw;

	cout << "Введите количество элементов в стеке: ";
	while (!(cin >> n) or (n < 1))
	{
		cout << "Введено недопустимое значение. Введите значение заново." << endl;
		cin.clear();
		cin.ignore();
	}

	cout << endl;
	cout << "Выбор ввода:" << endl;
	cout << "1)С клавиатуры" << endl;
	cout << "2)Рандомом" << endl;
	
	do 
	{
		sw = _getch();
		switch (sw)
		{
		
			case '1':
			{
				cout << "Ввод элементов стека: " << endl;
				for (int i = 0; i < n; i++)
				{
					while (!(cin >>a))
					{
						cout << "Введено недопустимое значение. Введите значение заново." << endl;
						cin.clear();
						cin.ignore();
					}
					begin = input(begin, a);
				}
				flag = true;
				break;
			}
			case '2':
			{
				srand(time(NULL));																							//использует системное время для того, чтобы числа при перезапуске программы отличались 		
				for (int i = 0; i < n; i++)
				{
					a = rand() % 21 - 10;
					begin = input(begin, a);
				}
				cout << endl;
				flag = true;
				break;
			}
		
			default:
			{
				flag = false;
			}
		
		}
	
	} while (flag == false);
	
	cout << endl;

	cout << "Вывод стека: " << endl;
	if (begin == NULL)
		cout << "Стек пуст" << endl;
	else
		view(begin);

	while (menu== true)
	{
		cout << "\t\t\t\t\t\t\t Меню \n" << endl;
		cout << "1)Вывод стека" << endl;
		cout << "2)Добавление элемента в стек" << endl;
		cout << "3)Добавление нескольких элементов в стек" << endl;
		cout << "4)Очистка стека" << endl;
		cout << "5)Получение информации из вершины стека с извлечением" << endl;
		cout << "6)Выполнение задания используя динамический массив" << endl;
		cout << "7)Выполнение задания" << endl;
		cout << "8)Завершить работу программы" << endl;
		cout << endl;

		do
		{
			sw = _getch();
			switch (sw)
			{
				case '1':
				{
					system("cls");
					cout << "Вывод стека: " << endl;
					if (begin == NULL)
					{
						cout << "Стек пуст" << endl;
					}
					else
					{
						view(begin);
					}
					menu = true;
					flag = true;
					cout << endl;
					cout << "Выберите новую операцию:" << endl;
					cout << endl;
					break;
				}
				
				case '2':
				{
					system("cls");
					cout << "Добавить элемент в стек: ";
					while (!(cin >> x))
					{
						cout << "Введено недопустимое значение. Введите значение заново." << endl;
						cin.clear();
						cin.ignore();
					}
					begin = input(begin, x);
					cout << "\nВывод стека:" << endl;
					view(begin);
					menu = true;
					flag = true;
					cout << endl;
					cout << "Выберите новую операцию:" << endl;
					cout << endl;
					break;
				}
				
				case '3':
				{	
					system("cls");
					cout << "Количество добавляемых элементов: ";
					while (!(cin >> n) and n < 1)
					{
						cout << "Введено недопустимое значение. Введите значение заново." << endl;
						cin.clear();
						cin.ignore();
					}
					cout << "Добавление элементов:" << endl;
					cout << "1)С клавиатуры" << endl;
					cout << "2)Рандомом" << endl;
					do
					{
						sw = _getch();
						switch (sw)
						{

							case '1':
							{
								cout << "Ввод элементов стека: " << endl;
								for (int i = 0; i < n; i++)
								{
									while (!(cin >> x))
									{
										cout << "Введено недопустимое значение. Введите значение заново." << endl;
										cin.clear();
										cin.ignore();
									}
									begin = input(begin, x);
								}
								flag = true;
								break;
							}
							case '2':
							{
								srand(time(NULL));																							//использует системное время для того, чтобы числа при перезапуске программы отличались 		
								for (int i = 0; i < n; i++)
								{
									a = rand() % 21 - 10;
									begin = input(begin, a);
								}
								cout << endl;
								flag = true;
								break;
							}

							default:
							{
								flag = false;
							}
						}
					} while (flag == false);
	
					cout << "\nВывод стека:" << endl;
					view(begin);
					menu = true;
					flag = true;
					cout << endl;
					cout << "Выберите новую операцию:" << endl;
					cout << endl;
					break;
			
				}

				case '4':
				{
					system("cls");
					for (int i = 0; i < n; i++)
					{
						begin = delete_stack(begin);
					}
					menu = true;
					flag = true;
					cout << "Стек пуст" << endl;
					cout << "Выберите новую операцию:" << endl;
					cout << endl;
					break;
				}

				case '5':
				{
					system("cls");
					if (begin == NULL)
						cout << "Стек пуст" << endl;
					else
					{
						begin = out_stack(begin, &out);
						cout << "Вершина стека: " << out << endl;
					}
					menu = true;
					flag = true;
					cout << endl;
					cout << "Выберите новую операцию:" << endl;
					cout << endl;
					break;
				}
			
				case '6':
				{
					system("cls");
					cout << "Исходный стек:" << endl;
					view(begin);
					begin = mas(begin);
					cout << endl;

					cout << "Отсортированный стек: " << endl;
					view(begin);
					flag = true;
					menu = true;
					cout << endl;
					cout << "Выберите новую операцию:" << endl;
					cout << endl;
					break;
				}
			
				case '7':
				{
					system("cls");
					cout << "Исходный стек:" << endl;
					view(begin);
					cout << endl;
					cout << endl;
					
					begin = Work(begin);
					cout << "Отсортированный стек: " << endl;
					view(begin);
					
					flag = true;
					menu = true;
					cout << endl;
					cout << endl;
					cout << "Выберите новую операцию:" << endl;
					cout << endl;
					break;
				}

				case '8':
				{
					cout << "Итоговый результат:" << endl;
					view(begin);
					flag = true;
					menu = false;
					break;
				}
				
				default:
				{
					flag = false;
					menu = true;
					break;
				}

			}
		} while (flag == false);	
	}
}