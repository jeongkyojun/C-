#include<iostream>
#include<vector>
using namespace std;

int MIN(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
int main()
{
	int n,m;
	char color;
	vector<vector<char> > chess;
	cin >> n>> m;
	vector<char> row(m);
	int min = n * m;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> color;
			row[j] = color;
		}
		chess.push_back(row);
	}
	for (int i = 0; i <= chess.size()-8; i++)
	{
		for (int j = 0; j <= row.size() - 8; j++)
		{
			cnt = 0;
			for (int a = i; a < i+8; a++)
			{
				for (int b = j; b < j + 8; b++)
				{
					if ((a + b) % 2 == 1)
					{
						if (chess[a][b] != 'W')
						{
							cnt++;
						}
					}
					else
					{
						if (chess[a][b] != 'B')
						{
							cnt++;
						}
					}
				}
			}
			if (MIN(cnt, 64 - cnt) < min)
			{
				min = MIN(cnt, 64 - cnt);
			}
		}
	}

	cout << min<<endl;

}