#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	int X[10],w,r;
	/*
	X(0) = 0
	X(1) = 0
	X(2) = 0
	X(3) = 9 * X(2) + 9*X(1) + 9*X(0) + pow(10,0) = 1
	X(n) = 9 * X(n-1) + 9* X(n-2) + 9 * X(n-3) + pow(10,n-3) 

	X(n-1)
	X(n-1)
	X(n-1)
	X(n-1)
	X(n-1)
	X(n-1)
		X(n-2)
		X(n-2)
		X(n-2)
		X(n-2)
		X(n-2)
		X(n-2)
			X(n-3)
			X(n-3)
			X(n-3)
			X(n-3)
			X(n-3)
			X(n-3)
				pow(10,n)
			X(n-3)
			X(n-3)
			X(n-3)
		X(n-2)
		X(n-2)
		X(n-2)
	X(n-1)
	X(n-1)
	X(n-1)
	*/

	X[0] = 0;
	X[1] = 0;
	X[2] = 0;
	for (int i = 3; i < 10; i++)
	{
		X[i] = X[i - 1] + X[i - 2] + X[i - 3] + pow(10, i - 3);
	}
	cin >> w;
	for (int i = 0; i < 10; i++)
	{
		if (w < X[i])
		{
			n = i;
			break;
		}
	}
}