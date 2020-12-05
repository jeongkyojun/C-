#include<iostream>

using namespace std;

void Eratostenes(bool Arr[],int num)
{
	for(int i = 0; i < num; i++)
	{
		Arr[i] = true;
	}
	Arr[1] = false;
	for (int i = 2; i * i < num; i++)
	{
		if (Arr[i])
		{
			for (int j = i*i; j < num; j += i)
			{
				Arr[j] = false;
			}
		}
	}
}

int main()
{
	bool PrimeArr[246913];
	int n,res;
	Eratostenes(PrimeArr, 246913);
	while (true)
	{
		cin >> n;
		if (n == 0)
			break;
		res = 0;
		for (int i = n+1; i <= 2*n; i++)
		{
			if (PrimeArr[i])
				res++;
		}
		printf("%d\n", res);
	}
}