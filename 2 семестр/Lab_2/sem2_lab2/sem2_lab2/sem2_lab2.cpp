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

//������� �������� ��� ���������� ��������� � ����
Stack* input(Stack *b, int a)	
{
	Stack *t = new Stack;
	t->info=a;
	t->next=b;
	return t;
}

//������� ��� ������ ��������� �����
void view(Stack *b)
{
	Stack *t = b;
	while (t != NULL)
	{
		cout << t->info <<" ";
		t = t->next;
	}
}

//������� ��� ������� �����
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

//������� ��������� ���������� �� ������� � ����������� 
Stack* out_stack(Stack *b, int *out)
{
	Stack* t = b;
	
	*out = b->info;
	b = b->next;
	delete t;
	
	return b;
}

//������� ���������� ������������� �������� � �����
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

//������� ���������� ������������ �������� � �����
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

//������� ��� ���������� �������
Stack* Work(Stack* b)
{
	if (b == NULL)
		return b;
	Stack* max = Max(b);				//����� ���� ��� ��������� � �����
	Stack* min = Min(b);

	if (max == min)						//�������� �� ������������ ������� 
		return b;

	if (min == max)
		return b;

	if (max->next == min)
		return b;

	if (min->next == max)
		return b;

	b = input(b, 9999);					//���������� ������ ������� 
		
	Stack *p=b;							// *t-��������� �� ��������� ������� *p-��������� �� ������� ������� 
	Stack *t = p->next;
		
	int del_numbs = 0;
	while (t != NULL)
	{
		if (t == max)
		{
			Stack* tmp_1 = t->next;			//�������������� ����������-��������� ������� ����� �������������
			while (tmp_1 != min)
			{
				Stack* tmp_2 = tmp_1;		//�������������� ���������� ��� �������� 
				tmp_1 = tmp_1->next;
				delete tmp_2;
				del_numbs++;
			}
			t->next = min;
			t = b;				//�������� �������
			b = b->next;
			delete t;
			cout << "���-�� ��������� ���������: " << del_numbs << endl;
			return b;
		}

		if (t == min)
		{
			Stack* tmp_1 = t->next;			//�������������� ����������-��������� ������� ����� ������������ 
			while (tmp_1 != max)			
			{
				Stack* tmp_2 = tmp_1;		//�������������� ���������� ��� �������� 
				tmp_1 = tmp_1->next;
				delete tmp_2;
				del_numbs++;
			}
			t->next = max;		
			t = b;			//�������� �������
			b = b->next;
			delete t;
			cout << "���-�� ��������� ���������: " << del_numbs << endl;
			return b;
		}
		p = t;
		t = t->next;
		}
		
	t = b;			//�������� �������
	b = b->next;
	delete t;
	cout << "���-�� ��������� ���������: " << del_numbs << endl;
	return b;
}

//������� ��� ���������� ������� ��������� ������
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
	cout << "���������� ��������� ���������: " <<numb_of_elements;
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

	cout << "������� ���������� ��������� � �����: ";
	while (!(cin >> n) or (n < 1))
	{
		cout << "������� ������������ ��������. ������� �������� ������." << endl;
		cin.clear();
		cin.ignore();
	}

	cout << endl;
	cout << "����� �����:" << endl;
	cout << "1)� ����������" << endl;
	cout << "2)��������" << endl;
	
	do 
	{
		sw = _getch();
		switch (sw)
		{
		
			case '1':
			{
				cout << "���� ��������� �����: " << endl;
				for (int i = 0; i < n; i++)
				{
					while (!(cin >>a))
					{
						cout << "������� ������������ ��������. ������� �������� ������." << endl;
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
				srand(time(NULL));																							//���������� ��������� ����� ��� ����, ����� ����� ��� ����������� ��������� ���������� 		
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

	cout << "����� �����: " << endl;
	if (begin == NULL)
		cout << "���� ����" << endl;
	else
		view(begin);

	while (menu== true)
	{
		cout << "\t\t\t\t\t\t\t ���� \n" << endl;
		cout << "1)����� �����" << endl;
		cout << "2)���������� �������� � ����" << endl;
		cout << "3)���������� ���������� ��������� � ����" << endl;
		cout << "4)������� �����" << endl;
		cout << "5)��������� ���������� �� ������� ����� � �����������" << endl;
		cout << "6)���������� ������� ��������� ������������ ������" << endl;
		cout << "7)���������� �������" << endl;
		cout << "8)��������� ������ ���������" << endl;
		cout << endl;

		do
		{
			sw = _getch();
			switch (sw)
			{
				case '1':
				{
					system("cls");
					cout << "����� �����: " << endl;
					if (begin == NULL)
					{
						cout << "���� ����" << endl;
					}
					else
					{
						view(begin);
					}
					menu = true;
					flag = true;
					cout << endl;
					cout << "�������� ����� ��������:" << endl;
					cout << endl;
					break;
				}
				
				case '2':
				{
					system("cls");
					cout << "�������� ������� � ����: ";
					while (!(cin >> x))
					{
						cout << "������� ������������ ��������. ������� �������� ������." << endl;
						cin.clear();
						cin.ignore();
					}
					begin = input(begin, x);
					cout << "\n����� �����:" << endl;
					view(begin);
					menu = true;
					flag = true;
					cout << endl;
					cout << "�������� ����� ��������:" << endl;
					cout << endl;
					break;
				}
				
				case '3':
				{	
					system("cls");
					cout << "���������� ����������� ���������: ";
					while (!(cin >> n) and n < 1)
					{
						cout << "������� ������������ ��������. ������� �������� ������." << endl;
						cin.clear();
						cin.ignore();
					}
					cout << "���������� ���������:" << endl;
					cout << "1)� ����������" << endl;
					cout << "2)��������" << endl;
					do
					{
						sw = _getch();
						switch (sw)
						{

							case '1':
							{
								cout << "���� ��������� �����: " << endl;
								for (int i = 0; i < n; i++)
								{
									while (!(cin >> x))
									{
										cout << "������� ������������ ��������. ������� �������� ������." << endl;
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
								srand(time(NULL));																							//���������� ��������� ����� ��� ����, ����� ����� ��� ����������� ��������� ���������� 		
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
	
					cout << "\n����� �����:" << endl;
					view(begin);
					menu = true;
					flag = true;
					cout << endl;
					cout << "�������� ����� ��������:" << endl;
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
					cout << "���� ����" << endl;
					cout << "�������� ����� ��������:" << endl;
					cout << endl;
					break;
				}

				case '5':
				{
					system("cls");
					if (begin == NULL)
						cout << "���� ����" << endl;
					else
					{
						begin = out_stack(begin, &out);
						cout << "������� �����: " << out << endl;
					}
					menu = true;
					flag = true;
					cout << endl;
					cout << "�������� ����� ��������:" << endl;
					cout << endl;
					break;
				}
			
				case '6':
				{
					system("cls");
					cout << "�������� ����:" << endl;
					view(begin);
					begin = mas(begin);
					cout << endl;

					cout << "��������������� ����: " << endl;
					view(begin);
					flag = true;
					menu = true;
					cout << endl;
					cout << "�������� ����� ��������:" << endl;
					cout << endl;
					break;
				}
			
				case '7':
				{
					system("cls");
					cout << "�������� ����:" << endl;
					view(begin);
					cout << endl;
					cout << endl;
					
					begin = Work(begin);
					cout << "��������������� ����: " << endl;
					view(begin);
					
					flag = true;
					menu = true;
					cout << endl;
					cout << endl;
					cout << "�������� ����� ��������:" << endl;
					cout << endl;
					break;
				}

				case '8':
				{
					cout << "�������� ���������:" << endl;
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