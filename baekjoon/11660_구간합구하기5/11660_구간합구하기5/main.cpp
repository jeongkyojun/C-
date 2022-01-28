#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> vec;
	vector<vector<int>>mat;
	int N, T,num;
	int x1, y1, x2, y2;
	cin >> N;
	cin >> T;
	for (int i = 0; i <= N; i++)
	{
		vec.push_back(0);
	}
	for (int i = 0; i <= N; i++)
	{
		mat.push_back(vec);
	}

	for (int i = 1; i <= N; i++)
	{
		mat[i][0] = 0;
		for (int j = 1; j <= N; j++)
		{
			cin >> num;
			mat[i][j] = num+mat[i][j-1];
		}
	}
	for (int i = 0; i < T; i++)
	{
		int sum = 0;
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		for (int j = x1; j <= x2; j++)
		{
			sum += mat[j][y2] - mat[j][y1-1];
		}
		cout << sum << endl;
	}
}