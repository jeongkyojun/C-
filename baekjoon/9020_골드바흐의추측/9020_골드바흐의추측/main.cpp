#include<iostream>

#define MaxSize 10001
using namespace std;

// 에라토스테네스의 체 - 초기화
void Eratostenes(bool Arr[], int num)
{
	Arr[1] = false;
	for (int i = 2; i < num; i++)
	{
		Arr[i] = true;
	}
	
	for (int i = 2; i*i < num; i++)
	{
		if (Arr[i])
		{
			for (int j = i * i; j < num; j += i)
			{
				Arr[j] = false;
			}
		}
	}
}

int main()
{
	int T,n;
	bool ArrPrime[MaxSize];
	Eratostenes(ArrPrime, MaxSize);
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		cin >> n;
		int a, b;
		int bound = n / 2;
		for (int i = bound; i < MaxSize; i++)
		{
			if (ArrPrime[i])
			{
				if (ArrPrime[n - i])
				{
					a = n - i;
					b = i;
					break;
				}
			}
		}
		cout << a <<" " <<b<<endl;
	}
}