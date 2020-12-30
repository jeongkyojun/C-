#include<iostream>

using namespace std;

int Min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int MaxDiv(int a, int b)
{
	int mx=1;
	for (int i = 2; i <= Min(a, b); i++)
	{
		while (true)
		{
			if (a % i == 0 && b % i == 0)
			{
				mx *= i;
				a /= i;
				b /= i;
			}
			else
				break;
		}
	}
	return mx;
}

int main()
{
	int A, B;
	int MD;
	cin >> A >> B;
	MD = MaxDiv(A, B);
	cout << MD << endl;
	cout << (A * B) / MD << endl;
}