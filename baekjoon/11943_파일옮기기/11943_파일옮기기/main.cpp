#include<iostream>

using namespace std;


int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	int a, b, c, d;
	cin >> a >> b;
	cin >> c >> d;
	cout << min(a+d,b+c) << endl;
}