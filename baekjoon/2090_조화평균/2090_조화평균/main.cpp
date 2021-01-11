#include<iostream>

using namespace std;

/*
* a , b , c ÀÇ Á¶È­Æò±Õ
* 1   1   1   ( bc + ac + ab ) / GDC(a,b,c)
* - + - + - = ------------------------------
* a   b   c       abc / GDC(a,b,c)
* 
* Áï, Á¶È­Æò±ÕÀº		abc / GDC(a,b,c)
*				-------------------------------
*				 ( bc + ac + ab ) / GDC(a,b,c)
* 
*/

unsigned long long get_GDC(unsigned long long a, unsigned long long b)
{
	int tmp;
	while (b != 0)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

// mother / son + 1/num = mother * num + son /  son * num

// mother -> mother * num + son
// son -> son * num

int main()
{
	int N, num;
	unsigned long long mother, son, gdc ; // son : ¸ðµç ¼öÀÇ °ö

	cin >> N;
	mother = 0;
	son = 1;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (i == 0)
			gdc = 1;
		else
		{
			gdc = get_GDC(son, num);
		}
		mother *= num;
		mother += son;
		son *= num;

		mother /= gdc;
		son /= gdc;
	}

	gdc = get_GDC(mother, son);
	son /= gdc;
	mother /= gdc;

	cout << son << "/" << mother << endl;

}