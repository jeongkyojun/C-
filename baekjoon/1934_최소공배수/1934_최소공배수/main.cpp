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
	int T, A, B;
	int num;

	cin >> T;
	for (int test = 0; test < T; test++)
	{
		cin >> A >> B;
		num = A * B;
		for (int i = 2; i <= min(A, B); i++)
		{
			while (true)
			{
				if (A % i == 0 && B % i == 0)
				{
					num /= i;
					A /= i;
					B /= i;
				}
				else
					break;
			}
		}
		cout << num << endl;
	}
}