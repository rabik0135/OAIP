#include <iostream>

using namespace std;

double fun(double x);

double Mn_Lagr(double* x, double xt, int kol) {
	int i, k;
	double e, p = 0;
	for (k = 0; k < kol; k++) {
		e = 1;
		for (i = 0; i < kol; i++)
		{
			if (i != k) {
				e *= ((xt - x[i]) / (x[k] - x[i]));
			}
			p += e * fun(x[k]);
		}
	}
	return p;
}

int main()
{
	double x, h, h1, a = -2., b = 5., *mas_x, *mas_y_t;
	int i, n = 5, m = 5;
	h = (b - a) / (m - 1);
	h1 = (b - a) / (n - 1);
	mas_x = new double[m + 1];
	mas_y_t = new double[n + 1];

	for (x = a, i = 0; i < m; i++) {
		mas_x[i] = x;
		x += h;
	}

	for (x = a, i = 0; i < n; i++, x += h1) {
		mas_y_t[i] = Mn_Lagr(mas_x, x, m);
		cout << " x = " << x << " f*(x) = " << mas_y_t[i] << endl;
	}
}

double fun(double x) {
	return pow(x,3)+5*x*x;
}

/*double x,h,h1, a, b, *mas_x, *mas_y_t;
	int i,n,m;
			a = StrToFloat(Edit1->Text);        	b = StrToFloat(Edit2->Text);
			m = StrToInt(Edit3->Text);        	n = StrToInt(Edit4->Text);
			h = (b-a)/(m-1);	        			h1 = (b-a)/(n-1);
			mas_x = new double[m+1];    		mas_y_t = new double[n+1];
			for(x=a, i=0; i<m; i++){
				mas_x[i] = x;
				x+=h;
			}
			Memo1->Lines->Add("---- Многочлен Лагранжа ---");
			Memo1->Lines->Add("Получили " + IntToStr(n) + " значений:");
			for(x=a, i=0; i<n; i++, x+=h1) {
							mas_y_t[i] = Mn_Lagr(mas_x,x,m);
				Memo1->Lines->Add(" x = "+FloatToStrF(x,ffFixed,8,2)
						+"  f*(x) = "+FloatToStrF(mas_y_t[i],ffFixed,8,4));
			}
*/