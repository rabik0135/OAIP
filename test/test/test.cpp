#include <iostream>
#include <cmath>

using namespace std;
 
struct Stack
{
	int info;
	Stack *next;
};

Stack* Max(Stack *t)
{
	Stack *max = t;
	while (t)
	{
		if (t->info > max->info)
			max = t;
		t = t->next;
	}

	return max;

}

Stack* Min(Stack*t)
{
	Stack* min = t;
	while (t)
	{
		if (t->info < min->info)
			min = t;

		t = t->next;
	}

	return min;
}

Stack* input(Stack *p, int a)			//Функция создания или добавления элементов в стек
{
	Stack *t = new Stack;
	t->info = a;
	t->next = p;
	return t;
}

Stack* out_stack(Stack *p, int *out)
{

	Stack* t = p;
	
	do
	{
		*out = p->info;
		p = p->next;
		delete t;
	} while (p != NULL);
		
	
	return p;
}

Stack* delete_stack(Stack *p)
{
	Stack*t;
	
	
		t = p;
		p = p->next;
		delete t;
	
	return p;
}

Stack* delete_between_max_min(Stack* p)
{
	if (p == NULL) {
		return p;
	}

	Stack* max = Max(p);
	Stack* min = Min(p);

	if (max == min) {
		return p;
	}

	if (max->next == min) {
		return p;
	}

	Stack* t = p;
	Stack* prev = NULL;

	while (t != NULL) {
		if (t == max) {
			Stack* d = t->next;
			while (d != min) {
				Stack* tmp = d;
				d = d->next;
				delete tmp;
			}
			t->next = min;
			return p;
		}

		if (t == min) {
			Stack* d = t->next;
			while (d != max) {
				Stack* tmp = d;
				d = d->next;
				delete tmp;
			}
			t->next = max;
			return p;
		}

		prev = t;
		t = t->next;
	}

	return p;
}






Stack* mas(Stack *b)
{
	
	int n = 0, *a, i, m, min, max;
	Stack *t=b;
	while (t != NULL)
	{
		n++;
		t = t->next;
	}
	
	a = new int[n];
	for (i = 0; i < n; i++)
		b = out_stack(b, (a+i));
	
	cout << endl;
	cout << "Полученный массив:" << endl;
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

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
		for (m= i = 0; i < n; i++)
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
						pos_max--; n--;
					} while (pos_now != pos_max);
					a[m++] = a[i];
				}
		}
	}
	if(pos_min>pos_max)
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
					pos_min--; n--;
				} while (pos_now != pos_min);
				a[m++] = a[i];
			}
		}
	}
	
	for (i = 0; i < m; i++)
		b = input(b, a[i]);
	
	for (i = 0; i < m; i++)
		b = input(b, a[i]);
	
	for (i = 0; i < m; i++)
		b = out_stack(b, (a + i));
	
	for (int i = 0; i < n; i++)
		b = delete_stack(b);

	for (i = 0; i < m; i++)
		b = input(b, a[i]);

	delete[] a;
	return b;
}


void view(Stack *p)
{
	Stack *t = p;
	while (t != NULL)
	{
		cout << t->info << endl;
		t = t->next;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	
	Stack *begin, *t; 
	
	begin = NULL;	
	t = new Stack;	
	int a, n;

	cout << "Введите количество элементов в стеке: ";
	cin >> n;
	cout << endl;

	cout << "Ввод элементов стека: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		begin = input(begin, a);
	}
	
	cout << endl;
	cout << endl;
	cout << "Исходный стек:" << endl;
	view(begin);
	cout << endl;
	cout << endl;
	cout << "Отсортированный стек: " << endl;
	begin = delete_between_max_min(begin);
	view(begin);
	 
}