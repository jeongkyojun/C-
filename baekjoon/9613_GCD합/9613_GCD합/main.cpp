#include<iostream>

using namespace std;

int GCD(int a, int b)
{
	int one, two,gcd;
	if (a > b)
	{
		one = a;
		two = b;
	}
	else
	{
		one = b;
		two = a;
	}

	while (true)
	{
		if (one % two == 0)
		{
			gcd = two;
			break;
		}
		one = one%two;
		if (two % one == 0)
		{
			gcd = one;
			break;
		}
		two = two%one;
	}
	return gcd;
}

unsigned long long gcdPlus(int a[],int len,int point)
{
	unsigned long long res=0;
	for (int i = point+1; i < len; i++)
	{
		res += GCD(a[point], a[i]);
	}
	return res;
}

int main()
{
	int arr[101];
	int t, n;
	unsigned long long res;
	cin >> t;
	for (int test = 0; test < t; test++)
	{
		res = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		for (int i = 0; i < n-1; i++)
		{
			res+= gcdPlus(arr, n, i);
		}
		cout << res << endl;
	}
}