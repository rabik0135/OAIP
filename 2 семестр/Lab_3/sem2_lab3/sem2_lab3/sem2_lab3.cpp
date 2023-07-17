#include <iostream>
#include <conio.h>
using namespace std;

struct Queue
{
	int info;
	Queue *next;
	Queue *prev;
}*t;	

Queue* Create(int i)
{
	Queue* t = new Queue;
	t->info = i;
	t->next = t->prev = NULL;
	return t;
}

void Add(bool flag, Queue **begin, Queue **end, int i)
{
	t = new Queue;
	t->info = i;
	if (flag == true)					//Добавление в начало
	{
		t->prev = NULL;
		t->next = *begin;
		(*begin)->prev = t;
		*begin = t;
	}
	else
	{
		t->next = NULL;					//Добавление в конец
		t->prev = *end;
		(*end)->next = t;
		*end = t;
	}
}

void View(bool flag, Queue *begin)
{
	t = begin;
	while (t != NULL)
	{
		cout << t->info <<" ";
		if (flag == true)
			t=t->next;
		else
			t = t->prev;
	}
	cout << endl;
}

void Delete_all(Queue **begin)
{
	Queue *t;
	if (*begin = NULL)
		cout << "Очередь пуста" << endl;
	while(*begin != NULL)
	{
		t = *begin;
		*begin = (*begin)->next;
		delete t;
	}
}

Queue *Max(Queue *begin)
{
	Queue *max = begin;
	while (begin)
	{
		if (begin->info > max->info)
			max = begin;
		if (begin->info == max->info)
			max = begin;											//???
		begin = begin->next;
	}
	return max;
}

Queue *Min(Queue *begin)
{
	Queue* min = begin;
	while (begin)
	{
		if (begin->info < min->info)
			min = begin;
		if (begin->info == min->info)
			min = begin;								//???
		begin = begin->next;
	}
	return min;
}

Queue* Work(Queue *begin)
{
	if (begin == NULL)
		return begin;
	Queue* max = Max(begin);
	Queue* min = Min(begin);

	if (max == min)
		return begin;
	if (min == max)
		return begin;
	if (max->next == min)
		return begin;
	if (min->next == max)
		return begin;
	int del_numbs = 0;
	
	Queue* current=begin;
	Queue* folowwing = current->next;

	while (folowwing != NULL)
	{
		if (folowwing == max)
		{	
			Queue *tmp_1 =folowwing->next;
			while (tmp_1 != min)
			{
				Queue* tmp_2 = tmp_1;
				tmp_1 = tmp_1->next;
				delete tmp_2;
			}
			folowwing->next= min;
			return begin;
		}
	
		if (folowwing == min)
		{
			Queue *tmp_1 = folowwing->next;
			while (tmp_1 != max)
			{
				Queue* tmp_2 = tmp_1;
				tmp_1 = tmp_1->next;
				delete tmp_2;
			}
			folowwing->next = max;
			return begin;
		}
		current = folowwing;
		folowwing = folowwing->next;
	}
	return begin;
}

Queue* Work_2(Queue *begin, Queue *end)
{
	if (begin == NULL)
		return begin;
	Queue* max = Max(begin);
	Queue* min = Min(begin);

	if (max == min)
		return begin;
	if (min == max)
		return begin;
	if (max->next == min)
		return begin;
	if (min->next == max)
		return begin;

	Add(true, &begin, &end, 9999);
	Queue* current = begin;
	Queue* folowwing = current->next;
	Add(false, &begin, &end, 1111);
	Queue* current_end = end;
	Queue* folowwing_end = current_end->prev;

	while (folowwing!=NULL)
	{
		if (folowwing == max)
		{
			while (folowwing_end != min)
			{
				folowwing_end = folowwing_end->prev;
			}
			folowwing_end = min;
			folowwing->next = folowwing_end;
			folowwing_end->prev = folowwing;
		

			folowwing = begin;
			begin = begin->next;
			delete folowwing;
			folowwing = NULL;

			folowwing_end = end;
			end = end->prev;
			delete folowwing_end;
			folowwing_end = NULL;

			begin->prev = NULL;
			end->next = NULL;
			return begin;
		}

		if (folowwing == min)
		{
			while (folowwing_end != max)
				folowwing_end = folowwing_end->prev;
			folowwing_end = max;
			folowwing->next = folowwing_end;
			folowwing_end->prev = folowwing;
		

			folowwing = begin;
			begin = begin->next;
			delete folowwing;
			folowwing = NULL;

			folowwing_end = end;
			end = end->prev;
			delete folowwing_end;
			folowwing_end = NULL;

			begin->prev = NULL;
			end->next = NULL;
			return begin;
		}
		current = folowwing;
		folowwing = folowwing->next;
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	
	Queue *begin = NULL;
	Queue *end = NULL;
	Queue *t = new Queue;
	int n, i;
	bool flag = false;

	bool menu = true;
	bool flag_menu = false;
	char sw;

	cout << "Введите первый элемент очереди: ";
	while (!(cin >> i))
	{
		cout << "Введено некорректное значение. Введите значение заново." << endl;
		cout << endl;
		cin.clear();
		cin.ignore();
		cout << "Первый элемент: " << endl;
	}
	
	begin=end=Create(i);
	
	while (menu == true)
	{
		cout << "\t\t\t\t\t\t\t Меню \n" << endl;
		cout << "1)Создание первого элемента" << endl;
		cout << "2)Добавление элементов в очередь" << endl;
		cout << "3)Вывод очереди" << endl;
		cout << "4)Очистка очереди" << endl;
		cout << "5)Выполнение работы первым способом" << endl;
		cout << "6)Выполнение работы вторым способом" << endl;
		cout << "7)Завершить работу программы" << endl;
		cout << endl;

		do
		{
			sw = _getch();
			switch (sw)
			{
			case '1':
			{
				system("cls");
				cout << "Введите первый элемент очереди: ";
				while (!(cin >> i))
				{
					cout << "Введено некорректное значение. Введите значение заново." << endl;
					cout << endl;
					cin.clear();
					cin.ignore();
					cout << "Первый элемент очереди: " << endl;
				}
				begin=end=Create(i);
				
				menu = true;
				flag_menu = true;
				cout << endl;
				cout << "Выберите новую операцию:" << endl;
				cout << endl;
				break;
			}

			case '2':
			{
				system("cls");
				cout << "1)Добавление с начала" << endl;
				cout << "2)Добавление с конца" << endl;
				cout << endl;
				do {
					sw = _getch();
					switch (sw)
					{
					case '1':
					{
						cout << "Добавление с начала " << endl;
						flag = true;
						cout << "Введите кол-во добавляемы элементов: ";
						cin >> n;
						for (int k = 0; k < n; k++)
						{
							cin >> i;
							Add(flag, &begin, &end, i);
						}
						cout << endl;
						cout << "Результат работы функции:" << endl;
						View(flag, begin);
						flag_menu = true;
						break;
					}
					case '2':
					{
						cout << "Добавление с конца " << endl;
						flag = false;
						cout << "Введите кол-во добавляемы элементов: ";
						cin >> n;
						for (int k = 0; k < n; k++)
						{
							cin >> i;
							Add(flag, &begin, &end, i);
						}
						cout << endl;
						cout << "Результат работы функции:" << endl;
						View(flag, end);
						flag_menu = true;
						break;
						
					}
					default:
					{
						menu = true;
						flag_menu = false;
						break;
					}
					}

				} while (flag_menu == false);
				
				menu = true;
				flag_menu = true;
				cout << endl;
				cout << "Выберите новую операцию:" << endl;
				cout << endl;
				break;
			}

			case '3':
			{
				system("cls");
				if (begin == NULL)
					cout << "Очередь пуста" << endl;
				else
				{
					cout << "1)Вывод с начала" << endl;
					cout << "2)Вывод с конца" << endl;
					cout << endl;
					sw = _getch();
					do {
						switch (sw)
						{
						case '1':
						{
							cout << "Вывод с начала:" << endl;
							flag = true;
							t = begin;
							View(flag, t);
							flag_menu = true;
							break;
						}
						case '2':
						{
							cout << "Вывод с конца:" << endl;
							flag = false;
							t = end;
							View(flag, t);
							flag_menu = true;
							break;
						}
						default:
						{
							flag_menu = false;
							menu = true;
							break;
						}
						}

					} while (flag_menu == false);
				}
				menu = true;
				flag_menu = true;
				cout << endl;
				cout << "Выберите новую операцию:" << endl;
				cout << endl;
				break;
			}

			case '4':
			{
				system("cls");
				if (begin == end)
					n = 1;
				for (int i = 0; i < n; i++)
				{
					Delete_all(&begin);
				}
				menu = true;
				flag = true;
				cout << endl;
				cout << "Выберите новую операцию:" << endl;
				cout << endl;
				break;
			}

			case '5':
			{
				system("cls");
				begin=Work(begin);
				cout << "Результат работы функции:" << endl;
				View(true, begin);
				menu = true;
				flag_menu = true;
				cout << endl;
				cout << "Выберите новую операцию:" << endl;
				cout << endl;
				break;
			}
			
			case '6':
			{
				system("cls");
				begin = Work_2(begin, end);
				cout << "Результат работы функции:" << endl;
				View(1, begin);
				menu = true;
				flag_menu = true;
				cout << endl;
				cout << "Выберите новую операцию:" << endl;
				cout << endl;
				break;
			}
			
			case '7':
			{
				system("cls");
				cout << "Итоговый результат:" << endl;
				View(true, begin);
				flag_menu = true;
				menu = false;
				break;
			}

			default:
			{
				flag_menu = false;
				menu = true;
				break;
			}

			}
		} while (flag_menu == false);
	}
}