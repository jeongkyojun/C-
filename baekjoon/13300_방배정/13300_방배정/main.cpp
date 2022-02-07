#include<iostream>

using namespace std;

int main()
{
	int N, K;
	int S, Y;
	int mat[2][7];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			mat[i][j] = 0;
		}
	}
	cin >> N >> K;
	// 학년 별, 성별 별로 나눈다.
	for (int i = 0; i < N; i++)
	{
		cin >> S >> Y;
		mat[S][Y]++;
	}
	int rn = 0;
	// 학년과 성별에 따라 방을 배정한다.
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			rn += mat[i][j] / K;
			if (mat[i][j] % K != 0)
				rn++;
		}
	}
	cout << rn << endl;
}