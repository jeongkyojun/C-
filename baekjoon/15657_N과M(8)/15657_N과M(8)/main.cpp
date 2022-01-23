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
// 3. 현재 값의 인덱스를 표시할 i
// 4. 배열의 최대 크기 M
// 5. 배열의 현재 크기 point
void N_M(vector<int>& v, vector<int>p,vector<bool>b, int i, int M, int point)
{
	p.push_back(v[i]);
	if (point == M) // 최대 개수만큼 넣었으면 출력
	{
		for (int j = 0; j < p.size(); j++)
		{
			//printf("%d ",p[j]);
			cout << p[j] << " ";
		}
		//printf("\n");
		cout << endl;
	}
	else
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (!b[j])
			{
				if (v[i] <= v[j])
				{
					N_M(v, p, b, j, M, point + 1);
				}
				else
				{
					b[j] = true;
				}
			}
		}
	}
}
int main()
{
	vector<int> v, p;
	vector<bool>b;
	int N, M, num;
	cin >> N;
	cin >> M;
	//scanf("%d%d",&N,&M);
	for (int i = 0; i < N; i++)
	{
		//scanf("%d",&num);
		cin >> num;
		v.push_back(num);
		b.push_back(false);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		N_M(v, p, b,i, M, 1);
	}
}