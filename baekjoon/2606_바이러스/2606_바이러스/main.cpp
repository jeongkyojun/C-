#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> vec;
	vector<vector<int> > mat;

	int arrStack[100]; // 스택이라고 하지만 사실 큐임
	int top = -1;

	int N,num;
	int res = 0;
	cin >> N;
	for (int i = 0; i <= N; i++)
	{
		vec.push_back(0);
	}
	for (int i = 0; i <= N; i++)
	{
		mat.push_back(vec);
	}
	cin >> num;
	arrStack[++top] = 1;
	int a, b;
	for (int i = 0; i < num; i++)
	{
		cin >> a >> b;
		mat[a][b] = 1;
		mat[b][a] = 1;
	}

	while (top != -1)
	{
		int x = arrStack[top--];
		for (int i = 2; i < vec.size(); i++)
		{
			if (mat[x][i] == 1)
			{
				arrStack[++top] = i;
				res++;
				for (int j = 0; j < mat.size(); j++)
				{
					mat[j][i] = 0;
				}
			}
		}
	}

	cout << res << endl;
}