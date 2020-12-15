#include<iostream>
using namespace std;

int main()
{
	int counting[10001];
	for (int i = 1; i <= 10000; i++)
	{
		counting[i] = 0;
	}

	int num, N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		counting[num]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 0; j < counting[i]; j++)
		{
			printf("%d\n",i);
		}
	}
}