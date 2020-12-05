#include<iostream>

using namespace std;

int max(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return a;
		return c;
	}
	if (b > c)
	{
		return b;
	}
	return c;
}
int main()
{
	int a, b, c;
	while (true)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;
		a *= a;
		b *= b;
		c *= c;
		if (max(a, b, c) == a + b + c - max(a, b, c))
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
}