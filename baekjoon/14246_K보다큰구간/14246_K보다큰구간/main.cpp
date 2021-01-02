#include<iostream>

using namespace std;

// n개의 자연수로 이루어진 수열
// 특정구간 [i,j]의 합이 k보다 큰 모든 쌍 ij의 개수

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unsigned long long sums[100001];
	unsigned long long res = 0;
	unsigned long long num,n,k;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (i == 0)
			sums[i] = num;
		else
			sums[i] = num + sums[i - 1];
	}

	for (int i = 0; i < n; i++)
		cout << sums[i] << " ";
	cout << endl;

	cin >> k;
	for (int i = 0; i < n; i++)
	{
		if (sums[i] <= k)
		{

		}
		else
		{
			cout << "check! " << sums[i] << endl;
			res++;
			for (int j = 0; j < i; j++)
			{
				cout << "check! " << j << endl;
				if (sums[i] - sums[j] > k)
					res++;
				else
					break;
			}
		}
	}
	cout << res<<endl;
}