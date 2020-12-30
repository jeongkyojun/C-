#include<iostream>

using namespace std;

int main()
{
	int mat[102][102];
	int vec[102];
	int row, col, wid, hei;
	int cnt = 1;
	int t;
	cin >> t;
	for (int i = 0; i <= 101; i++)
	{
		for (int j = 0; j <= 101; j++)
		{
			mat[i][j] = 0;
		}
		vec[i] = 0;
	}

	for (int test = 0; test < t; test++)
	{
		cin >> row >> col >> wid >> hei;
		for (int i = row; i < row + wid; i++)
		{
			for (int j = col; j < col + hei; j++)
			{
				mat[i][j] = cnt;
			}
		}
		cnt++;
	}

	for (int i = 0; i <= 101; i++)
	{
		for (int j = 0; j <= 101; j++)
		{
			if (mat[i][j] != 0)
				vec[mat[i][j]] ++;
		}
	}

	for (int i = 1; i <= t; i++)
	{
		cout << vec[i] << endl;
	}

}