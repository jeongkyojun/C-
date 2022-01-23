#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
* 입출력이 늦어서 시간초과 됨
* printf 와 scanf로 바꾸자. 그러면 된다.
*/

// 1. 원본 벡터 v
// 2. 값을 넣을 벡터 p
// 3. 어떤것들을 넣었는지 확인할 b
// 4. 현재 값의 인덱스를 표시할 i
// 5. 배열의 최대 크기 M
// 6. 배열의 현재 크기 point
void N_M(vector<int>&v,vector<int>p, vector<bool> b,int i,int M, int point)
{
	p.push_back(v[i]);
	b[i] = true;
	if (point == M) // 최대 개수만큼 넣었으면 출력
	{
		for (int j = 0; j < p.size(); j++)
		{
			cout << p[j] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (!b[j])
			{ 
				if (v[j] > v[i]) // 현재값이 지금보다 클경우
				{
					N_M(v, p, b, j, M, point + 1);
				}
			}
		}
	}
}
int main()
{
	vector<int> v,p;
	vector<bool> b;
	int N, M,num;
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
		b.push_back(false);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		N_M(v, p, b, i, M, 1);
	}
}