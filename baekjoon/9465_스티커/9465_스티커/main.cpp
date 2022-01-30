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
		//시작 : 초기화
		maxNum = -1;
		cin >> size;
		// 값 입력
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cin >> num;
				a[i][j] = num;
				// 가장 큰 수 구해서 저장해놓기
				if (maxNum < a[i][j])
					maxNum = a[i][j];
			}
		}
		for (int j = 1; j < size; j++)
		{
			for (int i = 0; i < 2; i++)
			{
				// dp 수행
				if (j == 1)
				{
					a[i][1] = a[(i + 1) % 2][j - 1] + a[i][1];
				}
				else
				{
					// a[i][j] + max( a[(i + 1) % 2][j - 1] , a[1][j - 2] , a[0][j - 2] )
					a[i][j] = a[i][j] + max(a[(i + 1) % 2][j - 1], a[1][j - 2], a[0][j - 2]);
				}
				// 큰수 저장
				if (maxNum < a[i][j])
					maxNum = a[i][j];
			}
		}
		// 가장 큰 수 출력
		cout << maxNum << endl;
	}
}