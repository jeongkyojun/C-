#include<iostream>

using namespace std;

// n���� �ڿ����� �̷���� ����
// Ư������ [i,j]�� ���� k���� ū ��� �� ij�� ����

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