#include<iostream>

using namespace std;

int main()
{
	int n, mat[101][101];
	int t,a,b,num;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			mat[i][j] = 0;
		}
	}
	cin >> t;
	// 경로 할당
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b>>num;
		if(mat[a][b]==0||mat[a][b]>num)
			mat[a][b] = num;
	}
	for (int x = 1; x <= n; x++) // 중간지점 n
	{
		for (int i = 1; i <= n; i++) // 경로 i -> j
		{
			for (int j = 1; j <= n; j++)
			{
				// i-> n이 존재
				if (i!=j&&mat[i][x] != 0 && mat[x][j] != 0)
				{
					if (mat[i][j] == 0 || mat[i][j] > mat[i][x] + mat[x][j])
						mat[i][j] = mat[i][x] + mat[x][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}