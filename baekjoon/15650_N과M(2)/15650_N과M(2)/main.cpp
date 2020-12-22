#include<iostream>
#include<vector>

using namespace std;

void N_M(int num, int N, int M, int cnt, vector<int> vec)
{
	vec.push_back(num);
	cnt++;
	if (cnt < M)
	{
		for (int i = num + 1; i <= N; i++)
		{
			N_M(i, N, M, cnt, vec);
		}
	}
	else
	{
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << " ";
		}
		cout << endl;
	}
}

int main()
{
	vector<int> vec;
	int N, M;

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		N_M(i, N, M, 0, vec);
	}
}