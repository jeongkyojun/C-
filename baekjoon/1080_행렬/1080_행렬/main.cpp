#include<iostream>
#include<string>

using namespace std;

int Min(int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}

int main()
{
	int row, col, result1 = 0,result2=0;
	string str;
	int mat[51][51], res[51][51];

	cin >> row >> col;
	getchar();
	for (int i = 0; i < row; i++)
	{
		getline(cin, str);
		for (int j = 0; j < col; j++)
		{
			mat[i][j]=str[j]-0x30;
		}
	}
	for (int i = 0; i < row; i++)
	{
		getline(cin, str);
		for (int j = 0; j < col; j++)
		{
			res[i][j] = str[j] - 0x30;
		}
	}

	//1Â÷
	for (int i = 0; i <= row - 3; i++)
	{
		for (int j = 0; j <= col - 3; j++)
		{
			if (mat[i][j]!=res[i][j])
			{
				result1++;
				for (int a = i; a < i + 3; a++)
				{
					for (int b = j; b < j + 3; b++)
					{
						mat[a][b] = (mat[a][b] + 1) % 2;
					}
				}
			}
		}
	}

	bool key = false;
	for (int i = row - 3; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (mat[i][j] != res[i][j])
			{
				result1 = -1;
				key = true;
				break;
			}
		}
		if (key)
			break;
	}

	if (!key)
	{
		for (int i = 0; i <= row-3; i++)
		{
			for (int j = col-3; j < col; j++)
			{
				if (mat[i][j] != res[i][j])
				{
					result1 = -1;
					key = true;
					break;
				}
			}
			if (key)
				break;
		}
	}

	// 2Â÷
	for (int i = row-1; i >= 3; i--)
	{
		for (int j = col-1; j >= 3; j--)
		{
			if (mat[i][j] != res[i][j])
			{
				result2++;
				for (int a = i; a > i - 3; a--)
				{
					for (int b = j; b > j - 3; b--)
					{
						mat[a][b] = (mat[a][b] + 1) % 2;
					}
				}
			}
		}
	}

	key = false;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (mat[i][j] != res[i][j])
			{
				result2 = -1;
				key = true;
				break;
			}
		}
		if (key)
			break;
	}

	if (!key)
	{
		for (int i = 3; i < row; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (mat[i][j] != res[i][j])
				{
						result2 = -1;
						key = true;
						break;
				}
			}
			if (key)
				break;
		}
	}

	int result;

	if (result1 != -1 && result2 != -1)
		result = Min(result1, result2);
	else if (result1 == -1)
		result = result2;
	else if(result2 == -1)
		result = result1;

	cout << result<<endl;
}