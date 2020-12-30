#include<iostream>

using namespace std;

int GDC(int a, int b)
{
	int r;
	while (b!=0)
	{
		r = a;
		a = b;
		b = r % b;
	}
	return a;
}
int main()
{
	int a, b, c, d,gdc;
	cin >> a>> b;
	cin >> c >> d;
	gdc = GDC(b, d);
	int head = (a * d + c * b) / gdc;
	int body = b * d / gdc;
	int gdc2 = GDC(head, body);
	cout << head/gdc2 << " " << body/gdc2 << endl;
}