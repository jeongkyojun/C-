#include<iostream>

using namespace std;
int max(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return a;
		return c;
	}
	if (b > c)
		return b;
	return c;
}
int main()
{
	int a[2][100001];
	int T, size, num, maxNum = -1;
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		//���� : �ʱ�ȭ
		maxNum = -1;
		cin >> size;
		// �� �Է�
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cin >> num;
				a[i][j] = num;
				// ���� ū �� ���ؼ� �����س���
				if (maxNum < a[i][j])
					maxNum = a[i][j];
			}
		}
		for (int j = 1; j < size; j++)
		{
			for (int i = 0; i < 2; i++)
			{
				// dp ����
				if (j == 1)
				{
					a[i][1] = a[(i + 1) % 2][j - 1] + a[i][1];
				}
				else
				{
					// a[i][j] + max( a[(i + 1) % 2][j - 1] , a[1][j - 2] , a[0][j - 2] )
					a[i][j] = a[i][j] + max(a[(i + 1) % 2][j - 1], a[1][j - 2], a[0][j - 2]);
				}
				// ū�� ����
				if (maxNum < a[i][j])
					maxNum = a[i][j];
			}
		}
		// ���� ū �� ���
		cout << maxNum << endl;
	}
}