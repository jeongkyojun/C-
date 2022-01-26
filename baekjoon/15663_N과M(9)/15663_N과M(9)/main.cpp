#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void M_N(vector<int>& vec, vector<int>v, vector<bool>b, int cnt, int point, int end)
{
	vector<int> v2;
	vector<bool>b2;
	bool key = false;
	// 1부터 값을 넣는다. 맨 처음은 pass
	if (cnt != 0)
	{
		b[point] = false;
		v.push_back(vec[point]);
	}

	// 추려내기 ( 겹치는건 임시적으로 false취급한다)
	for (int i = 0; i < vec.size(); i++)
	{
		key = false;
		for (int j = 0; j < i; j++)
		{
			if (b[i]&&b[j]&&vec[i] == vec[j])
			{
				key = true;
				break;
			}
		}
		if (!key)
		{
			v2.push_back(vec[i]);
			b2.push_back(b[i]);
		}
		else
		{
			v2.push_back(vec[i]);
			b2.push_back(false);
		}
	}

	// 다 담았으면 출력한다.
	if (cnt == end)
	{
		for (int j = 0; j < v.size(); j++)
		{
			cout << v[j] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int j = 0; j < vec.size(); j++)
		{
			// true인것만 넘어간다
			if (b2[j])
			{
				M_N(vec, v, b, cnt+1, j, end);
			}
		}
	}
}
int main()
{
	vector<int>vec,v;
	vector<bool>b;
	int N, M,num;
	bool f = false;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		f = false;
		cin >> num;
		vec.push_back(num);
		b.push_back(true);
	}

	sort(vec.begin(), vec.end());
	M_N(vec, v,b, 0, 0,M);
}