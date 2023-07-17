#include <iostream>
using namespace std;

struct Stack
{
	char element;
	Stack *next;
};
int Prior(char);
Stack* InStack(Stack*, char);
Stack* OutStack(Stack*, char&);
double Result(char*);
void Confus(char[], int);

int main()
{
	setlocale(LC_ALL, "rus");
	Stack *t, *operations = NULL;
	char a, input_string[81], output_string[81];
	int k=0, l = 0;
	cout << "Введите формулу:" << endl;
	cin>>input_string;
	Confus(input_string, k);

	for (k = 0; input_string[k] != NULL; ++k)
	{
		//Если элемент-буква
		if (input_string[k] >= 'a' and input_string[k] <= 'z')
			output_string[l++] = input_string[k];
		else
		{
			//Если элемент-открывающая скобка
			if (input_string[k] == '(')
				operations = InStack(operations, input_string[k]);
			else
			{
				//Если элемент-закрывающая скобка
				if (input_string[k] == ')')
				{
					while ((operations->element) != '(')
					{
						operations = OutStack(operations, a);
						if (!operations)
							a = NULL;
						output_string[l++] = a;
					}
					operations = OutStack(operations, a);
				}
				else
				{
					//Если элемент-знак операции 
					if (input_string[k] == '+' or input_string[k] == '-' or input_string[k] == '*' or input_string[k] == '/' or input_string[k] == '^')
					{
						while (operations != NULL and Prior(operations->element) >= Prior(input_string[k]))
						{
							operations = OutStack(operations, a);
							output_string[l++] = a;
						}

						operations = InStack(operations, input_string[k]);
					}
				}
			}
		}
	}
	//Если операций не пуст, извлекаем все из него в выходную строку
	while (operations != NULL)
	{
		operations = OutStack(operations, a);
		output_string[l++] = a;
	}

	output_string[l] = NULL;
	cout << "Польская запись: " << output_string << endl;
	cout << "Результат выражения: " << Result(output_string) << endl;
	system("pause");
}

int Prior(char a)
{
	switch (a)
	{
	case'^':				return 4;
	case'*':	case'/':	return 3;
	case'+':	case'-':	return 2;
	case'(':				return 1;
	}
	return 0;
}

Stack* InStack(Stack *p, char s)
{
	Stack *t = new Stack;
	t->element = s;
	t->next = p;
	return t;
}

Stack* OutStack(Stack *p, char &s)
{
	Stack *t = p;
	s = p->element;
	p = p->next;
	delete t;
	return p;
}

double Result(char *str)
{
	int i;	
	Stack *begin = NULL;
	char ss, ss_1, ss_2, ss_Result = 'z' + 1;
	double operation_1, operation_2, result, mas[50];
	cout << "Введите переменные" << endl;
	for (i = 0; str[i] != NULL; ++i)
	{
		ss = str[i];
		if (ss >= 'a' and ss <= 'z')
		{
			cout << ss << "=";
			cin >> mas[int(ss - 'a')];									//ss-'a' это индекс элемента в массиве 
		}
	}
	for (i = 0; str[i] != NULL; ++i)
	{
		ss = str[i];
		if (!(ss == '+' or ss == '-' or ss == '*' or ss == '/' or ss=='^'))
			begin = InStack(begin, ss);
		else
		{
			begin = OutStack(begin, ss_2);
			begin = OutStack(begin, ss_1);
			operation_2 = mas[int(ss_2 - 'a')];
			operation_1 = mas[int(ss_1 - 'a')];
			switch (ss)
			{
			case'+':	result = operation_1 + operation_2; break;
			case'-':	result = operation_1 - operation_2; break;
			case'*':	result = operation_1 * operation_2; break;
			case '^':	result = pow(operation_1, operation_2); break;
			case'/':	result = operation_1 / operation_2; 
						if (operation_2 == 0)
						{
							cout << "Невозможно выполнить деление на 0." << endl;
							return 0;
						}
						break;
			}
			mas[int(ss_Result - 'a')] = result;
			begin = InStack(begin, ss_Result);
			ss_Result++;
		}
	}
	return result;
}

void Confus(char input_string[], int k)
{
	while (input_string[k] != NULL)
	{
		if ((input_string[k] >= 'a' and input_string[k] <= 'z') == true and (input_string[k + 1] >= 'a' and input_string[k + 1] <= 'z') == true and (input_string[k+1]='^')==false)
		{
			cout << "Две переменные не могут стоять подряд." << endl;
			exit(0);
		}
		
		if ((input_string[k] == '+' or input_string[k] == '-' or input_string[k] == '*' or input_string[k] == '/' or input_string[k]=='^') == true and (input_string[k + 1] == '+' or input_string[k + 1] == '-' or input_string[k + 1] == '*' or input_string[k + 1] == '/' or input_string[k+1] == '^') == true)
		{
			cout << "Два оператора не могут стоять подряд." << endl;
			exit(0);
		}
		
		
		if ((input_string[k] == '(') == true and (input_string[k+1] == '+' or input_string[k+1] == '-' or input_string[k+1] == '*' or input_string[k+1] == '/' or input_string[k+1] == '^') == true)
		{
			cout << "После открывающей скобки должна идти переменная, а не оператор." << endl;
			exit(0);
		}
		
		if ((input_string[k + 1] == ')') == true and (input_string[k] == '+' or input_string[k] == '-' or input_string[k] == '*' or input_string[k] == '/' or input_string[k] == '^') == true)
		{
			cout << "Перед закрытием скобки должна идти переменная, а не оператор." << endl;
			exit(0);
		}
		
		if ((input_string[k + 1] == '(') == true and (input_string[k] >= 'a' and input_string[k] <= 'z') == true)
		{
			cout << "Перед открытием скобки должен идти оператор, а не переменная." << endl;
			exit(0);
		}

		if ((input_string[k] == ')') == true and (input_string[k+1] == '+' or input_string[k+1] == '-' or input_string[k+1] == '*' or input_string[k+1] == '/' or input_string[k+1] == '^') == true)
		{
			cout << "После закрытия скобки должна идти переменная, а не оператор." << endl;
			exit(0);
		}
		
		if ((input_string[0] == '+' or input_string[0] == '-' or input_string[0] == '*' or input_string[0] == '/' or input_string[0] == '^') == true)
		{
			cout << "Выражение должно начинаться с переменной или скобки." << endl;
			exit(0);
		}
	
		if ((input_string[k + 1] == '\0') == true and (input_string[k] == '+' or input_string[k] == '-' or input_string[k] == '*' or input_string[k] == '/' or input_string[k] == '^') == true)
		{
			cout << "Выражение должно оканчиваться переменной или скобкой" << endl;
			exit(0);
		}
		k++;
	}
}