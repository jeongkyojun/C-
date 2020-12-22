#include<iostream>
#include<vector>
using namespace std;

void N_M(int num, int N, int M, int cnt, vector<int> vec,vector<bool>vec2)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vec.push_back(num);
	vec2[num] = false;
	cnt++;
	if (cnt < M)
	{
		for (int i = 1; i <= N; i++)
		{
			if (vec2[i])
			{
				N_M(i, N, M, cnt, vec,vec2);
			}
		}
	}
	else
	{
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i]<<" ";
		}
		cout << "\n";
	}
}

/*
void N_M(int num, int N, int M,int cnt,vector<int> vec)
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
*/
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> vec;
	vector<bool>vec2(9);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= 8; i++)
	{
		vec2[i] = true;
	}
	for (int i = 1; i <= N; i++)
	{
		N_M(i,N, M, 0,vec,vec2);
	}
}