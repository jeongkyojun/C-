#include<iostream>

using namespace std;

int main()
{
	int V[100001];
	int N, K,num;
	int sw = 0, max = -1;

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		V[i] = num;
		if (i < K)
		{
			cout << " + " << endl;
			sw += num;
			max = sw;
		}
		else
		{
			for (int j = i - K; j <= i; j++)
			{
				cout << V[j] << " ";
			}
			cout << endl;
			sw -= V[i-K];
			sw += V[i];
			cout << i - K+1 << " 부터 " << i << " 까지의 연속합 : "<<sw << endl;
			if (max < sw)
				max = sw;
		}
	}
	cout << max << endl;
}